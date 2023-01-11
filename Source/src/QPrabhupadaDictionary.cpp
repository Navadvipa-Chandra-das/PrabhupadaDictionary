#include <QPrabhupadaDictionary.h>
#include <PrabhupadaUtil.h>
#include <memory>
#include <algorithm>

QPrabhupadaBukvary PrabhupadaBukvary;

QString QPrabhupadaDictionary::RemoveDiacritics( const QString& S )
{
  QString R;

  int L = S.length();
  for ( int i = 1; i <= L; ++i )
    R += PrabhupadaBukvary[ S[ i ] ].Bukva();
  return R;
}

bool QPrabhupadaDictionary::PrabhupadaComareLess( const QString& A, const QString& B )
{
  std::size_t AL = A.length()
            , BL = B.length();

  int L = std::min( AL, BL );

  int AV, BV;
  for ( int i = 1; i <= L; ++i ) {
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

bool QPrabhupadaDictionary::PrabhupadaComareMore( const QString& A, const QString& B )
{
  std::size_t AL = A.length()
            , BL = B.length();

  int L = std::min( AL, BL );

  int AV, BV;
  for ( int i = 1; i <= L; ++i ) {
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

void QPrabhupadaDictionary::LoadFromStream( QDataStream &ST )
{
  inherited::LoadFromStream( ST );
}

void QPrabhupadaDictionary::SaveToStream( QDataStream &ST )
{
  inherited::SaveToStream( ST );
}

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
  m_SanskritWithoutDiakritik  = RemoveDiacritics( m_Sanskrit );
  m_TranslateWithoutDiakritik = RemoveDiacritics( m_Translate );
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
    m_SanskritWithoutDiakritik = RemoveDiacritics( m_Sanskrit );
  }
}

void QFilterSlovar::SetTranslate( const QString &Value )
{
  if ( m_Translate != Value ) {
    m_Translate = Value;
    m_TranslateWithoutDiakritik = RemoveDiacritics( m_Translate );
  }
}

void QFilterSlovar::LoadFromStream( QDataStream &ST )
{
  bool B;
  QString S;

  ST >> S;
  SetSanskrit( S );
  ST >> S;
  SetTranslate( S );
  // нет нужды запоминать служебные свойства, так как они заполняются автоматически
  // SanskritWithoutDiakritik
  // TranslateWithoutDiakritik
  ST >> B;
  SetIsEmpty( B );
  SetIsReset( true );
}

void QFilterSlovar::SaveToStream( QDataStream &ST )
{
  ST << Sanskrit();
  ST << Translate();
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
  , m_Lang( A.m_Lang )
  , m_CurrentRow( A.m_CurrentRow )
  , m_FilterSlovar( A.m_FilterSlovar )
  , m_PrabhupadaZakladkaMap( A.m_PrabhupadaZakladkaMap )
{
}

QYazykInfo::~QYazykInfo()
{
}

QYazykVector::QYazykVector()
  : inherited()
{
}

QYazykVector::~QYazykVector()
{
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
  int N;
  ST >> N;
  m_RowNum = N;
  m_FilterSlovar.LoadFromStream( ST );
}

void QPrabhupadaZakladka::SaveToStream( QDataStream &ST )
{
  ST << m_RowNum;
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
  ST << size();
  for ( iterator I = begin(); I != end(); ++I ) {
    ST << (*I).first;
    (*I).second.SaveToStream( ST );
  }
}

int QYazykVector::FindYazyk( const QString &S )
{
  std::size_t L = size(), I = 0;
  for( ; I < L; ++I )
    if ( operator[]( I ).m_Yazyk == S )
      return I;
  return -1;
}

int QYazykVector::FindLang( const QString &S )
{
  std::size_t L = size(), I = 0;
  for( ; I < L; ++I )
    if ( operator[]( I ).m_Lang == S )
      return I;
  return -1;
}

void QYazykVector::LoadFromStream( QDataStream &ST )
{
  int N;
  for ( iterator I = begin(); I != end(); ++I ) {
    ST >> N;
    (*I).m_CurrentRow = N;
    (*I).m_FilterSlovar.LoadFromStream( ST );
    (*I).m_PrabhupadaZakladkaMap.LoadFromStream( ST );
  }
}

void QYazykVector::SaveToStream( QDataStream &ST )
{
  for ( iterator I = begin(); I != end(); ++I ) {
    ST << (*I).m_CurrentRow;
    (*I).m_FilterSlovar.SaveToStream( ST );
    (*I).m_PrabhupadaZakladkaMap.SaveToStream( ST );
  }
}
