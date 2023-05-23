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
#include <QPrabhupadaUtil.h>

int main( int argc, char *argv[] )
{
  QApplication app( argc, argv );
  QStorage AStorage;

  QPrabhupadaDictionary APrabhupadaDictionary( nullptr );
  APrabhupadaDictionary.setObjectName( "PrabhupadaDictionary" );
  APrabhupadaDictionary.m_Storage = &AStorage;
  app.setObjectName( APrabhupadaDictionary.objectName() );

  AStorage.LoadObject( &APrabhupadaDictionary.m_LanguageVector, QStorageKind::File );
  AStorage.LoadObject( &APrabhupadaDictionary.m_LanguageUIIndex, QStorageKind::File );

  QPrabhupadaLoginWindow *PrabhupadaLoginWindow = new QPrabhupadaLoginWindow( &APrabhupadaDictionary );

  PrabhupadaLoginWindow->m_ui->ComboBoxUserName->setEditText( "Navadvipa Chandra das" );
  PrabhupadaLoginWindow->m_ui->ComboBoxDatabaseName->setEditText( "NewNavadvipa" );
  PrabhupadaLoginWindow->m_ui->ComboBoxHostName->setEditText( "127.0.0.1" );
  PrabhupadaLoginWindow->m_ui->ComboBoxPort->setEditText( QString::number( 5432 ) );
  PrabhupadaLoginWindow->m_ui->ComboBoxSchema->setEditText( "\"NewNavadvipa\"" );

  AStorage.LoadObject( PrabhupadaLoginWindow, QStorageKind::File );
  APrabhupadaDictionary.m_LanguageUIIndex.PrepareComboBox( PrabhupadaLoginWindow->m_ui->ComboBoxLanguageUI );

  int R, N = 0;
  while ( ++N < 4 ) {
    R = PrabhupadaLoginWindow->exec();
    if ( R == QDialog::Accepted ) {
      QSqlDatabase DB = QSqlDatabase::addDatabase( PrabhupadaLoginWindow->m_DriverName, "PrabhupadaDB" );
      if ( PrabhupadaLoginWindow->Connect( &DB ) ) {
        // Prepare AStorage
        AStorage.SetDatabase( &DB );
        AStorage.m_Schema = PrabhupadaLoginWindow->m_Schema;
        // Подготавливаем APrabhupadaDictionary
        APrabhupadaDictionary.m_DB = &DB;
        APrabhupadaDictionary.m_Schema = AStorage.m_Schema;
        // Reset settings in DB, if need!
        if ( PrabhupadaLoginWindow->m_ui->CheckBoxResetSettings->isChecked() ) {
          AStorage.ResetSettings();
        }
        AStorage.LoadObject( &APrabhupadaDictionary, QStorageKind::DB );
        QPrabhupadaDictionaryWindow PrabhupadaDictionaryWindow = QPrabhupadaDictionaryWindow( &APrabhupadaDictionary );
        PrabhupadaDictionaryWindow.m_StorageKind = QStorageKind::DB;
        PrabhupadaDictionaryWindow.m_Storage = &AStorage;
        PrabhupadaDictionaryWindow.PrepareDictionary();
        AStorage.LoadObject( &PrabhupadaDictionaryWindow, PrabhupadaDictionaryWindow.m_StorageKind );
        PrabhupadaDictionaryWindow.FirstShow();
        AStorage.SaveObject( PrabhupadaLoginWindow, QStorageKind::File );

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
