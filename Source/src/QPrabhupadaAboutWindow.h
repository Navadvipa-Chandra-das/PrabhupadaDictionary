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

#ifndef QPrabhupadaAboutWindow_H
#define QPrabhupadaAboutWindow_H

#include <QtCore>
#include <QtGui>
#include <QtSql>
#include <QPrabhupadaStorage.h>
#include <QPrabhupadaDictionary.h>
#include <ui_QPrabhupadaAboutWindow.h>

class QPrabhupadaAboutWindow : public QPrabhupadaDialog
{
  CS_OBJECT( QPrabhupadaAboutWindow )

  public:
    QPrabhupadaAboutWindow() = delete;
    QPrabhupadaAboutWindow( QPrabhupadaStorage *APrabhupadaStorage );
    ~QPrabhupadaAboutWindow();
    Ui::QPrabhupadaAboutWindow *m_ui = new Ui::QPrabhupadaAboutWindow;
    QPrabhupadaStorage *m_PrabhupadaStorage;
  private:
    using inherited = QPrabhupadaDialog;
  protected:
    void LoadFromStream( QDataStream &ST ) override;
    void SaveToStream( QDataStream &ST ) override;
    void changeEvent( QEvent *event ) override;
    // void showEvent( QShowEvent *event ) override;
    // void closeEvent( QCloseEvent *event ) override;
};

#endif
