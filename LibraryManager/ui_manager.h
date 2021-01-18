/********************************************************************************
** Form generated from reading UI file 'manager.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_Manager
{
public:
    QVBoxLayout *verticalLayout;
    MenuBar *widget_4;
    QLabel *bookInfoLabel;
    QTableView *bookInfoView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *queryTypeLabel;
    QComboBox *queryTypeComboBox;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *queryContentLabel;
    QLineEdit *queryEdit;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QSpacerItem *horizontalSpacer;
    QWidget *addWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *numLabel;
    QLineEdit *numEdit;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *publishLabel;
    QLineEdit *publishEdit;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QLabel *authorLabel;
    QLineEdit *authorEdit;
    QLabel *inventoryLabel;
    QLineEdit *inventoryEdit;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *confirmButton;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Manager)
    {
        if (Manager->objectName().isEmpty())
            Manager->setObjectName(QString::fromUtf8("Manager"));
        Manager->resize(851, 545);
        verticalLayout = new QVBoxLayout(Manager);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_4 = new MenuBar(Manager);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));

        verticalLayout->addWidget(widget_4);

        bookInfoLabel = new QLabel(Manager);
        bookInfoLabel->setObjectName(QString::fromUtf8("bookInfoLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bookInfoLabel->sizePolicy().hasHeightForWidth());
        bookInfoLabel->setSizePolicy(sizePolicy);
        bookInfoLabel->setMinimumSize(QSize(0, 0));
        bookInfoLabel->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(bookInfoLabel);

        bookInfoView = new QTableView(Manager);
        bookInfoView->setObjectName(QString::fromUtf8("bookInfoView"));
        sizePolicy.setHeightForWidth(bookInfoView->sizePolicy().hasHeightForWidth());
        bookInfoView->setSizePolicy(sizePolicy);
        bookInfoView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        bookInfoView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        bookInfoView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        bookInfoView->setAlternatingRowColors(false);
        bookInfoView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        bookInfoView->setSelectionBehavior(QAbstractItemView::SelectRows);
        bookInfoView->setTextElideMode(Qt::ElideLeft);
        bookInfoView->setSortingEnabled(true);

        verticalLayout->addWidget(bookInfoView);

        widget = new QWidget(Manager);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        queryTypeLabel = new QLabel(widget);
        queryTypeLabel->setObjectName(QString::fromUtf8("queryTypeLabel"));
        sizePolicy.setHeightForWidth(queryTypeLabel->sizePolicy().hasHeightForWidth());
        queryTypeLabel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(queryTypeLabel);

        queryTypeComboBox = new QComboBox(widget);
        queryTypeComboBox->addItem(QString());
        queryTypeComboBox->addItem(QString());
        queryTypeComboBox->addItem(QString());
        queryTypeComboBox->addItem(QString());
        queryTypeComboBox->addItem(QString());
        queryTypeComboBox->setObjectName(QString::fromUtf8("queryTypeComboBox"));
        sizePolicy.setHeightForWidth(queryTypeComboBox->sizePolicy().hasHeightForWidth());
        queryTypeComboBox->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(queryTypeComboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(Manager);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        queryContentLabel = new QLabel(widget_2);
        queryContentLabel->setObjectName(QString::fromUtf8("queryContentLabel"));
        sizePolicy.setHeightForWidth(queryContentLabel->sizePolicy().hasHeightForWidth());
        queryContentLabel->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(queryContentLabel);

        queryEdit = new QLineEdit(widget_2);
        queryEdit->setObjectName(QString::fromUtf8("queryEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(queryEdit->sizePolicy().hasHeightForWidth());
        queryEdit->setSizePolicy(sizePolicy1);
        queryEdit->setMaximumSize(QSize(320, 16777215));
        queryEdit->setClearButtonEnabled(true);

        horizontalLayout_2->addWidget(queryEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(Manager);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(9, -1, 9, -1);
        addButton = new QPushButton(widget_3);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout_3->addWidget(addButton);

        deleteButton = new QPushButton(widget_3);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout_3->addWidget(deleteButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget_3);

        addWidget = new QWidget(Manager);
        addWidget->setObjectName(QString::fromUtf8("addWidget"));
        verticalLayout_2 = new QVBoxLayout(addWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_6 = new QWidget(addWidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        numLabel = new QLabel(widget_6);
        numLabel->setObjectName(QString::fromUtf8("numLabel"));

        horizontalLayout_4->addWidget(numLabel);

        numEdit = new QLineEdit(widget_6);
        numEdit->setObjectName(QString::fromUtf8("numEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(numEdit->sizePolicy().hasHeightForWidth());
        numEdit->setSizePolicy(sizePolicy2);
        numEdit->setMinimumSize(QSize(150, 0));
        numEdit->setClearButtonEnabled(true);

        horizontalLayout_4->addWidget(numEdit);

        nameLabel = new QLabel(widget_6);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        horizontalLayout_4->addWidget(nameLabel);

        nameEdit = new QLineEdit(widget_6);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        sizePolicy2.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy2);
        nameEdit->setMinimumSize(QSize(150, 0));
        nameEdit->setClearButtonEnabled(true);

        horizontalLayout_4->addWidget(nameEdit);

        publishLabel = new QLabel(widget_6);
        publishLabel->setObjectName(QString::fromUtf8("publishLabel"));

        horizontalLayout_4->addWidget(publishLabel);

        publishEdit = new QLineEdit(widget_6);
        publishEdit->setObjectName(QString::fromUtf8("publishEdit"));
        sizePolicy2.setHeightForWidth(publishEdit->sizePolicy().hasHeightForWidth());
        publishEdit->setSizePolicy(sizePolicy2);
        publishEdit->setMinimumSize(QSize(150, 0));
        publishEdit->setClearButtonEnabled(true);

        horizontalLayout_4->addWidget(publishEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_2->addWidget(widget_6);

        widget_7 = new QWidget(addWidget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        authorLabel = new QLabel(widget_7);
        authorLabel->setObjectName(QString::fromUtf8("authorLabel"));

        horizontalLayout_5->addWidget(authorLabel);

        authorEdit = new QLineEdit(widget_7);
        authorEdit->setObjectName(QString::fromUtf8("authorEdit"));
        sizePolicy2.setHeightForWidth(authorEdit->sizePolicy().hasHeightForWidth());
        authorEdit->setSizePolicy(sizePolicy2);
        authorEdit->setMinimumSize(QSize(150, 0));
        authorEdit->setClearButtonEnabled(true);

        horizontalLayout_5->addWidget(authorEdit);

        inventoryLabel = new QLabel(widget_7);
        inventoryLabel->setObjectName(QString::fromUtf8("inventoryLabel"));

        horizontalLayout_5->addWidget(inventoryLabel);

        inventoryEdit = new QLineEdit(widget_7);
        inventoryEdit->setObjectName(QString::fromUtf8("inventoryEdit"));
        sizePolicy2.setHeightForWidth(inventoryEdit->sizePolicy().hasHeightForWidth());
        inventoryEdit->setSizePolicy(sizePolicy2);
        inventoryEdit->setMinimumSize(QSize(150, 0));
        inventoryEdit->setClearButtonEnabled(true);

        horizontalLayout_5->addWidget(inventoryEdit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_2->addWidget(widget_7);

        widget_5 = new QWidget(addWidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_6 = new QHBoxLayout(widget_5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        confirmButton = new QPushButton(widget_5);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));

        horizontalLayout_6->addWidget(confirmButton);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);


        verticalLayout_2->addWidget(widget_5);


        verticalLayout->addWidget(addWidget);

        verticalSpacer = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Manager);

        QMetaObject::connectSlotsByName(Manager);
    } // setupUi

    void retranslateUi(QWidget *Manager)
    {
        Manager->setWindowTitle(QCoreApplication::translate("Manager", "Form", nullptr));
        bookInfoLabel->setText(QCoreApplication::translate("Manager", "\345\233\276\344\271\246\344\277\241\346\201\257", nullptr));
        queryTypeLabel->setText(QCoreApplication::translate("Manager", "\346\237\245\350\257\242\347\261\273\345\236\213", nullptr));
        queryTypeComboBox->setItemText(0, QCoreApplication::translate("Manager", "\347\274\226\345\217\267", nullptr));
        queryTypeComboBox->setItemText(1, QCoreApplication::translate("Manager", "\344\271\246\345\220\215", nullptr));
        queryTypeComboBox->setItemText(2, QCoreApplication::translate("Manager", "\345\207\272\347\211\210\347\244\276", nullptr));
        queryTypeComboBox->setItemText(3, QCoreApplication::translate("Manager", "\344\275\234\350\200\205", nullptr));
        queryTypeComboBox->setItemText(4, QCoreApplication::translate("Manager", "\345\272\223\345\255\230", nullptr));

        queryContentLabel->setText(QCoreApplication::translate("Manager", "\346\237\245\350\257\242\345\206\205\345\256\271", nullptr));
        addButton->setText(QCoreApplication::translate("Manager", "\346\267\273\345\212\240\344\271\246\347\261\215", nullptr));
        deleteButton->setText(QCoreApplication::translate("Manager", "\345\210\240\351\231\244\344\271\246\347\261\215", nullptr));
        numLabel->setText(QCoreApplication::translate("Manager", "\347\274\226\345\217\267:", nullptr));
        nameLabel->setText(QCoreApplication::translate("Manager", "\344\271\246\345\220\215:", nullptr));
        publishLabel->setText(QCoreApplication::translate("Manager", "\345\207\272\347\211\210\347\244\276:", nullptr));
        authorLabel->setText(QCoreApplication::translate("Manager", "\344\275\234\350\200\205:", nullptr));
        inventoryLabel->setText(QCoreApplication::translate("Manager", "\345\272\223\345\255\230:", nullptr));
        confirmButton->setText(QCoreApplication::translate("Manager", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Manager: public Ui_Manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGER_H
