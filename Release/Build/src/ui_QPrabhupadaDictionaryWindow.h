/********************************************************************************
** Form generated from reading the UI file 'QPrabhupadaDictionaryWindow.ui'
**
** Created by: CopperSpice User Interface Compiler, Version 1.8.1
**
** WARNING! Any changes made to this file will be lost when the UI file is recompiled
********************************************************************************/

#ifndef UI_QPRABHUPADADICTIONARYWINDOW_H
#define UI_QPRABHUPADADICTIONARYWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_QPrabhupadaDictionaryWindow
{
public:
    QAction *actionFind;
    QAction *actionCase_Sensitive;
    QAction *actionDelete;
    QAction *actionInsert;
    QAction *actionRemove_Duplicates;
    QAction *actionSet_Bookmark_0;
    QAction *actionSet_Bookmark_1;
    QAction *actionSet_Bookmark_2;
    QAction *actionSet_Bookmark_3;
    QAction *actionSet_Bookmark_4;
    QAction *actionSet_Bookmark_5;
    QAction *actionSet_Bookmark_6;
    QAction *actionSet_Bookmark_7;
    QAction *actionSet_Bookmark_8;
    QAction *actionSet_Bookmark_9;
    QAction *actionGo_to_ookmark_0;
    QAction *actionGo_to_bookmark_1;
    QAction *actionGo_to_bookmark_2;
    QAction *actionGo_to_bookmark_3;
    QAction *actionGo_to_bookmark_4;
    QAction *actionGo_to_bookmark_5;
    QAction *actionGo_to_bookmark_6;
    QAction *actionGo_to_bookmark_7;
    QAction *actionGo_to_bookmark_8;
    QAction *actionGo_to_bookmark_9;
    QAction *actionWhats_This_mode;
    QAction *actionGoToRow;
    QAction *actionAbout;
    QAction *ActionSaveYazykVectorToFile;
    QAction *ActionSaveAllBukvaToFile;
    QWidget *centralwidget;
    QVBoxLayout *vlPrabhuadaMain;
    QHBoxLayout *horizontalLayoutLanguage;
    QSpinBox *sbFontSize;
    QComboBox *ComboBoxLanguage;
    QComboBox *ComboBoxLanguageUI;
    QHBoxLayout *horizontalLayoutRow;
    QLineEdit *lineEditRowIndicator;
    QVBoxLayout *vlDictionary;
    QTableView *tbvPrabhupadaDictionary;
    QSplitter *splSanskritTranslate;
    QComboBox *ComboBoxSanskrit;
    QComboBox *ComboBoxTranslate;
    QMenuBar *mbPrabupadaDictionary;
    QMenu *menuAction;
    QMenu *menuSet_Bookmark;
    QMenu *menuGo_Bookmarks;
    QToolBar *tbPrabhupada;

    void setupUi(QMainWindow *QPrabhupadaDictionaryWindow)
    {
        if (QPrabhupadaDictionaryWindow->objectName().isEmpty())
            QPrabhupadaDictionaryWindow->setObjectName(QString::fromUtf8("QPrabhupadaDictionaryWindow"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/resources/PrabhupadaDictionary.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QPrabhupadaDictionaryWindow->setProperty("windowIcon", QVariant(icon));
        QPrabhupadaDictionaryWindow->setProperty("minimumSize", QVariant(QSize(320, 480)));
        QPrabhupadaDictionaryWindow->resize(320, 480);
        actionFind = new QAction(QPrabhupadaDictionaryWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        actionFind->setProperty("iconVisibleInMenu", QVariant(true));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ToolButton/resources/Find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setProperty("icon", QVariant(icon1));
        actionCase_Sensitive = new QAction(QPrabhupadaDictionaryWindow);
        actionCase_Sensitive->setObjectName(QString::fromUtf8("actionCase_Sensitive"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ToolButton/resources/Case_Sensitive.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCase_Sensitive->setProperty("icon", QVariant(icon2));
        actionCase_Sensitive->setProperty("checkable", QVariant(true));
        actionDelete = new QAction(QPrabhupadaDictionaryWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ToolButton/resources/Delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setProperty("icon", QVariant(icon3));
        actionInsert = new QAction(QPrabhupadaDictionaryWindow);
        actionInsert->setObjectName(QString::fromUtf8("actionInsert"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/ToolButton/resources/Insert.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInsert->setProperty("icon", QVariant(icon4));
        actionRemove_Duplicates = new QAction(QPrabhupadaDictionaryWindow);
        actionRemove_Duplicates->setObjectName(QString::fromUtf8("actionRemove_Duplicates"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/ToolButton/resources/RemoveDuplicates.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove_Duplicates->setProperty("icon", QVariant(icon5));
        actionSet_Bookmark_0 = new QAction(QPrabhupadaDictionaryWindow);
        actionSet_Bookmark_0->setObjectName(QString::fromUtf8("actionSet_Bookmark_0"));
        actionSet_Bookmark_1 = new QAction(QPrabhupadaDictionaryWindow);
        actionSet_Bookmark_1->setObjectName(QString::fromUtf8("actionSet_Bookmark_1"));
        actionSet_Bookmark_2 = new QAction(QPrabhupadaDictionaryWindow);
        actionSet_Bookmark_2->setObjectName(QString::fromUtf8("actionSet_Bookmark_2"));
        actionSet_Bookmark_3 = new QAction(QPrabhupadaDictionaryWindow);
        actionSet_Bookmark_3->setObjectName(QString::fromUtf8("actionSet_Bookmark_3"));
        actionSet_Bookmark_4 = new QAction(QPrabhupadaDictionaryWindow);
        actionSet_Bookmark_4->setObjectName(QString::fromUtf8("actionSet_Bookmark_4"));
        actionSet_Bookmark_5 = new QAction(QPrabhupadaDictionaryWindow);
        actionSet_Bookmark_5->setObjectName(QString::fromUtf8("actionSet_Bookmark_5"));
        actionSet_Bookmark_6 = new QAction(QPrabhupadaDictionaryWindow);
        actionSet_Bookmark_6->setObjectName(QString::fromUtf8("actionSet_Bookmark_6"));
        actionSet_Bookmark_7 = new QAction(QPrabhupadaDictionaryWindow);
        actionSet_Bookmark_7->setObjectName(QString::fromUtf8("actionSet_Bookmark_7"));
        actionSet_Bookmark_8 = new QAction(QPrabhupadaDictionaryWindow);
        actionSet_Bookmark_8->setObjectName(QString::fromUtf8("actionSet_Bookmark_8"));
        actionSet_Bookmark_9 = new QAction(QPrabhupadaDictionaryWindow);
        actionSet_Bookmark_9->setObjectName(QString::fromUtf8("actionSet_Bookmark_9"));
        actionGo_to_ookmark_0 = new QAction(QPrabhupadaDictionaryWindow);
        actionGo_to_ookmark_0->setObjectName(QString::fromUtf8("actionGo_to_ookmark_0"));
        actionGo_to_bookmark_1 = new QAction(QPrabhupadaDictionaryWindow);
        actionGo_to_bookmark_1->setObjectName(QString::fromUtf8("actionGo_to_bookmark_1"));
        actionGo_to_bookmark_2 = new QAction(QPrabhupadaDictionaryWindow);
        actionGo_to_bookmark_2->setObjectName(QString::fromUtf8("actionGo_to_bookmark_2"));
        actionGo_to_bookmark_3 = new QAction(QPrabhupadaDictionaryWindow);
        actionGo_to_bookmark_3->setObjectName(QString::fromUtf8("actionGo_to_bookmark_3"));
        actionGo_to_bookmark_4 = new QAction(QPrabhupadaDictionaryWindow);
        actionGo_to_bookmark_4->setObjectName(QString::fromUtf8("actionGo_to_bookmark_4"));
        actionGo_to_bookmark_5 = new QAction(QPrabhupadaDictionaryWindow);
        actionGo_to_bookmark_5->setObjectName(QString::fromUtf8("actionGo_to_bookmark_5"));
        actionGo_to_bookmark_6 = new QAction(QPrabhupadaDictionaryWindow);
        actionGo_to_bookmark_6->setObjectName(QString::fromUtf8("actionGo_to_bookmark_6"));
        actionGo_to_bookmark_7 = new QAction(QPrabhupadaDictionaryWindow);
        actionGo_to_bookmark_7->setObjectName(QString::fromUtf8("actionGo_to_bookmark_7"));
        actionGo_to_bookmark_8 = new QAction(QPrabhupadaDictionaryWindow);
        actionGo_to_bookmark_8->setObjectName(QString::fromUtf8("actionGo_to_bookmark_8"));
        actionGo_to_bookmark_9 = new QAction(QPrabhupadaDictionaryWindow);
        actionGo_to_bookmark_9->setObjectName(QString::fromUtf8("actionGo_to_bookmark_9"));
        actionWhats_This_mode = new QAction(QPrabhupadaDictionaryWindow);
        actionWhats_This_mode->setObjectName(QString::fromUtf8("actionWhats_This_mode"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/ToolButton/resources/WhatsThis.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWhats_This_mode->setProperty("icon", QVariant(icon6));
        actionGoToRow = new QAction(QPrabhupadaDictionaryWindow);
        actionGoToRow->setObjectName(QString::fromUtf8("actionGoToRow"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/ToolButton/resources/GoToRow.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGoToRow->setProperty("icon", QVariant(icon7));
        actionAbout = new QAction(QPrabhupadaDictionaryWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/ToolButton/resources/About.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setProperty("icon", QVariant(icon8));
        ActionSaveYazykVectorToFile = new QAction(QPrabhupadaDictionaryWindow);
        ActionSaveYazykVectorToFile->setObjectName(QString::fromUtf8("ActionSaveYazykVectorToFile"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/ToolButton/resources/SaveLang.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionSaveYazykVectorToFile->setProperty("icon", QVariant(icon9));
        ActionSaveAllBukvaToFile = new QAction(QPrabhupadaDictionaryWindow);
        ActionSaveAllBukvaToFile->setObjectName(QString::fromUtf8("ActionSaveAllBukvaToFile"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/ToolButton/resources/SaveBukva.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionSaveAllBukvaToFile->setProperty("icon", QVariant(icon10));
        centralwidget = new QWidget(QPrabhupadaDictionaryWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        vlPrabhuadaMain = new QVBoxLayout(centralwidget);
        vlPrabhuadaMain->setObjectName(QString::fromUtf8("vlPrabhuadaMain"));
        horizontalLayoutLanguage = new QHBoxLayout();
        horizontalLayoutLanguage->setObjectName(QString::fromUtf8("horizontalLayoutLanguage"));
        sbFontSize = new QSpinBox(centralwidget);
        sbFontSize->setObjectName(QString::fromUtf8("sbFontSize"));
        sbFontSize->setProperty("value", QVariant(14));
        sbFontSize->setProperty("minimum", QVariant(14));
        sbFontSize->setProperty("maximum", QVariant(24));
        sbFontSize->setProperty("alignment", QVariant(Qt::AlignCenter));
        sbFontSize->setProperty("focusPolicy", QVariant(Qt::WheelFocus));

        horizontalLayoutLanguage->addWidget(sbFontSize);

        ComboBoxLanguage = new QComboBox(centralwidget);
        ComboBoxLanguage->setObjectName(QString::fromUtf8("ComboBoxLanguage"));
        ComboBoxLanguage->setProperty("focusPolicy", QVariant(Qt::WheelFocus));

        horizontalLayoutLanguage->addWidget(ComboBoxLanguage);

        ComboBoxLanguageUI = new QComboBox(centralwidget);
        ComboBoxLanguageUI->setObjectName(QString::fromUtf8("ComboBoxLanguageUI"));
        ComboBoxLanguageUI->setProperty("focusPolicy", QVariant(Qt::WheelFocus));

        horizontalLayoutLanguage->addWidget(ComboBoxLanguageUI);

        horizontalLayoutLanguage->setStretch(0, 1);
        horizontalLayoutLanguage->setStretch(1, 3);
        horizontalLayoutLanguage->setStretch(2, 3);

        vlPrabhuadaMain->addLayout(horizontalLayoutLanguage);

        horizontalLayoutRow = new QHBoxLayout();
        horizontalLayoutRow->setObjectName(QString::fromUtf8("horizontalLayoutRow"));
        lineEditRowIndicator = new QLineEdit(centralwidget);
        lineEditRowIndicator->setObjectName(QString::fromUtf8("lineEditRowIndicator"));
        lineEditRowIndicator->setProperty("readOnly", QVariant(true));
        lineEditRowIndicator->setProperty("alignment", QVariant(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter));
        lineEditRowIndicator->setProperty("focusPolicy", QVariant(Qt::NoFocus));

        horizontalLayoutRow->addWidget(lineEditRowIndicator);


        vlPrabhuadaMain->addLayout(horizontalLayoutRow);

        vlDictionary = new QVBoxLayout();
        vlDictionary->setObjectName(QString::fromUtf8("vlDictionary"));
        tbvPrabhupadaDictionary = new QTableView(centralwidget);
        tbvPrabhupadaDictionary->setObjectName(QString::fromUtf8("tbvPrabhupadaDictionary"));
        tbvPrabhupadaDictionary->setProperty("sortingEnabled", QVariant(true));
        QFont font;
        font.setFamily(QString::fromUtf8("Gaura Times"));
        font.setPointSize(14);
        tbvPrabhupadaDictionary->setProperty("font", QVariant(font));
        tbvPrabhupadaDictionary->horizontalHeader()->setProperty("cascadingSectionResizes", QVariant(false));
        tbvPrabhupadaDictionary->horizontalHeader()->setProperty("stretchLastSection", QVariant(false));

        vlDictionary->addWidget(tbvPrabhupadaDictionary);

        splSanskritTranslate = new QSplitter(centralwidget);
        splSanskritTranslate->setObjectName(QString::fromUtf8("splSanskritTranslate"));
        splSanskritTranslate->setProperty("orientation", QVariant(Qt::Horizontal));
        splSanskritTranslate->setProperty("childrenCollapsible", QVariant(false));
        ComboBoxSanskrit = new QComboBox(splSanskritTranslate);
        ComboBoxSanskrit->setObjectName(QString::fromUtf8("ComboBoxSanskrit"));
        ComboBoxSanskrit->setProperty("editable", QVariant(true));
        ComboBoxSanskrit->setProperty("font", QVariant(font));
        splSanskritTranslate->addWidget(ComboBoxSanskrit);
        ComboBoxTranslate = new QComboBox(splSanskritTranslate);
        ComboBoxTranslate->setObjectName(QString::fromUtf8("ComboBoxTranslate"));
        ComboBoxTranslate->setProperty("editable", QVariant(true));
        ComboBoxTranslate->setProperty("font", QVariant(font));
        splSanskritTranslate->addWidget(ComboBoxTranslate);

        vlDictionary->addWidget(splSanskritTranslate);


        vlPrabhuadaMain->addLayout(vlDictionary);

        QPrabhupadaDictionaryWindow->setCentralWidget(centralwidget);
        mbPrabupadaDictionary = new QMenuBar(QPrabhupadaDictionaryWindow);
        mbPrabupadaDictionary->setObjectName(QString::fromUtf8("mbPrabupadaDictionary"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mbPrabupadaDictionary->sizePolicy().hasHeightForWidth());
        mbPrabupadaDictionary->setProperty("sizePolicy", QVariant(sizePolicy));
        mbPrabupadaDictionary->setProperty("geometry", QVariant(QRect(0, 0, 320, 21)));
        menuAction = new QMenu(mbPrabupadaDictionary);
        menuAction->setObjectName(QString::fromUtf8("menuAction"));
        menuSet_Bookmark = new QMenu(mbPrabupadaDictionary);
        menuSet_Bookmark->setObjectName(QString::fromUtf8("menuSet_Bookmark"));
        menuGo_Bookmarks = new QMenu(mbPrabupadaDictionary);
        menuGo_Bookmarks->setObjectName(QString::fromUtf8("menuGo_Bookmarks"));
        QPrabhupadaDictionaryWindow->setMenuBar(mbPrabupadaDictionary);
        tbPrabhupada = new QToolBar(QPrabhupadaDictionaryWindow);
        tbPrabhupada->setObjectName(QString::fromUtf8("tbPrabhupada"));
        tbPrabhupada->setProperty("toolButtonStyle", QVariant(Qt::ToolButtonFollowStyle));
        tbPrabhupada->setProperty("orientation", QVariant(Qt::Horizontal));
        tbPrabhupada->setProperty("floatable", QVariant(true));
        QPrabhupadaDictionaryWindow->addToolBar(Qt::TopToolBarArea, tbPrabhupada);
        QWidget::setTabOrder(sbFontSize, ComboBoxLanguage);
        QWidget::setTabOrder(ComboBoxLanguage, ComboBoxLanguageUI);
        QWidget::setTabOrder(ComboBoxLanguageUI, lineEditRowIndicator);
        QWidget::setTabOrder(lineEditRowIndicator, tbvPrabhupadaDictionary);
        QWidget::setTabOrder(tbvPrabhupadaDictionary, ComboBoxSanskrit);
        QWidget::setTabOrder(ComboBoxSanskrit, ComboBoxTranslate);

        mbPrabupadaDictionary->addAction(menuAction->menuAction());
        mbPrabupadaDictionary->addAction(menuSet_Bookmark->menuAction());
        mbPrabupadaDictionary->addAction(menuGo_Bookmarks->menuAction());
        menuAction->addAction(actionFind);
        menuAction->addAction(actionCase_Sensitive);
        menuAction->addAction(actionDelete);
        menuAction->addAction(actionInsert);
        menuAction->addAction(actionRemove_Duplicates);
        menuAction->addAction(actionWhats_This_mode);
        menuAction->addAction(actionGoToRow);
        menuAction->addAction(actionAbout);
        menuAction->addAction(ActionSaveYazykVectorToFile);
        menuAction->addAction(ActionSaveAllBukvaToFile);
        menuSet_Bookmark->addAction(actionSet_Bookmark_0);
        menuSet_Bookmark->addAction(actionSet_Bookmark_1);
        menuSet_Bookmark->addAction(actionSet_Bookmark_2);
        menuSet_Bookmark->addAction(actionSet_Bookmark_3);
        menuSet_Bookmark->addAction(actionSet_Bookmark_4);
        menuSet_Bookmark->addAction(actionSet_Bookmark_5);
        menuSet_Bookmark->addAction(actionSet_Bookmark_6);
        menuSet_Bookmark->addAction(actionSet_Bookmark_7);
        menuSet_Bookmark->addAction(actionSet_Bookmark_8);
        menuSet_Bookmark->addAction(actionSet_Bookmark_9);
        menuGo_Bookmarks->addAction(actionGo_to_ookmark_0);
        menuGo_Bookmarks->addAction(actionGo_to_bookmark_1);
        menuGo_Bookmarks->addAction(actionGo_to_bookmark_2);
        menuGo_Bookmarks->addAction(actionGo_to_bookmark_3);
        menuGo_Bookmarks->addAction(actionGo_to_bookmark_4);
        menuGo_Bookmarks->addAction(actionGo_to_bookmark_5);
        menuGo_Bookmarks->addAction(actionGo_to_bookmark_6);
        menuGo_Bookmarks->addAction(actionGo_to_bookmark_7);
        menuGo_Bookmarks->addAction(actionGo_to_bookmark_8);
        menuGo_Bookmarks->addAction(actionGo_to_bookmark_9);
        tbPrabhupada->addAction(actionDelete);
        tbPrabhupada->addAction(actionFind);
        tbPrabhupada->addAction(actionInsert);
        tbPrabhupada->addAction(actionWhats_This_mode);
        tbPrabhupada->addAction(actionCase_Sensitive);
        tbPrabhupada->addAction(actionRemove_Duplicates);
        tbPrabhupada->addAction(actionGoToRow);
        tbPrabhupada->addAction(actionAbout);

        retranslateUi(QPrabhupadaDictionaryWindow);

        QMetaObject::connectSlotsByName(QPrabhupadaDictionaryWindow);
    }  // setupUi

    void retranslateUi(QMainWindow *QPrabhupadaDictionaryWindow)
    {
        QPrabhupadaDictionaryWindow->setProperty("windowTitle", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\241\320\273\320\276\320\262\320\260\321\200\321\214 \320\250\321\200\320\270\320\273\321\213 \320\237\321\200\320\260\320\261\321\205\321\203\320\277\320\260\320\264\321\213", nullptr)));
#ifndef QT_NO_WHATSTHIS
        QPrabhupadaDictionaryWindow->setProperty("whatsThis", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\241\320\273\320\276\320\262\320\260\321\200\321\214 \320\225\320\263\320\276 \320\221\320\276\320\266\320\265\321\201\321\202\320\262\320\265\320\275\320\275\320\276\320\271 \320\234\320\270\320\273\320\276\321\201\321\202\320\270 \320\276\321\201\320\275\320\276\320\262\320\260\321\202\320\265\320\273\321\217-\320\260\321\207\320\260\321\200\321\214\320\270 \320\234\320\265\320\266\320\264\321\203\320\275\320\260\321\200\320\276\320\264\320\275\320\276\320\263\320\276 \320\236\320\261\321\211\320\265\321\201\321\202\320\262\320\260 \321\201\320\276\320"
                        "\267\320\275\320\260\320\275\320\270\321\217 \320\232\321\200\320\270\321\210\320\275\321\213 \320\250\321\200\320\270 \320\250\321\200\320\270\320\274\320\260\320\264 \320\220\320\261\321\205\320\260\321\217 \320\247\320\260\321\200\320\260\320\275\320\260\321\200\320\260\320\262\320\270\320\264\320\275\321\213 \320\221\321\205\320\260\320\272\321\202\320\270\320\262\320\265\320\264\320\260\320\275\321\202\321\213 \320\241\320\262\320\260\320\274\320\270 \320\237\321\200\320\260\320\261\321\205\321\203\320\277\320\260\320\264\321\213!<br />\320\237\320\276\320\267\320\275\320\260\320\272\320\276\320\274\320\270\321\202\321\214\321\201\321\217 \321\201 \320\265\320\263\320\276 \320\272\320\275\320\270\320\263\320\260\320\274\320\270 \320\274\320\276\320\266\320\275\320\276 \320\275\320\260 \321\201\320\260\320\271\321\202\320\265 <a href=\"https://vedabase.io\"><span style=\" text-decoration: underline; color:#0000ff;\">https://vedabase.io!</span></a></p></body></html>", nullptr)));
#endif
        actionFind->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "&\320\235\320\260\320\271\321\202\320\270", nullptr)));
        actionFind->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Ctrl+Return", nullptr)));
        actionFind->setProperty("iconText", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "&\320\235\320\260\320\271\321\202\320\270", nullptr)));
        actionCase_Sensitive->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "&\320\240\320\260\320\267\320\273\320\270\321\207\320\260\321\202\321\214 \321\200\320\265\320\263\320\270\321\201\321\202\321\200", nullptr)));
        actionCase_Sensitive->setProperty("iconText", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "&\320\240\320\260\320\267\320\273\320\270\321\207\320\260\321\202\321\214 \321\200\320\265\320\263\320\270\321\201\321\202\321\200", nullptr)));
        actionDelete->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "&\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr)));
        actionDelete->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Ctrl+Del", nullptr)));
        actionDelete->setProperty("iconText", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "&\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr)));
        actionInsert->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "&\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214", nullptr)));
        actionInsert->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Ctrl+Ins", nullptr)));
        actionInsert->setProperty("iconText", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "&\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214", nullptr)));
        actionRemove_Duplicates->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 &\320\264\321\203\320\261\320\273\320\270\320\272\320\260\321\202\321\213", nullptr)));
        actionRemove_Duplicates->setProperty("iconText", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 &\320\264\321\203\320\261\320\273\320\270\320\272\320\260\321\202\321\213", nullptr)));
        actionSet_Bookmark_0->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\321\203 &0", nullptr)));
        actionSet_Bookmark_0->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Ctrl+0", nullptr)));
        actionSet_Bookmark_1->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\321\203 &1", nullptr)));
        actionSet_Bookmark_1->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Ctrl+1", nullptr)));
        actionSet_Bookmark_2->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\321\203 &2", nullptr)));
        actionSet_Bookmark_2->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Ctrl+2", nullptr)));
        actionSet_Bookmark_3->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\321\203 &3", nullptr)));
        actionSet_Bookmark_3->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Ctrl+3", nullptr)));
        actionSet_Bookmark_4->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\321\203 &4", nullptr)));
        actionSet_Bookmark_4->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Ctrl+4", nullptr)));
        actionSet_Bookmark_5->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\321\203 &5", nullptr)));
        actionSet_Bookmark_5->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Ctrl+5", nullptr)));
        actionSet_Bookmark_6->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\321\203 &6", nullptr)));
        actionSet_Bookmark_6->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Ctrl+6", nullptr)));
        actionSet_Bookmark_7->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\321\203 &7", nullptr)));
        actionSet_Bookmark_7->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Ctrl+7", nullptr)));
        actionSet_Bookmark_8->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\321\203 &8", nullptr)));
        actionSet_Bookmark_8->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Ctrl+8", nullptr)));
        actionSet_Bookmark_9->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\321\203 &9", nullptr)));
        actionSet_Bookmark_9->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Ctrl+9", nullptr)));
        actionGo_to_ookmark_0->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\232 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\320\265 &0", nullptr)));
        actionGo_to_ookmark_0->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Alt+0", nullptr)));
        actionGo_to_bookmark_1->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\232 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\320\265 &1", nullptr)));
        actionGo_to_bookmark_1->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Alt+1", nullptr)));
        actionGo_to_bookmark_2->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\232 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\320\265 &2", nullptr)));
        actionGo_to_bookmark_2->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Alt+2", nullptr)));
        actionGo_to_bookmark_3->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\232 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\320\265 &3", nullptr)));
        actionGo_to_bookmark_3->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Alt+3", nullptr)));
        actionGo_to_bookmark_4->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\232 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\320\265 &4", nullptr)));
        actionGo_to_bookmark_4->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Alt+4", nullptr)));
        actionGo_to_bookmark_5->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\232 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\320\265 &5", nullptr)));
        actionGo_to_bookmark_5->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Alt+5", nullptr)));
        actionGo_to_bookmark_6->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\232 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\320\265 &6", nullptr)));
        actionGo_to_bookmark_6->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Alt+6", nullptr)));
        actionGo_to_bookmark_7->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\232 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\320\265 &7", nullptr)));
        actionGo_to_bookmark_7->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Alt+7", nullptr)));
        actionGo_to_bookmark_8->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\232 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\320\265 &8", nullptr)));
        actionGo_to_bookmark_8->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Alt+8", nullptr)));
        actionGo_to_bookmark_9->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\232 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\320\265 &9", nullptr)));
        actionGo_to_bookmark_9->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Alt+9", nullptr)));
        actionWhats_This_mode->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "&\320\240\320\265\320\266\320\270\320\274 \320\262\320\276\320\277\321\200\320\276\321\201\320\260", nullptr)));
        actionWhats_This_mode->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Ctrl+F1", nullptr)));
        actionWhats_This_mode->setProperty("iconText", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "&\320\240\320\265\320\266\320\270\320\274 \320\262\320\276\320\277\321\200\320\276\321\201\320\260", nullptr)));
        actionGoToRow->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "&\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \321\201\321\202\321\200\320\276\320\272\320\265", nullptr)));
        actionGoToRow->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "Ctrl+G", nullptr)));
        actionAbout->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "&\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr)));
        actionAbout->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "F1", nullptr)));
        actionAbout->setProperty("iconText", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "&\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr)));
        ActionSaveYazykVectorToFile->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\217\320\267\321\213\320\272\320\270 \320\262 \321\204\320\260\320\271\320\273", nullptr)));
        ActionSaveAllBukvaToFile->setProperty("text", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\261\321\203\320\272\320\262\321\213 \320\262 \321\204\320\260\320\271\320\273", nullptr)));
#ifndef QT_NO_TOOLTIP
        sbFontSize->setProperty("toolTip", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260", nullptr)));
#endif
#ifndef QT_NO_TOOLTIP
        ComboBoxLanguage->setProperty("toolTip", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\257\320\267\321\213\320\272 \321\201\320\273\320\276\320\262\320\260\321\200\321\217", nullptr)));
#endif
#ifndef QT_NO_TOOLTIP
        ComboBoxLanguageUI->setProperty("toolTip", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "<html><head/><body><p>\320\257\320\267\321\213\320\272 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213 \321\201\320\273\320\276\320\262\320\260\321\200\321\217<br/>\320\250\321\200\320\270\320\273\321\213 \320\237\321\200\320\260\320\261\321\205\321\203\320\277\320\260\320\264\321\213</p></body></html>", nullptr)));
#endif
#ifndef QT_NO_WHATSTHIS
        lineEditRowIndicator->setProperty("whatsThis", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "<html><head/><body><p>\320\230\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200, \320\272\320\276\321\202\320\276\321\200\321\213\320\271 \320\277\320\276\320\272\320\260\320\267\321\213\320\262\320\260\320\265\321\202 \320\275\320\276\320\274\320\265\321\200 \321\202\320\265\320\272\321\203\321\211\320\265\320\271 \321\201\321\202\321\200\320\276\320\272\320\270, \320\260 \321\202\320\260\320\272\320\266\320\265 \320\276\320\261\321\211\320\265\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\202\321\200\320\276\320\272 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\320\265!</p></body></html>", nullptr)));
#endif
#ifndef QT_NO_TOOLTIP
        lineEditRowIndicator->setProperty("toolTip", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260 / \320\262\321\201\320\265\320\263\320\276 \321\201\321\202\321\200\320\276\320\272", nullptr)));
#endif
#ifndef QT_NO_WHATSTHIS
        ComboBoxSanskrit->setProperty("whatsThis", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "<html><head/><body><p>\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \321\201\320\260\320\275\321\201\320\272\321\200\320\270\321\202\321\203!</p><p>\320\234\320\276\320\266\320\275\320\276 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214 \321\200\320\265\320\263\321\203\320\273\321\217\321\200\320\275\321\213\320\265 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\270\321\217!</p></body></html>", nullptr)));
#endif
#ifndef QT_NO_TOOLTIP
        ComboBoxSanskrit->setProperty("toolTip", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "<html><head/><body><p>\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \321\201\320\260\320\275\321\201\320\272\321\200\320\270\321\202\321\203!</p></body></html>", nullptr)));
#endif
#ifndef QT_NO_WHATSTHIS
        ComboBoxTranslate->setProperty("whatsThis", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "<html><head/><body><p>\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\277\320\265\321\200\320\265\320\262\320\276\320\264\321\203!</p><p>\320\234\320\276\320\266\320\275\320\276 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214 \321\200\320\265\320\263\321\203\320\273\321\217\321\200\320\275\321\213\320\265 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\270\321\217!</p></body></html>", nullptr)));
#endif
#ifndef QT_NO_TOOLTIP
        ComboBoxTranslate->setProperty("toolTip", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "<html><head/><body><p>\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\277\320\265\321\200\320\265\320\262\320\276\320\264\321\203!</p></body></html>", nullptr)));
#endif
        menuAction->setProperty("title", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "&\320\224\320\265\320\271\321\201\321\202\320\262\320\270\320\265", nullptr)));
        menuSet_Bookmark->setProperty("title", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "&\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\321\203", nullptr)));
        menuGo_Bookmarks->setProperty("title", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "&\320\232 \320\267\320\260\320\272\320\273\320\260\320\264\320\272\320\265", nullptr)));
        tbPrabhupada->setProperty("windowTitle", QVariant(QApplication::translate("QPrabhupadaDictionaryWindow", "toolBar", nullptr)));
    }  // retranslateUi

};

namespace Ui {
    class QPrabhupadaDictionaryWindow : public Ui_QPrabhupadaDictionaryWindow {};
}  // namespace Ui

#endif // UI_QPRABHUPADADICTIONARYWINDOW_H
