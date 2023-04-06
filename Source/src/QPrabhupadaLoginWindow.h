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
#include <QPrabhupadaStorage.h>
#include <QPrabhupadaDictionary.h>
#include <ui_QPrabhupadaLoginWindow.h>

class QPrabhupadaLoginWindow : public QPrabhupadaDialog
{
  CS_OBJECT( QPrabhupadaLoginWindow )

  public:
    QPrabhupadaLoginWindow() = delete;
    QPrabhupadaLoginWindow( QPrabhupadaDictionary *APrabhupadaDictionary );
    ~QPrabhupadaLoginWindow();
    Ui::QPrabhupadaLoginWindow *m_ui = new Ui::QPrabhupadaLoginWindow;
    QPrabhupadaDictionary *m_PrabhupadaDictionary = nullptr;
    bool Connect( QSqlDatabase *DB );
    inline QString DriverName() { return m_DriverName; };
    inline QString Schema() { return m_Schema; };
    inline void SetPrabhupadaDictionary( QPrabhupadaDictionary *Value ) { m_PrabhupadaDictionary = Value; };
  private:
    using inherited = QPrabhupadaDialog;
    QString m_DriverName;
    QString m_Schema;
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
