/********************************************************************************
** Form generated from reading UI file 'AiLvlList.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AILVLLIST_H
#define UI_AILVLLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AiLvlList
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonVs1;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *buttonVs2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *buttonBack;

    void setupUi(QWidget *AiLvlList)
    {
        if (AiLvlList->objectName().isEmpty())
            AiLvlList->setObjectName(QStringLiteral("AiLvlList"));
        AiLvlList->resize(400, 300);
        gridLayout = new QGridLayout(AiLvlList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonVs1 = new QPushButton(AiLvlList);
        buttonVs1->setObjectName(QStringLiteral("buttonVs1"));

        horizontalLayout->addWidget(buttonVs1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        buttonVs2 = new QPushButton(AiLvlList);
        buttonVs2->setObjectName(QStringLiteral("buttonVs2"));

        horizontalLayout_2->addWidget(buttonVs2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        buttonBack = new QPushButton(AiLvlList);
        buttonBack->setObjectName(QStringLiteral("buttonBack"));

        horizontalLayout_3->addWidget(buttonBack);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(AiLvlList);

        QMetaObject::connectSlotsByName(AiLvlList);
    } // setupUi

    void retranslateUi(QWidget *AiLvlList)
    {
        AiLvlList->setWindowTitle(QApplication::translate("AiLvlList", "Form", 0));
        buttonVs1->setText(QApplication::translate("AiLvlList", "PushButton", 0));
        buttonVs2->setText(QApplication::translate("AiLvlList", "PushButton", 0));
        buttonBack->setText(QApplication::translate("AiLvlList", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class AiLvlList: public Ui_AiLvlList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AILVLLIST_H
