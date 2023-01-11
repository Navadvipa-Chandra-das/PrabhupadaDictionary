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
#include <PrabhupadaLoginWindow.h>
#include <PrabhupadaUtil.h>
#include <QPrabhupadaStorage.h>

PrabhupadaLoginWindow::PrabhupadaLoginWindow()
  : inherited()
{
  m_ui->setupUi( this );

  setWindowTitle( tr( "Prabhupada Login" ) );
  setWindowIcon( QIcon( "://resources/PrabhupadaDictionary.ico" ) );

  connect( m_ui->radioButtonSQLite
         , &QAbstractButton::toggled
         , this
         , &PrabhupadaLoginWindow::SQLRadioButton );
  m_ui->radioButtonSQLite->setChecked( true );
}

PrabhupadaLoginWindow::~PrabhupadaLoginWindow()
{
  delete m_ui;
}

void PrabhupadaLoginWindow::LoadFromStream( QDataStream &ST )
{
  inherited::LoadFromStream( ST );

  QPrabhupadaStorage::LoadFromStream( m_ui->ComboBoxUserName, ST );
  QPrabhupadaStorage::LoadFromStream( m_ui->ComboBoxDatabaseName, ST );
  QPrabhupadaStorage::LoadFromStream( m_ui->ComboBoxHostName, ST );
  QPrabhupadaStorage::LoadFromStream( m_ui->ComboBoxPort, ST );
  bool B;
  ST >> B;
  if ( B )
    m_ui->radioButtonSQLite->setChecked( true );
  else
    m_ui->radioButtonPostgreSQL->setChecked( true );
}

void PrabhupadaLoginWindow::SaveToStream( QDataStream &ST )
{
  inherited::SaveToStream( ST );

  QPrabhupadaStorage::SaveToStream( m_ui->ComboBoxUserName, ST );
  QPrabhupadaStorage::SaveToStream( m_ui->ComboBoxDatabaseName, ST );
  QPrabhupadaStorage::SaveToStream( m_ui->ComboBoxHostName, ST );
  QPrabhupadaStorage::SaveToStream( m_ui->ComboBoxPort, ST );
  ST << m_ui->radioButtonSQLite->isChecked();
}

void PrabhupadaLoginWindow::changeEvent( QEvent *event )
{
  if ( event->type() == QEvent::LanguageChange ) {
    m_ui->retranslateUi( this );
  }

  inherited::changeEvent( event );
}

void PrabhupadaLoginWindow::DatabaseToWidget( QSqlDatabase *DB )
{
  m_ui->ComboBoxUserName    ->setEditText( DB->userName() );
  m_ui->ComboBoxDatabaseName->setEditText( DB->databaseName() );
  m_ui->ComboBoxHostName    ->setEditText( DB->hostName() );
  m_ui->ComboBoxPort        ->setEditText( QString::number( DB->port() ) );
}

void PrabhupadaLoginWindow::WidgetToDatabase( QSqlDatabase *DB )
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

void PrabhupadaLoginWindow::SQLRadioButton( bool checked )
{
  m_ui->ComboBoxUserName    ->setEnabled( !checked );
  m_ui->LineEditPassword    ->setEnabled( !checked );
  m_ui->ComboBoxDatabaseName->setEnabled( !checked );
  m_ui->ComboBoxHostName    ->setEnabled( !checked );
  m_ui->ComboBoxPort        ->setEnabled( !checked );

  m_DriverName = checked ? "QSQLITE" : "QPSQL";
}

bool PrabhupadaLoginWindow::Connect( QSqlDatabase *DB )
{
  WidgetToDatabase( DB );
  return DB->open();
}
