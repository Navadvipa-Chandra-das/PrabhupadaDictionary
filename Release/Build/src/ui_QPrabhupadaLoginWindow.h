/********************************************************************************
** Form generated from reading the UI file 'QPrabhupadaLoginWindow.ui'
**
** Created by: CopperSpice User Interface Compiler, Version 1.8.0
**
** WARNING! Any changes made to this file will be lost when the UI file is recompiled
********************************************************************************/

#ifndef UI_QPRABHUPADALOGINWINDOW_H
#define UI_QPRABHUPADALOGINWINDOW_H

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

class Ui_QPrabhupadaLoginWindow
{
public:
    QVBoxLayout *LayoutPrabhupadaLogin;
    QHBoxLayout *LayoutSQL;
    QRadioButton *radioButtonSQLite;
    QRadioButton *radioButtonPostgreSQL;
    QFormLayout *LayoutConnection;
    QLabel *LabelUserName;
    QComboBox *ComboBoxUserName;
    QLabel *LabelPassword;
    QLineEdit *LineEditPassword;
    QLabel *LabelDatabase;
    QComboBox *ComboBoxDatabaseName;
    QLabel *LabelServer;
    QComboBox *ComboBoxHostName;
    QLabel *LabelPort;
    QComboBox *ComboBoxPort;
    QCheckBox *CheckBoxResetSettings;
    QComboBox *ComboBoxSchema;
    QLabel *LabelSchema;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QPrabhupadaLoginWindow)
    {
        if (QPrabhupadaLoginWindow->objectName().isEmpty())
            QPrabhupadaLoginWindow->setObjectName(QString::fromUtf8("QPrabhupadaLoginWindow"));
        QPrabhupadaLoginWindow->setProperty("modal", QVariant(false));
        QPrabhupadaLoginWindow->setProperty("windowModality", QVariant(Qt::NonModal));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/resources/PrabhupadaDictionary.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QPrabhupadaLoginWindow->setProperty("windowIcon", QVariant(icon));
        QPrabhupadaLoginWindow->setProperty("mouseTracking", QVariant(false));
        QPrabhupadaLoginWindow->resize(263, 255);
        LayoutPrabhupadaLogin = new QVBoxLayout(QPrabhupadaLoginWindow);
        LayoutPrabhupadaLogin->setObjectName(QString::fromUtf8("LayoutPrabhupadaLogin"));
        LayoutSQL = new QHBoxLayout();
        LayoutSQL->setObjectName(QString::fromUtf8("LayoutSQL"));
        radioButtonSQLite = new QRadioButton(QPrabhupadaLoginWindow);
        radioButtonSQLite->setObjectName(QString::fromUtf8("radioButtonSQLite"));

        LayoutSQL->addWidget(radioButtonSQLite);

        radioButtonPostgreSQL = new QRadioButton(QPrabhupadaLoginWindow);
        radioButtonPostgreSQL->setObjectName(QString::fromUtf8("radioButtonPostgreSQL"));

        LayoutSQL->addWidget(radioButtonPostgreSQL);


        LayoutPrabhupadaLogin->addLayout(LayoutSQL);

        LayoutConnection = new QFormLayout();
        LayoutConnection->setObjectName(QString::fromUtf8("LayoutConnection"));
        LabelUserName = new QLabel(QPrabhupadaLoginWindow);
        LabelUserName->setObjectName(QString::fromUtf8("LabelUserName"));

        LayoutConnection->setWidget(0, QFormLayout::LabelRole, LabelUserName);

        ComboBoxUserName = new QComboBox(QPrabhupadaLoginWindow);
        ComboBoxUserName->setObjectName(QString::fromUtf8("ComboBoxUserName"));
        ComboBoxUserName->setProperty("editable", QVariant(true));

        LayoutConnection->setWidget(0, QFormLayout::FieldRole, ComboBoxUserName);

        LabelPassword = new QLabel(QPrabhupadaLoginWindow);
        LabelPassword->setObjectName(QString::fromUtf8("LabelPassword"));

        LayoutConnection->setWidget(1, QFormLayout::LabelRole, LabelPassword);

        LineEditPassword = new QLineEdit(QPrabhupadaLoginWindow);
        LineEditPassword->setObjectName(QString::fromUtf8("LineEditPassword"));
        LineEditPassword->setProperty("echoMode", QVariant(QLineEdit::Password));
        LineEditPassword->setProperty("clearButtonEnabled", QVariant(false));

        LayoutConnection->setWidget(1, QFormLayout::FieldRole, LineEditPassword);

        LabelDatabase = new QLabel(QPrabhupadaLoginWindow);
        LabelDatabase->setObjectName(QString::fromUtf8("LabelDatabase"));

        LayoutConnection->setWidget(2, QFormLayout::LabelRole, LabelDatabase);

        ComboBoxDatabaseName = new QComboBox(QPrabhupadaLoginWindow);
        ComboBoxDatabaseName->setObjectName(QString::fromUtf8("ComboBoxDatabaseName"));
        ComboBoxDatabaseName->setProperty("editable", QVariant(true));

        LayoutConnection->setWidget(2, QFormLayout::FieldRole, ComboBoxDatabaseName);

        LabelServer = new QLabel(QPrabhupadaLoginWindow);
        LabelServer->setObjectName(QString::fromUtf8("LabelServer"));

        LayoutConnection->setWidget(3, QFormLayout::LabelRole, LabelServer);

        ComboBoxHostName = new QComboBox(QPrabhupadaLoginWindow);
        ComboBoxHostName->setObjectName(QString::fromUtf8("ComboBoxHostName"));
        ComboBoxHostName->setProperty("editable", QVariant(true));

        LayoutConnection->setWidget(3, QFormLayout::FieldRole, ComboBoxHostName);

        LabelPort = new QLabel(QPrabhupadaLoginWindow);
        LabelPort->setObjectName(QString::fromUtf8("LabelPort"));

        LayoutConnection->setWidget(4, QFormLayout::LabelRole, LabelPort);

        ComboBoxPort = new QComboBox(QPrabhupadaLoginWindow);
        ComboBoxPort->setObjectName(QString::fromUtf8("ComboBoxPort"));
        ComboBoxPort->setProperty("editable", QVariant(true));

        LayoutConnection->setWidget(4, QFormLayout::FieldRole, ComboBoxPort);

        CheckBoxResetSettings = new QCheckBox(QPrabhupadaLoginWindow);
        CheckBoxResetSettings->setObjectName(QString::fromUtf8("CheckBoxResetSettings"));

        LayoutConnection->setWidget(6, QFormLayout::FieldRole, CheckBoxResetSettings);

        ComboBoxSchema = new QComboBox(QPrabhupadaLoginWindow);
        ComboBoxSchema->setObjectName(QString::fromUtf8("ComboBoxSchema"));
        ComboBoxSchema->setProperty("editable", QVariant(true));

        LayoutConnection->setWidget(5, QFormLayout::FieldRole, ComboBoxSchema);

        LabelSchema = new QLabel(QPrabhupadaLoginWindow);
        LabelSchema->setObjectName(QString::fromUtf8("LabelSchema"));

        LayoutConnection->setWidget(5, QFormLayout::LabelRole, LabelSchema);


        LayoutPrabhupadaLogin->addLayout(LayoutConnection);

        buttonBox = new QDialogButtonBox(QPrabhupadaLoginWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setProperty("standardButtons", QVariant(QDialogButtonBox::Cancel|QDialogButtonBox::FirstButton|QDialogButtonBox::Ok));
        buttonBox->setProperty("orientation", QVariant(Qt::Horizontal));

        LayoutPrabhupadaLogin->addWidget(buttonBox);

        QWidget::setTabOrder(radioButtonSQLite, radioButtonPostgreSQL);
        QWidget::setTabOrder(radioButtonPostgreSQL, ComboBoxUserName);
        QWidget::setTabOrder(ComboBoxUserName, LineEditPassword);
        QWidget::setTabOrder(LineEditPassword, ComboBoxDatabaseName);
        QWidget::setTabOrder(ComboBoxDatabaseName, ComboBoxHostName);
        QWidget::setTabOrder(ComboBoxHostName, ComboBoxPort);
        QWidget::setTabOrder(ComboBoxPort, ComboBoxSchema);
        QWidget::setTabOrder(ComboBoxSchema, CheckBoxResetSettings);

        retranslateUi(QPrabhupadaLoginWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), QPrabhupadaLoginWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QPrabhupadaLoginWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(QPrabhupadaLoginWindow);
    }  // setupUi

    void retranslateUi(QDialog *QPrabhupadaLoginWindow)
    {
        QPrabhupadaLoginWindow->setProperty("windowTitle", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\222\321\205\320\276\320\264 \320\262 \"\320\241\320\273\320\276\320\262\320\260\321\200\321\214 \320\250\321\200\320\270\320\273\321\213 \320\237\321\200\320\260\320\261\321\205\321\203\320\277\320\260\320\264\321\213\"", nullptr)));
        radioButtonSQLite->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "SQLite", nullptr)));
        radioButtonPostgreSQL->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "PostgreSQL", nullptr)));
        LabelUserName->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr)));
        LabelPassword->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr)));
        LabelDatabase->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\230\320\274\321\217 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr)));
        LabelServer->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\241\320\265\321\200\320\262\320\265\321\200", nullptr)));
        LabelPort->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\237\320\276\321\200\321\202", nullptr)));
        CheckBoxResetSettings->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr)));
#ifndef QT_NO_WHATSTHIS
        CheckBoxResetSettings->setProperty("whatsThis", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "<html><head/><body><p>This flag resets all settings made by the user!</p></body></html>", nullptr)));
#endif
        LabelSchema->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\241\321\205\320\265\320\274\320\260", nullptr)));
    }  // retranslateUi

};

namespace Ui {
    class QPrabhupadaLoginWindow : public Ui_QPrabhupadaLoginWindow {};
}  // namespace Ui

#endif // UI_QPRABHUPADALOGINWINDOW_H
