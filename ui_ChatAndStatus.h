/********************************************************************************
** Form generated from reading UI file 'ChatAndStatus.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATANDSTATUS_H
#define UI_CHATANDSTATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatAndStatus
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelLeft;
    QTextBrowser *textBrowser;
    QLabel *labelRight;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *buttonEnter;

    void setupUi(QWidget *ChatAndStatus)
    {
        if (ChatAndStatus->objectName().isEmpty())
            ChatAndStatus->setObjectName(QStringLiteral("ChatAndStatus"));
        ChatAndStatus->resize(662, 168);
        gridLayout = new QGridLayout(ChatAndStatus);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelLeft = new QLabel(ChatAndStatus);
        labelLeft->setObjectName(QStringLiteral("labelLeft"));

        horizontalLayout->addWidget(labelLeft);

        textBrowser = new QTextBrowser(ChatAndStatus);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        horizontalLayout->addWidget(textBrowser);

        labelRight = new QLabel(ChatAndStatus);
        labelRight->setObjectName(QStringLiteral("labelRight"));

        horizontalLayout->addWidget(labelRight);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit = new QLineEdit(ChatAndStatus);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        buttonEnter = new QPushButton(ChatAndStatus);
        buttonEnter->setObjectName(QStringLiteral("buttonEnter"));

        horizontalLayout_2->addWidget(buttonEnter);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(ChatAndStatus);

        QMetaObject::connectSlotsByName(ChatAndStatus);
    } // setupUi

    void retranslateUi(QWidget *ChatAndStatus)
    {
        ChatAndStatus->setWindowTitle(QApplication::translate("ChatAndStatus", "Form", 0));
        labelLeft->setText(QApplication::translate("ChatAndStatus", "TextLabel", 0));
        labelRight->setText(QApplication::translate("ChatAndStatus", "TextLabel", 0));
        buttonEnter->setText(QApplication::translate("ChatAndStatus", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatAndStatus: public Ui_ChatAndStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATANDSTATUS_H
