/********************************************************************************
** Form generated from reading the UI file 'QPrabhupadaGoToLineWindow.ui'
**
** Created by: CopperSpice User Interface Compiler, Version 1.8.1
**
** WARNING! Any changes made to this file will be lost when the UI file is recompiled
********************************************************************************/

#ifndef UI_QPRABHUPADAGOTOLINEWINDOW_H
#define UI_QPRABHUPADAGOTOLINEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

class Ui_QPrabhupadaGoToLineWindow
{
public:
    QVBoxLayout *verticalLayoutPrabhupada;
    QVBoxLayout *verticalLayoutRowNumber;
    QFormLayout *formLayout;
    QLabel *LabelRowNumber;
    QComboBox *ComboBoxRowNumber;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *PushButtonGo;
    QPushButton *PushButtonCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *QPrabhupadaGoToLineWindow)
    {
        if (QPrabhupadaGoToLineWindow->objectName().isEmpty())
            QPrabhupadaGoToLineWindow->setObjectName(QString::fromUtf8("QPrabhupadaGoToLineWindow"));
        QPrabhupadaGoToLineWindow->resize(272, 82);
        verticalLayoutPrabhupada = new QVBoxLayout(QPrabhupadaGoToLineWindow);
        verticalLayoutPrabhupada->setObjectName(QString::fromUtf8("verticalLayoutPrabhupada"));
        verticalLayoutRowNumber = new QVBoxLayout();
        verticalLayoutRowNumber->setObjectName(QString::fromUtf8("verticalLayoutRowNumber"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        LabelRowNumber = new QLabel(QPrabhupadaGoToLineWindow);
        LabelRowNumber->setObjectName(QString::fromUtf8("LabelRowNumber"));

        formLayout->setWidget(0, QFormLayout::LabelRole, LabelRowNumber);

        ComboBoxRowNumber = new QComboBox(QPrabhupadaGoToLineWindow);
        ComboBoxRowNumber->setObjectName(QString::fromUtf8("ComboBoxRowNumber"));
        ComboBoxRowNumber->setProperty("editable", QVariant(true));

        formLayout->setWidget(0, QFormLayout::FieldRole, ComboBoxRowNumber);


        verticalLayoutRowNumber->addLayout(formLayout);


        verticalLayoutPrabhupada->addLayout(verticalLayoutRowNumber);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        PushButtonGo = new QPushButton(QPrabhupadaGoToLineWindow);
        PushButtonGo->setObjectName(QString::fromUtf8("PushButtonGo"));

        horizontalLayout->addWidget(PushButtonGo);

        PushButtonCancel = new QPushButton(QPrabhupadaGoToLineWindow);
        PushButtonCancel->setObjectName(QString::fromUtf8("PushButtonCancel"));

        horizontalLayout->addWidget(PushButtonCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayoutPrabhupada->addLayout(horizontalLayout);

        verticalLayoutPrabhupada->setStretch(0, 1);

        retranslateUi(QPrabhupadaGoToLineWindow);

        QMetaObject::connectSlotsByName(QPrabhupadaGoToLineWindow);
    }  // setupUi

    void retranslateUi(QDialog *QPrabhupadaGoToLineWindow)
    {
        QPrabhupadaGoToLineWindow->setProperty("windowTitle", QVariant(QApplication::translate("QPrabhupadaGoToLineWindow", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \321\201\321\202\321\200\320\276\320\272\320\265", nullptr)));
        LabelRowNumber->setProperty("text", QVariant(QApplication::translate("QPrabhupadaGoToLineWindow", "\320\235\320\276\320\274\320\265\321\200 \321\201\321\202\321\200\320\276\320\272\320\270", nullptr)));
#ifndef QT_NO_WHATSTHIS
        ComboBoxRowNumber->setProperty("whatsThis", QVariant(QApplication::translate("QPrabhupadaGoToLineWindow", "<html><head/><body><p>\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \321\201\321\202\321\200\320\276\320\272\320\270 \320\270 \320\275\320\260\320\266\320\274\320\270\321\202\320\265 Enter \320\264\320\273\321\217 \320\277\320\265\321\200\320\265\321\205\320\276\320\264\320\260 \320\272 \320\275\320\265\320\271!</p></body></html>", nullptr)));
#endif
#ifndef QT_NO_TOOLTIP
        ComboBoxRowNumber->setProperty("toolTip", QVariant(QApplication::translate("QPrabhupadaGoToLineWindow", "\320\235\320\276\320\274\320\265\321\200 \321\201\321\202\321\200\320\276\320\272\320\270", nullptr)));
#endif
        PushButtonGo->setProperty("text", QVariant(QApplication::translate("QPrabhupadaGoToLineWindow", "\320\237\320\276\320\265\321\205\320\260\320\273\320\270!", nullptr)));
        PushButtonGo->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaGoToLineWindow", "Return", nullptr)));
        PushButtonCancel->setProperty("text", QVariant(QApplication::translate("QPrabhupadaGoToLineWindow", "\320\227\320\260\320\264\320\275\320\270\320\271 \321\205\320\276\320\264!", nullptr)));
        PushButtonCancel->setProperty("shortcut", QVariant(QApplication::translate("QPrabhupadaGoToLineWindow", "Esc", nullptr)));
    }  // retranslateUi

};

namespace Ui {
    class QPrabhupadaGoToLineWindow : public Ui_QPrabhupadaGoToLineWindow {};
}  // namespace Ui

#endif // UI_QPRABHUPADAGOTOLINEWINDOW_H
