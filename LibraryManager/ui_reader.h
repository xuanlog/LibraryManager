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
    QTableView *readerView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Reader)
    {
        if (Reader->objectName().isEmpty())
            Reader->setObjectName(QString::fromUtf8("Reader"));
        Reader->resize(787, 572);
        verticalLayout = new QVBoxLayout(Reader);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new MenuBar(Reader);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        verticalLayout->addWidget(widget_2);

        readerView = new QTableView(Reader);
        readerView->setObjectName(QString::fromUtf8("readerView"));
        readerView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        readerView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(readerView);

        widget = new QWidget(Reader);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        deleteButton = new QPushButton(widget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout->addWidget(deleteButton);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Reader);

        QMetaObject::connectSlotsByName(Reader);
    } // setupUi

    void retranslateUi(QWidget *Reader)
    {
        Reader->setWindowTitle(QCoreApplication::translate("Reader", "Form", nullptr));
        deleteButton->setText(QCoreApplication::translate("Reader", "\346\263\250\351\224\200\346\255\244\350\264\246\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reader: public Ui_Reader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READER_H
