#ifndef QPrabhupadaDictionary_H
#define QPrabhupadaDictionary_H

#include <QtCore>
#include <QtGui>
#include <QtSql>
#include <vector>
#include <map>
#include <set>

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
    bool m_IsEmpty = true;
    bool m_IsReset = true;
  public:
    QFilterSlovar();
    QFilterSlovar( const QFilterSlovar &A );
    QFilterSlovar( const QString &ASanskrit
                 , const QString &APerevod );
    ~QFilterSlovar();
    QFilterSlovar& operator = ( const QFilterSlovar & a );

    void LoadFromStream( QDataStream &ST );
    void SaveToStream( QDataStream &ST );

    inline QString Sanskrit() { return m_Sanskrit; };
    inline QString Translate() { return m_Translate; };
    void SetSanskrit( const QString &Value );
    void SetTranslate( const QString &Value );
    inline QString SanskritWithoutDiakritik() { return m_SanskritWithoutDiakritik; };
    inline QString TranslateWithoutDiakritik() { return m_TranslateWithoutDiakritik; };
    void SetSanskritWithoutDiakritik( const QString &Value );
    void SetTranslateWithoutDiakritik( const QString &Value );
    inline bool IsEmpty() { return m_IsEmpty; };
    inline void SetIsEmpty( bool Value ) { m_IsEmpty = Value; };
    inline bool IsReset() { return m_IsReset; };
    inline void SetIsReset( bool Value ) { m_IsReset = Value; };

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
      return m_Sanskrit.empty() && m_Translate.empty();
    }
    void Clear()
    {
      m_Sanskrit  = "";
      m_Translate = "";
    }
};

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

enum class QOrderBy : char
{
  SanskritVozrastanie
, SanskritUbyvanie
, PerevodVozrastanie
, PerevodUbyvanie
};

class QSanskritTranslate
{
  public:
    int m_ID;
    QString m_Sanskrit;
    QString m_Perevod;
    QString m_SanskritWithoutDiakritik;
    QString m_PerevodWithoutDiakritik;
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

class QYazykVector : public std::vector< QYazykInfo >
{
  private:
    using inherited = std::vector< QYazykInfo >;
  public:
    QYazykVector();
    ~QYazykVector();
    bool m_LoadSuccess = false;
    int FindYazyk( const QString &S );
    void LoadFromStream( QDataStream &ST );
    void SaveToStream( QDataStream &ST );
};

class QLanguageIndex : public QObject
{
  CS_OBJECT( QLanguageIndex )
  private:
    using inherited = QObject;
    int m_Index = -1;
    int m_Start = 0;
  public:
    QLanguageIndex() = delete;
    QLanguageIndex( QYazykVector &AYazykVector );
    ~QLanguageIndex();
    static const int RussianIndex = 4;
    QYazykVector &m_YazykVector;

    CS_SIGNAL_1( Public, void SignalIndexChanged( int Value ) )
    CS_SIGNAL_2( SignalIndexChanged, Value )

    inline int Index() { return m_Index; };
    void SetIndex( int Value );
    inline void IncStart() { ++m_Start; };
    inline void DecStart() { --m_Start; };
    inline int Start() { return m_Start; };

    void IndexChanged( int Value );
    void PrepareComboBox( QComboBox *CB );
    void LoadFromStream( QDataStream &ST ) override;
    void SaveToStream( QDataStream &ST ) override;
  protected:
};

class QPrabhupadaDictionary : public QObject
{
  CS_OBJECT( QPrabhupadaDictionary )
  private:
    using inherited = QObject;
    //int m_LanguageUI_Index = -1;
    //int m_LanguageUI_Start = 0;
  public:
    QPrabhupadaDictionary();
    ~QPrabhupadaDictionary();
    QSqlDatabase *m_DB = nullptr;
    inline QSqlDatabase *DB() { return m_DB; };
    QYazykVector m_YazykVector;
    QLanguageIndex m_LanguageIndex   = QLanguageIndex( m_YazykVector );
    QLanguageIndex m_LanguageUIIndex = QLanguageIndex( m_YazykVector );
    int m_MaxID;
    QString m_Schema;
    QTranslator m_Translator;

    void LanguageIndexChanged( int Value );
    void LanguageUIIndexChanged( int Value );
    //CS_SIGNAL_1( Public, void SignalLanguageUI_IndexChanged( int Value ) )
    //CS_SIGNAL_2( SignalLanguageUI_IndexChanged, Value )

    //inline int LanguageUI_Index() { return m_LanguageUI_Index; };
    //void SetLanguageUI_Index( int Value );
    //inline void IncLanguageUI_Start() { ++m_LanguageUI_Start; };
    //inline void DecLanguageUI_Start() { --m_LanguageUI_Start; };
    //inline int LanguageUI_Start() { return m_LanguageUI_Start; };
    static const QString PrabhupadaDictionaryFiles;
    static QPrabhupadaBukvary PrabhupadaBukvary;
    static void PreparePrabhupadaBukvary();
    void PrepareYazykAndMaxID();
    static QString RemoveDiacritics( const QString& S );
    static bool PrabhupadaComareLess( const QString& A, const QString& B );
    static bool PrabhupadaComareMore( const QString& A, const QString& B );
    void Language_IndexChanged( int Value );
    void LanguageUI_IndexChanged( int Value );
    void LoadFromStream( QDataStream &ST ) override;
    void SaveToStream( QDataStream &ST ) override;
  protected:
};

#endif
