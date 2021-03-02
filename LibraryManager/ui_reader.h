/********************************************************************************
** Form generated from reading UI file 'reader.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READER_H
#define UI_READER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_Reader
{
public:
    QVBoxLayout *verticalLayout;
    MenuBar *widget_2;
    QLabel *label_2;
    QTableView *readerView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *deleteButton;
    QLabel *label_3;
    QTableView *bookInfoView;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *confirmButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *Reader)
    {
        if (Reader->objectName().isEmpty())
            Reader->setObjectName(QString::fromUtf8("Reader"));
        Reader->resize(745, 585);
        Reader->setStyleSheet(QString::fromUtf8("QLabel,\n"
"QPushButton \n"
"{\n"
"	border: none;\n"
"	color: #1296db;\n"
"	font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
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
"	subcontrol-position: bottom;\n"
"	subcontrol-origin: margin;\n"
"	"
                        "border-image: url(:/Images/down.png);\n"
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
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	color: #ffffff;\n"
"}\n"
"\n"
"QMessageBox\n"
"{\n"
"	border-image: url(:/Images/dialog.jpg);\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"	border: none;\n"
"	"
                        "color: #000000;\n"
"	font: 75 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	border-radius: 5px;\n"
"	selection-background-color: #def0fe;\n"
"	selection-color: #1296db;\n"
"}"));
        verticalLayout = new QVBoxLayout(Reader);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        widget_2 = new MenuBar(Reader);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        verticalLayout->addWidget(widget_2);

        label_2 = new QLabel(Reader);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;  \n"
"	color: #1296db;\n"
"	font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));

        verticalLayout->addWidget(label_2);

        readerView = new QTableView(Reader);
        readerView->setObjectName(QString::fromUtf8("readerView"));
        readerView->setFocusPolicy(Qt::NoFocus);
        readerView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        readerView->setSelectionMode(QAbstractItemView::SingleSelection);
        readerView->setSelectionBehavior(QAbstractItemView::SelectRows);
        readerView->setSortingEnabled(true);

        verticalLayout->addWidget(readerView);

        widget = new QWidget(Reader);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        searchEdit = new QLineEdit(widget);
        searchEdit->setObjectName(QString::fromUtf8("searchEdit"));
        searchEdit->setMaximumSize(QSize(320, 16777215));

        horizontalLayout->addWidget(searchEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        deleteButton = new QPushButton(widget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setFocusPolicy(Qt::NoFocus);
        deleteButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
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

        horizontalLayout->addWidget(deleteButton);


        verticalLayout->addWidget(widget);

        label_3 = new QLabel(Reader);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;  \n"
"	color: #1296db;\n"
"	font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));

        verticalLayout->addWidget(label_3);

        bookInfoView = new QTableView(Reader);
        bookInfoView->setObjectName(QString::fromUtf8("bookInfoView"));
        bookInfoView->setFocusPolicy(Qt::NoFocus);
        bookInfoView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        bookInfoView->setSelectionMode(QAbstractItemView::SingleSelection);
        bookInfoView->setSelectionBehavior(QAbstractItemView::SelectRows);
        bookInfoView->setSortingEnabled(true);

        verticalLayout->addWidget(bookInfoView);

        widget_3 = new QWidget(Reader);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        confirmButton = new QPushButton(widget_3);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setMinimumSize(QSize(250, 30));
        confirmButton->setMaximumSize(QSize(250, 30));
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
"}\n"
""));

        horizontalLayout_2->addWidget(confirmButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget_4 = new QWidget(Reader);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label = new QLabel(widget_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;  \n"
"	color: #1296db;\n"
"	font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addWidget(widget_4);


        retranslateUi(Reader);

        QMetaObject::connectSlotsByName(Reader);
    } // setupUi

    void retranslateUi(QWidget *Reader)
    {
        Reader->setWindowTitle(QCoreApplication::translate("Reader", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Reader", "\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        searchEdit->setPlaceholderText(QCoreApplication::translate("Reader", "\350\257\267\350\276\223\345\205\245\346\243\200\347\264\242\350\264\246\345\217\267", nullptr));
        deleteButton->setText(QCoreApplication::translate("Reader", "\346\263\250\351\224\200\346\255\244\350\264\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("Reader", "\351\200\276\346\234\237\344\271\246\347\261\215", nullptr));
        confirmButton->setText(QCoreApplication::translate("Reader", "\347\241\256\350\256\244\345\275\222\350\277\230", nullptr));
        label->setText(QCoreApplication::translate("Reader", "\347\256\241\347\220\206\345\221\230\344\270\215\345\276\227\346\263\204\351\234\262\344\273\273\344\275\225\346\234\211\345\205\263\347\224\250\346\210\267\347\232\204\344\277\241\346\201\257\357\274\214\350\277\235\350\200\205\345\277\205\347\251\266\357\274\201\357\274\201\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reader: public Ui_Reader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READER_H
