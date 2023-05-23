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
#include <QPrabhupadaGoToLineWindow.h>
#include <QPrabhupadaUtil.h>
#include <QPrabhupada.h>

QPrabhupadaGoToLineWindow::QPrabhupadaGoToLineWindow( QStorage *AStorage )
  : inherited()
  , m_Storage( AStorage )
{
  m_ui->setupUi( this );
  QObject::connect( m_ui->PushButtonGo
                  , &QPushButton::clicked
                  , this
                  , &QPrabhupadaGoToLineWindow::PushButtonGoClicked );
  QObject::connect( m_ui->PushButtonCancel
                  , &QPushButton::clicked
                  , this
                  , &QPrabhupadaGoToLineWindow::PushButtonCancelClicked );
}

QPrabhupadaGoToLineWindow::~QPrabhupadaGoToLineWindow()
{
  delete m_ui;
}

void QPrabhupadaGoToLineWindow::LoadFromStream( QDataStream &ST )
{
  inherited::LoadFromStream( ST );

  QStorage::LoadFromStream( m_ui->ComboBoxRowNumber, ST );
}

void QPrabhupadaGoToLineWindow::SaveToStream( QDataStream &ST )
{
  inherited::SaveToStream( ST );

  QStorage::SaveToStream( m_ui->ComboBoxRowNumber, ST );
}

void QPrabhupadaGoToLineWindow::changeEvent( QEvent *event )
{
  if ( event->type() == QEvent::LanguageChange ) {
    m_ui->retranslateUi( this );
  }

  inherited::changeEvent( event );
}

void QPrabhupadaGoToLineWindow::PushButtonGoClicked()
{
  accept();
  emit SignalGoToLine( QStringParser::toInteger< int >( m_ui->ComboBoxRowNumber->currentText() ) );
}

void QPrabhupadaGoToLineWindow::PushButtonCancelClicked()
{
  reject();
}
