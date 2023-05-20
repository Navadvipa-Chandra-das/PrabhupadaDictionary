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

QFilterSlovar::QFilterSlovar( const QFilterSlovar& A )
  : m_PrabhupadaFindOptions    ( A.m_PrabhupadaFindOptions )
  , m_Sanskrit                 ( A.m_Sanskrit )
  , m_Translate                ( A.m_Translate )
  , m_SanskritWithoutDiakritik ( A.m_SanskritWithoutDiakritik )
  , m_TranslateWithoutDiakritik( A.m_TranslateWithoutDiakritik )
{
}

QFilterSlovar::QFilterSlovar( QFilterSlovar&& A )
  : m_PrabhupadaFindOptions    ( std::move( A.m_PrabhupadaFindOptions ) )
  , m_Sanskrit                 ( std::move( A.m_Sanskrit ) )
  , m_Translate                ( std::move( A.m_Translate ) )
  , m_SanskritWithoutDiakritik ( std::move( A.m_SanskritWithoutDiakritik ) )
  , m_TranslateWithoutDiakritik( std::move( A.m_TranslateWithoutDiakritik ) )
{
}

QFilterSlovar::QFilterSlovar( QPrabhupadaFindOptions APrabhupadaFindOptions
                            , const QString &ASanskrit
                            , const QString &ATranslate )
  : m_PrabhupadaFindOptions( APrabhupadaFindOptions )
  , m_Sanskrit             ( ASanskrit )
  , m_Translate            ( ATranslate )
{
  m_SanskritWithoutDiakritik  = QPrabhupadaDictionary::RemoveDiacritics( m_Sanskrit );
  m_TranslateWithoutDiakritik = QPrabhupadaDictionary::RemoveDiacritics( m_Translate );
}

QFilterSlovar::~QFilterSlovar()
{
}

QFilterSlovar& QFilterSlovar::operator = ( const QFilterSlovar& A )
{
  m_PrabhupadaFindOptions     = A.m_PrabhupadaFindOptions;
  m_Sanskrit                  = A.m_Sanskrit;
  m_Translate                 = A.m_Translate;
  m_SanskritWithoutDiakritik  = A.m_SanskritWithoutDiakritik;
  m_TranslateWithoutDiakritik = A.m_TranslateWithoutDiakritik;

  return *this;
}

QFilterSlovar& QFilterSlovar::operator = ( QFilterSlovar&& A )
{
  m_PrabhupadaFindOptions     = std::move( A.m_PrabhupadaFindOptions );
  m_Sanskrit                  = std::move( A.m_Sanskrit );
  m_Translate                 = std::move( A.m_Translate );
  m_SanskritWithoutDiakritik  = std::move( A.m_SanskritWithoutDiakritik );
  m_TranslateWithoutDiakritik = std::move( A.m_TranslateWithoutDiakritik );

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
  QString S;

  // 1
  ST >> m_PrabhupadaFindOptions;
  // 2
  ST >> S;
  SetSanskrit( S );
  // 3
  ST >> S;
  SetTranslate( S );
  // нет нужды запоминать служебные поля, так как они заполняются автоматически через методы SetSanskrit() и SetTranslate()!
  // SanskritWithoutDiakritik
  // TranslateWithoutDiakritik
}

void QFilterSlovar::SaveToStream( QDataStream &ST )
{
  // 1, 2, 3
  ST << m_PrabhupadaFindOptions << m_Sanskrit << m_Translate;
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

    ST >> YI.m_CurrentRow;
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
  Clear();
}

void QPrabhupadaSlovarVector::Clear()
{
  for ( QPrabhupadaSlovarVector::iterator I = begin(); I != end(); ++I )
    delete *I;
  clear();
  m_SearchCount = 0;
}

QSanskritTranslate::QSanskritTranslate()
{
}

QSanskritTranslate::~QSanskritTranslate()
{
}

QPrabhupadaFindOptions::QPrabhupadaFindOptions()
{
}

QPrabhupadaFindOptions::QPrabhupadaFindOptions( bool ACaseSensitive
                                              , bool ARegularExpression
                                              , bool AAutoPercentBegin
                                              , bool AAutoPercentEnd )
  : m_CaseSensitive    ( ACaseSensitive )
  , m_RegularExpression( ARegularExpression )
  , m_AutoPercentBegin ( AAutoPercentBegin )
  , m_AutoPercentEnd   ( AAutoPercentEnd )
{
}

QPrabhupadaFindOptions::QPrabhupadaFindOptions( const QPrabhupadaFindOptions& A )
  : m_CaseSensitive    ( A.m_CaseSensitive )
  , m_RegularExpression( A.m_RegularExpression )
  , m_AutoPercentBegin ( A.m_AutoPercentBegin )
  , m_AutoPercentEnd   ( A.m_AutoPercentEnd )
{
}

QPrabhupadaFindOptions::QPrabhupadaFindOptions( QPrabhupadaFindOptions&& A )
  : m_CaseSensitive    ( std::move( A.m_CaseSensitive ) )
  , m_RegularExpression( std::move( A.m_RegularExpression ) )
  , m_AutoPercentBegin ( std::move( A.m_AutoPercentBegin ) )
  , m_AutoPercentEnd   ( std::move( A.m_AutoPercentEnd ) )
{
}

QPrabhupadaFindOptions::~QPrabhupadaFindOptions()
{
}

QPrabhupadaFindOptions& QPrabhupadaFindOptions::operator = ( const QPrabhupadaFindOptions& A )
{
  m_CaseSensitive     = A.m_CaseSensitive;
  m_RegularExpression = A.m_RegularExpression;
  m_AutoPercentBegin  = A.m_AutoPercentBegin;
  m_AutoPercentEnd    = A.m_AutoPercentEnd;

  return *this;
}

QPrabhupadaFindOptions& QPrabhupadaFindOptions::operator = ( QPrabhupadaFindOptions&& A )
{
  m_CaseSensitive     = std::move( A.m_CaseSensitive );
  m_RegularExpression = std::move( A.m_RegularExpression );
  m_AutoPercentBegin  = std::move( A.m_AutoPercentBegin );
  m_AutoPercentEnd    = std::move( A.m_AutoPercentEnd );

  return *this;
}

void QPrabhupadaFindOptions::LoadFromStream( QDataStream &ST )
{
  // 1, 2, 3, 4
  ST >> m_CaseSensitive >> m_RegularExpression >> m_AutoPercentBegin >> m_AutoPercentEnd;

}

void QPrabhupadaFindOptions::SaveToStream( QDataStream &ST )
{
  // 1, 2, 3, 4
  ST << m_CaseSensitive << m_RegularExpression << m_AutoPercentBegin << m_AutoPercentEnd;
}

QPrabhupadaZakladka::QPrabhupadaZakladka()
{
}

QPrabhupadaZakladka::QPrabhupadaZakladka( int ARowNum
                                        , int AColumnNum
                                        , QFilterSlovar AFilterSlovar )
  : m_RowNum( ARowNum )
  , m_ColumnNum( AColumnNum )
  , m_FilterSlovar( AFilterSlovar )
{
}

QPrabhupadaZakladka::QPrabhupadaZakladka( const QPrabhupadaZakladka& A )
  : m_RowNum      ( A.m_RowNum )
  , m_ColumnNum   ( A.m_ColumnNum )
  , m_FilterSlovar( A.m_FilterSlovar )
{
}

QPrabhupadaZakladka::QPrabhupadaZakladka( QPrabhupadaZakladka&& A )
  : m_RowNum      ( std::move( A.m_RowNum ) )
  , m_ColumnNum   ( std::move( A.m_ColumnNum ) )
  , m_FilterSlovar( std::move( A.m_FilterSlovar ) )
{
}

QPrabhupadaZakladka::~QPrabhupadaZakladka()
{
}

QPrabhupadaZakladka& QPrabhupadaZakladka::operator = ( const QPrabhupadaZakladka& A )
{
  m_RowNum       = A.m_RowNum;
  m_ColumnNum    = A.m_ColumnNum;
  m_FilterSlovar = A.m_FilterSlovar;

  return *this;
}

QPrabhupadaZakladka& QPrabhupadaZakladka::operator = ( QPrabhupadaZakladka&& A )
{
  m_RowNum       = std::move( A.m_RowNum );
  m_ColumnNum    = std::move( A.m_ColumnNum );
  m_FilterSlovar = std::move( A.m_FilterSlovar );

  return *this;
}

void QPrabhupadaZakladka::LoadFromStream( QDataStream &ST )
{
  // 1
  ST >> m_RowNum;
  // 2
  ST >> m_ColumnNum;
  // 3
  m_FilterSlovar.LoadFromStream( ST );
}

void QPrabhupadaZakladka::SaveToStream( QDataStream &ST )
{
  // 1
  ST << m_RowNum;
  // 2
  ST << m_ColumnNum;
  // 3
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
    ++m_Stop;
    CB->clear();
    for ( QYazykVector::iterator i = m_YazykVector.begin(); i != m_YazykVector.end(); ++i ) {
      CB->addItem( ( *i ).m_YazykSlovo );
    }
    CB->setCurrentIndex( m_Value );
    QObject::connect( CB
                    , ( void ( QComboBox::* )( int ) )( QComboBox::currentIndexChanged )
                    , this
                    , &SetValue );
    --m_Stop;
  }
}

void QLanguageIndex::ComboBoxAddItem( QComboBox *CB, const QString &S )
{
  if ( CB ) {
    ++m_Stop;
    CB->addItem( S );
    --m_Stop;
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
                  , &OrderByChanged );
  QObject::connect( &m_CaseSensitive
                  , &QPrabhupadaBool::SignalValueChanged
                  , this
                  , &CaseSensitiveChanged );
  QObject::connect( &m_RegularExpression
                  , &QPrabhupadaBool::SignalValueChanged
                  , this
                  , &RegularExpressionChanged );
  QObject::connect( &m_AutoPercentBegin
                  , &QPrabhupadaBool::SignalValueChanged
                  , this
                  , &AutoPercentBeginChanged );
  QObject::connect( &m_AutoPercentEnd
                  , &QPrabhupadaBool::SignalValueChanged
                  , this
                  , &AutoPercentEndChanged );
  QObject::connect( &m_PrabhupadaFilterSlovar
                  , &QPrabhupadaFilterSlovar::SignalValueChanged
                  , this
                  , &FilterSlovarChanged );
}

QPrabhupadaDictionary::~QPrabhupadaDictionary()
{
}

QString QPrabhupadaDictionary::RemoveDiacritics( const QString& S )
{
  QString R;

  int L = S.length();
  QPrabhupadaBukvary::iterator F;
  for ( int i = 0; i < L; ++i ) {
    F = PrabhupadaBukvary.find( S[ i ] );
    if ( F != PrabhupadaBukvary.end() ) {
      R += (*F).second.m_Bukva;
    } else {
      R += S[ i ];
    }
  }
  return R;
}

bool QPrabhupadaDictionary::PrabhupadaCompareLess( const QString& A, const QString& B )
{
  std::size_t AL = A.length()
            , BL = B.length();

  int L = std::min( AL, BL );

  int AV, BV;
  for ( int i = 0; i < L; ++i ) {
    AV = PrabhupadaBukvary[ A[ i ] ].m_Ves;
    BV = PrabhupadaBukvary[ B[ i ] ].m_Ves;
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
    AV = PrabhupadaBukvary[ A[ i ] ].m_Ves;
    BV = PrabhupadaBukvary[ B[ i ] ].m_Ves;
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

    B.m_Bukva = S[ 2 ];
    B.m_Ves = ++V;

    PrabhupadaBukvary[ S[ 0 ] ] = B;
  }
}

void QPrabhupadaDictionary::PrepareYazykAndMaxID()
{
  if ( m_DB != nullptr && m_DB->isOpen () ) {
    QSqlQuery qu( *m_DB );

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
  if ( m_DB != nullptr && m_DB->isOpen () ) {
    QSqlQuery qu( *m_DB );

    qu.prepare( QString( "select\n"
                         "  a.\"ID\"\n"
                         ", a.\"IZNACHALYNO\"\n"
                         ", a.\"PEREVOD\"\n"
                         "from\n"
                         "    %1\"SANSKRIT\" a\n"
                         "where\n"
                         "    a.\"YAZYK\" = :YAZYK;" ).formatArg( m_Schema ) );
    qu.bindValue( ":YAZYK", m_YazykVector[ m_LanguageIndex.m_Value ].m_Yazyk );
    qu.exec();
    QSanskritTranslate *ST;

    m_PrabhupadaSlovarVector.Clear();

    while ( qu.next() ) {
      ST = new QSanskritTranslate();

      ST->m_ID                        = qu.value( 0 ).toInt();
      ST->m_Sanskrit                  = qu.value( 1 ).toString();
      ST->m_Translate                 = qu.value( 2 ).toString();
      ST->m_SanskritWithoutDiakritik  = QPrabhupadaDictionary::RemoveDiacritics( ST->m_Sanskrit );
      ST->m_TranslateWithoutDiakritik = QPrabhupadaDictionary::RemoveDiacritics( ST->m_Translate  );
      m_PrabhupadaSlovarVector.push_back( ST );
    }
    m_PrabhupadaOrder.EmitValueChanged( true );
    emit modelReset();
    m_LanguageIndex.m_NeedMainWork = false;
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
}

void QPrabhupadaDictionary::LanguageIndexChanged( int Value )
{
  if ( m_LanguageIndex.m_NeedMainWork ) {
    int L = m_YazykVector.size();
    if ( Value > -1 && L > Value ) {
      PreparePrabhupadaSlovarVector();
      m_PrabhupadaFilterSlovar.SetValue( m_YazykVector[ m_LanguageIndex.m_Value ].m_FilterSlovar );
    }
  }
}

void QPrabhupadaDictionary::LanguageUIIndexChanged( int Value )
{
  if ( m_LanguageUIIndex.m_NeedMainWork ) {
    int L = m_YazykVector.size();
    if ( Value > -1 && L > Value ) {
      QString AFileTranslate = "PrabhupadaDictionary_" + m_YazykVector[ Value ].m_Yazyk + ".qm";
      if ( m_Translator.load( AFileTranslate, PrabhupadaDictionaryFiles ) ) {
        qApp->installTranslator( &m_Translator );
        QApplication::setApplicationDisplayName( tr( "B Шрилы Прабхупады!" ) );
        m_LanguageUIIndex.m_NeedMainWork = false;
      } else {
        PrabhupadaMessage( tr( "Не удалось загрузить файл перевода " ) + AFileTranslate );
      }
    }
  }
}

void QPrabhupadaDictionary::FilterSlovarChanged( QFilterSlovar Value )
{
  if ( m_PrabhupadaFilterSlovar.m_NeedMainWork ) {

    m_FilterSlovarIsEmpty = Value.GetIsEmpty();
    m_PrabhupadaSlovarVector.m_SearchCount = 0;

    if ( !m_FilterSlovarIsEmpty ) {
      int ActualIndex = -1;
      bool CheckSanskrit  = !Value.m_SanskritWithoutDiakritik.empty(),
           CheckTranslate = !Value.m_TranslateWithoutDiakritik.empty();

      bool NeedSanskrit
         , NeedTranslate;

      int L = m_PrabhupadaSlovarVector.size();
      qint64 T_Start = QDateTime::currentMSecsSinceEpoch();

      if ( Value.m_PrabhupadaFindOptions.m_RegularExpression ) {
        QPatternOptionFlags RO = QPatternOption::MultilineOption;
        if ( !Value.m_PrabhupadaFindOptions.m_CaseSensitive ) {
          RO = RO | QPatternOption::CaseInsensitiveOption;
        }
        QRegularExpression reSanskrit ( Value.m_SanskritWithoutDiakritik,  RO )
                        , reTranslate( Value.m_TranslateWithoutDiakritik, RO );
        for ( int I = 0; I < L; ++I ) {
          NeedTranslate = false;

          NeedSanskrit = CheckSanskrit ? reSanskrit.match( m_PrabhupadaSlovarVector[ I ]->m_SanskritWithoutDiakritik ).hasMatch() : true;
          if ( NeedSanskrit ) {
            NeedTranslate  = CheckTranslate ? reTranslate.match( m_PrabhupadaSlovarVector[ I ]->m_TranslateWithoutDiakritik ).hasMatch() : true;
          }
          if ( NeedTranslate ) {
            m_PrabhupadaSlovarVector[ ++ActualIndex ]->m_SearchIndex = I;
          }
        }
      } else {
        QString ASanskritWithoutDiakritik  = Value.m_SanskritWithoutDiakritik
              , ATranslateWithoutDiakritik = Value.m_TranslateWithoutDiakritik;

        if ( Value.m_PrabhupadaFindOptions.m_AutoPercentBegin ) {
          ASanskritWithoutDiakritik  = QPrabhupadaStorage::CharPercent + ASanskritWithoutDiakritik;
          ATranslateWithoutDiakritik = QPrabhupadaStorage::CharPercent + ATranslateWithoutDiakritik;
        }

        if ( Value.m_PrabhupadaFindOptions.m_AutoPercentEnd ) {
          ASanskritWithoutDiakritik  = ASanskritWithoutDiakritik  + QPrabhupadaStorage::CharPercent;
          ATranslateWithoutDiakritik = ATranslateWithoutDiakritik + QPrabhupadaStorage::CharPercent;
        }

        for ( int I = 0; I < L; ++I ) {
          NeedTranslate = false;

          if ( CheckSanskrit ) {
            NeedSanskrit =
              QPrabhupadaStorage::Like( ASanskritWithoutDiakritik.cend()
                                      , m_PrabhupadaSlovarVector[ I ]->m_SanskritWithoutDiakritik.cend()
                                      , ASanskritWithoutDiakritik.cbegin()
                                      , m_PrabhupadaSlovarVector[ I ]->m_SanskritWithoutDiakritik.cbegin() );
          } else {
            NeedSanskrit = true;
          }
          if ( NeedSanskrit ) {
            if ( CheckTranslate ) {
              NeedTranslate =
                QPrabhupadaStorage::Like( ATranslateWithoutDiakritik.end()
                                        , m_PrabhupadaSlovarVector[ I ]->m_TranslateWithoutDiakritik.end()
                                        , ATranslateWithoutDiakritik.begin()
                                        , m_PrabhupadaSlovarVector[ I ]->m_TranslateWithoutDiakritik.begin() );
            } else {
              NeedTranslate = true;
            }
          }
          if ( NeedTranslate ) {
            m_PrabhupadaSlovarVector[ ++ActualIndex ]->m_SearchIndex = I;
          }
        }
      }

      qint64 T_Finish = QDateTime::currentMSecsSinceEpoch();
      PrabhupadaMessage( "Цикл потратил " + QString::number( T_Finish - T_Start ) );

      m_PrabhupadaSlovarVector.m_SearchCount = ActualIndex + 1;
    } else {
      m_PrabhupadaSlovarVector.m_SearchCount = m_PrabhupadaSlovarVector.size();
    }
    m_PrabhupadaFilterSlovar.m_NeedMainWork = false;
    emit modelReset();
  }
}

int QPrabhupadaDictionary::rowCount( const QModelIndex& /*parent*/ ) const
{
  int N = m_FilterSlovarIsEmpty ? m_PrabhupadaSlovarVector.size() : m_PrabhupadaSlovarVector.m_SearchCount;
  return N;
}

int QPrabhupadaDictionary::columnCount( const QModelIndex& /*parent*/ ) const
{
  return 2;
}

QVariant QPrabhupadaDictionary::data( const QModelIndex &index, int role ) const
{
  int row = index.row();
  int col = index.column();

  switch ( role ) {
  case Qt::DisplayRole:
    if ( m_FilterSlovarIsEmpty ) {
      if ( col == 0 ) {
        return m_PrabhupadaSlovarVector[ row ]->m_Sanskrit;
      } else {
        return m_PrabhupadaSlovarVector[ row ]->m_Translate;
      }
    } else {
      if ( col == 0 )
        return m_PrabhupadaSlovarVector[ m_PrabhupadaSlovarVector[ row ]->m_SearchIndex ]->m_Sanskrit;
      else
        return m_PrabhupadaSlovarVector[ m_PrabhupadaSlovarVector[ row ]->m_SearchIndex ]->m_Translate;
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
      m_PrabhupadaOrder.SetValue( QPrabhupadaDictionaryOrderBy::SanskritVozrastanie );
    } else {
      m_PrabhupadaOrder.SetValue( QPrabhupadaDictionaryOrderBy::SanskritUbyvanie );
    }
  } else {
    if ( order == Qt::AscendingOrder ) {
      m_PrabhupadaOrder.SetValue( QPrabhupadaDictionaryOrderBy::TranslateVozrastanie );
    } else {
      m_PrabhupadaOrder.SetValue( QPrabhupadaDictionaryOrderBy::TranslateUbyvanie );
    }
  }
}

void QPrabhupadaDictionary::OrderByChanged( QPrabhupadaDictionaryOrderBy Value )
{
  if ( m_PrabhupadaOrder.m_NeedMainWork ) {
    switch ( Value ) {
      case QPrabhupadaDictionaryOrderBy::SanskritVozrastanie :
        std::sort( m_PrabhupadaSlovarVector.begin()
                 , m_PrabhupadaSlovarVector.end()
                 , [] ( const QSanskritTranslate *A, const QSanskritTranslate *B )
                   {
                     return A->m_Sanskrit == B->m_Sanskrit ?
                             PrabhupadaCompareLess( A->m_Translate, B->m_Translate  ) :
                             PrabhupadaCompareLess( A->m_Sanskrit,  B->m_Sanskrit );
                   }
                 );
        break;
      case QPrabhupadaDictionaryOrderBy::SanskritUbyvanie :
        std::sort( m_PrabhupadaSlovarVector.begin()
                 , m_PrabhupadaSlovarVector.end()
                 , [] ( const QSanskritTranslate *A, const QSanskritTranslate *B )
                   {
                     return A->m_Sanskrit == B->m_Sanskrit ?
                             PrabhupadaCompareMore( A->m_Translate, B->m_Translate  ) :
                             PrabhupadaCompareMore( A->m_Sanskrit,  B->m_Sanskrit );
                   }
                 );
        break;
      case QPrabhupadaDictionaryOrderBy::TranslateVozrastanie :
        std::sort( m_PrabhupadaSlovarVector.begin()
                 , m_PrabhupadaSlovarVector.end()
                 , [] ( const QSanskritTranslate *A, const QSanskritTranslate *B )
                   {
                     return A->m_Translate == B->m_Translate ?
                             PrabhupadaCompareLess( A->m_Sanskrit,  B->m_Sanskrit ) :
                             PrabhupadaCompareLess( A->m_Translate, B->m_Translate  );
                   }
                 );
        break;
      case QPrabhupadaDictionaryOrderBy::TranslateUbyvanie :
        std::sort( m_PrabhupadaSlovarVector.begin()
                 , m_PrabhupadaSlovarVector.end()
                 , [] ( const QSanskritTranslate *A, const QSanskritTranslate *B )
                   {
                     return A->m_Translate == B->m_Translate ?
                             PrabhupadaCompareMore( A->m_Sanskrit,  B->m_Sanskrit ) :
                             PrabhupadaCompareMore( A->m_Translate, B->m_Translate  );
                   }
                 );
        break;
    }
    m_PrabhupadaFilterSlovar.EmitValueChanged( true );
    // emit modelReset() вызывается при фильтрации!;
    m_PrabhupadaOrder.m_NeedMainWork = false;
  }
}

void QPrabhupadaDictionary::CaseSensitiveChanged( bool Value )
{
  if ( m_CaseSensitive.m_NeedMainWork ) {
    QYazykInfo& YI = m_YazykVector[ m_LanguageIndex.m_Value ];
    YI.m_FilterSlovar.m_PrabhupadaFindOptions.m_CaseSensitive = Value;
    m_CaseSensitive.m_NeedMainWork = false;
  }
}

void QPrabhupadaDictionary::RegularExpressionChanged( bool Value )
{
  if ( m_RegularExpression.m_NeedMainWork ) {
    QYazykInfo& YI = m_YazykVector[ m_LanguageIndex.m_Value ];
    YI.m_FilterSlovar.m_PrabhupadaFindOptions.m_RegularExpression = Value;
    m_RegularExpression.m_NeedMainWork = false;
  }
}

void QPrabhupadaDictionary::AutoPercentBeginChanged( bool Value )
{
  if ( m_AutoPercentBegin.m_NeedMainWork ) {
    QYazykInfo& YI = m_YazykVector[ m_LanguageIndex.m_Value ];
    YI.m_FilterSlovar.m_PrabhupadaFindOptions.m_AutoPercentBegin = Value;
    m_AutoPercentBegin.m_NeedMainWork = false;
  }
}

void QPrabhupadaDictionary::AutoPercentEndChanged( bool Value )
{
  if ( m_AutoPercentEnd.m_NeedMainWork ) {
    QYazykInfo& YI = m_YazykVector[ m_LanguageIndex.m_Value ];
    YI.m_FilterSlovar.m_PrabhupadaFindOptions.m_AutoPercentEnd = Value;
    m_AutoPercentEnd.m_NeedMainWork = false;
  }
}

void QPrabhupadaDictionary::SaveYazykVectorToFile()
{
  m_PrabhupadaStorage->SaveObject( &m_YazykVector, QPrabhupadaStorageKind::File );
}
