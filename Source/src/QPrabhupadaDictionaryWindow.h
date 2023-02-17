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

#ifndef QPrabhupadaDictionaryWindow_H
#define QPrabhupadaDictionaryWindow_H

#include <QtCore>
#include <QtGui>
#include <QPrabhupadaStorage.h>
#include <QPrabhupadaDictionary.h>
#include <ui_QPrabhupadaDictionaryWindow.h>

class QPrabhupadaDictionaryWindow : public QPrabhupadaMainWindow
{
  CS_OBJECT( QPrabhupadaDictionaryWindow )

  public:
    QPrabhupadaDictionaryWindow() = delete;
    QPrabhupadaDictionaryWindow( QPrabhupadaStorage *APrabhupadaStorage
                               , QPrabhupadaDictionary *APrabhupadaDictionary );
    ~QPrabhupadaDictionaryWindow();
    Ui::QPrabhupadaDictionaryWindow *m_ui = new Ui::QPrabhupadaDictionaryWindow;
    QPrabhupadaStorage *m_PrabhupadaStorage;
    QPrabhupadaDictionary *m_PrabhupadaDictionary;
    void PrepareDictionary( QSqlDatabase *DB, bool ASetLang );

    //CS_SIGNAL_1( Public, void addYazykSlovo( QString &AYazykSlovo ) )
    //CS_SIGNAL_2( addYazykSlovo, AYazykSlovo )
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
    void PrepareLanguages();
    void SetFilterSlovar( QFilterSlovar Value );
    inline QSqlDatabase *DB() { return m_PrabhupadaDictionary->m_DB; };
    void Language_IndexChanged( int Value );
    void LanguageUI_IndexChanged( int Value );
  protected:
    void changeEvent( QEvent *event ) override;
    void closeEvent( QCloseEvent *event ) override;
    void LoadFromStream( QDataStream &ST ) override;
    void SaveToStream( QDataStream &ST ) override;
    virtual void FontSizeChanged( int Value );
};

#endif
