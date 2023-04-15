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

#ifndef QPrabhupadaGoToLineWindow_H
#define QPrabhupadaGoToLineWindow_H

#include <QtCore>
#include <QtGui>
#include <QtSql>
#include <QPrabhupadaStorage.h>
#include <QPrabhupadaDictionary.h>
#include <ui_QPrabhupadaGoToLineWindow.h>

class QPrabhupadaGoToLineWindow : public QPrabhupadaDialog
{
  CS_OBJECT( QPrabhupadaGoToLineWindow )

  public:
    QPrabhupadaGoToLineWindow() = delete;
    QPrabhupadaGoToLineWindow( QPrabhupadaStorage *APrabhupadaStorage );
    ~QPrabhupadaGoToLineWindow();
    Ui::QPrabhupadaGoToLineWindow *m_ui = new Ui::QPrabhupadaGoToLineWindow;
    QPrabhupadaStorage *m_PrabhupadaStorage;

    CS_SIGNAL_1( Public, void SignalGoToLine( int Value ) )
    CS_SIGNAL_2( SignalGoToLine, Value )

  private:
    using inherited = QPrabhupadaDialog;
    void PushButtonGoClicked();
    void PushButtonCancelClicked();
  protected:
    void LoadFromStream( QDataStream &ST ) override;
    void SaveToStream( QDataStream &ST ) override;
    void changeEvent( QEvent *event ) override;
    // void showEvent( QShowEvent *event ) override;
    // void closeEvent( QCloseEvent *event ) override;
};

#endif