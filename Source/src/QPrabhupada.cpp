#include <QPrabhupada.h>

QMapMemoryStorage::QMapMemoryStorage()
  : inherited()
{
}

QMapMemoryStorage::~QMapMemoryStorage()
{
}

void QMapMemoryStorage::LoadFromStream( QDataStream& ST )
{
  clear();
  // 1
  std::size_t L;
  ST >> L;
  // 2
  QString AFileName;
  QByteArray *BA;
  QBuffer    *BU;
  for ( std::size_t I = 0; I < L; ++I ) {
    BA = new QByteArray();
    BU = new QBuffer( BA );

    ST >> AFileName;
    ST >> *BA;

    if ( BU->open( QIODevice::ReadWrite ) ) {
      emplace( std::make_pair( AFileName, std::make_unique< QDataStream >( BU ) ) );
    }
  }
}

void QMapMemoryStorage::SaveToStream( QDataStream& ST )
{
  // 1
  ST << size();
  // 2
  QDataStream *AStream;
  QByteArray *BA;
  QBuffer    *BU;
  for ( iterator I = begin(); I != end(); ++I ) {
    ST << (*I).first;

    AStream = (*I).second.get();
    BU = static_cast< QBuffer* >( AStream->device() );
    BA = static_cast< QByteArray* >( &BU->buffer() );
    ST << *BA;
  }
}

QStorage::QStorage()
  : inherited()
{
}

QStorage::~QStorage()
{
  if ( m_Query != nullptr ) {
    delete m_Query;
  }
}

void QStorage::SetDatabase( QSqlDatabase *Value )
{
  if ( m_Database != Value ) {
    m_Database = Value;
    if ( m_Query != nullptr ) {
      delete m_Query;
    }
    m_Query = new QSqlQuery( *m_Database );
  }
}

bool QStorage::BeginLoad( QObject *O, QStorageKind AStorageKind )
{
  m_FileName = KeyStorage( O, AStorageKind );
  switch ( AStorageKind ) {
    case QStorageKind::File :
      m_File     = new QFile( m_FileName );
      m_Stream   = new QDataStream( m_File );
      return m_File->open( QIODevice::ReadOnly );
    case QStorageKind::DB :
      if ( m_Query != nullptr ) {
        m_Query->prepare( QString( "select\n"
                                  "  a.\"UserRegKey\"\n"
                                  ", a.\"UserData\"\n"
                                  "from\n"
                                  "    %1\"UserReg\" a\n"
                                  "where a.\"UserRegKey\" = :UserRegKey;" ).formatArg( m_Schema ) );
        m_Query->bindValue( ":UserRegKey", m_FileName );
        m_Query->exec();
        if ( m_Query->next() ) {
          m_Stream = new QDataStream( m_Query->value( 1 ).toByteArray() );
          return true;
        } else {
          return false;
        }
      }
      break;
    case QStorageKind::Memory :
      QMapMemoryStorage::iterator I = m_MapMemoryStorage.find( m_FileName );
      if ( I != m_MapMemoryStorage.end() ) {
        m_Stream = m_MapMemoryStorage[ m_FileName ].get();
        m_Stream->device()->seek( 0 );
        return true;
      } else {
        return false;
      }
  }
  return false;
}

void QStorage::EndLoad( QStorageKind AStorageKind )
{
  switch ( AStorageKind ) {
    case QStorageKind::File :
      m_File->close();
      delete m_Stream;
      delete m_File;
      m_File   = nullptr;
      break;
    case QStorageKind::DB :
      delete m_Stream;
      m_Query->clear();
      break;
    case QStorageKind::Memory :
      break;
  }
  m_Stream = nullptr;
}

void QStorage::BeginSave( QObject *O, QStorageKind AStorageKind )
{
  QBuffer *BU;
  m_FileName = KeyStorage( O, AStorageKind );
  switch ( AStorageKind ) {
    case QStorageKind::File :
      m_SaveFile = new QSaveFile( m_FileName );
      if ( m_SaveFile->open( QIODevice::WriteOnly ) ) {
        m_Stream = new QDataStream( m_SaveFile );
      }
      break;
    case QStorageKind::DB :
      if ( m_Query != nullptr ) {
        m_Query->prepare( QString( "select\n"
                                  "  a.\"UserRegKey\"\n"
                                  "from\n"
                                  "    %1\"UserReg\" a\n"
                                  "where a.\"UserRegKey\" = :UserRegKey;" ).formatArg( m_Schema ) );
        m_Query->bindValue( ":UserRegKey", m_FileName );
        m_Query->exec();
        m_ByteArray = new QByteArray();
        BU = new QBuffer( m_ByteArray );
        if ( BU->open( QIODevice::ReadWrite ) ) {
          m_Stream = new QDataStream( BU );
          if ( m_Query->next() ) {
            m_SQL = QString( "update %1\"UserReg\"\n"
                            "set\n"
                            "  \"UserData\" = :UserData\n"
                            "where\n"
                            "    \"UserRegKey\" = :UserRegKey;" ).formatArg( m_Schema );
          } else {
            m_SQL = QString( "insert into %1\"UserReg\"\n"
                            "( \"UserRegKey\", \"UserData\" )\n"
                            "values\n"
                            "( :UserRegKey, :UserData );" ).formatArg( m_Schema );
          }
        }
      }
      break;
    case QStorageKind::Memory :
      QMapMemoryStorage::iterator I = m_MapMemoryStorage.find( m_FileName );
      QByteArray *BA;
      QBuffer    *BU;
      if ( I == m_MapMemoryStorage.end() ) {
        BA = new QByteArray();
        BU = new QBuffer( BA );
        if ( BU->open( QIODevice::ReadWrite ) ) {
          auto J = m_MapMemoryStorage.emplace( std::make_pair( m_FileName, std::make_unique< QDataStream >( BU ) ) );
          m_Stream = (*J.first).second.get();
        }
      } else {
        m_Stream = m_MapMemoryStorage[ m_FileName ].get();
        BU = static_cast< QBuffer* >( m_Stream->device() );
        BA = static_cast< QByteArray* >( &BU->buffer() );
        BU->seek( 0 );
        BA->truncate( 0 );
      }
      break;
  }
}

void QStorage::EndSave( QStorageKind AStorageKind )
{
  switch ( AStorageKind ) {
    case QStorageKind::File :
      m_SaveFile->commit();
      delete m_Stream;
      delete m_SaveFile;
      m_SaveFile = nullptr;
      break;
    case QStorageKind::DB :
      m_Query->clear();
      m_Query->prepare( m_SQL );
      m_Query->bindValue( ":UserRegKey", m_FileName );
      m_Query->bindValue( ":UserData", *m_ByteArray, QSql::In | QSql::Binary );
      m_Query->exec();

      delete m_Stream;
      break;
    case QStorageKind::Memory :
      break;
  }
  m_Stream = nullptr;
}

bool QStorage::LoadObject( QObject *O, QStorageKind AStorageKind )
{
  bool LoadSuccess = false;
  if ( m_Enabled ) {

    if ( BeginLoad( O, AStorageKind ) ) {
      if ( m_Stream != nullptr ) {
        qint8 V;
        *m_Stream >> V;
        if ( V == m_Version ) {
          O->LoadFromStream( *m_Stream );
          *m_Stream >> V;
          if ( V == m_Version ) {
            LoadSuccess = true;
          }
        }
      }
    }
    EndLoad( AStorageKind );
  }
  return LoadSuccess;
}

void QStorage::SaveObject( QObject *O, QStorageKind AStorageKind )
{
  if ( m_Enabled ) {
    BeginSave( O, AStorageKind );
    if ( m_Stream != nullptr ) {
      *m_Stream << m_Version;
      O->SaveToStream( *m_Stream );
      *m_Stream << m_Version;
      EndSave( AStorageKind );
    }
  }
}

QString QStorage::PrefixKeyStorage()
{
  QString APrefix, AUserName;

  APrefix = qApp->objectName();
  if ( !APrefix.empty() ) {
    APrefix += "-";
  }
  if ( m_Database != nullptr ) {
    AUserName = m_Database->userName();
    if ( !AUserName.empty() ) {
      APrefix += AUserName + "-";
    }
  }

  return APrefix;
}

QString QStorage::KeyStorage( QObject *O, QStorageKind AStorageKind )
{
  QString R, S, APrefix;
  int i = 0;

  if ( AStorageKind == QStorageKind::DB ) {
    APrefix = PrefixKeyStorage();
  }

  while ( O != nullptr ) {
    S = O->objectName();
    if ( !S.empty() ) {
      if ( R.empty() )
        R = S;
      else
        R = S + "." + R;
    }

    O = O->parent();
    ++i;
  }

  if ( !R.empty() )
    R += ".ini";

  if ( !APrefix.empty() )
    R = APrefix + R;

  return R;
}

void QStorage::ResetSettings()
{
  m_Query->clear();
  m_Query->prepare( QString( "delete from %1\"UserReg\" where \"UserRegKey\" like :APrefix || '%';" ).formatArg( m_Schema ) );
  m_Query->bindValue( ":APrefix", PrefixKeyStorage() );
  m_Query->exec();
}

void QStorage::PrepareHistoryComboBox( QComboBox *CB, int MaxCount )
{
 if ( CB->isEditable() ) {
    QString S = CB->currentText();
    if ( !S.empty() ) {
      int I = CB->findText( S );
      if ( I != -1 ) {
        QString SA = CB->itemText( I );
        CB->setItemText( I, CB->itemText( 0 ) );
        CB->setItemText( 0, SA );
      } else {
        CB->insertItem( 0, S );
      }
      for ( I = CB->count() - 1; I >= MaxCount; --I ) {
        CB->removeItem( I );
      }
      CB->setCurrentIndex( 0 );
    }
  }
}

void QStorage::LoadFromStream( QComboBox *CB, QDataStream &ST )
{
  // 1
  QStringList SL;
  ST >> SL;
  CB->addItems( SL );
  // 2
  QString S;
  ST >> S;
  CB->setCurrentText( S );
}

void QStorage::SaveToStream( QComboBox *CB, QDataStream &ST )
{
  // 1, 2
  QStringList SL;
  int L = CB->count();
  for ( int i = 0; i < L; ++i ) {
    SL << CB->itemText( i );
  }
  ST << SL << CB->currentText();
}

void QStorage::SaveToStreamPrepareHistory( QComboBox *CB, QDataStream &ST, int HistoryCount )
{
  PrepareHistoryComboBox( CB, HistoryCount );
  SaveToStream( CB, ST );
}

void QStorage::LoadFromStream( QDataStream &ST )
{
  inherited::LoadFromStream( ST );

  m_MapMemoryStorage.LoadFromStream( ST );
}

void QStorage::SaveToStream( QDataStream &ST )
{
  inherited::SaveToStream( ST );

  m_MapMemoryStorage.SaveToStream( ST );
}

const QChar32 QStorage::CharPercent   = '%';
const QChar32 QStorage::CharUnderline = '_';

bool QStorage::Like( QString::iterator t_end, QString::iterator s_end, QString::iterator t, QString::iterator s )
{
  if ( t == t_end ) {
    return true;
  }
  QString::iterator tt, ss;
  while ( t != t_end && s != s_end ) {
    if ( ( *t ) == CharPercent ) {
      tt = ++t;
      ss = s;
      while ( ( ss != s_end ) ) {
        if ( Like( t_end, s_end, tt, ss++ ) ) {
          return true;
        }
      }
      return false;
    }
    if ( ( ( *t ) != ( *s ) ) && ( ( *t ) != CharUnderline ) ) {
      return false;
    }
    t++;
    s++;
  }
  if ( ( s != s_end ) ) {
    return false;
  }
  if ( t == t_end ) {
    return true;
  }
  do {
    if ( ( *t ) != CharPercent ) {
      return false;
    }
  } while ( ++t != t_end );
  return true;
}

bool QStorage::LikeBest( const QString& Template, const QString& Source )
{
  int I, J, K
    , LTemplate = Template.size()
    , LSource   = Source.size();

  bool Result = false;

  I = 0;
  J = 0;
  while ( I < LTemplate && J < LSource ) {
    if ( Template[ I ] == CharPercent ) {
      while ( I < LTemplate && ( Template[ I ] == CharPercent || Template[ I ] == CharUnderline ) ) {
        ++I;
      }
      if ( I >= LTemplate ) {
        Result = true;
      } else {
        while ( J < LSource ) {
          while ( Source[ J ] != Template[ I ] && J <= LSource ) {
            ++J;
          }
          if ( J >= LSource ) {
            break;
          }
          K = 0;
          while ( ( Source[ J + K ] == Template[ I + K ] ) &&
                  ( J + K < LSource && I + K < LTemplate ) &&
                  ( !( Template[ I + K ] == CharPercent || Template[ I + K ] == CharUnderline ) )
                ) {
            ++K;
          }
          if ( ( Template[ I + K ] == CharPercent || Template[ I + K ] == CharUnderline ) || ( I + K >= LTemplate ) ) {
            I = I + K - 1;
            J = J + K - 1;
            break;
          }
          J = J + K;
        }
      }
      if ( J >= LSource ) {
        break;
      }
    } else if ( Template[ I ] != CharUnderline ) {
      if ( Source[ J ] != Template[ I ] ) {
        break;
      }
    }
    ++I;
    ++J;
    if ( J >= LSource ) {
      K = 0;
      while ( Template[ I + K ] == CharPercent && I + K < LTemplate ) {
        ++K;
      }
      if ( I + K >= LTemplate ) {
        Result = true;
      }
    }
  }
  return Result;
}

QStorageMainWindow::QStorageMainWindow()
  : inherited()
{
}

QStorageMainWindow::~QStorageMainWindow()
{
}

void QStorageMainWindow::closeEvent( QCloseEvent *event )
{
  if ( m_Storage ) {
    m_Storage->SaveObject( this, m_StorageKind );
  }

  inherited::closeEvent( event );
}
