/********************************************************************************
** Form generated from reading UI file 'BattleWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTLEWIDGET_H
#define UI_BATTLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BattleWidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *YouCnt;
    QLCDNumber *YouCntDisplay;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *EnemyCnt;
    QLCDNumber *EnemyCntDisplay;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLCDNumber *lcdNumber;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *layoutForChat;

    void setupUi(QWidget *BattleWidget)
    {
        if (BattleWidget->objectName().isEmpty())
            BattleWidget->setObjectName(QStringLiteral("BattleWidget"));
        BattleWidget->resize(406, 316);
        gridLayout = new QGridLayout(BattleWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        YouCnt = new QLabel(BattleWidget);
        YouCnt->setObjectName(QStringLiteral("YouCnt"));

        horizontalLayout->addWidget(YouCnt);

        YouCntDisplay = new QLCDNumber(BattleWidget);
        YouCntDisplay->setObjectName(QStringLiteral("YouCntDisplay"));
        YouCntDisplay->setMinimumSize(QSize(25, 25));
        YouCntDisplay->setSmallDecimalPoint(false);
        YouCntDisplay->setDigitCount(2);
        YouCntDisplay->setSegmentStyle(QLCDNumber::Flat);
        YouCntDisplay->setProperty("intValue", QVariant(7));

        horizontalLayout->addWidget(YouCntDisplay);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(BattleWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        EnemyCnt = new QLabel(BattleWidget);
        EnemyCnt->setObjectName(QStringLiteral("EnemyCnt"));

        horizontalLayout->addWidget(EnemyCnt);

        EnemyCntDisplay = new QLCDNumber(BattleWidget);
        EnemyCntDisplay->setObjectName(QStringLiteral("EnemyCntDisplay"));
        EnemyCntDisplay->setMinimumSize(QSize(25, 25));
        EnemyCntDisplay->setSmallDecimalPoint(false);
        EnemyCntDisplay->setDigitCount(2);
        EnemyCntDisplay->setSegmentStyle(QLCDNumber::Flat);
        EnemyCntDisplay->setProperty("intValue", QVariant(7));

        horizontalLayout->addWidget(EnemyCntDisplay);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        lcdNumber = new QLCDNumber(BattleWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(40, 30));
        lcdNumber->setDigitCount(2);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_3->addWidget(lcdNumber);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        verticalLayout->addLayout(horizontalLayout_2);

        layoutForChat = new QHBoxLayout();
        layoutForChat->setObjectName(QStringLiteral("layoutForChat"));

        verticalLayout->addLayout(layoutForChat);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(BattleWidget);

        QMetaObject::connectSlotsByName(BattleWidget);
    } // setupUi

    void retranslateUi(QWidget *BattleWidget)
    {
        BattleWidget->setWindowTitle(QApplication::translate("BattleWidget", "Form", 0));
        YouCnt->setText(QApplication::translate("BattleWidget", "TextLabel", 0));
        label->setText(QApplication::translate("BattleWidget", "TextLabel", 0));
        EnemyCnt->setText(QApplication::translate("BattleWidget", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class BattleWidget: public Ui_BattleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTLEWIDGET_H
