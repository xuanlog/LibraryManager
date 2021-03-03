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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QCheckBox *statusCheckBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirmButton;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *typeComboBox;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *searchEdit;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Message)
    {
        if (Message->objectName().isEmpty())
            Message->setObjectName(QString::fromUtf8("Message"));
        Message->resize(795, 608);
        Message->setStyleSheet(QString::fromUtf8("QMessageBox\n"
"{\n"
"	border-image: url(:/Images/dialog.jpg);\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"	border: none;\n"
"	color: #000000;\n"
"	font: 75 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	border-radius: 5px;\n"
"	selection-background-color: #def0fe;\n"
"	selection-color: #1296db;\n"
"}\n"
"\n"
"QComboBox\n"
"{\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{	\n"
"	border-left-width: 1px;\n"
"	border-left-style: solid;	\n"
"	border-bottom-right-radius: 3px;\n"
"	border-left-color: #1296db;\n"
"}\n"
"\n"
"QComboBox:down-arrow\n"
"{\n"
"	image: url(:/Images/down.png);\n"
"}\n"
"\n"
"QLabel,\n"
"QComboBox,\n"
"QCheckBox,\n"
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
"	font: 14px \"\345\276\256\350\275\257"
                        "\351\233\205\351\273\221\";\n"
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
"QScrollBar:horizontal\n"
"{\n"
"	padding-left: 15px;\n"
"	padding-right: 15px;\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"}\n"
"\n"
"QScrollBar:add-line:vertical\n"
"{\n"
"	height: 15px;\n"
"	width: 15px;\n"
"	subcontrol-position: bottom;\n"
"	subcontrol-origin: margin;\n"
"	border-image: url(:/Images/down.png);\n"
"}\n"
"\n"
"QScrollBar:add-line:vertical:pressed\n"
"{\n"
"	height: 15px;\n"
"	width: 15px;\n"
"	subcontrol-position: bottom;\n"
""
                        "	subcontrol-origin: margin;\n"
"	border-image: url(:/Images/down_pre.png);\n"
"}\n"
"\n"
"QScrollBar:add-line:horizontal\n"
"{\n"
"	height: 15px;\n"
"	width: 15px;\n"
"	subcontrol-position: right;\n"
"	subcontrol-origin: margin;\n"
"	border-image: url(:/Images/right.png);\n"
"}\n"
"\n"
"QScrollBar:add-line:horizontal:pressed\n"
"{\n"
"	height: 15px;\n"
"	width: 15px;\n"
"	subcontrol-position: right;\n"
"	subcontrol-origin: margin;\n"
"	border-image: url(:/Images/right_pre.png);\n"
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
"QScrollBar:sub-line:horizontal\n"
"{\n"
"	height: 15px;\n"
"	width: 15px;\n"
"	subcontrol-position: left;\n"
"	subcontrol-origin: mar"
                        "gin;\n"
"	border-image: url(:/Images/left.png);\n"
"}\n"
"\n"
"QScrollBar:sub-line:horizontal:pressed\n"
"{\n"
"	height: 15px;\n"
"	width: 15px;\n"
"	subcontrol-position: left;\n"
"	subcontrol-origin: margin;\n"
"	border-image: url(:/Images/left_pre.png);\n"
"}\n"
"\n"
"QScrollBar:handle:vertical,\n"
"QScrollBar:handle:horizontal\n"
"{\n"
"	background: #1296db;\n"
"	width: 15px;\n"
"}\n"
"\n"
"QScrollBar:handle:vertical:hover,\n"
"QScrollBar:handle:horizontal:hover\n"
"{\n"
"	width: 15px;\n"
"	background: #00aaff;\n"
"}\n"
"\n"
"QCheckBox:indicator\n"
"{\n"
"	width: 20px;\n"
"	height: 20px;\n"
"}\n"
"\n"
"QCheckBox:indicator:unchecked\n"
"{\n"
"	image: url(:/Images/uncheck.png);\n"
"}\n"
"\n"
"QCheckBox:indicator:checked\n"
"{ \n"
"	image: url(:/Images/check.png);\n"
"}"));
        verticalLayout = new QVBoxLayout(Message);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new MenuBar(Message);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        verticalLayout->addWidget(widget_2);

        messageView = new QTableView(Message);
        messageView->setObjectName(QString::fromUtf8("messageView"));
        messageView->setFocusPolicy(Qt::NoFocus);
        messageView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        messageView->setSelectionMode(QAbstractItemView::SingleSelection);
        messageView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(messageView);

        widget = new QWidget(Message);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        statusCheckBox = new QCheckBox(widget);
        statusCheckBox->setObjectName(QString::fromUtf8("statusCheckBox"));
        statusCheckBox->setLayoutDirection(Qt::RightToLeft);
        statusCheckBox->setStyleSheet(QString::fromUtf8("QCheckBox\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;  \n"
"	color: #1296db;\n"
"	font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));

        horizontalLayout->addWidget(statusCheckBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        confirmButton = new QPushButton(widget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setMinimumSize(QSize(75, 0));
        confirmButton->setFocusPolicy(Qt::NoFocus);
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

        widget_5 = new QWidget(Message);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(widget_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;  \n"
"	color: #1296db;\n"
"	font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));

        horizontalLayout_4->addWidget(label);

        typeComboBox = new QComboBox(widget_5);
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->setObjectName(QString::fromUtf8("typeComboBox"));
        typeComboBox->setMinimumSize(QSize(60, 0));
        typeComboBox->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_4->addWidget(typeComboBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_5);

        widget_3 = new QWidget(Message);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;  \n"
"	color: #1296db;\n"
"	font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));

        horizontalLayout_2->addWidget(label_2);

        searchEdit = new QLineEdit(widget_3);
        searchEdit->setObjectName(QString::fromUtf8("searchEdit"));
        searchEdit->setMaximumSize(QSize(320, 16777215));

        horizontalLayout_2->addWidget(searchEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Message);

        QMetaObject::connectSlotsByName(Message);
    } // setupUi

    void retranslateUi(QWidget *Message)
    {
        Message->setWindowTitle(QCoreApplication::translate("Message", "Form", nullptr));
        statusCheckBox->setText(QCoreApplication::translate("Message", "\346\230\276\347\244\272\345\267\262\345\244\204\347\220\206", nullptr));
        confirmButton->setText(QCoreApplication::translate("Message", "\345\244\204\347\220\206", nullptr));
        label->setText(QCoreApplication::translate("Message", "\346\237\245\347\234\213\347\261\273\345\236\213", nullptr));
        typeComboBox->setItemText(0, QCoreApplication::translate("Message", "\346\227\240", nullptr));
        typeComboBox->setItemText(1, QCoreApplication::translate("Message", "\345\200\237\344\271\246", nullptr));
        typeComboBox->setItemText(2, QCoreApplication::translate("Message", "\350\277\230\344\271\246", nullptr));

        label_2->setText(QCoreApplication::translate("Message", "\347\224\250\346\210\267\346\220\234\347\264\242", nullptr));
        searchEdit->setPlaceholderText(QCoreApplication::translate("Message", "\350\257\267\350\276\223\345\205\245\351\234\200\350\246\201\346\220\234\347\264\242\347\232\204\350\264\246\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Message: public Ui_Message {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGE_H
