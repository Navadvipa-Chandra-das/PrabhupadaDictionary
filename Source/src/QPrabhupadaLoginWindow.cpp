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

QPrabhupadaLoginWindow::QPrabhupadaLoginWindow()
  : inherited()
{
  m_ui->setupUi( this );

  connect( m_ui->radioButtonSQLite
         , &QAbstractButton::toggled
         , this
         , &QPrabhupadaLoginWindow::SQLRadioButton );
  m_ui->radioButtonSQLite->setChecked( true );
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
}

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
  return DB->open();
}
