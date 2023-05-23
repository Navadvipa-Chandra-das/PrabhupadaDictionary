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
#include <QPrabhupadaUtil.h>
#include <QPrabhupada.h>

QPrabhupadaLoginWindow::QPrabhupadaLoginWindow( QPrabhupadaDictionary *APrabhupadaDictionary )
  : inherited()
  , m_PrabhupadaDictionary( APrabhupadaDictionary )
{
  m_ui->setupUi( this );

  Connects();
  Emits();
}

QPrabhupadaLoginWindow::~QPrabhupadaLoginWindow()
{
  delete m_ui;
}

void QPrabhupadaLoginWindow::Connects()
{
  QObject::connect( m_ui->radioButtonSQLite
                  , &QAbstractButton::toggled
                  , this
                  , &QPrabhupadaLoginWindow::SQLRadioButton );
  m_ui->radioButtonSQLite->setChecked( true );

  QObject::connect( m_ui->ComboBoxLanguageUI
                  , ( void ( QComboBox::* )( int ) )( QComboBox::currentIndexChanged )
                  , &m_PrabhupadaDictionary->m_LanguageUIIndex
                  , &QLanguageIndex::SetValue );
  QObject::connect( &m_PrabhupadaDictionary->m_LanguageUIIndex
                  , &QLanguageIndex::SignalValueChanged
                  , this
                  , &QPrabhupadaLoginWindow::LanguageUI_IndexChanged );
  QObject::connect( m_ui->pushButtonOK
                  , &QPushButton::clicked
                  , this
                  , &QPrabhupadaLoginWindow::pushButtonOKClicked );
  QObject::connect( m_ui->pushButtonCancel
                  , &QPushButton::clicked
                  , this
                  , &QPrabhupadaLoginWindow::pushButtonCancelClicked );
}

void QPrabhupadaLoginWindow::Emits()
{
  m_PrabhupadaDictionary->m_LanguageUIIndex.EmitValueChanged();
}

void QPrabhupadaLoginWindow::LoadFromStream( QDataStream &ST )
{
  inherited::LoadFromStream( ST );
  // 1
  QStorage::LoadFromStream( m_ui->ComboBoxUserName, ST );
  // 2
  QStorage::LoadFromStream( m_ui->ComboBoxDatabaseName, ST );
  // 3
  QStorage::LoadFromStream( m_ui->ComboBoxHostName, ST );
  // 4
  QStorage::LoadFromStream( m_ui->ComboBoxPort, ST );
  // 5
  QStorage::LoadFromStream( m_ui->ComboBoxSchema, ST );
  // 6
  bool B;
  ST >> B;
  if ( B ) {
    m_ui->radioButtonSQLite->setChecked( true );
  } else {
    m_ui->radioButtonPostgreSQL->setChecked( true );
  }
}

void QPrabhupadaLoginWindow::SaveToStream( QDataStream &ST )
{
  inherited::SaveToStream( ST );

  // 1
  QStorage::SaveToStream( m_ui->ComboBoxUserName, ST );
  // 2
  QStorage::SaveToStream( m_ui->ComboBoxDatabaseName, ST );
  // 3
  QStorage::SaveToStream( m_ui->ComboBoxHostName, ST );
  // 4
  QStorage::SaveToStream( m_ui->ComboBoxPort, ST );
  // 5
  QStorage::SaveToStream( m_ui->ComboBoxSchema, ST );
  // 6
  ST << m_ui->radioButtonSQLite->isChecked();
}

void QPrabhupadaLoginWindow::pushButtonOKClicked()
{
  accept();
}

void QPrabhupadaLoginWindow::pushButtonCancelClicked()
{
  reject();
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
  DB->setUserName( m_ui->ComboBoxUserName->currentText () );
  DB->setPassword( m_ui->LineEditPassword->text() );
  if ( m_ui->radioButtonSQLite->isChecked() ) {
    DB->setDatabaseName( "./resources/PrabhupadaDictionaryFiles/Sanskrit.db" );
  } else {
    DB->setDatabaseName( m_ui->ComboBoxDatabaseName->currentText() );
  }
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
  return B;
}

void QPrabhupadaLoginWindow::LanguageUI_IndexChanged( int Value )
{
  m_ui->ComboBoxLanguageUI->setCurrentIndex( Value );
}
