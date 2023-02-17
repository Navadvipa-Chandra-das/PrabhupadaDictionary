#ifndef QPrabhupadaStorage_H
#define QPrabhupadaStorage_H

#include <QtCore>
#include <QtGui>
#include <QtSql>

enum class QPrabhupadaStorageKind : char { File, DB, ByteArray };

class QPrabhupadaStorage : public QObject
{
  CS_OBJECT( QPrabhupadaStorage )

  public:
    explicit QPrabhupadaStorage();
    ~QPrabhupadaStorage();
    void setDatabase( QSqlDatabase *Value );
    inline QSqlDatabase* Database() { return m_Database; };
    void setEnabled( bool Value );
    inline bool Enabled() { return m_Enabled; };
    static QString KeyStorage( QObject *O );
    static void LoadFromStream( QComboBox *CB, QDataStream &ST );
    static void SaveToStream( QComboBox *CB, QDataStream &ST );
    static void PrepareComboBox( QComboBox *CB, int MaxCount );
    bool LoadObject( QObject *O );
    void SaveObject( QObject *O );
    inline qint8 Version() { return m_Version; };
    inline void setVersion( qint8 Value ) { m_Version = Value; };
  private:
    using inherited = QObject;
    bool m_Enabled = true;
    QPrabhupadaStorageKind m_StorageKind = QPrabhupadaStorageKind::File;
    qint8 m_Version = 0;
    QSqlDatabase *m_Database = nullptr;
    QFile *m_File = nullptr;
    QSaveFile *m_SaveFile = nullptr;
    QDataStream *m_Stream = nullptr;
    QString m_FileName;
    bool BeginLoad( QObject *O );
    void EndLoad();
    void BeginSave( QObject *O );
    void EndSave();
};

class QPrabhupadaDialog : public QDialog
{
  CS_OBJECT( QPrabhupadaDialog )

  public:
    QPrabhupadaDialog();
    ~QPrabhupadaDialog();
    inline QPrabhupadaStorage *PrabhupadaStorage() { return m_PrabhupadaStorage; };
    inline void setPrabhupadaStorage( QPrabhupadaStorage *Value ) { m_PrabhupadaStorage = Value; };
    void done( int result ) override;
  private:
    using inherited = QDialog;
    QPrabhupadaStorage *m_PrabhupadaStorage = nullptr;
};

class QPrabhupadaMainWindow : public QMainWindow
{
  CS_OBJECT( QPrabhupadaMainWindow )

  public:
    QPrabhupadaMainWindow();
    ~QPrabhupadaMainWindow();
    inline QPrabhupadaStorage *PrabhupadaStorage() { return m_PrabhupadaStorage; };
    inline void setPrabhupadaStorage( QPrabhupadaStorage *Value ) { m_PrabhupadaStorage = Value; };
  private:
    using inherited = QMainWindow;
    QPrabhupadaStorage *m_PrabhupadaStorage = nullptr;
  protected:
    void closeEvent( QCloseEvent *event ) override;
};

#endif
