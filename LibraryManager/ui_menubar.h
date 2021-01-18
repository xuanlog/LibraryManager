/********************************************************************************
** Form generated from reading UI file 'menubar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUBAR_H
#define UI_MENUBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuBar
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *userWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *stackRoomButton;
    QPushButton *personalButton;
    QWidget *managerWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *managerButton;
    QPushButton *readerButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *logoutButton;

    void setupUi(QWidget *MenuBar)
    {
        if (MenuBar->objectName().isEmpty())
            MenuBar->setObjectName(QString::fromUtf8("MenuBar"));
        MenuBar->resize(777, 364);
        horizontalLayout = new QHBoxLayout(MenuBar);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        userWidget = new QWidget(MenuBar);
        userWidget->setObjectName(QString::fromUtf8("userWidget"));
        horizontalLayout_2 = new QHBoxLayout(userWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        stackRoomButton = new QPushButton(userWidget);
        stackRoomButton->setObjectName(QString::fromUtf8("stackRoomButton"));

        horizontalLayout_2->addWidget(stackRoomButton);

        personalButton = new QPushButton(userWidget);
        personalButton->setObjectName(QString::fromUtf8("personalButton"));

        horizontalLayout_2->addWidget(personalButton);


        horizontalLayout->addWidget(userWidget);

        managerWidget = new QWidget(MenuBar);
        managerWidget->setObjectName(QString::fromUtf8("managerWidget"));
        horizontalLayout_3 = new QHBoxLayout(managerWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        managerButton = new QPushButton(managerWidget);
        managerButton->setObjectName(QString::fromUtf8("managerButton"));

        horizontalLayout_3->addWidget(managerButton);

        readerButton = new QPushButton(managerWidget);
        readerButton->setObjectName(QString::fromUtf8("readerButton"));

        horizontalLayout_3->addWidget(readerButton);


        horizontalLayout->addWidget(managerWidget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        logoutButton = new QPushButton(MenuBar);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));

        horizontalLayout->addWidget(logoutButton);


        retranslateUi(MenuBar);

        QMetaObject::connectSlotsByName(MenuBar);
    } // setupUi

    void retranslateUi(QWidget *MenuBar)
    {
        MenuBar->setWindowTitle(QCoreApplication::translate("MenuBar", "Form", nullptr));
        stackRoomButton->setText(QCoreApplication::translate("MenuBar", "\344\271\246\345\272\223\345\244\247\345\216\205", nullptr));
        personalButton->setText(QCoreApplication::translate("MenuBar", "\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
        managerButton->setText(QCoreApplication::translate("MenuBar", "\344\271\246\347\261\215\347\256\241\347\220\206", nullptr));
        readerButton->setText(QCoreApplication::translate("MenuBar", "\350\257\273\350\200\205\347\256\241\347\220\206", nullptr));
        logoutButton->setText(QCoreApplication::translate("MenuBar", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuBar: public Ui_MenuBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUBAR_H
