#include <QPrabhupadaDictionary.h>
#include <PrabhupadaUtil.h>
#include <memory>
#include <algorithm>

QPrabhupadaBukvary QPrabhupadaDictionary::PrabhupadaBukvary;
const QString QPrabhupadaDictionary::PrabhupadaDictionaryFiles = QString( "./resources/PrabhupadaDictionaryFiles/" );

QStringMap::QStringMap()
  : inherited()
{
}

QStringMap::~QStringMap()
{
}

QStringSet::QStringSet()
  : inherited()
{
}

QStringSet::~QStringSet()
{
}

QFilterSlovar::QFilterSlovar()
{
}

QFilterSlovar::QFilterSlovar( const QFilterSlovar &A )
  : m_Sanskrit( A.m_Sanskrit )
  , m_Translate( A.m_Translate )
  , m_SanskritWithoutDiakritik( A.m_SanskritWithoutDiakritik )
  , m_TranslateWithoutDiakritik( A.m_TranslateWithoutDiakritik )
{
}

QFilterSlovar::QFilterSlovar( const QString &ASanskrit
                            , const QString &ATranslate )
  : m_Sanskrit( ASanskrit )
  , m_Translate( ATranslate )
{
  m_SanskritWithoutDiakritik  = QPrabhupadaDictionary::RemoveDiacritics( m_Sanskrit );
  m_TranslateWithoutDiakritik = QPrabhupadaDictionary::RemoveDiacritics( m_Translate );
}

QFilterSlovar::~QFilterSlovar()
{
}

QFilterSlovar& QFilterSlovar::operator = ( const QFilterSlovar &a )
{
  m_Sanskrit  = a.m_Sanskrit;
  m_Translate = a.m_Translate;
  // нет нужды сравнивать служебные поля m_SanskritWithoutDiakritik, m_TranslateWithoutDiakritik и другие
  return *this;
}

void QFilterSlovar::SetSanskrit( const QString &Value )
{
  if ( m_Sanskrit != Value ) {
    m_Sanskrit = Value;
    m_SanskritWithoutDiakritik = QPrabhupadaDictionary::RemoveDiacritics( m_Sanskrit );
  }
}

void QFilterSlovar::SetTranslate( const QString &Value )
{
  if ( m_Translate != Value ) {
    m_Translate = Value;
    m_TranslateWithoutDiakritik = QPrabhupadaDictionary::RemoveDiacritics( m_Translate );
  }
}

void QFilterSlovar::LoadFromStream( QDataStream &ST )
{
  bool B;
  QString S;

  // 1
  ST >> S;
  SetSanskrit( S );
  // 2
  ST >> S;
  SetTranslate( S );
  // нет нужды запоминать служебные свойства, так как они заполняются автоматически
  // SanskritWithoutDiakritik
  // TranslateWithoutDiakritik
  // 3
  ST >> B;
  SetIsEmpty( B );
  SetIsReset( true );
}

void QFilterSlovar::SaveToStream( QDataStream &ST )
{
  // 1
  ST << Sanskrit();
  // 2
  ST << Translate();
  // 3
  ST << IsEmpty();
}

QPrabhupadaBukva::QPrabhupadaBukva()
{
}

QPrabhupadaBukva::~QPrabhupadaBukva()
{
}

QPrabhupadaBukvary::QPrabhupadaBukvary()
  : inherited()
{
}

QPrabhupadaBukvary::~QPrabhupadaBukvary()
{
}

QYazykInfo::QYazykInfo()
{
}

QYazykInfo::QYazykInfo( const QYazykInfo &A )
  : m_ID( A.m_ID )
  , m_Yazyk( A.m_Yazyk )
  , m_YazykSlovo( A.m_YazykSlovo )
  , m_CurrentRow( A.m_CurrentRow )
  , m_FilterSlovar( A.m_FilterSlovar )
  , m_PrabhupadaZakladkaMap( A.m_PrabhupadaZakladkaMap )
{
}

QYazykInfo::~QYazykInfo()
{
}

QYazykVector::QYazykVector()
  : inherited_v()
  , inherited_o()
{
}

QYazykVector::~QYazykVector()
{
}

int QYazykVector::FindYazyk( const QString &S )
{
  std::size_t L = size(), I = 0;
  for( ; I < L; ++I )
    if ( operator[]( I ).m_Yazyk == S )
      return I;
  return -1;
}

void QYazykVector::LoadFromStream( QDataStream &ST )
{
  inherited_o::LoadFromStream( ST );
  // 1
  clear();
  int L;
  ST >> L;
  QYazykInfo YI;
  for ( int I = 0; I < L; ++I ) {
    ST >> YI.m_ID;
    ST >> YI.m_Yazyk;
    ST >> YI.m_YazykSlovo;

    ST >> YI.m_CurrentRow/* = N*/;
    YI.m_FilterSlovar.LoadFromStream( ST );
    YI.m_PrabhupadaZakladkaMap.LoadFromStream( ST );
    push_back( YI );
  }
  m_LoadSuccess = L > 0;
}

void QYazykVector::SaveToStream( QDataStream &ST )
{
  inherited_o::SaveToStream( ST );
  // 1
  int L = size();
  ST << L;
  for ( iterator I = begin(); I != end(); ++I ) {
    ST << (*I).m_ID;
    ST << (*I).m_Yazyk;
    ST << (*I).m_YazykSlovo;

    ST << (*I).m_CurrentRow;
    (*I).m_FilterSlovar.SaveToStream( ST );
    (*I).m_PrabhupadaZakladkaMap.SaveToStream( ST );
  }
}

QPrabhupadaSlovarVector::QPrabhupadaSlovarVector()
  : inherited()
{
}

QPrabhupadaSlovarVector::~QPrabhupadaSlovarVector()
{
  for ( QPrabhupadaSlovarVector::iterator I = begin(); I != end(); ++I )
    delete *I;
}

QSanskritTranslate::QSanskritTranslate()
{
}

QSanskritTranslate::~QSanskritTranslate()
{
}

QPrabhupadaZakladka::QPrabhupadaZakladka()
{
}

QPrabhupadaZakladka::QPrabhupadaZakladka( int ARowNum
                                        , QFilterSlovar AFilterSlovar )
  : m_RowNum( ARowNum )
  , m_FilterSlovar( AFilterSlovar )
{
}


QPrabhupadaZakladka::~QPrabhupadaZakladka()
{
}

void QPrabhupadaZakladka::LoadFromStream( QDataStream &ST )
{
  // 1
  ST >> m_RowNum;
  // 2
  m_FilterSlovar.LoadFromStream( ST );
}

void QPrabhupadaZakladka::SaveToStream( QDataStream &ST )
{
  // 1
  ST << m_RowNum;
  // 2
  m_FilterSlovar.SaveToStream( ST );
}

QPrabhupadaZakladkaMap::QPrabhupadaZakladkaMap()
  : inherited()
{
}

QPrabhupadaZakladkaMap::~QPrabhupadaZakladkaMap()
{
}

void QPrabhupadaZakladkaMap::LoadFromStream( QDataStream &ST )
{
  // 1
  QPrabhupadaZakladka PZ;
  unsigned short I;
  std::size_t L;
  ST >> L;
  clear();
  for ( std::size_t i = 0; i < L; ++i ) {
    ST >> I;
    PZ.LoadFromStream( ST );
    operator[]( I ) = PZ;
  }
}

void QPrabhupadaZakladkaMap::SaveToStream( QDataStream &ST )
{
  // 1
  ST << size();
  for ( iterator I = begin(); I != end(); ++I ) {
    ST << (*I).first;
    (*I).second.SaveToStream( ST );
  }
}

QLanguageIndex::QLanguageIndex( int Value
                              , QYazykVector &AYazykVector )
  : inherited( Value )
  , m_YazykVector( AYazykVector )
{
}

QLanguageIndex::~QLanguageIndex()
{
}

void QLanguageIndex::PrepareComboBox( QComboBox *CB )
{
  if ( CB ) {
    IncStop();
    CB->clear();
    for ( QYazykVector::iterator i = m_YazykVector.begin(); i != m_YazykVector.end(); ++i ) {
      CB->addItem( ( *i ).m_YazykSlovo );
    }
    CB->setCurrentIndex( Value() );
    QObject::connect( CB
                    , ( void ( QComboBox::* )( int ) )( QComboBox::currentIndexChanged )
                    , this
                    , &SetValue );
    DecStop();
  }
}

void QLanguageIndex::ComboBoxAddItem( QComboBox *CB, const QString &S )
{
  if ( CB ) {
    IncStop();
    CB->addItem( S );
    DecStop();
  }
}

QPrabhupadaDictionary::QPrabhupadaDictionary( QObject *parent )
  : inherited( parent )
{
  m_YazykVector    .setObjectName( "m_YazykVector" );
  m_LanguageUIIndex.setObjectName( "m_LanguageUIIndex" );

  PreparePrabhupadaBukvary();
  QObject::connect( &m_LanguageIndex
                  , &QLanguageIndex::SignalValueChanged
                  , this
                  , &LanguageIndexChanged );
  QObject::connect( &m_LanguageUIIndex
                  , &QLanguageIndex::SignalValueChanged
                  , this
                  , &LanguageUIIndexChanged );
  QObject::connect( &m_PrabhupadaOrder
                  , &QPrabhupadaOrder::SignalValueChanged
                  , this
                  , &DoOrderBy );
  QObject::connect( &m_CaseSensitive
                  , &QPrabhupadaBool::SignalValueChanged
                  , this
                  , &DoCaseSensitive );
}

QPrabhupadaDictionary::~QPrabhupadaDictionary()
{
}

QString QPrabhupadaDictionary::RemoveDiacritics( const QString& S )
{
  QString R;

  int L = S.length();
  for ( int i = 0; i < L; ++i )
    R += PrabhupadaBukvary[ S[ i ] ].Bukva();
  return R;
}

bool QPrabhupadaDictionary::PrabhupadaCompareLess( const QString& A, const QString& B )
{
  std::size_t AL = A.length()
            , BL = B.length();

  int L = std::min( AL, BL );

  int AV, BV;
  for ( int i = 0; i < L; ++i ) {
    AV = PrabhupadaBukvary[ A[ i ] ].Ves();
    BV = PrabhupadaBukvary[ B[ i ] ].Ves();
    if ( AV == BV ) {
      continue;
    } else if ( AV > BV ) {
      return false;
    } else if ( AV < BV ) {
      return true;
    }
  }

  if ( AL < BL )
    return true;

  return false;
}

bool QPrabhupadaDictionary::PrabhupadaCompareMore( const QString& A, const QString& B )
{
  std::size_t AL = A.length()
            , BL = B.length();

  int L = std::min( AL, BL );

  int AV, BV;
  for ( int i = 0; i < L; ++i ) {
    AV = PrabhupadaBukvary[ A[ i ] ].Ves();
    BV = PrabhupadaBukvary[ B[ i ] ].Ves();
    if ( AV == BV ) {
      continue;
    } else if ( AV < BV ) {
      return false;
    } else if ( AV > BV ) {
      return true;
    }
  }

  if ( AL > BL )
    return true;

  return false;
}

void QPrabhupadaDictionary::PreparePrabhupadaBukvary()
{
  QPrabhupadaBukva B;

  QFile AFile( PrabhupadaDictionaryFiles + "PrabhupadaBukvary.txt" );
  QTextStream AStream( &AFile );
  AFile.open( QIODevice::ReadOnly );

  int V = 0;
  QString S;
  while ( true ) {
    S = AStream.readLine();
    if ( S.length() < 3 ) {
      break;
    }

    B.SetBukva( S[ 2 ] );
    B.SetVes( ++V );

    PrabhupadaBukvary[ S[ 0 ] ] = B;
  }
}

void QPrabhupadaDictionary::PrepareYazykAndMaxID()
{
  if ( DB() != nullptr && DB()->isOpen () ) {
    QSqlQuery qu( *DB() );

    if ( !m_YazykVector.m_LoadSuccess ) {
      qu.exec( QString( "select\n"
                        "  a.\"ID\"\n"
                        ", a.\"YAZYK\"\n"
                        ", a.\"YAZYK_SLOVO\"\n"
                        "from\n"
                        "    %1\"YAZYK\" a\n"
                        "order by a.\"YAZYK_SLOVO\";" ).formatArg( m_Schema ) );

      QYazykInfo YI;

      while ( qu.next() ) {
        YI.m_ID         = qu.value( 0 ).toInt();
        YI.m_Yazyk      = qu.value( 1 ).toString();
        YI.m_YazykSlovo = qu.value( 2 ).toString();

        m_YazykVector.push_back( YI );
      }
      SaveYazykVectorToFile();
    }

    qu.clear();
    qu.exec( QString( "select max( a.\"ID\" ) as \"MAX_ID\" from %1\"SANSKRIT\" a;" ).formatArg( m_Schema ) );
    qu.next();

    m_MaxID = qu.value( 0 ).toInt();
  }
}

void QPrabhupadaDictionary::PreparePrabhupadaSlovarVector()
{
  if ( DB() != nullptr && DB()->isOpen () ) {
    QSqlQuery qu( *DB() );

    qu.prepare( QString( "select\n"
                         "  a.\"ID\"\n"
                         ", a.\"IZNACHALYNO\"\n"
                         ", a.\"PEREVOD\"\n"
                         "from\n"
                         "    %1\"SANSKRIT\" a\n"
                         "where\n"
                         "    a.\"YAZYK\" = :YAZYK;" ).formatArg( m_Schema ) );
    qu.bindValue( ":YAZYK", m_LanguageIndex.YazykInfo().m_Yazyk );
    qu.exec();
    QSanskritTranslate *ST;

    m_PrabhupadaSlovarVector.clear();
    while ( qu.next() ) {
      ST = new QSanskritTranslate();

      ST->m_ID                       = qu.value( 0 ).toInt();
      ST->m_Sanskrit                 = qu.value( 1 ).toString();
      ST->m_Perevod                  = qu.value( 2 ).toString();
      ST->m_SanskritWithoutDiakritik = QPrabhupadaDictionary::RemoveDiacritics( ST->m_Sanskrit );
      ST->m_PerevodWithoutDiakritik  = QPrabhupadaDictionary::RemoveDiacritics( ST->m_Perevod  );

      m_PrabhupadaSlovarVector.push_back( ST );
    }
    PrabhupadaMessage( "Загрузка словаря Шрилы Прабхупады из базы данных " + m_LanguageIndex.YazykInfo().m_Yazyk );
    m_PrabhupadaOrder.EmitValueChanged( true );
    m_CaseSensitive.EmitValueChanged( true );
    emit modelReset();
    m_LanguageIndex.SetNeedMainWork( false );
  }
}

void QPrabhupadaDictionary::LoadFromStream( QDataStream &ST )
{
  inherited::LoadFromStream( ST );
  // m_LanguageUIIndex загружается в main() из файла!
  // 1
  m_LanguageIndex.LoadFromStream( ST );
  // 2
  m_FontSize.LoadFromStream( ST );
  // 3
  m_PrabhupadaOrder.LoadFromStream( ST );
  // 4
  m_CaseSensitive.LoadFromStream( ST );
}

void QPrabhupadaDictionary::SaveToStream( QDataStream &ST )
{
  inherited::SaveToStream( ST );
  // m_LanguageUIIndex сохраняется в QPrabhupadaDictionaryWindow::closeEvent() в файл!
  // 1
  m_LanguageIndex.SaveToStream( ST );
  // 2
  m_FontSize.SaveToStream( ST );
  // 3
  m_PrabhupadaOrder.SaveToStream( ST );
  // 4
  m_CaseSensitive.SaveToStream( ST );
}

void QPrabhupadaDictionary::LanguageIndexChanged( int Value )
{
  if ( m_LanguageIndex.NeedMainWork() ) {
    int L = m_YazykVector.size();
    if ( Value > -1 && L > Value ) {
      PreparePrabhupadaSlovarVector();
    }
  }
}

void QPrabhupadaDictionary::LanguageUIIndexChanged( int Value )
{
  if ( m_LanguageUIIndex.NeedMainWork() ) {
    int L = m_YazykVector.size();
    if ( Value > -1 && L > Value ) {
      QString AFileTranslate = "PrabhupadaDictionary_" + m_YazykVector[ Value ].m_Yazyk + ".qm";
      if ( m_Translator.load( AFileTranslate, PrabhupadaDictionaryFiles ) ) {
        qApp->installTranslator( &m_Translator );
        QApplication::setApplicationDisplayName( tr( "Словарь Шрилы Прабхупады!" ) );
        m_LanguageUIIndex.SetNeedMainWork( false );
        PrabhupadaMessage( "Устанавливается язык программы " + m_YazykVector[ Value ].m_Yazyk );
      } else {
        PrabhupadaMessage( tr( "Не удалось загрузить файл перевода " ) + AFileTranslate );
      }
    }
  }
}

int QPrabhupadaDictionary::rowCount( const QModelIndex & /*parent*/) const
{
  int N = m_PrabhupadaSlovarVector.size();
  return N;
}

int QPrabhupadaDictionary::columnCount( const QModelIndex & /*parent*/ ) const
{
  return 2;
}

QVariant QPrabhupadaDictionary::data( const QModelIndex &index, int role ) const
{
  int row = index.row();
  int col = index.column();

  switch ( role ) {
  case Qt::DisplayRole:
    if ( GetFilterSlovar().IsEmpty() ) {
      if ( col == 0 ) {
        return m_PrabhupadaSlovarVector[ row ]->m_Sanskrit;
      } else {
        return m_PrabhupadaSlovarVector[ row ]->m_Perevod;
      }
    } else {
      if ( col == 0 )
        return QString( "== " ) + m_PrabhupadaSlovarVector[ m_PrabhupadaSlovarVector[ row ]->m_SearchIndex ]->m_Sanskrit;
      else
        return QString( "== " ) + m_PrabhupadaSlovarVector[ m_PrabhupadaSlovarVector[ row ]->m_SearchIndex ]->m_Perevod;
    }
  // case Qt::FontRole:
  //   if ( row % 2 == 1 ) {
  //     QFont boldFont;
  //     boldFont.setBold(true);
  //     return boldFont;
  //   }
  //   break;
  // case Qt::BackgroundRole:
  //   if ( row % 2 == 0 )
  //     return QBrush( Qt::yellow );
  //   break;
  // case Qt::TextAlignmentRole:
  //   if ( row == 1 && col == 1 )
  //     return int( Qt::AlignRight | Qt::AlignVCenter );
  //   break;
  // case Qt::CheckStateRole:
  //   if ( row == 1 && col == 0 )
  //     return Qt::Checked;
  //   break;
  }
  return QVariant();
}

QVariant QPrabhupadaDictionary::headerData( int section, Qt::Orientation orientation, int role ) const
{
  if ( role == Qt::DisplayRole && orientation == Qt::Horizontal ) {
    switch ( section ) {
      case 0:
        return QString( tr( "Санскрит" ) );
      case 1:
        return QString( tr( "Перевод" ) );
    }
  }
  return QVariant();
}

void QPrabhupadaDictionary::sortByColumn( int column, Qt::SortOrder order )
{
  if ( column == 0 ) {
    if ( order == Qt::AscendingOrder ) {
      m_PrabhupadaOrder.SetValue( QOrderBy::SanskritVozrastanie );
    } else {
      m_PrabhupadaOrder.SetValue( QOrderBy::SanskritUbyvanie );
    }
  } else {
    if ( order == Qt::AscendingOrder ) {
      m_PrabhupadaOrder.SetValue( QOrderBy::PerevodVozrastanie );
    } else {
      m_PrabhupadaOrder.SetValue( QOrderBy::PerevodUbyvanie );
    }
  }
}

void QPrabhupadaDictionary::DoOrderBy( QOrderBy Value )
{
  if ( m_PrabhupadaOrder.NeedMainWork() ) {
    switch ( Value ) {
      case QOrderBy::SanskritVozrastanie :
        std::sort( m_PrabhupadaSlovarVector.begin()
                 , m_PrabhupadaSlovarVector.end()
                 , [] ( const QSanskritTranslate *A, const QSanskritTranslate *B )
                   {
                     return A->m_Sanskrit == B->m_Sanskrit ?
                             PrabhupadaCompareLess( A->m_Perevod,  B->m_Perevod  ) :
                             PrabhupadaCompareLess( A->m_Sanskrit, B->m_Sanskrit );
                   }
                 );
        break;
      case QOrderBy::SanskritUbyvanie :
        std::sort( m_PrabhupadaSlovarVector.begin()
                 , m_PrabhupadaSlovarVector.end()
                 , [] ( const QSanskritTranslate *A, const QSanskritTranslate *B )
                   {
                     return A->m_Sanskrit == B->m_Sanskrit ?
                             PrabhupadaCompareMore( A->m_Perevod,  B->m_Perevod  ) :
                             PrabhupadaCompareMore( A->m_Sanskrit, B->m_Sanskrit );
                   }
                 );
        break;
      case QOrderBy::PerevodVozrastanie :
        std::sort( m_PrabhupadaSlovarVector.begin()
                 , m_PrabhupadaSlovarVector.end()
                 , [] ( const QSanskritTranslate *A, const QSanskritTranslate *B )
                   {
                     return A->m_Perevod == B->m_Perevod ?
                             PrabhupadaCompareLess( A->m_Sanskrit, B->m_Sanskrit ) :
                             PrabhupadaCompareLess( A->m_Perevod,  B->m_Perevod  );
                   }
                 );
        break;
      case QOrderBy::PerevodUbyvanie :
        std::sort( m_PrabhupadaSlovarVector.begin()
                 , m_PrabhupadaSlovarVector.end()
                 , [] ( const QSanskritTranslate *A, const QSanskritTranslate *B )
                   {
                     return A->m_Perevod == B->m_Perevod ?
                             PrabhupadaCompareMore( A->m_Sanskrit, B->m_Sanskrit ) :
                             PrabhupadaCompareMore( A->m_Perevod,  B->m_Perevod  );
                   }
                 );
        break;
    }
    emit modelReset();
    m_PrabhupadaOrder.SetNeedMainWork( false );
  }
}

void QPrabhupadaDictionary::DoCaseSensitive( bool Value )
{
  if ( m_CaseSensitive.NeedMainWork() ) {
    if ( m_PrabhupadaSlovarVector.size() > 0 ) {
      emit modelReset();
      m_CaseSensitive.SetNeedMainWork( false );
      PrabhupadaMessage( "DoCaseSensitive " + QString::number( Value ) );
    }
  }
}

void QPrabhupadaDictionary::SaveYazykVectorToFile()
{
  m_PrabhupadaStorage->SaveObject( &m_YazykVector, QPrabhupadaStorageKind::File );
}
