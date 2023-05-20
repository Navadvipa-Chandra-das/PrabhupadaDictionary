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
#include <QPrabhupadaAboutWindow.h>
#include <PrabhupadaUtil.h>
#include <QPrabhupada.h>

QPrabhupadaAboutWindow::QPrabhupadaAboutWindow( QPrabhupadaStorage *APrabhupadaStorage )
  : inherited()
  , m_PrabhupadaStorage( APrabhupadaStorage )
{
  m_ui->setupUi( this );
}

QPrabhupadaAboutWindow::~QPrabhupadaAboutWindow()
{
  delete m_ui;
}

void QPrabhupadaAboutWindow::LoadFromStream( QDataStream &ST )
{
  inherited::LoadFromStream( ST );

  QPrabhupadaStorage::LoadFromStream( m_ui->ComboBoxRowNumber, ST );
}

void QPrabhupadaAboutWindow::SaveToStream( QDataStream &ST )
{
  inherited::SaveToStream( ST );

  QPrabhupadaStorage::SaveToStream( m_ui->ComboBoxRowNumber, ST );
}

void QPrabhupadaAboutWindow::changeEvent( QEvent *event )
{
  if ( event->type() == QEvent::LanguageChange ) {
    m_ui->retranslateUi( this );
  }

  inherited::changeEvent( event );
}
