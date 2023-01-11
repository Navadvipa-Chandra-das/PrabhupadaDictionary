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

#ifndef PrabhupadaDictionaryWindow_H
#define PrabhupadaDictionaryWindow_H

#include <QtCore>
#include <QtGui>
#include <QPrabhupadaStorage.h>
#include <ui_PrabhupadaDictionaryWindow.h>

class PrabhupadaDictionaryWindow : public QPrabhupadaMainWindow
{
  CS_OBJECT( PrabhupadaDictionaryWindow )

  public:
    PrabhupadaDictionaryWindow();
    ~PrabhupadaDictionaryWindow();
    QPrabhupadaStorage *m_PrabhupadaStorage = nullptr;
    void PrepareDictionary( QSqlDatabase *DB );
  private:
    using inherited = QPrabhupadaMainWindow;
    bool m_Case_Sensitive = false;
    void actionExit_Program();

    void actionFind();
    void actionCase_Sensitive( bool ACaseSensitive );
    void actionDelete();
    void actionInsert();
    void actionRemove_Duplicates();
    void actionWhats_This_mode();
    void FontSizeChanged( int Value );
    void PreparePrabhupadaBukvary();
    void PrepareYazykAndMaxID();
  protected:
    Ui::PrabhupadaDictionaryWindow *m_ui;
    void changeEvent( QEvent *event ) override;
    void LoadFromStream( QDataStream &ST ) override;
    void SaveToStream( QDataStream &ST ) override;
};

#endif
