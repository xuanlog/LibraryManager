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
    QPushButton *stackRoomButton;
    QPushButton *personalButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *MenuBar)
    {
        if (MenuBar->objectName().isEmpty())
            MenuBar->setObjectName(QString::fromUtf8("MenuBar"));
        MenuBar->resize(777, 364);
        horizontalLayout = new QHBoxLayout(MenuBar);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        stackRoomButton = new QPushButton(MenuBar);
        stackRoomButton->setObjectName(QString::fromUtf8("stackRoomButton"));

        horizontalLayout->addWidget(stackRoomButton);

        personalButton = new QPushButton(MenuBar);
        personalButton->setObjectName(QString::fromUtf8("personalButton"));

        horizontalLayout->addWidget(personalButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(MenuBar);

        QMetaObject::connectSlotsByName(MenuBar);
    } // setupUi

    void retranslateUi(QWidget *MenuBar)
    {
        MenuBar->setWindowTitle(QCoreApplication::translate("MenuBar", "Form", nullptr));
        stackRoomButton->setText(QCoreApplication::translate("MenuBar", "\344\271\246\345\272\223\345\244\247\345\216\205", nullptr));
        personalButton->setText(QCoreApplication::translate("MenuBar", "\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuBar: public Ui_MenuBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUBAR_H
