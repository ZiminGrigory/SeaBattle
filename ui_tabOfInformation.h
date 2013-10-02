/********************************************************************************
** Form generated from reading UI file 'tabOfInformation.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABOFINFORMATION_H
#define UI_TABOFINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabOfInformation
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QGridLayout *gridLayout;
    QLCDNumber *lcdNumber_4;
    QLabel *label;
    QLCDNumber *lcdNumber_3;
    QLabel *label_2;
    QLCDNumber *lcdNumber_2;
    QLabel *label_3;
    QLCDNumber *lcdNumber;
    QLabel *label_4;
    QToolButton *toolButton_2;
    QToolButton *toolButton;

    void setupUi(QWidget *TabOfInformation)
    {
        if (TabOfInformation->objectName().isEmpty())
            TabOfInformation->setObjectName(QStringLiteral("TabOfInformation"));
        TabOfInformation->resize(400, 400);
        gridLayout_3 = new QGridLayout(TabOfInformation);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textBrowser = new QTextBrowser(TabOfInformation);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_2->addWidget(textBrowser, 0, 0, 1, 2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lcdNumber_4 = new QLCDNumber(TabOfInformation);
        lcdNumber_4->setObjectName(QStringLiteral("lcdNumber_4"));
        lcdNumber_4->setBaseSize(QSize(0, 0));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(161, 160, 159, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        lcdNumber_4->setPalette(palette);
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferAntialias);
        lcdNumber_4->setFont(font);
        lcdNumber_4->setFocusPolicy(Qt::NoFocus);
        lcdNumber_4->setAutoFillBackground(false);
        lcdNumber_4->setFrameShape(QFrame::Panel);
        lcdNumber_4->setFrameShadow(QFrame::Sunken);
        lcdNumber_4->setSmallDecimalPoint(false);
        lcdNumber_4->setDigitCount(1);
        lcdNumber_4->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_4->setProperty("value", QVariant(1));
        lcdNumber_4->setProperty("intValue", QVariant(1));

        gridLayout->addWidget(lcdNumber_4, 0, 0, 1, 1);

        label = new QLabel(TabOfInformation);
        label->setObjectName(QStringLiteral("label"));
        label->setBaseSize(QSize(0, 0));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        lcdNumber_3 = new QLCDNumber(TabOfInformation);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setBaseSize(QSize(0, 0));
        lcdNumber_3->setFrameShape(QFrame::Panel);
        lcdNumber_3->setFrameShadow(QFrame::Sunken);
        lcdNumber_3->setSmallDecimalPoint(false);
        lcdNumber_3->setDigitCount(1);
        lcdNumber_3->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_3->setProperty("value", QVariant(2));

        gridLayout->addWidget(lcdNumber_3, 1, 0, 1, 1);

        label_2 = new QLabel(TabOfInformation);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setBaseSize(QSize(0, 0));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        lcdNumber_2 = new QLCDNumber(TabOfInformation);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setEnabled(true);
        lcdNumber_2->setBaseSize(QSize(0, 0));
        lcdNumber_2->setFrameShape(QFrame::Panel);
        lcdNumber_2->setFrameShadow(QFrame::Sunken);
        lcdNumber_2->setSmallDecimalPoint(false);
        lcdNumber_2->setDigitCount(1);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_2->setProperty("value", QVariant(3));

        gridLayout->addWidget(lcdNumber_2, 2, 0, 1, 1);

        label_3 = new QLabel(TabOfInformation);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setBaseSize(QSize(0, 0));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        lcdNumber = new QLCDNumber(TabOfInformation);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setBaseSize(QSize(0, 0));
        lcdNumber->setFrameShape(QFrame::Panel);
        lcdNumber->setFrameShadow(QFrame::Sunken);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setDigitCount(1);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("value", QVariant(4));

        gridLayout->addWidget(lcdNumber, 3, 0, 1, 1);

        label_4 = new QLabel(TabOfInformation);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setBaseSize(QSize(0, 0));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 2, 1);

        toolButton_2 = new QToolButton(TabOfInformation);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));

        gridLayout_2->addWidget(toolButton_2, 1, 1, 1, 1);

        toolButton = new QToolButton(TabOfInformation);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setBaseSize(QSize(0, 0));

        gridLayout_2->addWidget(toolButton, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(TabOfInformation);

        QMetaObject::connectSlotsByName(TabOfInformation);
    } // setupUi

    void retranslateUi(QWidget *TabOfInformation)
    {
        TabOfInformation->setWindowTitle(QApplication::translate("TabOfInformation", "Form", 0));
        textBrowser->setHtml(QApplication::translate("TabOfInformation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">to do: write info</p></body></html>", 0));
        label->setText(QApplication::translate("TabOfInformation", "aerocarrier", 0));
        label_2->setText(QApplication::translate("TabOfInformation", "cruiser", 0));
        label_3->setText(QApplication::translate("TabOfInformation", "destroyer", 0));
        label_4->setText(QApplication::translate("TabOfInformation", "boat-scout", 0));
        toolButton_2->setText(QApplication::translate("TabOfInformation", "\320\220\320\262\321\202\320\276\321\200\320\260\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260", 0));
        toolButton->setText(QApplication::translate("TabOfInformation", "\320\222 \320\221\320\236\320\231!!!", 0));
        toolButton->setShortcut(QString());
    } // retranslateUi

};

namespace Ui {
    class TabOfInformation: public Ui_TabOfInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABOFINFORMATION_H
