/***********************************************************************
*
* Copyright (c) 2012-2022 Barbara Geller
* Copyright (c) 2012-2022 Ansel Sermersheim
* Copyright (c) 2015 The Qt Company Ltd.
*
* This file is part of KitchenSink.
*
* KitchenSink is free software, released under the BSD 2-Clause license.
* For license details refer to LICENSE provided with this project.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://opensource.org/licenses/BSD-2-Clause
*
***********************************************************************/

#include <QPrabhupadaLoginWindow.h>
#include <QPrabhupadaDictionaryWindow.h>

#include <QApplication>
#include <QPrabhupadaStorage.h>
#include <PrabhupadaUtil.h>

int main( int argc, char *argv[] )
{
  QApplication app( argc, argv );
  QPrabhupadaDictionary APrabhupadaDictionary;
  APrabhupadaDictionary.setObjectName( "PrabhupadaDictionary" );
  QPrabhupadaStorage APrabhupadaStorage;
  bool ASetLang = !APrabhupadaStorage.LoadObject( &APrabhupadaDictionary );

  QPrabhupadaLoginWindow *PrabhupadaLoginWindow = new QPrabhupadaLoginWindow( &APrabhupadaStorage, &APrabhupadaDictionary );

  PrabhupadaLoginWindow->m_ui->ComboBoxUserName->setEditText( "Navadvipa Chandra das" );
  PrabhupadaLoginWindow->m_ui->ComboBoxDatabaseName->setEditText( "NewNavadvipa" );
  PrabhupadaLoginWindow->m_ui->ComboBoxHostName->setEditText( "127.0.0.1" );
  PrabhupadaLoginWindow->m_ui->ComboBoxPort->setEditText( QString::number( 5432 ) );
  PrabhupadaLoginWindow->m_ui->ComboBoxSchema->setEditText( "\"NewNavadvipa\"" );

  APrabhupadaDictionary.m_LanguageUIIndex.IncStart();
  if ( !APrabhupadaStorage.LoadObject( PrabhupadaLoginWindow ) ) {
    PrabhupadaLoginWindow->m_ui->ComboBoxLanguageUI->addItem( "Русский" );
  } else {
    APrabhupadaDictionary.m_LanguageUIIndex.PrepareComboBox( PrabhupadaLoginWindow->m_ui->ComboBoxLanguageUI );
    PrabhupadaLoginWindow->m_ui->ComboBoxLanguageUI->setCurrentIndex( APrabhupadaDictionary.m_LanguageUIIndex.Index() );
  }
  APrabhupadaDictionary.m_LanguageUIIndex.DecStart();

  int R, N = 0;
  while ( ++N < 4 ) {
    R = PrabhupadaLoginWindow->exec();
    if ( R == QDialog::Accepted ) {
      QSqlDatabase DB = QSqlDatabase::addDatabase( PrabhupadaLoginWindow->DriverName(), "PrabhupadaDB" );
      if ( PrabhupadaLoginWindow->Connect( &DB ) ) {
        QPrabhupadaDictionaryWindow PrabhupadaDictionaryWindow( &APrabhupadaStorage, &APrabhupadaDictionary );

        // QObject::connect( &PrabhupadaDictionaryWindow
        //                 , &QPrabhupadaDictionaryWindow::addYazykSlovo
        //                 , PrabhupadaLoginWindow
        //                 , &QPrabhupadaLoginWindow::addYazykSlovo );

        PrabhupadaDictionaryWindow.m_PrabhupadaDictionary->m_Schema = PrabhupadaLoginWindow->Schema();
        PrabhupadaDictionaryWindow.setPrabhupadaStorage( &APrabhupadaStorage );
        PrabhupadaDictionaryWindow.PrepareDictionary( &DB, ASetLang );
        APrabhupadaStorage.LoadObject( &PrabhupadaDictionaryWindow );
        PrabhupadaDictionaryWindow.show();
        if ( DB.open() ) {
          APrabhupadaStorage.SaveObject( PrabhupadaLoginWindow );
          delete PrabhupadaLoginWindow;
          APrabhupadaStorage.setDatabase( &DB );
          return app.exec();
        }
      }
    } else
      break;
  }
  delete PrabhupadaLoginWindow;
  return 0;
}
