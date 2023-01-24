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
  QApplication::setApplicationDisplayName( QObject::tr( "Словарь Шрилы Прабхупады!" ) );

  QPrabhupadaLoginWindow *PrabhupadaLoginWindow = new QPrabhupadaLoginWindow();

  PrabhupadaLoginWindow->m_ui->ComboBoxUserName->setEditText( "Navadvipa Chandra das" );
  PrabhupadaLoginWindow->m_ui->ComboBoxDatabaseName->setEditText( "NewNavadvipa" );
  PrabhupadaLoginWindow->m_ui->ComboBoxHostName->setEditText( "127.0.0.1" );
  PrabhupadaLoginWindow->m_ui->ComboBoxPort->setEditText( QString::number( 5432 ) );
  PrabhupadaLoginWindow->m_ui->ComboBoxSchema->setEditText( "\"NewNavadvipa\"" );

  QPrabhupadaStorage APrabhupadaStorage;
  APrabhupadaStorage.LoadObject( PrabhupadaLoginWindow );

  int R, N = 0;
  while ( ++N < 4 ) {
    R = PrabhupadaLoginWindow->exec();
    if ( R == QDialog::Accepted ) {
      QSqlDatabase DB = QSqlDatabase::addDatabase( PrabhupadaLoginWindow->DriverName(), "PrabhupadaDB" );
      if ( PrabhupadaLoginWindow->Connect( &DB ) ) {
        QPrabhupadaDictionaryWindow PrabhupadaDictionaryWindow;
        PrabhupadaDictionaryWindow.m_PrabhupadaDictionary.m_Schema = PrabhupadaLoginWindow->Schema();
        PrabhupadaDictionaryWindow.setPrabhupadaStorage( &APrabhupadaStorage );
        PrabhupadaDictionaryWindow.PrepareDictionary( &DB );
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
