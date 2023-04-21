#ifndef QPrabhupadaDictionary_H
#define QPrabhupadaDictionary_H

#include <QtCore>
#include <QtGui>
#include <QtSql>
#include <vector>
#include <map>
#include <set>
#include <QPrabhupadaStorage.h>

enum class QOrderBy : qint8
{
  SanskritVozrastanie
, SanskritUbyvanie
, TranslateVozrastanie
, TranslateUbyvanie
};

template < class TValueType >
class QPrabhupadaValue : public QObject
{
  CS_OBJECT( QPrabhupadaValue )
  private:
    using inherited = QObject;
    TValueType m_Value;
    bool m_NeedMainWork = true;
    int m_Stop = 0;
  public:
    QPrabhupadaValue() = delete;
    QPrabhupadaValue( TValueType Value )
      : inherited()
      , m_Value( Value ) {};
    ~QPrabhupadaValue() {};

    CS_SIGNAL_1( Public, void SignalValueChanged( TValueType Value ) )
    CS_SIGNAL_2( SignalValueChanged, Value )

    inline TValueType Value() const { return m_Value; };
    void SetValue( TValueType Value )
    {
      if ( Stop() == 0 && m_Value != Value ) {
        m_Value = Value;
        m_NeedMainWork = true;
        emit SignalValueChanged( m_Value );
      }
    };
    inline void IncStop() { ++m_Stop; };
    inline void DecStop() { --m_Stop; };
    inline int Stop() { return m_Stop; };
    inline int NeedMainWork() { return m_NeedMainWork; };
    inline void SetNeedMainWork( bool Value ) { m_NeedMainWork = Value; };

    void LoadFromStream( QDataStream &ST ) override
    {
      inherited::LoadFromStream( ST );
      TValueType N;
      ST >> N;
      SetValue( N );
    };
    void SaveToStream( QDataStream &ST ) override
    {
      inherited::SaveToStream( ST );
      ST << m_Value;
    };
    inline void EmitValueChanged( bool ANeedResetMainWork = false )
    {
      if ( ANeedResetMainWork ) {
        m_NeedMainWork = true;
      }
      emit SignalValueChanged( m_Value );
      m_NeedMainWork = false;
    };
  protected:
};

using QFontSize        = QPrabhupadaValue< int >;
using QPrabhupadaOrder = QPrabhupadaValue< QOrderBy >;
using QPrabhupadaBool  = QPrabhupadaValue< bool >;

class QStringMap : public std::map< QString, QString >
{
  private:
    using inherited = std::map< QString, QString >;
  public:
    QStringMap();
    ~QStringMap();
};

class QStringSet : public std::set< QString >
{
  private:
    using inherited = std::set< QString >;
  public:
    QStringSet();
    ~QStringSet();
};

class QFilterSlovar
{
  private:
    QString m_Sanskrit;
    QString m_Translate;
    QString m_SanskritWithoutDiakritik;
    QString m_TranslateWithoutDiakritik;
  public:
    QFilterSlovar();
    QFilterSlovar( const QFilterSlovar& A );
    QFilterSlovar( QFilterSlovar&& A );
    QFilterSlovar( const QString &ASanskrit
                 , const QString &ATranslate );
    ~QFilterSlovar();

    inline QString Sanskrit()  const { return m_Sanskrit; };
    inline QString Translate() const { return m_Translate; };
    void SetSanskrit( const QString &Value );
    void SetTranslate( const QString &Value );
    inline QString SanskritWithoutDiakritik()  const { return m_SanskritWithoutDiakritik; };
    inline QString TranslateWithoutDiakritik() const { return m_TranslateWithoutDiakritik; };
    void SetSanskritWithoutDiakritik( const QString &Value );
    void SetTranslateWithoutDiakritik( const QString &Value );

    void LoadFromStream( QDataStream &ST );
    void SaveToStream( QDataStream &ST );

    QFilterSlovar& operator = ( const QFilterSlovar& a );
    bool operator == ( const QFilterSlovar& F )
    {
      return ( m_Sanskrit == F.m_Sanskrit ) && ( m_Translate == F.m_Translate );
    }
    bool operator != ( const QFilterSlovar& F )
    {
      return ( ( m_Sanskrit != F.m_Sanskrit ) || ( m_Translate != F.m_Translate ) );
    }
    bool GetIsEmpty() const
    {
      return m_SanskritWithoutDiakritik.empty() && m_TranslateWithoutDiakritik.empty();
    }
    void Clear()
    {
      m_Sanskrit  = "";
      m_Translate = "";
      m_SanskritWithoutDiakritik  = "";
      m_TranslateWithoutDiakritik = "";
    }
};

inline QDataStream& operator << ( QDataStream &ST, const QFilterSlovar &FilterSlovar )
{
  return ST << FilterSlovar.Sanskrit() << FilterSlovar.Translate();
}

inline QDataStream& operator >> ( QDataStream &ST, QFilterSlovar &FilterSlovar )
{
  QString S;
  ST >> S;
  FilterSlovar.SetSanskrit( S );
  ST >> S;
  FilterSlovar.SetTranslate( S );
  return ST;
}

using QPrabhupadaFilterSlovar = QPrabhupadaValue< QFilterSlovar >;

class QPrabhupadaBukva
{
  private:
    QChar32 m_Bukva;
    int m_Ves;
  public:
    QPrabhupadaBukva();
    ~QPrabhupadaBukva();
    inline QChar32 Bukva() { return m_Bukva; };
    inline void SetBukva( QChar32 Value ) { m_Bukva = Value; };
    inline int Ves() { return m_Ves; };
    inline void SetVes( int Value ) { m_Ves = Value; };
};

class QPrabhupadaBukvary : public std::map< QChar32, QPrabhupadaBukva >
{
  private:
    using inherited = std::map< QChar32, QPrabhupadaBukva >;
  public:
    QPrabhupadaBukvary();
    ~QPrabhupadaBukvary();
};

inline QDataStream& operator << ( QDataStream &ST, const QOrderBy &OrderBy )
{
  return ST << (qint8)OrderBy;
}

inline QDataStream& operator >> ( QDataStream &ST, QOrderBy &OrderBy )
{
  return ST >> (qint8&)OrderBy;
}

class QSanskritTranslate
{
  public:
    int m_ID;
    QString m_Sanskrit;
    QString m_Translate;
    QString m_SanskritWithoutDiakritik;
    QString m_TranslateWithoutDiakritik;
    int m_SearchIndex;
    QSanskritTranslate();
    ~QSanskritTranslate();
};

class QPrabhupadaSlovarVector : public std::vector< QSanskritTranslate* >
{
  private:
    using inherited = std::vector< QSanskritTranslate* >;
  public:
    QPrabhupadaSlovarVector();
    ~QPrabhupadaSlovarVector();
    int m_SearchCount = 0;
    void Clear();
};

class QPrabhupadaZakladka
{
  public:
    QPrabhupadaZakladka();
    QPrabhupadaZakladka( int ARowNum
                       , QFilterSlovar AFilterSlovar );
    ~QPrabhupadaZakladka();

    int m_RowNum;
    QFilterSlovar m_FilterSlovar;

    void LoadFromStream( QDataStream &ST );
    void SaveToStream( QDataStream &ST );
};

class QPrabhupadaZakladkaMap : public std::map< unsigned short, QPrabhupadaZakladka >
{
  private:
    using inherited = std::map< unsigned short, QPrabhupadaZakladka >;
  public:
    QPrabhupadaZakladkaMap();
    ~QPrabhupadaZakladkaMap();
    void LoadFromStream( QDataStream &ST );
    void SaveToStream( QDataStream &ST );
};

class QYazykInfo
{
  public:
    QYazykInfo();
    QYazykInfo( const QYazykInfo &A );
    ~QYazykInfo();

    int m_ID;
    QString m_Yazyk;
    QString m_YazykSlovo;
    int m_CurrentRow = 0;
    QFilterSlovar m_FilterSlovar;
    QPrabhupadaZakladkaMap m_PrabhupadaZakladkaMap;
};

class QYazykVector : public std::vector< QYazykInfo >, public QObject
{
  CS_OBJECT( QYazykVector )
  private:
    using inherited_v = std::vector< QYazykInfo >;
    using inherited_o = QObject;
  public:
    QYazykVector();
    ~QYazykVector();
    bool m_LoadSuccess = false;
    int FindYazyk( const QString &S );
    void LoadFromStream( QDataStream &ST ) override;
    void SaveToStream( QDataStream &ST ) override;
};

class QLanguageIndex : public QPrabhupadaValue< int >
{
  private:
    using inherited = QPrabhupadaValue< int >;
  public:
    QLanguageIndex() = delete;
    QLanguageIndex( int Value
                  , QYazykVector &AYazykVector );
    ~QLanguageIndex();
    static const int RussianIndex = 4;
    QYazykVector& m_YazykVector;
    void PrepareComboBox( QComboBox *CB );
    void ComboBoxAddItem( QComboBox *CB, const QString &S );
    inline QYazykInfo& YazykInfo() { return m_YazykVector[ Value() ]; };
  protected:
};

class QPrabhupadaDictionary : public QAbstractTableModel
{
  CS_OBJECT( QPrabhupadaDictionary )
  private:
    using inherited = QAbstractTableModel;
    QSqlDatabase *m_DB = nullptr;
    QPrabhupadaStorage* m_PrabhupadaStorage;
    bool m_FilterSlovarIsEmpty = true;
  public:
    QPrabhupadaDictionary( QObject *parent = nullptr );
    ~QPrabhupadaDictionary();
    QTranslator m_Translator;
    QYazykVector m_YazykVector;
    inline bool FilterSlovarIsEmpty() { return m_FilterSlovarIsEmpty; };
    inline QPrabhupadaStorage* PrabhupadaStorage() { return m_PrabhupadaStorage; };
    inline void SetPrabhupadaStorage( QPrabhupadaStorage* APrabhupadaStorage ) { m_PrabhupadaStorage = APrabhupadaStorage; };
    inline QSqlDatabase* DB() { return m_DB; };
    inline void SetDB( QSqlDatabase* ADB ) { m_DB = ADB; };
    QLanguageIndex m_LanguageIndex   = QLanguageIndex( QLanguageIndex::RussianIndex, m_YazykVector );
    QLanguageIndex m_LanguageUIIndex = QLanguageIndex( QLanguageIndex::RussianIndex, m_YazykVector );
    QFontSize m_FontSize = QFontSize( 14 );
    QPrabhupadaOrder m_PrabhupadaOrder = QPrabhupadaOrder( QOrderBy::SanskritVozrastanie );
    QPrabhupadaBool m_CaseSensitive = QPrabhupadaBool( false );
    QPrabhupadaFilterSlovar m_PrabhupadaFilterSlovar = QPrabhupadaFilterSlovar( QFilterSlovar( "", "" ) );
    int m_MaxID;
    QString m_Schema;
    QPrabhupadaSlovarVector m_PrabhupadaSlovarVector;

    void LanguageIndexChanged( int Value );
    void LanguageUIIndexChanged( int Value );
    void FilterSlovarChanged( QFilterSlovar Value );
    void PrepareYazykAndMaxID();
    void PreparePrabhupadaSlovarVector();

    static const QString PrabhupadaDictionaryFiles;
    static QPrabhupadaBukvary PrabhupadaBukvary;
    static void PreparePrabhupadaBukvary();
    static QString RemoveDiacritics( const QString& S );
    static bool PrabhupadaCompareLess( const QString& A, const QString& B );
    static bool PrabhupadaCompareMore( const QString& A, const QString& B );

    void LoadFromStream( QDataStream &ST ) override;
    void SaveToStream( QDataStream &ST ) override;

    int rowCount( const QModelIndex &parent = QModelIndex() ) const override;
    int columnCount( const QModelIndex &parent = QModelIndex() ) const override;
    QVariant data( const QModelIndex &index, int role = Qt::DisplayRole ) const override;
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const override;

    inline const QFilterSlovar& GetFilterSlovar() const { return m_YazykVector[ m_LanguageIndex.Value() ].m_FilterSlovar; };
    void sortByColumn( int column, Qt::SortOrder order );
    void OrderByChanged( QOrderBy Value );
    void CaseSensitiveChanged( bool Value );
    void SaveYazykVectorToFile();
  protected:
};

#endif
