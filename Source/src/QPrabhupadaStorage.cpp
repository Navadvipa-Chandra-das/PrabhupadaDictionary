#include <QPrabhupadaStorage.h>
#include <PrabhupadaUtil.h>

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

QPrabhupadaStorage::QPrabhupadaStorage()
  : inherited()
{
}

QPrabhupadaStorage::~QPrabhupadaStorage()
{
  CheckDeleteQuery();
}

void QPrabhupadaStorage::SetDatabase( QSqlDatabase *Value )
{
  if ( m_Database != Value ) {
    m_Database = Value;
    CheckDeleteQuery();
    m_Query = new QSqlQuery( *m_Database );
  }
}

bool QPrabhupadaStorage::BeginLoad( QObject *O, QPrabhupadaStorageKind AKind )
{
  switch ( AKind ) {
    case QPrabhupadaStorageKind::File :
      m_FileName = KeyStorage( O );
      m_File     = new QFile( m_FileName );
      m_Stream   = new QDataStream( m_File );
      return m_File->open( QIODevice::ReadOnly );
    case QPrabhupadaStorageKind::DB :
      m_FileName = KeyStorage( O );
      m_Query->exec( QString( "select\n"
                              "  a.\"UserRegKey\"\n"
                              ", a.\"UserData\"\n"
                              "from\n"
                              "    %1\"UserReg\" a\n"
                              "where a.\"UserRegKey\" = :AUserRegKey;" ).formatArg( Schema() ) );
      return true;
    case QPrabhupadaStorageKind::ByteArray :
      m_FileName = KeyStorage( O );
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

void QPrabhupadaStorage::EndLoad( QPrabhupadaStorageKind AKind )
{
  switch ( AKind ) {
    case QPrabhupadaStorageKind::File :
      m_File->close();
      delete m_Stream;
      delete m_File;
      m_Stream = nullptr;
      m_File   = nullptr;
      break;
    case QPrabhupadaStorageKind::DB :
      break;
    case QPrabhupadaStorageKind::ByteArray :
      break;
  }
}

void QPrabhupadaStorage::BeginSave( QObject *O, QPrabhupadaStorageKind AKind )
{
  switch ( AKind ) {
    case QPrabhupadaStorageKind::File :
      m_FileName = KeyStorage( O );
      m_SaveFile = new QSaveFile( m_FileName );
      m_Stream   = new QDataStream( m_SaveFile );
      m_SaveFile->open( QIODevice::WriteOnly );
      break;
    case QPrabhupadaStorageKind::DB :
      break;
    case QPrabhupadaStorageKind::ByteArray :
      m_FileName = KeyStorage( O );
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

void QPrabhupadaStorage::EndSave( QPrabhupadaStorageKind AKind )
{
  switch ( AKind ) {
    case QPrabhupadaStorageKind::File :
      m_SaveFile->commit();
      delete m_Stream;
      delete m_SaveFile;
      m_Stream   = nullptr;
      m_SaveFile = nullptr;
      break;
    case QPrabhupadaStorageKind::DB :
      break;
    case QPrabhupadaStorageKind::ByteArray :
      break;
  }
}

bool QPrabhupadaStorage::LoadObject( QObject *O, QPrabhupadaStorageKind AKind )
{
  bool LoadSuccess = false;
  if ( m_Enabled ) {

    if ( BeginLoad( O, AKind ) ) {
      qint8 V;
      *m_Stream >> V;
      if ( V == Version() ) {
        O->LoadFromStream( *m_Stream );
        *m_Stream >> V;
        if ( V == Version() ) {
          LoadSuccess = true;
        }
      }
    }
    EndLoad( AKind );
  }
  return LoadSuccess;
}

void QPrabhupadaStorage::SaveObject( QObject *O, QPrabhupadaStorageKind AKind )
{
  if ( m_Enabled ) {
    BeginSave( O, AKind );
    *m_Stream << Version();
    O->SaveToStream( *m_Stream );
    *m_Stream << Version();
    EndSave( AKind );
  }
}

QString QPrabhupadaStorage::KeyStorage( QObject *O )
{
  QString R, S;
  int i = 0;
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

  return R;
}

void QPrabhupadaStorage::PrepareComboBox( QComboBox *CB, int MaxCount )
{
  if ( CB->isEditable() ) {
    QString S = CB->currentText();
    if ( !S.empty() ) {
      int I = CB->findText( S );
      if ( I != -1 )
        CB->removeItem( I );
      CB->insertItem( 0, S );
      for ( I = CB->count() - 1; I >= MaxCount; --I )
        CB->removeItem( I );
      CB->setCurrentIndex( 0 );
    }
  }
}

void QPrabhupadaStorage::LoadFromStream( QComboBox *CB, QDataStream &ST, bool LoadCurrentIndex )
{
  // 1
  QStringList SL;
  ST >> SL;
  CB->addItems( SL );
  // 2
  if ( LoadCurrentIndex ) {
    int I;
    ST >> I;
    CB->setCurrentIndex( I );
  }
}

void QPrabhupadaStorage::SaveToStream( QComboBox *CB, QDataStream &ST, bool SaveCurrentIndex )
{
  // 1
  PrepareComboBox( CB, 10 );
  QStringList SL;
  int L = CB->count();
  for ( int i = 0; i < L; ++i ) {
    SL << CB->itemText( i );
  }
  ST << SL;
  // 2
  if ( SaveCurrentIndex ) {
    ST << CB->currentIndex();
  }
}

void QPrabhupadaStorage::LoadFromStream( QDataStream &ST )
{
  inherited::LoadFromStream( ST );

  m_MapMemoryStorage.LoadFromStream( ST );
}

void QPrabhupadaStorage::SaveToStream( QDataStream &ST )
{
  inherited::SaveToStream( ST );

  m_MapMemoryStorage.SaveToStream( ST );
}

QPrabhupadaDialog::QPrabhupadaDialog()
  : inherited()
{
}

QPrabhupadaDialog::~QPrabhupadaDialog()
{
//  if ( m_PrabhupadaStorage )
//    m_PrabhupadaStorage->SaveObject( this );
}

void QPrabhupadaDialog::done( int result )
{
//  if ( m_PrabhupadaStorage && result != QDialog::Rejected )
//    m_PrabhupadaStorage->SaveObject( this );
  inherited::done( result );
}

QPrabhupadaMainWindow::QPrabhupadaMainWindow()
  : inherited()
{
}

QPrabhupadaMainWindow::~QPrabhupadaMainWindow()
{
}

void QPrabhupadaMainWindow::closeEvent( QCloseEvent *event )
{
  if ( m_PrabhupadaStorage )
    m_PrabhupadaStorage->SaveObject( this );

  inherited::closeEvent( event );
}
