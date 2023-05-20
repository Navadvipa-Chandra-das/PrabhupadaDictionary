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
#include <QPrabhupada.h>
#include <PrabhupadaUtil.h>

int main( int argc, char *argv[] )
{
  QApplication app( argc, argv );
  QPrabhupadaStorage APrabhupadaStorage;

  QPrabhupadaDictionary APrabhupadaDictionary( nullptr );
  APrabhupadaDictionary.setObjectName( "PrabhupadaDictionary" );
  APrabhupadaDictionary.m_PrabhupadaStorage = &APrabhupadaStorage;
  app.setObjectName( APrabhupadaDictionary.objectName() );

  APrabhupadaStorage.LoadObject( &APrabhupadaDictionary.m_YazykVector, QPrabhupadaStorageKind::File );
  APrabhupadaStorage.LoadObject( &APrabhupadaDictionary.m_LanguageUIIndex, QPrabhupadaStorageKind::File );

  QPrabhupadaLoginWindow *PrabhupadaLoginWindow = new QPrabhupadaLoginWindow( &APrabhupadaDictionary );

  PrabhupadaLoginWindow->m_ui->ComboBoxUserName->setEditText( "Navadvipa Chandra das" );
  PrabhupadaLoginWindow->m_ui->ComboBoxDatabaseName->setEditText( "NewNavadvipa" );
  PrabhupadaLoginWindow->m_ui->ComboBoxHostName->setEditText( "127.0.0.1" );
  PrabhupadaLoginWindow->m_ui->ComboBoxPort->setEditText( QString::number( 5432 ) );
  PrabhupadaLoginWindow->m_ui->ComboBoxSchema->setEditText( "\"NewNavadvipa\"" );

  APrabhupadaStorage.LoadObject( PrabhupadaLoginWindow, QPrabhupadaStorageKind::File );
  APrabhupadaDictionary.m_LanguageUIIndex.PrepareComboBox( PrabhupadaLoginWindow->m_ui->ComboBoxLanguageUI );

  int R, N = 0;
  while ( ++N < 4 ) {
    R = PrabhupadaLoginWindow->exec();
    if ( R == QDialog::Accepted ) {
      QSqlDatabase DB = QSqlDatabase::addDatabase( PrabhupadaLoginWindow->m_DriverName, "PrabhupadaDB" );
      if ( PrabhupadaLoginWindow->Connect( &DB ) ) {
        // Подготавливаем APrabhupadaStorage
        APrabhupadaStorage.SetDatabase( &DB );
        APrabhupadaStorage.m_Schema = PrabhupadaLoginWindow->m_Schema;
        // Подготавливаем APrabhupadaDictionary
        APrabhupadaDictionary.m_DB = &DB;
        APrabhupadaDictionary.m_Schema = APrabhupadaStorage.m_Schema;
        // Удаляем настройки программы в базе данных, если надо!
        if ( PrabhupadaLoginWindow->m_ui->CheckBoxResetSettings->isChecked() ) {
          APrabhupadaStorage.ResetSettings();
        }
        APrabhupadaStorage.LoadObject( &APrabhupadaDictionary, QPrabhupadaStorageKind::DB );
        QPrabhupadaDictionaryWindow PrabhupadaDictionaryWindow = QPrabhupadaDictionaryWindow( &APrabhupadaDictionary );
        PrabhupadaDictionaryWindow.m_PrabhupadaStorage = &APrabhupadaStorage;
        PrabhupadaDictionaryWindow.PrepareDictionary();
        APrabhupadaStorage.LoadObject( &PrabhupadaDictionaryWindow, QPrabhupadaStorageKind::DB );
        PrabhupadaDictionaryWindow.FirstShow();
        APrabhupadaStorage.SaveObject( PrabhupadaLoginWindow, QPrabhupadaStorageKind::File );

        delete PrabhupadaLoginWindow;
        PrabhupadaLoginWindow = nullptr;
        return app.exec();
      }
    } else
      break;
  }
  if ( PrabhupadaLoginWindow )
    delete PrabhupadaLoginWindow;
  return 0;
}
