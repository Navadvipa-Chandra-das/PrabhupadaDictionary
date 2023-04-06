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
#include <QPrabhupadaGoToLineWindow.h>
#include <QPrabhupadaAboutWindow.h>
#include <PrabhupadaUtil.h>
#include <QPrabhupadaStorage.h>
#include <QSaveFile>

QPrabhupadaDictionaryWindow::QPrabhupadaDictionaryWindow( QPrabhupadaDictionary *APrabhupadaDictionary
                                                        , QPrabhupadaStorage *APrabhupadaStorage )
  : inherited()
  , m_PrabhupadaDictionary( APrabhupadaDictionary )
  , m_PrabhupadaStorage( APrabhupadaStorage )
{
  m_ui->setupUi( this );
  m_ui->tbvPrabhupadaDictionary->verticalHeader()->hide();
  m_ui->tbvPrabhupadaDictionary->setModel( m_PrabhupadaDictionary );
  Connects();

#ifdef Q_OS_MAC
  setUnifiedTitleAndToolBarOnMac( true );
#endif
}

void QPrabhupadaDictionaryWindow::Connects()
{
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
  QObject::connect( m_ui->actionGoToRow
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionGoToRow );
  QObject::connect( m_ui->actionAbout
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionAbout );
  QObject::connect( m_ui->sbFontSize
                  , ( void ( QSpinBox::* )( int ) )( QSpinBox::valueChanged )
                  , this
                  , &QPrabhupadaDictionaryWindow::SpinBoxFontSizeChanged );
  QObject::connect( &m_PrabhupadaDictionary->m_FontSize
                  , &QFontSize::SignalValueChanged
                  , this
                  , &FontSizeChanged );
  QObject::connect( m_ui->ComboBoxLanguage
                  , ( void ( QComboBox::* )( int ) )( QComboBox::currentIndexChanged )
                  , &m_PrabhupadaDictionary->m_LanguageIndex
                  , &QLanguageIndex::SetValue );
  QObject::connect( m_ui->ComboBoxLanguageUI
                  , ( void ( QComboBox::* )( int ) )( QComboBox::currentIndexChanged )
                  , &m_PrabhupadaDictionary->m_LanguageUIIndex
                  , &QLanguageIndex::SetValue );
  QObject::connect( &m_PrabhupadaDictionary->m_LanguageIndex
                  , &QLanguageIndex::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionaryWindow::Language_IndexChanged );
  QObject::connect( &m_PrabhupadaDictionary->m_LanguageUIIndex
                  , &QLanguageIndex::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionaryWindow::LanguageUI_IndexChanged );
  QObject::connect( m_ui->tbvPrabhupadaDictionary->horizontalHeader()
                  , &QHeaderView::sortIndicatorChanged
                  , m_PrabhupadaDictionary
                  , &QPrabhupadaDictionary::sortByColumn );
  QObject::connect( &m_PrabhupadaDictionary->m_PrabhupadaOrder
                  , &QPrabhupadaOrder::SignalValueChanged
                  , this
                  , &DoOrderBy );
  QObject::connect( &m_PrabhupadaDictionary->m_CaseSensitive
                  , &QPrabhupadaBool::SignalValueChanged
                  , this
                  , &DoCaseSensitive );
  QObject::connect( m_ui->tbvPrabhupadaDictionary->selectionModel()
                  , &QItemSelectionModel::currentRowChanged
                  , this
                  , &TablePrabhupadaCurrentRowChanged );
  QObject::connect( m_ui->tbvPrabhupadaDictionary->horizontalHeader()
                  , &QHeaderView::sectionResized
                  , this
                  , &TablePrabhupadaHeaderSectionResized );
}

void QPrabhupadaDictionaryWindow::Emits()
{
  m_PrabhupadaDictionary->m_LanguageIndex.EmitValueChanged();
  m_PrabhupadaDictionary->m_LanguageUIIndex.EmitValueChanged();
  m_PrabhupadaDictionary->m_FontSize.EmitValueChanged();
  m_PrabhupadaDictionary->m_PrabhupadaOrder.EmitValueChanged();
  m_PrabhupadaDictionary->m_CaseSensitive.EmitValueChanged();
  m_ui->tbvPrabhupadaDictionary->setFocus( Qt::ActiveWindowFocusReason );
}

QPrabhupadaDictionaryWindow::~QPrabhupadaDictionaryWindow()
{
  delete m_ui;
}

void QPrabhupadaDictionaryWindow::SpinBoxFontSizeChanged( int Value )
{
  m_PrabhupadaDictionary->m_FontSize.SetValue( Value );
}

void QPrabhupadaDictionaryWindow::FontSizeChanged( int Value )
{
  m_ui->sbFontSize->setValue( Value );
  QFont F = m_ui->ComboBoxSanskrit->font();
  F.setPointSize( Value );
  m_ui->ComboBoxSanskrit->setFont( F );
  m_ui->ComboBoxTranslate->setFont( F );
  m_ui->tbvPrabhupadaDictionary->setFont( F );

  QHeaderView *verticalHeader = m_ui->tbvPrabhupadaDictionary->verticalHeader();
  //verticalHeader->setSectionResizeMode( QHeaderView::Fixed );
  QFontMetrics FM( F );
  verticalHeader->setDefaultSectionSize( FM.height() );
}

void QPrabhupadaDictionaryWindow::actionFind()
{
  //FilterSlovar = QFilterSlovar( edSanskrit->Text, edPerevod->Text );
}

void QPrabhupadaDictionaryWindow::actionCase_Sensitive( bool Value )
{
  m_PrabhupadaDictionary->m_CaseSensitive.SetValue( Value );
}

void QPrabhupadaDictionaryWindow::actionDelete()
{
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

void QPrabhupadaDictionaryWindow::actionGoToRow()
{
  QPrabhupadaGoToLineWindow PrabhupadaGoToLineWindow( m_PrabhupadaStorage );

  QObject::connect( &PrabhupadaGoToLineWindow
                  , &QPrabhupadaGoToLineWindow::SignalGoToLine
                  , this
                  , &DoGoToLine );

  m_PrabhupadaStorage->LoadObject( &PrabhupadaGoToLineWindow, QPrabhupadaStorageKind::ByteArray );
  PrabhupadaGoToLineWindow.exec();
  m_PrabhupadaStorage->SaveObject( &PrabhupadaGoToLineWindow, QPrabhupadaStorageKind::ByteArray );
}

void QPrabhupadaDictionaryWindow::actionAbout()
{
  QPrabhupadaAboutWindow PrabhupadaAboutWindow( m_PrabhupadaStorage );
  m_PrabhupadaStorage->LoadObject( &PrabhupadaAboutWindow, QPrabhupadaStorageKind::ByteArray );
  PrabhupadaAboutWindow.exec();
  m_PrabhupadaStorage->SaveObject( &PrabhupadaAboutWindow, QPrabhupadaStorageKind::ByteArray );
}

void QPrabhupadaDictionaryWindow::changeEvent( QEvent *event )
{
  if ( event->type() == QEvent::LanguageChange ) {
    m_ui->retranslateUi( this );
  }

  inherited::changeEvent( event );
}

void QPrabhupadaDictionaryWindow::closeEvent( QCloseEvent *event )
{
  m_PrabhupadaStorage->SaveObject( m_PrabhupadaDictionary );

  inherited::closeEvent( event );
}

void QPrabhupadaDictionaryWindow::actionExit_Program()
{
   close();
}

void QPrabhupadaDictionaryWindow::LoadFromStream( QDataStream &ST )
{
  inherited::LoadFromStream( ST );
  // 1
  QByteArray AS;
  ST >> AS;
  m_ui->splSanskritTranslate->restoreState( AS );
  // 2
  ST >> AS;
  m_ui->tbvPrabhupadaDictionary->horizontalHeader()->restoreState( AS );
  // 3
  m_PrabhupadaStorage->LoadFromStream( ST );
}

void QPrabhupadaDictionaryWindow::SaveToStream( QDataStream &ST )
{
  inherited::SaveToStream( ST );
  // 1
  ST << m_ui->splSanskritTranslate->saveState();
  // 2
  ST << m_ui->tbvPrabhupadaDictionary->horizontalHeader()->saveState();
  // 3
  m_PrabhupadaStorage->SaveToStream( ST );
}

void QPrabhupadaDictionaryWindow::PrepareDictionary( QSqlDatabase *DB )
{
  m_PrabhupadaDictionary->m_DB = DB;
  m_PrabhupadaDictionary->PrepareYazykAndMaxID();
  PrepareLanguages();

//   SetFilterStart = true;
//   FilterSlovar   = FilterSlovar;
}

void QPrabhupadaDictionaryWindow::PrepareLanguages()
{
  m_PrabhupadaDictionary->m_LanguageIndex.PrepareComboBox( m_ui->ComboBoxLanguage   );
  m_PrabhupadaDictionary->m_LanguageUIIndex.PrepareComboBox( m_ui->ComboBoxLanguageUI );
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

void QPrabhupadaDictionaryWindow::Language_IndexChanged( int Value )
{
  m_ui->ComboBoxLanguage->setCurrentIndex( Value );
}

void QPrabhupadaDictionaryWindow::LanguageUI_IndexChanged( int Value )
{
  m_ui->ComboBoxLanguageUI->setCurrentIndex( Value );
}

void QPrabhupadaDictionaryWindow::DoOrderBy( QOrderBy Value )
{
  QHeaderView* HV = m_ui->tbvPrabhupadaDictionary->horizontalHeader();
  switch ( Value ) {
    case QOrderBy::SanskritVozrastanie :
      HV->setSortIndicator( 0, Qt::AscendingOrder );
      break;
    case QOrderBy::SanskritUbyvanie :
      HV->setSortIndicator( 0, Qt::DescendingOrder );
      break;
    case QOrderBy::PerevodVozrastanie :
      HV->setSortIndicator( 1, Qt::AscendingOrder );
      break;
    case QOrderBy::PerevodUbyvanie :
      HV->setSortIndicator( 1, Qt::DescendingOrder );
      break;
  }
}

void QPrabhupadaDictionaryWindow::DoCaseSensitive( bool Value )
{
  m_ui->actionCase_Sensitive->setChecked( Value );
}

void QPrabhupadaDictionaryWindow::DoGoToLine( int Value )
{
  QModelIndex I = m_PrabhupadaDictionary->index( Value - 1, m_ui->tbvPrabhupadaDictionary->currentIndex().column() );
  m_ui->tbvPrabhupadaDictionary->setCurrentIndex( I );
  m_ui->tbvPrabhupadaDictionary->scrollTo( I );
}

void QPrabhupadaDictionaryWindow::TablePrabhupadaCurrentRowChanged( const QModelIndex &current, const QModelIndex &/*previous*/ )
{
  int R = current.row() + 1;
  std::size_t A = m_PrabhupadaDictionary->m_PrabhupadaSlovarVector.size();
  QString S = QString::number( R ) + " / " + QString::number( A );
  m_ui->lineEditRowIndicator->setText( S );
}

void QPrabhupadaDictionaryWindow::PrabhupadaTableResized()
{
  QTableView *TV = m_ui->tbvPrabhupadaDictionary;
  QScrollBar *SB = TV->verticalScrollBar();
  int SBW = 0;

  if ( SB ) {
    SBW = SB->width() + 2;
  }

  int WidthNew = TV->width()
    , WidthOld = m_SanskitHeaderSize + m_PerevodHeaderSize;

  if ( WidthNew > SBW )
    WidthNew -= SBW;

  TV->setColumnWidth( 0, m_SanskitHeaderSize * WidthNew / WidthOld );
  TV->setColumnWidth( 1, m_PerevodHeaderSize * WidthNew / WidthOld );
}

void QPrabhupadaDictionaryWindow::resizeEvent( QResizeEvent *event )
{
  if ( m_StartResize ) {
    PrabhupadaTableResized();
  }
  inherited::resizeEvent( event );
}

void QPrabhupadaDictionaryWindow::TablePrabhupadaHeaderSectionResized( int /*logicalIndex*/, int /*oldSize*/, int /*newSize*/ )
{
  if ( m_StartResize ) {
    QHeaderView *HV = m_ui->tbvPrabhupadaDictionary->horizontalHeader();

    m_SanskitHeaderSize = HV->sectionSize( 0 );
    m_PerevodHeaderSize = HV->sectionSize( 1 );
    //PrabhupadaLog( "log.txt", QString( "%1 : %2" ).formatArgs( m_SanskitHeaderSize, m_PerevodHeaderSize ) );
  }
}

void QPrabhupadaDictionaryWindow::FirstShow()
{
  Emits();
  show();
  SetStartResize( true );
  TablePrabhupadaHeaderSectionResized( 0, 0, 0 );
  PrabhupadaTableResized();
}
