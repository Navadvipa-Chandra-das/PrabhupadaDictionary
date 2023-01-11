#include <QPrabhupadaStorage.h>
#include <PrabhupadaUtil.h>

QPrabhupadaStorage::QPrabhupadaStorage()
  : inherited()
{
}

QPrabhupadaStorage::~QPrabhupadaStorage()
{
}

void QPrabhupadaStorage::setDatabase( QSqlDatabase *Value )
{
  if ( m_Database != Value ) {
    m_Database = Value;
  }
}

bool QPrabhupadaStorage::BeginLoad( QObject *O )
{
  m_FileName = KeyStorage( O );
  m_File     = new QFile( m_FileName );
  m_Stream   = new QDataStream( m_File );
  return m_File->open( QIODevice::ReadOnly );
}

void QPrabhupadaStorage::EndLoad()
{
  m_File->close();
  delete m_Stream;
  delete m_File;
  m_Stream = nullptr;
  m_File   = nullptr;
}

void QPrabhupadaStorage::BeginSave( QObject *O )
{
  m_FileName = KeyStorage( O );
  m_SaveFile = new QSaveFile( m_FileName );
  m_Stream   = new QDataStream( m_SaveFile );
  m_SaveFile->open( QIODevice::WriteOnly );
}

void QPrabhupadaStorage::EndSave()
{
  m_SaveFile->commit();
  delete m_Stream;
  delete m_SaveFile;
}

void QPrabhupadaStorage::LoadObject( QObject *O )
{
  if ( m_Enabled ) {
    if ( BeginLoad( O ) )
      O->LoadFromStream( *m_Stream );
    EndLoad();
  }
}
void QPrabhupadaStorage::SaveObject( QObject *O )
{
  if ( m_Enabled ) {
    BeginSave( O );
    O->SaveToStream( *m_Stream );
    EndSave();
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
    }
  }
}

void QPrabhupadaStorage::LoadFromStream( QComboBox *CB, QDataStream &ST )
{
  QStringList SL;
  ST >> SL;
  CB->addItems( SL );
  int I;
  ST >> I;
  CB->setCurrentIndex( I );
}

void QPrabhupadaStorage::SaveToStream( QComboBox *CB, QDataStream &ST )
{
  PrepareComboBox( CB, 10 );
  QStringList SL;
  int L = CB->count();
  for ( int i = 0; i < L; ++i ) {
    SL << CB->itemText( i );
  }
  ST << SL;
  ST << CB->currentIndex();
}

QPrabhupadaDialog::QPrabhupadaDialog()
  : inherited()
{
}

QPrabhupadaDialog::~QPrabhupadaDialog()
{
  if ( m_PrabhupadaStorage )
    m_PrabhupadaStorage->SaveObject( this );
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
