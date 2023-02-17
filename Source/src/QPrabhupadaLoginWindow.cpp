/***********************************************************************
*
* Copyright (c) 2022-2022 Navadvipa Chandra dasa
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://opensource.org/licenses/BSD-2-Clause
*
***********************************************************************/

#include <PrabhupadaDictionary_build_info.h>
#include <QPrabhupadaLoginWindow.h>
#include <PrabhupadaUtil.h>
#include <QPrabhupadaStorage.h>

QPrabhupadaLoginWindow::QPrabhupadaLoginWindow( QPrabhupadaStorage *APrabhupadaStorage
                                              , QPrabhupadaDictionary *APrabhupadaDictionary )
  : inherited()
, m_PrabhupadaStorage( APrabhupadaStorage )
, m_PrabhupadaDictionary( APrabhupadaDictionary )
{
  m_ui->setupUi( this );

  QObject::connect( m_ui->radioButtonSQLite
                  , &QAbstractButton::toggled
                  , this
                  , &QPrabhupadaLoginWindow::SQLRadioButton );
  m_ui->radioButtonSQLite->setChecked( true );

  QObject::connect( m_ui->ComboBoxLanguageUI
                  , ( void ( QComboBox::* )( int ) )( QComboBox::currentIndexChanged )
                  , &m_PrabhupadaDictionary->m_LanguageUIIndex
                  , &QLanguageIndex::IndexChanged );
  QObject::connect( &m_PrabhupadaDictionary->m_LanguageUIIndex
                  , &QLanguageIndex::SignalIndexChanged
                  , this
                  , &QPrabhupadaLoginWindow::LanguageUI_IndexChanged );
}

QPrabhupadaLoginWindow::~QPrabhupadaLoginWindow()
{
  delete m_ui;
}

void QPrabhupadaLoginWindow::LoadFromStream( QDataStream &ST )
{
  inherited::LoadFromStream( ST );

  QPrabhupadaStorage::LoadFromStream( m_ui->ComboBoxUserName, ST );
  QPrabhupadaStorage::LoadFromStream( m_ui->ComboBoxDatabaseName, ST );
  QPrabhupadaStorage::LoadFromStream( m_ui->ComboBoxHostName, ST );
  QPrabhupadaStorage::LoadFromStream( m_ui->ComboBoxPort, ST );
  QPrabhupadaStorage::LoadFromStream( m_ui->ComboBoxSchema, ST );
  bool B;
  ST >> B;
  if ( B )
    m_ui->radioButtonSQLite->setChecked( true );
  else
    m_ui->radioButtonPostgreSQL->setChecked( true );
  //QPrabhupadaStorage::LoadFromStream( m_ui->ComboBoxLanguageUI, ST );
}

void QPrabhupadaLoginWindow::SaveToStream( QDataStream &ST )
{
  inherited::SaveToStream( ST );

  QPrabhupadaStorage::SaveToStream( m_ui->ComboBoxUserName, ST );
  QPrabhupadaStorage::SaveToStream( m_ui->ComboBoxDatabaseName, ST );
  QPrabhupadaStorage::SaveToStream( m_ui->ComboBoxHostName, ST );
  QPrabhupadaStorage::SaveToStream( m_ui->ComboBoxPort, ST );
  QPrabhupadaStorage::SaveToStream( m_ui->ComboBoxSchema, ST );
  ST << m_ui->radioButtonSQLite->isChecked();
  //QPrabhupadaStorage::SaveToStream( m_ui->ComboBoxLanguageUI, ST );
}

// void QPrabhupadaLoginWindow::addYazykSlovo( QString &AYazykSlovo )
// {
//   if ( m_NeedAddYazykSlovo ) {
//     m_ui->ComboBoxLanguageUI->addItem( AYazykSlovo );
//   }
// }

void QPrabhupadaLoginWindow::changeEvent( QEvent *event )
{
  if ( event->type() == QEvent::LanguageChange ) {
    m_ui->retranslateUi( this );
  }

  inherited::changeEvent( event );
}

void QPrabhupadaLoginWindow::DatabaseToWidget( QSqlDatabase *DB )
{
  m_ui->ComboBoxUserName    ->setEditText( DB->userName() );
  m_ui->ComboBoxDatabaseName->setEditText( DB->databaseName() );
  m_ui->ComboBoxHostName    ->setEditText( DB->hostName() );
  m_ui->ComboBoxPort        ->setEditText( QString::number( DB->port() ) );
}

void QPrabhupadaLoginWindow::WidgetToDatabase( QSqlDatabase *DB )
{
  DB->setUserName( m_ui->ComboBoxUserName->currentText() );
  DB->setPassword( m_ui->LineEditPassword->text() );
  if ( m_ui->radioButtonSQLite->isChecked() )
    DB->setDatabaseName( "./resources/PrabhupadaDictionaryFiles/Sanskrit.db" );
  else
    DB->setDatabaseName( m_ui->ComboBoxDatabaseName->currentText() );
  DB->setHostName( m_ui->ComboBoxHostName->currentText() );
  DB->setPort( QStringParser::toInteger< int >( m_ui->ComboBoxPort->currentText() ) );
}

void QPrabhupadaLoginWindow::SQLRadioButton( bool checked )
{
  m_ui->LabelUserName       ->setEnabled( !checked );
  m_ui->LabelPassword       ->setEnabled( !checked );
  m_ui->LabelDatabaseName   ->setEnabled( !checked );
  m_ui->LabelHostName       ->setEnabled( !checked );
  m_ui->LabelPort           ->setEnabled( !checked );
  m_ui->LabelSchema         ->setEnabled( !checked );

  m_ui->ComboBoxUserName    ->setEnabled( !checked );
  m_ui->LineEditPassword    ->setEnabled( !checked );
  m_ui->ComboBoxDatabaseName->setEnabled( !checked );
  m_ui->ComboBoxHostName    ->setEnabled( !checked );
  m_ui->ComboBoxPort        ->setEnabled( !checked );
  m_ui->ComboBoxSchema      ->setEnabled( !checked );

  if ( checked ) {
    m_DriverName = "QSQLITE";
    m_Schema = "";
  } else {
    m_DriverName = "QPSQL";
    m_Schema = m_ui->ComboBoxSchema->currentText() + ".";
  }
}

bool QPrabhupadaLoginWindow::Connect( QSqlDatabase *DB )
{
  WidgetToDatabase( DB );
  bool B = DB->open();
  // if ( B && m_ui->ComboBoxLanguageUI->count() == 1 ) {
  //   m_PrabhupadaDictionary->IncLanguageUI_Start();
  //   m_ui->ComboBoxLanguageUI->clear();
  //   m_PrabhupadaDictionary->DecLanguageUI_Start();
  //   m_NeedAddYazykSlovo = true;
  // }
  return B;
}

void QPrabhupadaLoginWindow::LanguageUI_IndexChanged( int Value )
{
  m_ui->ComboBoxLanguageUI->setCurrentIndex( Value );
}
