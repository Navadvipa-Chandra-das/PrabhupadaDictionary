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

#ifndef QPrabhupadaLoginWindow_H
#define QPrabhupadaLoginWindow_H

#include <QtCore>
#include <QtGui>
#include <QtSql>
#include <QPrabhupada.h>
#include <QPrabhupadaDictionary.h>
#include <ui_QPrabhupadaLoginWindow.h>

class QPrabhupadaLoginWindow : public QDialog
{
  CS_OBJECT( QPrabhupadaLoginWindow )

  public:
    QPrabhupadaLoginWindow() = delete;
    QPrabhupadaLoginWindow( QPrabhupadaDictionary *APrabhupadaDictionary );
    ~QPrabhupadaLoginWindow();
    Ui::QPrabhupadaLoginWindow *m_ui = new Ui::QPrabhupadaLoginWindow;
    QString m_DriverName;
    QString m_Schema;
    QPrabhupadaDictionary *m_PrabhupadaDictionary = nullptr;
    bool Connect( QSqlDatabase *DB );
  private:
    using inherited = QDialog;
    void Connects();
    void Emits();
    void SQLRadioButton( bool checked );
    void DatabaseToWidget( QSqlDatabase *DB );
    void WidgetToDatabase( QSqlDatabase *DB );
    void LanguageUI_IndexChanged( int Value );
    void pushButtonOKClicked();
    void pushButtonCancelClicked();
  protected:
    void LoadFromStream( QDataStream &ST ) override;
    void SaveToStream( QDataStream &ST ) override;
    void changeEvent( QEvent *event ) override;
    // void showEvent( QShowEvent *event ) override;
    // void closeEvent( QCloseEvent *event ) override;
};

#endif
