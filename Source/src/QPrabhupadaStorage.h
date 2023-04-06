#ifndef QPrabhupadaStorage_H
#define QPrabhupadaStorage_H

#include <QtCore>
#include <QtGui>
#include <QtSql>
#include <map>
#include <memory>

enum class QPrabhupadaStorageKind : quint8 { File, DB, ByteArray };

//using QMapMemoryStorage = std::map< QString, std::unique_ptr< QDataStream > >;

class QMapMemoryStorage : public std::map< QString, std::unique_ptr< QDataStream > >
{
  private:
    using inherited = std::map< QString, std::unique_ptr< QDataStream > >;
  public:
    QMapMemoryStorage();
    ~QMapMemoryStorage();
    void LoadFromStream( QDataStream &ST );
    void SaveToStream( QDataStream &ST );
};

class QPrabhupadaStorage : public QObject
{
  CS_OBJECT( QPrabhupadaStorage )

  public:
    QPrabhupadaStorage();
    ~QPrabhupadaStorage();
    void SetDatabase( QSqlDatabase* Value );
    inline QSqlDatabase* Database() { return m_Database; };
    inline void SetSchema( const QString& Value ) { m_Schema = Value; };
    inline QString Schema() { return m_Schema; };
    void setEnabled( bool Value );
    inline bool Enabled() { return m_Enabled; };
    static QString KeyStorage( QObject *O );

    static void LoadFromStream( QComboBox *CB, QDataStream &ST, bool LoadCurrentIndex = true );
    static void SaveToStream( QComboBox *CB, QDataStream &ST, bool SaveCurrentIndex = true );

    template< class TMap, class TKey, class TValue >
    static void LoadMap( TMap &MP, QDataStream &ST )
    {
      // 1
      std::size_t L;
      ST >> L;
      // 2
      TKey AKey;
      TValue AValue;
      for ( std::size_t I = 0; I < L; ++I ) {
        ST >> AKey;
        ST >> AValue;
        MP[ AKey ] = AValue;
      }
    }

    template< class TMap >
    static void SaveMap( TMap &MP, QDataStream &ST )
    {
      // 1
      ST << MP.size();
      // 2
      for ( typename TMap::iterator I = MP.begin(); I != MP.end(); ++I ) {
        ST << (*I).first;
        ST << (*I).second;
      }
    }

    template< class TVector, class TValue >
    static void LoadVector( TVector &VC, QDataStream &ST )
    {
      // 1
      std::size_t L;
      ST >> L;
      // 2
      TValue AValue;
      for ( std::size_t I = 0; I < L; ++I ) {
        ST >> AValue;
        VC.push_back( AValue );
      }
    }

    template< class TVector >
    static void SaveVector( TVector &VC, QDataStream &ST )
    {
      // 1
      ST << VC.size();
      // 2
      for ( typename TVector::iterator I = VC.begin(); I != VC.end(); ++I ) {
        ST << (*I);
      }
    }

    static void PrepareComboBox( QComboBox *CB, int MaxCount );

    bool LoadObject( QObject *O, QPrabhupadaStorageKind AKind = QPrabhupadaStorageKind::File );
    void SaveObject( QObject *O, QPrabhupadaStorageKind AKind = QPrabhupadaStorageKind::File );
    inline qint8 Version() { return m_Version; };
    inline void setVersion( qint8 Value ) { m_Version = Value; };
    void LoadFromStream( QDataStream &ST ) override;
    void SaveToStream( QDataStream &ST ) override;
    inline void CheckDeleteQuery()
    {
      if ( m_Query != nullptr ) {
        delete m_Query;
        m_Query = nullptr;
      }
    };
  private:
    using inherited = QObject;
    bool m_Enabled = true;
    qint8 m_Version = 0;
    QSqlDatabase* m_Database = nullptr;
    QSqlQuery* m_Query = nullptr;
    QFile *m_File = nullptr;
    QSaveFile *m_SaveFile = nullptr;
    QDataStream *m_Stream = nullptr;
    QString m_FileName;
    QString m_Schema;
    QMapMemoryStorage m_MapMemoryStorage;
    bool BeginLoad( QObject *O, QPrabhupadaStorageKind AKind );
    void EndLoad( QPrabhupadaStorageKind AKind );
    void BeginSave( QObject *O, QPrabhupadaStorageKind AKind );
    void EndSave( QPrabhupadaStorageKind AKind );
};

class QPrabhupadaDialog : public QDialog
{
  CS_OBJECT( QPrabhupadaDialog )

  public:
    QPrabhupadaDialog();
    ~QPrabhupadaDialog();
    inline QPrabhupadaStorage *PrabhupadaStorage() { return m_PrabhupadaStorage; };
    inline void SetPrabhupadaStorage( QPrabhupadaStorage *Value ) { m_PrabhupadaStorage = Value; };
    void done( int result ) override;
  private:
    using inherited = QDialog;
  protected:
    QPrabhupadaStorage *m_PrabhupadaStorage;
};

class QPrabhupadaMainWindow : public QMainWindow
{
  CS_OBJECT( QPrabhupadaMainWindow )

  public:
    QPrabhupadaMainWindow();
    ~QPrabhupadaMainWindow();
    inline QPrabhupadaStorage *PrabhupadaStorage() { return m_PrabhupadaStorage; };
    inline void SetPrabhupadaStorage( QPrabhupadaStorage *Value ) { m_PrabhupadaStorage = Value; };
  private:
    using inherited = QMainWindow;
  protected:
    QPrabhupadaStorage *m_PrabhupadaStorage;
    void closeEvent( QCloseEvent *event ) override;
};

#endif
