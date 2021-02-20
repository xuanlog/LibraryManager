/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *closeButton;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->resize(700, 561);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(About->sizePolicy().hasHeightForWidth());
        About->setSizePolicy(sizePolicy);
        About->setMinimumSize(QSize(700, 0));
        About->setMaximumSize(QSize(700, 16777215));
        About->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: none;\n"
"	color: #1296db;\n"
"	font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLabel:hover\n"
"{\n"
"	color: #ffffff;\n"
"}"));
        verticalLayout = new QVBoxLayout(About);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(About);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 25px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        label_2 = new QLabel(About);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(About);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(About);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(About);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(About);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(About);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget_2 = new QWidget(About);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        closeButton = new QPushButton(widget_2);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMinimumSize(QSize(250, 30));
        closeButton->setMaximumSize(QSize(250, 30));
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: rgba(18, 150, 219, 0.7);\n"
"    border-radius: 4px;  \n"
"	color: #ffffff;\n"
"	font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}  \n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #00aaff;\n"
"}\n"
""));

        horizontalLayout_2->addWidget(closeButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_2);


        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QWidget *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "Form", nullptr));
        label->setText(QCoreApplication::translate("About", "\345\205\263\344\272\216", nullptr));
        label_2->setText(QCoreApplication::translate("About", "1\343\200\201\345\234\250\346\234\254\347\263\273\347\273\237\345\200\237\347\232\204\344\271\246\347\261\215\345\260\206\344\274\232\351\200\232\350\277\207\345\277\253\351\200\222(\351\231\220\346\234\254\345\270\202\345\206\205)\351\202\256\345\210\260\346\202\250\347\232\204\346\211\213\344\270\212\357\274\214\350\257\267\347\241\256\344\277\235\346\202\250\346\234\211\345\205\205\350\266\263\347\232\204\346\227\266\351\227\264\346\224\266\345\217\226\357\274\233", nullptr));
        label_3->setText(QCoreApplication::translate("About", "2\343\200\201\345\200\237\344\271\246\351\230\205\350\247\210\346\227\266\351\225\277\344\270\27230\345\244\251\357\274\214\345\246\202\346\236\234\351\234\200\350\246\201\345\273\266\351\225\277\350\277\230\344\271\246\346\227\266\351\227\264\357\274\214\345\217\257\347\202\271\345\207\273\347\273\255\345\200\237\357\274\214\345\215\225\346\234\254\344\271\246\344\273\205\345\217\257\347\273\255\345\200\237\344\270\200\346\254\241\357\274\214\347\273\255\345\200\237\346\227\266\351\225\277\344\270\27230\345\244\251\357\274\233", nullptr));
        label_4->setText(QCoreApplication::translate("About", "3\343\200\201\350\277\230\344\271\246\346\227\266\350\257\267\345\260\206\344\271\246\347\261\215\346\225\264\347\220\206\345\245\275\357\274\214\347\202\271\345\207\273\350\277\230\344\271\246\345\220\216\357\274\214\344\274\232\346\234\211\344\270\223\344\272\272\345\211\215\346\235\245\345\233\236\346\224\266(\351\231\220\346\234\254\345\270\202\345\206\205)\357\274\214\350\257\267\347\241\256\344\277\235\346\202\250\346\234\211\345\205\205\350\266\263\347\232\204\346\227\266\351\227\264\344\272\244\344\273\230\344\271\246\347\261\215\357\274\233", nullptr));
        label_5->setText(QCoreApplication::translate("About", "4\343\200\201\346\202\250\347\232\204\345\200\237\344\271\246\344\270\212\351\231\220\344\270\2725\346\234\254\357\274\214\345\234\250\345\267\262\345\200\237\344\271\246\347\261\215\347\255\211\344\272\2165\346\234\254\347\232\204\346\203\205\345\206\265\344\270\213\351\234\200\345\205\210\350\277\230\346\216\211\351\203\250\345\210\206\344\271\246\347\261\215\346\211\215\345\217\257\347\273\247\347\273\255\345\200\237\344\271\246\357\274\233", nullptr));
        label_6->setText(QCoreApplication::translate("About", "5\343\200\201\345\246\202\346\234\211\344\271\246\347\261\215\351\200\276\346\234\237\346\234\252\350\277\230\357\274\214\346\202\250\347\232\204\345\200\237\344\271\246\346\235\203\351\231\220\345\260\206\350\242\253\345\206\273\347\273\223\357\274\214\344\270\224\351\200\276\346\234\237\344\271\246\347\261\215\344\270\215\345\217\257\347\273\255\345\200\237\345\217\212\347\272\277\344\270\212\350\277\230\344\271\246\357\274\214\346\202\250\351\234\200\345\210\260\345\233\276\344\271\246\351\246\206\346\237\234\345\217\260\345\212\236\347\220\206\n"
"\350\277\230\344\271\246\345\271\266\346\224\257\344\273\230\344\270\200\345\256\232\347\232\204\351\200\276\346\234\237\350\264\271\347\224\250\357\274\214\345\205\267\344\275\223\350\264\271\347\224\250\344\270\272\351\200\276\346\234\237\344\271\246\347\261\215\346\257\217\346\227\245\346\257\217\345\206\2140.3\345\205\203\357\274\214\346\257\217\345\206\214\344\270\212\351\231\22020\345\205\203\343\200\202", nullptr));
        label_7->setText(QCoreApplication::translate("About", "6\343\200\201\350\257\267\347\241\256\344\277\235\346\202\250\347\232\204\345\234\260\345\235\200\345\241\253\345\206\231\346\255\243\347\241\256\357\274\214\345\220\246\345\210\231\345\270\246\346\235\245\347\232\204\346\215\237\345\244\261\345\260\206\347\224\261\346\202\250\344\270\252\344\272\272\346\211\277\346\213\205", nullptr));
        closeButton->setText(QCoreApplication::translate("About", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
