/********************************************************************************
** Form generated from reading the UI file 'PrabhupadaDictionaryWindow.ui'
**
** Created by: CopperSpice User Interface Compiler, Version 1.8.0
**
** WARNING! Any changes made to this file will be lost when the UI file is recompiled
********************************************************************************/

#ifndef UI_PRABHUPADADICTIONARYWINDOW_H
#define UI_PRABHUPADADICTIONARYWINDOW_H

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

class Ui_PrabhupadaDictionaryWindow
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
    QWidget *centralwidget;
    QVBoxLayout *vlPrabhuadaMain;
    QHBoxLayout *horizontalLayout;
    QSpinBox *sbFontSize;
    QComboBox *cbLanguage;
    QComboBox *cbLanguageUI;
    QVBoxLayout *vlDictionary;
    QTableView *tbvPrabhupadaDictionary;
    QSplitter *splSanskritTranslate;
    QLineEdit *leSanskrit;
    QLineEdit *leTranslate;
    QMenuBar *mbPrabupadaDictionary;
    QMenu *menuAction;
    QMenu *menuSet_Bookmark;
    QMenu *menuGo_Bookmarks;
    QToolBar *tbPrabhupada;

    void setupUi(QMainWindow *PrabhupadaDictionaryWindow)
    {
        if (PrabhupadaDictionaryWindow->objectName().isEmpty())
            PrabhupadaDictionaryWindow->setObjectName(QString::fromUtf8("PrabhupadaDictionaryWindow"));
        PrabhupadaDictionaryWindow->setProperty("minimumSize", QVariant(QSize(320, 480)));
        PrabhupadaDictionaryWindow->resize(320, 480);
        actionFind = new QAction(PrabhupadaDictionaryWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ToolButton/resources/Find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setProperty("icon", QVariant(icon));
        actionCase_Sensitive = new QAction(PrabhupadaDictionaryWindow);
        actionCase_Sensitive->setObjectName(QString::fromUtf8("actionCase_Sensitive"));
        actionCase_Sensitive->setProperty("checkable", QVariant(true));
        actionDelete = new QAction(PrabhupadaDictionaryWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ToolButton/resources/Delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setProperty("icon", QVariant(icon1));
        actionInsert = new QAction(PrabhupadaDictionaryWindow);
        actionInsert->setObjectName(QString::fromUtf8("actionInsert"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ToolButton/resources/Insert.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInsert->setProperty("icon", QVariant(icon2));
        actionRemove_Duplicates = new QAction(PrabhupadaDictionaryWindow);
        actionRemove_Duplicates->setObjectName(QString::fromUtf8("actionRemove_Duplicates"));
        actionSet_Bookmark_0 = new QAction(PrabhupadaDictionaryWindow);
        actionSet_Bookmark_0->setObjectName(QString::fromUtf8("actionSet_Bookmark_0"));
        actionSet_Bookmark_1 = new QAction(PrabhupadaDictionaryWindow);
        actionSet_Bookmark_1->setObjectName(QString::fromUtf8("actionSet_Bookmark_1"));
        actionSet_Bookmark_2 = new QAction(PrabhupadaDictionaryWindow);
        actionSet_Bookmark_2->setObjectName(QString::fromUtf8("actionSet_Bookmark_2"));
        actionSet_Bookmark_3 = new QAction(PrabhupadaDictionaryWindow);
        actionSet_Bookmark_3->setObjectName(QString::fromUtf8("actionSet_Bookmark_3"));
        actionSet_Bookmark_4 = new QAction(PrabhupadaDictionaryWindow);
        actionSet_Bookmark_4->setObjectName(QString::fromUtf8("actionSet_Bookmark_4"));
        actionSet_Bookmark_5 = new QAction(PrabhupadaDictionaryWindow);
        actionSet_Bookmark_5->setObjectName(QString::fromUtf8("actionSet_Bookmark_5"));
        actionSet_Bookmark_6 = new QAction(PrabhupadaDictionaryWindow);
        actionSet_Bookmark_6->setObjectName(QString::fromUtf8("actionSet_Bookmark_6"));
        actionSet_Bookmark_7 = new QAction(PrabhupadaDictionaryWindow);
        actionSet_Bookmark_7->setObjectName(QString::fromUtf8("actionSet_Bookmark_7"));
        actionSet_Bookmark_8 = new QAction(PrabhupadaDictionaryWindow);
        actionSet_Bookmark_8->setObjectName(QString::fromUtf8("actionSet_Bookmark_8"));
        actionSet_Bookmark_9 = new QAction(PrabhupadaDictionaryWindow);
        actionSet_Bookmark_9->setObjectName(QString::fromUtf8("actionSet_Bookmark_9"));
        actionGo_to_ookmark_0 = new QAction(PrabhupadaDictionaryWindow);
        actionGo_to_ookmark_0->setObjectName(QString::fromUtf8("actionGo_to_ookmark_0"));
        actionGo_to_bookmark_1 = new QAction(PrabhupadaDictionaryWindow);
        actionGo_to_bookmark_1->setObjectName(QString::fromUtf8("actionGo_to_bookmark_1"));
        actionGo_to_bookmark_2 = new QAction(PrabhupadaDictionaryWindow);
        actionGo_to_bookmark_2->setObjectName(QString::fromUtf8("actionGo_to_bookmark_2"));
        actionGo_to_bookmark_3 = new QAction(PrabhupadaDictionaryWindow);
        actionGo_to_bookmark_3->setObjectName(QString::fromUtf8("actionGo_to_bookmark_3"));
        actionGo_to_bookmark_4 = new QAction(PrabhupadaDictionaryWindow);
        actionGo_to_bookmark_4->setObjectName(QString::fromUtf8("actionGo_to_bookmark_4"));
        actionGo_to_bookmark_5 = new QAction(PrabhupadaDictionaryWindow);
        actionGo_to_bookmark_5->setObjectName(QString::fromUtf8("actionGo_to_bookmark_5"));
        actionGo_to_bookmark_6 = new QAction(PrabhupadaDictionaryWindow);
        actionGo_to_bookmark_6->setObjectName(QString::fromUtf8("actionGo_to_bookmark_6"));
        actionGo_to_bookmark_7 = new QAction(PrabhupadaDictionaryWindow);
        actionGo_to_bookmark_7->setObjectName(QString::fromUtf8("actionGo_to_bookmark_7"));
        actionGo_to_bookmark_8 = new QAction(PrabhupadaDictionaryWindow);
        actionGo_to_bookmark_8->setObjectName(QString::fromUtf8("actionGo_to_bookmark_8"));
        actionGo_to_bookmark_9 = new QAction(PrabhupadaDictionaryWindow);
        actionGo_to_bookmark_9->setObjectName(QString::fromUtf8("actionGo_to_bookmark_9"));
        actionWhats_This_mode = new QAction(PrabhupadaDictionaryWindow);
        actionWhats_This_mode->setObjectName(QString::fromUtf8("actionWhats_This_mode"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ToolButton/resources/WhatsThis.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWhats_This_mode->setProperty("icon", QVariant(icon3));
        centralwidget = new QWidget(PrabhupadaDictionaryWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        vlPrabhuadaMain = new QVBoxLayout(centralwidget);
        vlPrabhuadaMain->setObjectName(QString::fromUtf8("vlPrabhuadaMain"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sbFontSize = new QSpinBox(centralwidget);
        sbFontSize->setObjectName(QString::fromUtf8("sbFontSize"));
        sbFontSize->setProperty("value", QVariant(14));
        sbFontSize->setProperty("minimum", QVariant(14));
        sbFontSize->setProperty("maximum", QVariant(24));
        sbFontSize->setProperty("alignment", QVariant(Qt::AlignCenter));

        horizontalLayout->addWidget(sbFontSize);

        cbLanguage = new QComboBox(centralwidget);
        cbLanguage->setObjectName(QString::fromUtf8("cbLanguage"));

        horizontalLayout->addWidget(cbLanguage);

        cbLanguageUI = new QComboBox(centralwidget);
        cbLanguageUI->setObjectName(QString::fromUtf8("cbLanguageUI"));

        horizontalLayout->addWidget(cbLanguageUI);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 3);

        vlPrabhuadaMain->addLayout(horizontalLayout);

        vlDictionary = new QVBoxLayout();
        vlDictionary->setObjectName(QString::fromUtf8("vlDictionary"));
        tbvPrabhupadaDictionary = new QTableView(centralwidget);
        tbvPrabhupadaDictionary->setObjectName(QString::fromUtf8("tbvPrabhupadaDictionary"));
        QFont font;
        font.setFamily(QString::fromUtf8("Gaura Times"));
        font.setPointSize(14);
        tbvPrabhupadaDictionary->setProperty("font", QVariant(font));

        vlDictionary->addWidget(tbvPrabhupadaDictionary);

        splSanskritTranslate = new QSplitter(centralwidget);
        splSanskritTranslate->setObjectName(QString::fromUtf8("splSanskritTranslate"));
        splSanskritTranslate->setProperty("orientation", QVariant(Qt::Horizontal));
        splSanskritTranslate->setProperty("childrenCollapsible", QVariant(false));
        leSanskrit = new QLineEdit(splSanskritTranslate);
        leSanskrit->setObjectName(QString::fromUtf8("leSanskrit"));
        leSanskrit->setProperty("font", QVariant(font));
        splSanskritTranslate->addWidget(leSanskrit);
        leTranslate = new QLineEdit(splSanskritTranslate);
        leTranslate->setObjectName(QString::fromUtf8("leTranslate"));
        leTranslate->setProperty("font", QVariant(font));
        splSanskritTranslate->addWidget(leTranslate);

        vlDictionary->addWidget(splSanskritTranslate);


        vlPrabhuadaMain->addLayout(vlDictionary);

        PrabhupadaDictionaryWindow->setCentralWidget(centralwidget);
        mbPrabupadaDictionary = new QMenuBar(PrabhupadaDictionaryWindow);
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
        PrabhupadaDictionaryWindow->setMenuBar(mbPrabupadaDictionary);
        tbPrabhupada = new QToolBar(PrabhupadaDictionaryWindow);
        tbPrabhupada->setObjectName(QString::fromUtf8("tbPrabhupada"));
        tbPrabhupada->setProperty("toolButtonStyle", QVariant(Qt::ToolButtonFollowStyle));
        tbPrabhupada->setProperty("orientation", QVariant(Qt::Horizontal));
        tbPrabhupada->setProperty("floatable", QVariant(true));
        PrabhupadaDictionaryWindow->addToolBar(Qt::TopToolBarArea, tbPrabhupada);
        QWidget::setTabOrder(tbvPrabhupadaDictionary, leSanskrit);
        QWidget::setTabOrder(leSanskrit, leTranslate);

        mbPrabupadaDictionary->addAction(menuAction->menuAction());
        mbPrabupadaDictionary->addAction(menuSet_Bookmark->menuAction());
        mbPrabupadaDictionary->addAction(menuGo_Bookmarks->menuAction());
        menuAction->addAction(actionFind);
        menuAction->addAction(actionCase_Sensitive);
        menuAction->addAction(actionDelete);
        menuAction->addAction(actionInsert);
        menuAction->addAction(actionRemove_Duplicates);
        menuAction->addAction(actionWhats_This_mode);
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

        retranslateUi(PrabhupadaDictionaryWindow);

        QMetaObject::connectSlotsByName(PrabhupadaDictionaryWindow);
    }  // setupUi

    void retranslateUi(QMainWindow *PrabhupadaDictionaryWindow)
    {
        PrabhupadaDictionaryWindow->setProperty("windowTitle", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "MainWindow", nullptr)));
        actionFind->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "&Find", nullptr)));
        actionFind->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+Return", nullptr)));
        actionFind->setProperty("iconText", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "&Find", nullptr)));
        actionCase_Sensitive->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "&Case Sensitive", nullptr)));
        actionCase_Sensitive->setProperty("iconText", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "&Case Sensitive", nullptr)));
        actionDelete->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "&Delete", nullptr)));
        actionDelete->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+Del", nullptr)));
        actionDelete->setProperty("iconText", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "&Delete", nullptr)));
        actionInsert->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "&Insert", nullptr)));
        actionInsert->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+Ins", nullptr)));
        actionInsert->setProperty("iconText", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "&Insert", nullptr)));
        actionRemove_Duplicates->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "&Remove Duplicates", nullptr)));
        actionRemove_Duplicates->setProperty("iconText", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "&Remove Duplicates", nullptr)));
        actionSet_Bookmark_0->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Set bookmark 0", nullptr)));
        actionSet_Bookmark_0->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+Alt+0", nullptr)));
        actionSet_Bookmark_1->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Set bookmark 1", nullptr)));
        actionSet_Bookmark_1->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+Alt+1", nullptr)));
        actionSet_Bookmark_2->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Set bookmark 2", nullptr)));
        actionSet_Bookmark_2->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+Alt+2", nullptr)));
        actionSet_Bookmark_3->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Set bookmark 3", nullptr)));
        actionSet_Bookmark_3->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+Alt+3", nullptr)));
        actionSet_Bookmark_4->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Set bookmark 4", nullptr)));
        actionSet_Bookmark_4->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+Alt+4", nullptr)));
        actionSet_Bookmark_5->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Set bookmark 5", nullptr)));
        actionSet_Bookmark_5->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+Alt+5", nullptr)));
        actionSet_Bookmark_6->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Set bookmark 6", nullptr)));
        actionSet_Bookmark_6->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+Alt+6", nullptr)));
        actionSet_Bookmark_7->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Set bookmark 7", nullptr)));
        actionSet_Bookmark_7->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+Alt+7", nullptr)));
        actionSet_Bookmark_8->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Set bookmark 8", nullptr)));
        actionSet_Bookmark_8->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+Alt+\342\202\275", nullptr)));
        actionSet_Bookmark_9->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Set bookmark 9", nullptr)));
        actionSet_Bookmark_9->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+Alt+9", nullptr)));
        actionGo_to_ookmark_0->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Go to bookmark 0", nullptr)));
        actionGo_to_ookmark_0->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+0", nullptr)));
        actionGo_to_bookmark_1->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Go to bookmark 1", nullptr)));
        actionGo_to_bookmark_1->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+1", nullptr)));
        actionGo_to_bookmark_2->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Go to bookmark 2", nullptr)));
        actionGo_to_bookmark_2->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+2", nullptr)));
        actionGo_to_bookmark_3->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Go to bookmark 3", nullptr)));
        actionGo_to_bookmark_3->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+3", nullptr)));
        actionGo_to_bookmark_4->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Go to bookmark 4", nullptr)));
        actionGo_to_bookmark_4->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+4", nullptr)));
        actionGo_to_bookmark_5->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Go to bookmark 5", nullptr)));
        actionGo_to_bookmark_5->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+5", nullptr)));
        actionGo_to_bookmark_6->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Go to bookmark 6", nullptr)));
        actionGo_to_bookmark_6->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+6", nullptr)));
        actionGo_to_bookmark_7->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Go to bookmark 7", nullptr)));
        actionGo_to_bookmark_7->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+7", nullptr)));
        actionGo_to_bookmark_8->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Go to bookmark 8", nullptr)));
        actionGo_to_bookmark_8->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+8", nullptr)));
        actionGo_to_bookmark_9->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Go to bookmark 9", nullptr)));
        actionGo_to_bookmark_9->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+9", nullptr)));
        actionWhats_This_mode->setProperty("text", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "&Whats This mode", nullptr)));
        actionWhats_This_mode->setProperty("shortcut", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Ctrl+F1", nullptr)));
        actionWhats_This_mode->setProperty("iconText", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "&Whats This mode", nullptr)));
#ifndef QT_NO_TOOLTIP
        sbFontSize->setProperty("toolTip", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Font size", nullptr)));
#endif
#ifndef QT_NO_TOOLTIP
        cbLanguage->setProperty("toolTip", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Language dictionary", nullptr)));
#endif
#ifndef QT_NO_TOOLTIP
        cbLanguageUI->setProperty("toolTip", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "Language user interface", nullptr)));
#endif
#ifndef QT_NO_WHATSTHIS
        leSanskrit->setProperty("whatsThis", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "<html><head/><body><p>Search string for Sanskrit!</p><p>You can use regular expressions!</p><p>For example muni|rishi !</p></body></html>", nullptr)));
#endif
#ifndef QT_NO_TOOLTIP
        leSanskrit->setProperty("toolTip", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "<html><head/><body><p>Search Sanskrit!<br/>Type and press enter!</p></body></html>", nullptr)));
#endif
#ifndef QT_NO_WHATSTHIS
        leTranslate->setProperty("whatsThis", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "<html><head/><body><p>Search bar for translation!</p><p>You can use regular expressions!</p><p>For example, a teacher|sage !</p></body></html>", nullptr)));
#endif
#ifndef QT_NO_TOOLTIP
        leTranslate->setProperty("toolTip", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "<html><head/><body><p>Search Translate!</p></body></html>", nullptr)));
#endif
        menuAction->setProperty("title", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "&Action", nullptr)));
        menuSet_Bookmark->setProperty("title", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "&Set Bookmark", nullptr)));
        menuGo_Bookmarks->setProperty("title", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "&Go Bookmarks", nullptr)));
        tbPrabhupada->setProperty("windowTitle", QVariant(QApplication::translate("PrabhupadaDictionaryWindow", "toolBar", nullptr)));
    }  // retranslateUi

};

namespace Ui {
    class PrabhupadaDictionaryWindow : public Ui_PrabhupadaDictionaryWindow {};
}  // namespace Ui

#endif // UI_PRABHUPADADICTIONARYWINDOW_H
