/********************************************************************************
** Form generated from reading the UI file 'QPrabhupadaLoginWindow.ui'
**
** Created by: CopperSpice User Interface Compiler, Version 1.8.1
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
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
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
    QLabel *LabelDatabaseName;
    QComboBox *ComboBoxDatabaseName;
    QLabel *LabelHostName;
    QComboBox *ComboBoxHostName;
    QLabel *LabelPort;
    QComboBox *ComboBoxPort;
    QLabel *LabelSchema;
    QComboBox *ComboBoxSchema;
    QCheckBox *CheckBoxResetSettings;
    QLabel *LabelLanguageUI;
    QComboBox *ComboBoxLanguageUI;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_2;

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
        QPrabhupadaLoginWindow->resize(263, 285);
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

        LabelDatabaseName = new QLabel(QPrabhupadaLoginWindow);
        LabelDatabaseName->setObjectName(QString::fromUtf8("LabelDatabaseName"));

        LayoutConnection->setWidget(2, QFormLayout::LabelRole, LabelDatabaseName);

        ComboBoxDatabaseName = new QComboBox(QPrabhupadaLoginWindow);
        ComboBoxDatabaseName->setObjectName(QString::fromUtf8("ComboBoxDatabaseName"));
        ComboBoxDatabaseName->setProperty("editable", QVariant(true));

        LayoutConnection->setWidget(2, QFormLayout::FieldRole, ComboBoxDatabaseName);

        LabelHostName = new QLabel(QPrabhupadaLoginWindow);
        LabelHostName->setObjectName(QString::fromUtf8("LabelHostName"));

        LayoutConnection->setWidget(3, QFormLayout::LabelRole, LabelHostName);

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

        LabelSchema = new QLabel(QPrabhupadaLoginWindow);
        LabelSchema->setObjectName(QString::fromUtf8("LabelSchema"));

        LayoutConnection->setWidget(5, QFormLayout::LabelRole, LabelSchema);

        ComboBoxSchema = new QComboBox(QPrabhupadaLoginWindow);
        ComboBoxSchema->setObjectName(QString::fromUtf8("ComboBoxSchema"));
        ComboBoxSchema->setProperty("editable", QVariant(true));

        LayoutConnection->setWidget(5, QFormLayout::FieldRole, ComboBoxSchema);

        CheckBoxResetSettings = new QCheckBox(QPrabhupadaLoginWindow);
        CheckBoxResetSettings->setObjectName(QString::fromUtf8("CheckBoxResetSettings"));

        LayoutConnection->setWidget(6, QFormLayout::FieldRole, CheckBoxResetSettings);

        LabelLanguageUI = new QLabel(QPrabhupadaLoginWindow);
        LabelLanguageUI->setObjectName(QString::fromUtf8("LabelLanguageUI"));

        LayoutConnection->setWidget(7, QFormLayout::LabelRole, LabelLanguageUI);

        ComboBoxLanguageUI = new QComboBox(QPrabhupadaLoginWindow);
        ComboBoxLanguageUI->setObjectName(QString::fromUtf8("ComboBoxLanguageUI"));

        LayoutConnection->setWidget(7, QFormLayout::FieldRole, ComboBoxLanguageUI);


        LayoutPrabhupadaLogin->addLayout(LayoutConnection);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonOK = new QPushButton(QPrabhupadaLoginWindow);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setProperty("default", QVariant(true));

        horizontalLayout->addWidget(pushButtonOK);

        pushButtonCancel = new QPushButton(QPrabhupadaLoginWindow);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setProperty("autoDefault", QVariant(true));

        horizontalLayout->addWidget(pushButtonCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        LayoutPrabhupadaLogin->addLayout(horizontalLayout);

        QWidget::setTabOrder(radioButtonSQLite, radioButtonPostgreSQL);
        QWidget::setTabOrder(radioButtonPostgreSQL, ComboBoxUserName);
        QWidget::setTabOrder(ComboBoxUserName, LineEditPassword);
        QWidget::setTabOrder(LineEditPassword, ComboBoxDatabaseName);
        QWidget::setTabOrder(ComboBoxDatabaseName, ComboBoxHostName);
        QWidget::setTabOrder(ComboBoxHostName, ComboBoxPort);
        QWidget::setTabOrder(ComboBoxPort, ComboBoxSchema);
        QWidget::setTabOrder(ComboBoxSchema, CheckBoxResetSettings);

        retranslateUi(QPrabhupadaLoginWindow);

        QMetaObject::connectSlotsByName(QPrabhupadaLoginWindow);
    }  // setupUi

    void retranslateUi(QDialog *QPrabhupadaLoginWindow)
    {
        QPrabhupadaLoginWindow->setProperty("windowTitle", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\222\321\205\320\276\320\264 \320\262 \"\320\241\320\273\320\276\320\262\320\260\321\200\321\214 \320\250\321\200\320\270\320\273\321\213 \320\237\321\200\320\260\320\261\321\205\321\203\320\277\320\260\320\264\321\213\"", nullptr)));
        radioButtonSQLite->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "SQLite", nullptr)));
        radioButtonPostgreSQL->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "PostgreSQL", nullptr)));
        LabelUserName->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr)));
        LabelPassword->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr)));
        LabelDatabaseName->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\230\320\274\321\217 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr)));
        LabelHostName->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\241\320\265\321\200\320\262\320\265\321\200", nullptr)));
        LabelPort->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\237\320\276\321\200\321\202", nullptr)));
        LabelSchema->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\241\321\205\320\265\320\274\320\260", nullptr)));
        CheckBoxResetSettings->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr)));
#ifndef QT_NO_WHATSTHIS
        CheckBoxResetSettings->setProperty("whatsThis", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "<html><head/><body><p>\320\255\321\202\320\276\321\202 \321\204\320\273\320\260\320\263 \321\201\320\261\321\200\320\260\321\201\321\213\320\262\320\260\320\265\321\202 \320\262\321\201\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217 \320\277\320\276\321\201\320\273\320\265 \320\262\321\205\320\276\320\264\320\260 \320\262 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203! \320\235\320\276 \321\202\320\276\320\273\321\214\320\272\320\276 \321\202\320\265 \320\270\320\267 \320\275\320\270\321\205, \320\272\320\276\321\202\320\276\321\200\321\213\320\265 \321\205\321\200\320\260\320\275\321\217\321\202\321\201\321\217 \320\262 \320\261\320\260\320\267\320\265 \320\264\320\260\320\275\320\275\321\213\321\205! \320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270, \321\205\321\200\320\260\320\275\321\217\321\211\320\270\320\265\321\201\321\217 \320"
                        "\262 \321\204\320\260\320\271\320\273\320\260\321\205 &quot;ini&quot; \321\201\320\261\321\200\320\260\321\201\321\213\320\262\320\260\320\271\321\202\320\265 \320\277\321\200\320\276\321\201\321\202\321\213\320\274 \321\203\320\264\320\260\320\273\320\265\320\275\320\270\320\265\320\274 \321\215\321\202\320\270\321\205 \321\204\320\260\320\271\320\273\320\276\320\262!</p></body></html>", nullptr)));
#endif
        LabelLanguageUI->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\257\320\267\321\213\320\272 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr)));
        pushButtonOK->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\237\320\276\320\265\321\205\320\260\320\273\320\270!", nullptr)));
        pushButtonCancel->setProperty("text", QVariant(QApplication::translate("QPrabhupadaLoginWindow", "\320\227\320\260\320\264\320\275\320\270\320\271 \321\205\320\276\320\264!", nullptr)));
    }  // retranslateUi

};

namespace Ui {
    class QPrabhupadaLoginWindow : public Ui_QPrabhupadaLoginWindow {};
}  // namespace Ui

#endif // UI_QPRABHUPADALOGINWINDOW_H
