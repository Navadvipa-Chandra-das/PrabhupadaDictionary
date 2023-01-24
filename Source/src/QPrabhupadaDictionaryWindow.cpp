/***********************************************************************
*
* Copyright (c) 2022-2022 Navadvipa Chandra dasa
*
* PrabhupadaDictionary is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://opensource.org/licenses/BSD-2-Clause
*
***********************************************************************/

#include <PrabhupadaDictionary_build_info.h>
#include <QPrabhupadaDictionaryWindow.h>
#include <PrabhupadaUtil.h>
#include <QPrabhupadaStorage.h>
#include <QSaveFile>

QPrabhupadaDictionaryWindow::QPrabhupadaDictionaryWindow()
  : inherited()
{
  m_ui->setupUi( this );

  QObject::connect( m_ui->actionFind
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionFind );
  QObject::connect( m_ui->actionCase_Sensitive
                  , &QAction::toggled
                  , this
                  , &QPrabhupadaDictionaryWindow::actionCase_Sensitive );
  QObject::connect( m_ui->actionDelete
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionDelete );
  QObject::connect( m_ui->actionInsert
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionInsert );
  QObject::connect( m_ui->actionRemove_Duplicates
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionRemove_Duplicates );
  QObject::connect( m_ui->actionWhats_This_mode
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionWhats_This_mode );

  QObject::connect( m_ui->sbFontSize
                  , ( void ( QSpinBox::* )( int ) )( QSpinBox::valueChanged )
                  , this
                  , &QPrabhupadaDictionaryWindow::FontSizeChanged );

#ifdef Q_OS_MAC
  setUnifiedTitleAndToolBarOnMac( true );
#endif

}

QPrabhupadaDictionaryWindow::~QPrabhupadaDictionaryWindow()
{
  delete m_ui;
}

void QPrabhupadaDictionaryWindow::FontSizeChanged( int Value )
{
  QFont F = m_ui->leTranslate->font();
  F.setPointSize( Value );
  m_ui->leTranslate->setFont( F );
  m_ui->leSanskrit->setFont( F );
}

void QPrabhupadaDictionaryWindow::actionFind()
{
}

void QPrabhupadaDictionaryWindow::actionCase_Sensitive( bool ACaseSensitive )
{
  m_Case_Sensitive = ACaseSensitive;
}

void QPrabhupadaDictionaryWindow::actionDelete()
{
  PrabhupadaMessage( QPrabhupadaStorage::KeyStorage( this ) );
}

void QPrabhupadaDictionaryWindow::actionInsert()
{
}

void QPrabhupadaDictionaryWindow::actionRemove_Duplicates()
{
}

void QPrabhupadaDictionaryWindow::actionWhats_This_mode()
{
  if ( QWhatsThis::inWhatsThisMode() )
    QWhatsThis::leaveWhatsThisMode();
  else
    QWhatsThis::enterWhatsThisMode();
}

void QPrabhupadaDictionaryWindow::changeEvent( QEvent *event )
{
  if ( event->type() == QEvent::LanguageChange ) {
    m_ui->retranslateUi( this );
  }

  inherited::changeEvent( event );
}

void QPrabhupadaDictionaryWindow::actionExit_Program()
{
   close();
}

void QPrabhupadaDictionaryWindow::LoadFromStream( QDataStream &ST )
{
  inherited::LoadFromStream( ST );
  int FS;
  ST >> FS;
  m_ui->sbFontSize->setValue( FS );
  QByteArray AS;
  ST >> AS;
  m_ui->splSanskritTranslate->restoreState( AS );
}

void QPrabhupadaDictionaryWindow::SaveToStream( QDataStream &ST )
{
  inherited::SaveToStream( ST );
  ST << m_ui->sbFontSize->value();
  ST << m_ui->splSanskritTranslate->saveState();
}

void QPrabhupadaDictionaryWindow::PrepareDictionary( QSqlDatabase *DB )
{
  m_PrabhupadaDictionary.m_DB = DB;
  m_PrabhupadaDictionary.PrepareYazykAndMaxID();
//   OrderBy       = QOrderBy::SanskritVozrastanie;
//   YazykIndex    = RussianIndex;
//   CaseSensitive = false;
//
  PrepareLanguages();
//
//   SetFilterStart = true;
//   FilterSlovar   = FilterSlovar;
}

void QPrabhupadaDictionaryWindow::PrepareLanguages()
{
  for ( QYazykVector::iterator i = m_PrabhupadaDictionary.m_YazykVector.begin(); i != m_PrabhupadaDictionary.m_YazykVector.end(); ++i ) {
    m_ui->ComboBoxLanguage  ->addItem( ( *i ).m_YazykSlovo );
    m_ui->ComboBoxLanguageUI->addItem( ( *i ).m_YazykSlovo );
  }
  // dmfNewNavadvipa->lmDB->PrepareStrings( cbLanguage->Items );
  // dmfNewNavadvipa->lmDB->MainLanguageID = NNFConst::MainLanguageID;
  // cbLanguage->ItemIndex = dmfNewNavadvipa->lmDB->LanguageIDToItemIndex( dmfNewNavadvipa->lmDB->CurrentLanguageID );
  // NNFConst::MainLanguageIndex = dmfNewNavadvipa->lmDB->LanguageIDToItemIndex( dmfNewNavadvipa->lmDB->CurrentLanguageID );
}

void QPrabhupadaDictionaryWindow::SetFilterSlovar( QFilterSlovar Value )
{
  if ( Value.IsEmpty() )
    PrabhupadaMessage( "Харе Кришна!" );
  // if ( !SetFilterStart )
  //   return;
  //
  // QFilterSlovar &FS = YazykVector[ YazykIndex ].FilterSlovar;
  // if ( FS != Value || Value.IsReset ) {
  //   FS = Value;
  //
  //   bool SIsReset = FS.IsReset;
  //   FS.IsReset = false;
  //   // В дальнейшем мы можем повысить скорость, еспользуя простое свойство IsEmpty вместо функции GetIsEmpty()!
  //   FS.IsEmpty = FS.GetIsEmpty();
  //
  //   PreparePrabhupadaSearchVector();
  //   RefreshPrabhupadaSlovar( SIsReset ? YazykVector[ YazykIndex ].CurrentRow : 0, PrabhupadaSlovarVector.SearchCount );
  //
  //   edSanskrit->Text = FS.Sanskrit;
  //   edPerevod->Text  = FS.Perevod;
  // }
}
