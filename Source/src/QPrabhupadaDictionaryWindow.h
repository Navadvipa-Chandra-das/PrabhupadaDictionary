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
    QPrabhupadaDictionaryWindow( QPrabhupadaDictionary *APrabhupadaDictionary
                               , QPrabhupadaStorage *APrabhupadaStorage );
    ~QPrabhupadaDictionaryWindow();
    Ui::QPrabhupadaDictionaryWindow *m_ui = new Ui::QPrabhupadaDictionaryWindow;
    QPrabhupadaDictionary *m_PrabhupadaDictionary;
    QPrabhupadaStorage *m_PrabhupadaStorage;
    void PrepareDictionary( QSqlDatabase *DB );
    inline void SetStartResize( bool Value ) { m_StartResize = Value; };
    inline void SetPrabhupadaDictionary( QPrabhupadaDictionary *Value ) { m_PrabhupadaDictionary = Value; };
    void FirstShow();
  private:
    using inherited = QPrabhupadaMainWindow;
    int m_SanskitHeaderSize = 50;
    int m_PerevodHeaderSize = 50;
    bool m_StartResize = false;

    void actionExit_Program();
    void actionFind();
    void actionCase_Sensitive( bool Value );
    void actionDelete();
    void actionInsert();
    void actionRemove_Duplicates();
    void actionWhats_This_mode();
    void actionGoToRow();
    void actionAbout();
    void PrepareLanguages();
    void SetFilterSlovar( QFilterSlovar Value );
    inline QSqlDatabase *DB() { return m_PrabhupadaDictionary->m_DB; };
    void Language_IndexChanged( int Value );
    void LanguageUI_IndexChanged( int Value );
    void DoOrderBy( QOrderBy Value );
    void DoCaseSensitive( bool Value );
    void DoGoToLine( int Value );
    void Connects();
    void Emits();
    void TablePrabhupadaCurrentRowChanged( const QModelIndex &current, const QModelIndex &previous );
    void TablePrabhupadaHeaderSectionResized( int logicalIndex, int oldSize, int newSize );
  protected:
    void changeEvent( QEvent *event ) override;
    void closeEvent( QCloseEvent *event ) override;
    void LoadFromStream( QDataStream &ST ) override;
    void SaveToStream( QDataStream &ST ) override;
    void SpinBoxFontSizeChanged( int Value );
    virtual void FontSizeChanged( int Value );
    virtual void PrabhupadaTableResized();
    void resizeEvent( QResizeEvent *event ) override;
};

#endif
