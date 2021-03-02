/********************************************************************************
** Form generated from reading UI file 'message.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGE_H
#define UI_MESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "menubar.h"

QT_BEGIN_NAMESPACE

class Ui_Message
{
public:
    QVBoxLayout *verticalLayout;
    MenuBar *widget_2;
    QTableView *messageView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirmButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Message)
    {
        if (Message->objectName().isEmpty())
            Message->setObjectName(QString::fromUtf8("Message"));
        Message->resize(795, 608);
        Message->setStyleSheet(QString::fromUtf8("QLabel,\n"
"QPushButton \n"
"{\n"
"	border: none;\n"
"	color: #1296db;\n"
"	font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	color: #ffffff;\n"
"}\n"
"\n"
"QTableView\n"
"{\n"
"	border: none;\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"	color: #000000;\n"
"	font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QTableView:item:selected\n"
"{\n"
"	color: #1296db;\n"
"	background: qlineargradient(spread: pad, x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #def0fe, stop: 1 #c0def6);\n"
"}\n"
"\n"
"QTableView:item:hover\n"
"{\n"
"	background: qlineargradient(spread: pad, x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #f2f9ff, stop: 1 #daefff);\n"
"}\n"
"\n"
"QTableView:item\n"
"{\n"
"	padding: 5px;\n"
"	margin: 0px;\n"
"}\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"	padding-top: 15px;\n"
"	padding-bottom: 15px;\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"}\n"
"\n"
"QScrollBar:add-line:vertical\n"
"{\n"
"	height: 15px;\n"
"	width: 15px;\n"
"	subc"
                        "ontrol-position: bottom;\n"
"	subcontrol-origin: margin;\n"
"	border-image: url(:/Images/down.png);\n"
"}\n"
"\n"
"QScrollBar:add-line:vertical:pressed\n"
"{\n"
"	height: 15px;\n"
"	width: 15px;\n"
"	subcontrol-position: bottom;\n"
"	subcontrol-origin: margin;\n"
"	border-image: url(:/Images/down_pre.png);\n"
"}\n"
"\n"
"QScrollBar:sub-line:vertical\n"
"{\n"
"	height: 15px;\n"
"	width: 15px;\n"
"	subcontrol-position: top;\n"
"	subcontrol-origin: margin;\n"
"	border-image: url(:/Images/up.png);\n"
"}\n"
"\n"
"QScrollBar:sub-line:vertical:pressed\n"
"{\n"
"	height: 15px;\n"
"	width: 15px;\n"
"	subcontrol-position: top;\n"
"	subcontrol-origin: margin;\n"
"	border-image: url(:/Images/up_pre.png);\n"
"}\n"
"\n"
"QScrollBar:handle:vertical\n"
"{\n"
"	background: #1296db;\n"
"	width: 15px;\n"
"}\n"
"\n"
"QScrollBar:handle:vertical:hover\n"
"{\n"
"	width: 15px;\n"
"	background: #00aaff;\n"
"}"));
        verticalLayout = new QVBoxLayout(Message);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new MenuBar(Message);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        verticalLayout->addWidget(widget_2);

        messageView = new QTableView(Message);
        messageView->setObjectName(QString::fromUtf8("messageView"));
        messageView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        messageView->setSelectionMode(QAbstractItemView::SingleSelection);
        messageView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(messageView);

        widget = new QWidget(Message);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        confirmButton = new QPushButton(widget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setMinimumSize(QSize(75, 0));
        confirmButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
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
"}"));

        horizontalLayout->addWidget(confirmButton);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Message);

        QMetaObject::connectSlotsByName(Message);
    } // setupUi

    void retranslateUi(QWidget *Message)
    {
        Message->setWindowTitle(QCoreApplication::translate("Message", "Form", nullptr));
        confirmButton->setText(QCoreApplication::translate("Message", "\345\244\204\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Message: public Ui_Message {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGE_H
