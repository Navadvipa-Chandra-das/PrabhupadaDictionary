/********************************************************************************
** Form generated from reading the UI file 'PrabhupadaLoginWindow.ui'
**
** Created by: CopperSpice User Interface Compiler, Version 1.8.0
**
** WARNING! Any changes made to this file will be lost when the UI file is recompiled
********************************************************************************/

#ifndef UI_PRABHUPADALOGINWINDOW_H
#define UI_PRABHUPADALOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>

class Ui_PrabhupadaLoginWindow
{
public:
    QVBoxLayout *LayoutPrabhupadaLogin;
    QHBoxLayout *LayoutSQL;
    QRadioButton *radioButtonSQLite;
    QRadioButton *radioButtonPostgreSQL;
    QFormLayout *LayoutConnection;
    QLabel *laUserName;
    QComboBox *ComboBoxUserName;
    QLabel *laPassword;
    QLineEdit *LineEditPassword;
    QLabel *laDatabase;
    QComboBox *ComboBoxDatabaseName;
    QLabel *laServer;
    QComboBox *ComboBoxHostName;
    QLabel *laPort;
    QComboBox *ComboBoxPort;
    QCheckBox *CheckBoxResetSettings;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PrabhupadaLoginWindow)
    {
        if (PrabhupadaLoginWindow->objectName().isEmpty())
            PrabhupadaLoginWindow->setObjectName(QString::fromUtf8("PrabhupadaLoginWindow"));
        PrabhupadaLoginWindow->setProperty("modal", QVariant(false));
        PrabhupadaLoginWindow->setProperty("windowModality", QVariant(Qt::NonModal));
        PrabhupadaLoginWindow->setProperty("mouseTracking", QVariant(false));
        PrabhupadaLoginWindow->resize(263, 255);
        LayoutPrabhupadaLogin = new QVBoxLayout(PrabhupadaLoginWindow);
        LayoutPrabhupadaLogin->setObjectName(QString::fromUtf8("LayoutPrabhupadaLogin"));
        LayoutSQL = new QHBoxLayout();
        LayoutSQL->setObjectName(QString::fromUtf8("LayoutSQL"));
        radioButtonSQLite = new QRadioButton(PrabhupadaLoginWindow);
        radioButtonSQLite->setObjectName(QString::fromUtf8("radioButtonSQLite"));

        LayoutSQL->addWidget(radioButtonSQLite);

        radioButtonPostgreSQL = new QRadioButton(PrabhupadaLoginWindow);
        radioButtonPostgreSQL->setObjectName(QString::fromUtf8("radioButtonPostgreSQL"));

        LayoutSQL->addWidget(radioButtonPostgreSQL);


        LayoutPrabhupadaLogin->addLayout(LayoutSQL);

        LayoutConnection = new QFormLayout();
        LayoutConnection->setObjectName(QString::fromUtf8("LayoutConnection"));
        laUserName = new QLabel(PrabhupadaLoginWindow);
        laUserName->setObjectName(QString::fromUtf8("laUserName"));

        LayoutConnection->setWidget(0, QFormLayout::LabelRole, laUserName);

        ComboBoxUserName = new QComboBox(PrabhupadaLoginWindow);
        ComboBoxUserName->setObjectName(QString::fromUtf8("ComboBoxUserName"));
        ComboBoxUserName->setProperty("editable", QVariant(true));

        LayoutConnection->setWidget(0, QFormLayout::FieldRole, ComboBoxUserName);

        laPassword = new QLabel(PrabhupadaLoginWindow);
        laPassword->setObjectName(QString::fromUtf8("laPassword"));

        LayoutConnection->setWidget(1, QFormLayout::LabelRole, laPassword);

        LineEditPassword = new QLineEdit(PrabhupadaLoginWindow);
        LineEditPassword->setObjectName(QString::fromUtf8("LineEditPassword"));
        LineEditPassword->setProperty("echoMode", QVariant(QLineEdit::Password));
        LineEditPassword->setProperty("clearButtonEnabled", QVariant(false));

        LayoutConnection->setWidget(1, QFormLayout::FieldRole, LineEditPassword);

        laDatabase = new QLabel(PrabhupadaLoginWindow);
        laDatabase->setObjectName(QString::fromUtf8("laDatabase"));

        LayoutConnection->setWidget(2, QFormLayout::LabelRole, laDatabase);

        ComboBoxDatabaseName = new QComboBox(PrabhupadaLoginWindow);
        ComboBoxDatabaseName->setObjectName(QString::fromUtf8("ComboBoxDatabaseName"));
        ComboBoxDatabaseName->setProperty("editable", QVariant(true));

        LayoutConnection->setWidget(2, QFormLayout::FieldRole, ComboBoxDatabaseName);

        laServer = new QLabel(PrabhupadaLoginWindow);
        laServer->setObjectName(QString::fromUtf8("laServer"));

        LayoutConnection->setWidget(3, QFormLayout::LabelRole, laServer);

        ComboBoxHostName = new QComboBox(PrabhupadaLoginWindow);
        ComboBoxHostName->setObjectName(QString::fromUtf8("ComboBoxHostName"));
        ComboBoxHostName->setProperty("editable", QVariant(true));

        LayoutConnection->setWidget(3, QFormLayout::FieldRole, ComboBoxHostName);

        laPort = new QLabel(PrabhupadaLoginWindow);
        laPort->setObjectName(QString::fromUtf8("laPort"));

        LayoutConnection->setWidget(4, QFormLayout::LabelRole, laPort);

        ComboBoxPort = new QComboBox(PrabhupadaLoginWindow);
        ComboBoxPort->setObjectName(QString::fromUtf8("ComboBoxPort"));
        ComboBoxPort->setProperty("editable", QVariant(true));

        LayoutConnection->setWidget(4, QFormLayout::FieldRole, ComboBoxPort);

        CheckBoxResetSettings = new QCheckBox(PrabhupadaLoginWindow);
        CheckBoxResetSettings->setObjectName(QString::fromUtf8("CheckBoxResetSettings"));

        LayoutConnection->setWidget(5, QFormLayout::FieldRole, CheckBoxResetSettings);


        LayoutPrabhupadaLogin->addLayout(LayoutConnection);

        buttonBox = new QDialogButtonBox(PrabhupadaLoginWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setProperty("standardButtons", QVariant(QDialogButtonBox::Cancel|QDialogButtonBox::FirstButton|QDialogButtonBox::Ok));
        buttonBox->setProperty("orientation", QVariant(Qt::Horizontal));

        LayoutPrabhupadaLogin->addWidget(buttonBox);


        retranslateUi(PrabhupadaLoginWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), PrabhupadaLoginWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PrabhupadaLoginWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(PrabhupadaLoginWindow);
    }  // setupUi

    void retranslateUi(QDialog *PrabhupadaLoginWindow)
    {
        PrabhupadaLoginWindow->setProperty("windowTitle", QVariant(QApplication::translate("PrabhupadaLoginWindow", "Dialog", nullptr)));
        radioButtonSQLite->setProperty("text", QVariant(QApplication::translate("PrabhupadaLoginWindow", "SQLite", nullptr)));
        radioButtonPostgreSQL->setProperty("text", QVariant(QApplication::translate("PrabhupadaLoginWindow", "PostgreSQL", nullptr)));
        laUserName->setProperty("text", QVariant(QApplication::translate("PrabhupadaLoginWindow", "User name", nullptr)));
        laPassword->setProperty("text", QVariant(QApplication::translate("PrabhupadaLoginWindow", "Password", nullptr)));
        laDatabase->setProperty("text", QVariant(QApplication::translate("PrabhupadaLoginWindow", "Database", nullptr)));
        laServer->setProperty("text", QVariant(QApplication::translate("PrabhupadaLoginWindow", "Server", nullptr)));
        laPort->setProperty("text", QVariant(QApplication::translate("PrabhupadaLoginWindow", "Port", nullptr)));
        CheckBoxResetSettings->setProperty("text", QVariant(QApplication::translate("PrabhupadaLoginWindow", "Reset settings", nullptr)));
#ifndef QT_NO_WHATSTHIS
        CheckBoxResetSettings->setProperty("whatsThis", QVariant(QApplication::translate("PrabhupadaLoginWindow", "<html><head/><body><p>This flag resets all settings made by the user!</p></body></html>", nullptr)));
#endif
    }  // retranslateUi

};

namespace Ui {
    class PrabhupadaLoginWindow : public Ui_PrabhupadaLoginWindow {};
}  // namespace Ui

#endif // UI_PRABHUPADALOGINWINDOW_H
