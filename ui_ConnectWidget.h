/********************************************************************************
** Form generated from reading UI file 'ConnectWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTWIDGET_H
#define UI_CONNECTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectWidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QSpacerItem *verticalSpacer;
    QLabel *labelStatus;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *labelGif;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonTryAgain;
    QPushButton *buttoCancel;

    void setupUi(QWidget *ConnectWidget)
    {
        if (ConnectWidget->objectName().isEmpty())
            ConnectWidget->setObjectName(QStringLiteral("ConnectWidget"));
        ConnectWidget->resize(557, 427);
        gridLayout = new QGridLayout(ConnectWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelTitle = new QLabel(ConnectWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));

        verticalLayout->addWidget(labelTitle);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        labelStatus = new QLabel(ConnectWidget);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));

        verticalLayout->addWidget(labelStatus);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        labelGif = new QLabel(ConnectWidget);
        labelGif->setObjectName(QStringLiteral("labelGif"));

        horizontalLayout_2->addWidget(labelGif);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        buttonTryAgain = new QPushButton(ConnectWidget);
        buttonTryAgain->setObjectName(QStringLiteral("buttonTryAgain"));

        horizontalLayout->addWidget(buttonTryAgain);

        buttoCancel = new QPushButton(ConnectWidget);
        buttoCancel->setObjectName(QStringLiteral("buttoCancel"));

        horizontalLayout->addWidget(buttoCancel);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(ConnectWidget);

        QMetaObject::connectSlotsByName(ConnectWidget);
    } // setupUi

    void retranslateUi(QWidget *ConnectWidget)
    {
        ConnectWidget->setWindowTitle(QApplication::translate("ConnectWidget", "Form", 0));
        labelTitle->setText(QApplication::translate("ConnectWidget", "TextLabel", 0));
        labelStatus->setText(QApplication::translate("ConnectWidget", "TextLabel", 0));
        labelGif->setText(QApplication::translate("ConnectWidget", "TextLabel", 0));
        buttonTryAgain->setText(QApplication::translate("ConnectWidget", "Try again", 0));
        buttoCancel->setText(QApplication::translate("ConnectWidget", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class ConnectWidget: public Ui_ConnectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTWIDGET_H
