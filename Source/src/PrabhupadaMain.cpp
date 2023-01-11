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

#include <PrabhupadaLoginWindow.h>
#include <PrabhupadaDictionaryWindow.h>

#include <QApplication>
#include <QPrabhupadaStorage.h>
#include <PrabhupadaUtil.h>

int main( int argc, char *argv[] )
{
  QApplication app( argc, argv );
  QApplication::setApplicationDisplayName( "Prabhupada Dictionary!" );

  PrabhupadaLoginWindow *PrabhupadaLogin = new PrabhupadaLoginWindow();

  PrabhupadaLogin->m_ui->ComboBoxUserName->setEditText( "Navadvipa Chandra das" );
  PrabhupadaLogin->m_ui->ComboBoxDatabaseName->setEditText( "NewNavadvipa" );
  PrabhupadaLogin->m_ui->ComboBoxHostName->setEditText( "127.0.0.1" );
  PrabhupadaLogin->m_ui->ComboBoxPort->setEditText( QString::number( 5432 ) );

  QPrabhupadaStorage APrabhupadaStorage;
  APrabhupadaStorage.LoadObject( PrabhupadaLogin );

  int R, N = 0;
  while ( ++N < 4 ) {
    R = PrabhupadaLogin->exec();
    if ( R == QDialog::Accepted ) {
      QSqlDatabase DB = QSqlDatabase::addDatabase( PrabhupadaLogin->DriverName(), "PrabhupadaDB" );
      if ( PrabhupadaLogin->Connect( &DB ) ) {
        PrabhupadaDictionaryWindow PrabhupadaDictionary;
        PrabhupadaDictionary.setPrabhupadaStorage( &APrabhupadaStorage );
        APrabhupadaStorage.LoadObject( &PrabhupadaDictionary );
        PrabhupadaDictionary.show();
        if ( DB.open() ) {
          APrabhupadaStorage.SaveObject( PrabhupadaLogin );
          delete PrabhupadaLogin;
          APrabhupadaStorage.setDatabase( &DB );
          return app.exec();
        }
      }
    } else
      break;
  }
  delete PrabhupadaLogin;
  return 0;
}
