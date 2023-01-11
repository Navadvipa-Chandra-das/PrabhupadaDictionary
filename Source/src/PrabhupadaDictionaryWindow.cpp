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
#include <PrabhupadaDictionaryWindow.h>
#include <PrabhupadaUtil.h>
#include <QPrabhupadaStorage.h>
#include <QSaveFile>

const QString FileINIPrabhupadaDictionaryWindow( "./PrabhupadaFiles/PrabhupadaDictionaryWindow.ini" );

PrabhupadaDictionaryWindow::PrabhupadaDictionaryWindow()
  : inherited()
  , m_ui( new Ui::PrabhupadaDictionaryWindow )
{
  m_ui->setupUi( this );

  setWindowTitle( tr( "Prabhupada Dictionary" ) );
  setWindowIcon( QIcon( "://resources/PrabhupadaDictionary.ico" ) );

  connect( m_ui->actionFind
         , &QAction::triggered
         , this
         , &PrabhupadaDictionaryWindow::actionFind );
  connect( m_ui->actionCase_Sensitive
         , &QAction::toggled
         , this
         , &PrabhupadaDictionaryWindow::actionCase_Sensitive );
  connect( m_ui->actionDelete
         , &QAction::triggered
         , this
         , &PrabhupadaDictionaryWindow::actionDelete );
  connect( m_ui->actionInsert
         , &QAction::triggered
         , this
         , &PrabhupadaDictionaryWindow::actionInsert );
  connect( m_ui->actionRemove_Duplicates
         , &QAction::triggered
         , this
         , &PrabhupadaDictionaryWindow::actionRemove_Duplicates );
  connect( m_ui->actionWhats_This_mode
         , &QAction::triggered
         , this
         , &PrabhupadaDictionaryWindow::actionWhats_This_mode );

  connect( m_ui->sbFontSize
         , ( void ( QSpinBox::* )( int ) )( QSpinBox::valueChanged )
         , this
         , &PrabhupadaDictionaryWindow::FontSizeChanged );

#ifdef Q_OS_MAC
  setUnifiedTitleAndToolBarOnMac( true );
#endif

}

PrabhupadaDictionaryWindow::~PrabhupadaDictionaryWindow()
{
  delete m_ui;
}

void PrabhupadaDictionaryWindow::FontSizeChanged( int Value )
{
  QFont F = m_ui->leTranslate->font();
  F.setPointSize( Value );
  m_ui->leTranslate->setFont( F );
  m_ui->leSanskrit->setFont( F );
}

void PrabhupadaDictionaryWindow::actionFind()
{
}

void PrabhupadaDictionaryWindow::actionCase_Sensitive( bool ACaseSensitive )
{
  m_Case_Sensitive = ACaseSensitive;
}

void PrabhupadaDictionaryWindow::actionDelete()
{
  PrabhupadaMessage( QPrabhupadaStorage::KeyStorage( this ) );
}

void PrabhupadaDictionaryWindow::actionInsert()
{
}

void PrabhupadaDictionaryWindow::actionRemove_Duplicates()
{
}

void PrabhupadaDictionaryWindow::actionWhats_This_mode()
{
  if ( QWhatsThis::inWhatsThisMode() )
    QWhatsThis::leaveWhatsThisMode();
  else
    QWhatsThis::enterWhatsThisMode();
}

void PrabhupadaDictionaryWindow::changeEvent( QEvent *event )
{
  if ( event->type() == QEvent::LanguageChange ) {
    m_ui->retranslateUi( this );
  }

  inherited::changeEvent( event );
}

void PrabhupadaDictionaryWindow::actionExit_Program()
{
   close();
}

void PrabhupadaDictionaryWindow::LoadFromStream( QDataStream &ST )
{
  inherited::LoadFromStream( ST );
  int FS;
  ST >> FS;
  m_ui->sbFontSize->setValue( FS );
  QByteArray AS;
  ST >> AS;
  m_ui->splSanskritTranslate->restoreState( AS );
}

void PrabhupadaDictionaryWindow::SaveToStream( QDataStream &ST )
{
  inherited::SaveToStream( ST );
  ST << m_ui->sbFontSize->value();
  ST << m_ui->splSanskritTranslate->saveState();
}

void PrabhupadaDictionaryWindow::PrepareDictionary( QSqlDatabase *DB );
{
  PreparePrabhupadaBukvary();
  PrepareYazykAndMaxID();

//   OrderBy       = QOrderBy::SanskritVozrastanie;
//   YazykIndex    = RussianIndex;
//   CaseSensitive = false;
//
//   PrepareLanguages();
//
//   SetFilterStart = true;
//   FilterSlovar   = FilterSlovar;
}

void PrabhupadaDictionaryWindow::PrepareLanguages()
{
  dmfNewNavadvipa->lmDB->PrepareStrings( cbLanguage->Items );
  dmfNewNavadvipa->lmDB->MainLanguageID = NNFConst::MainLanguageID;
  cbLanguage->ItemIndex = dmfNewNavadvipa->lmDB->LanguageIDToItemIndex( dmfNewNavadvipa->lmDB->CurrentLanguageID );
  NNFConst::MainLanguageIndex = dmfNewNavadvipa->lmDB->LanguageIDToItemIndex( dmfNewNavadvipa->lmDB->CurrentLanguageID );
}

void PrabhupadaDictionaryWindow::PreparePrabhupadaBukvary()
{
  QPrabhupadaBukva B;

  m_File     = new QFile( m_FileName );
  m_Stream   = new QDataStream( m_File );
  m_File->open( QIODevice::ReadOnly );
  std::unique_ptr< TFileStream > FS( new TFileStream( Prabhupada::PrabhupadaSlovarFiles + "PrabhupadaBukvary.txt", fmOpenRead ) );
  std::unique_ptr< TNNFTextStream > TS( new TNNFTextStream( FS.get() ) );
  int V = 0;
  String S;
  while ( TS->ReadStringLine( S ) ) {
    B.Bukva = S[ 3 ];
    B.Ves = ++V;
    NNF::PrabhupadaBukvary[ S[ 1 ] ] = B;
  }
}

void __fastcall TfmfPrabhupadaSlovar::PrepareYazykAndMaxID()
{
  quYazyk->Active = true;
  NNF::TYazykInfo YI;
  String ALang;
  while ( !quYazyk->Eof ) {
    YI.ID         = quYazykID->AsInteger;
    YI.Yazyk      = quYazykYAZYK->AsString;
    YI.YazykSlovo = quYazykYAZYK_SLOVO->AsString;
    ALang         = YI.Yazyk.SubString( 1, 2 );
    YI.Lang       = ALang;

    YazykVector.push_back( YI );

    cbYazyk->Items->Add( YI.YazykSlovo );
    //cbLang->Items->Add( YI.YazykSlovo );
    quYazyk->Next();
  }
  quYazyk->Active = false;

  quMaxID->Active = true;
  MaxID = quMaxID->Fields->Fields[ 0 ]->AsInteger;
  quMaxID->Active = false;
}

void __fastcall TfmfPrabhupadaSlovar::SetFilterSlovar( NNF::TFilterSlovar Value )
{
  if ( !SetFilterStart )
    return;

  NNF::TFilterSlovar &FS = YazykVector[ YazykIndex ].FilterSlovar;
  if ( FS != Value || Value.IsReset ) {
    FS = Value;

    bool SIsReset = FS.IsReset;
    FS.IsReset = false;
    // В дальнейшем мы можем повысить скорость, еспользуя простое свойство IsEmpty вместо функции GetIsEmpty()!
    FS.IsEmpty = FS.GetIsEmpty();

    PreparePrabhupadaSearchVector();
    RefreshPrabhupadaSlovar( SIsReset ? YazykVector[ YazykIndex ].CurrentRow : 0, PrabhupadaSlovarVector.SearchCount );

    edSanskrit->Text = FS.Sanskrit;
    edPerevod->Text  = FS.Perevod;
  }
}
