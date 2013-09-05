/********************************************************************************
** Form generated from reading UI file 'field.ui'
**
** Created: Mon 2. Sep 19:29:31 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIELD_H
#define UI_FIELD_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Field
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_19;
    QLabel *label_17;
    QLabel *label_11;
    QLabel *label_16;
    QLabel *label_12;
    QLabel *label_20;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_13;
    QLabel *label_18;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *Field)
    {
        if (Field->objectName().isEmpty())
            Field->setObjectName(QString::fromUtf8("Field"));
        Field->resize(400, 400);
        Field->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout_2 = new QGridLayout(Field);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(Field);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(Field);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        label_5 = new QLabel(Field);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_5);

        label_9 = new QLabel(Field);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_9);

        label_10 = new QLabel(Field);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_10);

        label_7 = new QLabel(Field);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_7);

        label_8 = new QLabel(Field);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_8);

        label_6 = new QLabel(Field);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_6);

        label = new QLabel(Field);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(Field);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_19 = new QLabel(Field);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_19);

        label_17 = new QLabel(Field);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_17);

        label_11 = new QLabel(Field);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_11);

        label_16 = new QLabel(Field);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_16);

        label_12 = new QLabel(Field);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_12);

        label_20 = new QLabel(Field);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_20);

        label_14 = new QLabel(Field);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_14);

        label_15 = new QLabel(Field);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_15);

        label_13 = new QLabel(Field);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_13);

        label_18 = new QLabel(Field);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_18);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        graphicsView = new QGraphicsView(Field);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(Field);

        QMetaObject::connectSlotsByName(Field);
    } // setupUi

    void retranslateUi(QWidget *Field)
    {
        Field->setWindowTitle(QApplication::translate("Field", "Form", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Field", "a", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Field", "b", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Field", "c", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Field", "d", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Field", "e", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Field", "f", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Field", "g", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Field", "h", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Field", "i", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Field", "j", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("Field", "1", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Field", "2", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Field", "3", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Field", "4", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Field", "5", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("Field", "6", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Field", "7", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Field", "8", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Field", "9", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("Field", "10", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Field: public Ui_Field {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIELD_H
