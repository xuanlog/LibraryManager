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
#include <QtWidgets/QLabel>
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
    QLabel *label;
    QPushButton *personalButton;
    QWidget *managerWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *managerButton;
    QLabel *label_2;
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
        stackRoomButton->setMinimumSize(QSize(32, 32));
        stackRoomButton->setFocusPolicy(Qt::NoFocus);
        stackRoomButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;\n"
"	border-image: url(:/Images/home.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;\n"
"	border-image: url(:/Images/home_pre.png);\n"
"}\n"
""));
        stackRoomButton->setFlat(true);

        horizontalLayout_2->addWidget(stackRoomButton);

        label = new QLabel(userWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(43, 0));

        horizontalLayout_2->addWidget(label);

        personalButton = new QPushButton(userWidget);
        personalButton->setObjectName(QString::fromUtf8("personalButton"));
        personalButton->setMinimumSize(QSize(32, 32));
        personalButton->setFocusPolicy(Qt::NoFocus);
        personalButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;\n"
"	border-image: url(:/Images/user.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;\n"
"	border-image: url(:/Images/user_pre.png);\n"
"}"));
        personalButton->setFlat(true);

        horizontalLayout_2->addWidget(personalButton);


        horizontalLayout->addWidget(userWidget);

        managerWidget = new QWidget(MenuBar);
        managerWidget->setObjectName(QString::fromUtf8("managerWidget"));
        horizontalLayout_3 = new QHBoxLayout(managerWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        managerButton = new QPushButton(managerWidget);
        managerButton->setObjectName(QString::fromUtf8("managerButton"));
        managerButton->setMinimumSize(QSize(32, 32));
        managerButton->setFocusPolicy(Qt::NoFocus);
        managerButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;\n"
"	border-image: url(:/Images/book.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;\n"
"	border-image: url(:/Images/book_pre.png);\n"
"}"));
        managerButton->setFlat(true);

        horizontalLayout_3->addWidget(managerButton);

        label_2 = new QLabel(managerWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(43, 0));

        horizontalLayout_3->addWidget(label_2);

        readerButton = new QPushButton(managerWidget);
        readerButton->setObjectName(QString::fromUtf8("readerButton"));
        readerButton->setMinimumSize(QSize(32, 32));
        readerButton->setFocusPolicy(Qt::NoFocus);
        readerButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;\n"
"	border-image: url(:/Images/reader.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;\n"
"	border-image: url(:/Images/reader_pre.png);\n"
"}"));
        readerButton->setFlat(true);

        horizontalLayout_3->addWidget(readerButton);


        horizontalLayout->addWidget(managerWidget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        logoutButton = new QPushButton(MenuBar);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));
        logoutButton->setMinimumSize(QSize(32, 32));
        logoutButton->setFocusPolicy(Qt::NoFocus);
        logoutButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;\n"
"	border-image: url(:/Images/logout.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;\n"
"	border-image: url(:/Images/logout_pre.png);\n"
"}"));
        logoutButton->setFlat(true);

        horizontalLayout->addWidget(logoutButton);


        retranslateUi(MenuBar);

        QMetaObject::connectSlotsByName(MenuBar);
    } // setupUi

    void retranslateUi(QWidget *MenuBar)
    {
        MenuBar->setWindowTitle(QCoreApplication::translate("MenuBar", "Form", nullptr));
#if QT_CONFIG(tooltip)
        stackRoomButton->setToolTip(QCoreApplication::translate("MenuBar", "\344\271\246\345\272\223", nullptr));
#endif // QT_CONFIG(tooltip)
        stackRoomButton->setText(QString());
        label->setText(QString());
#if QT_CONFIG(tooltip)
        personalButton->setToolTip(QCoreApplication::translate("MenuBar", "\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
#endif // QT_CONFIG(tooltip)
        personalButton->setText(QString());
#if QT_CONFIG(tooltip)
        managerButton->setToolTip(QCoreApplication::translate("MenuBar", "\344\271\246\347\261\215\347\256\241\347\220\206", nullptr));
#endif // QT_CONFIG(tooltip)
        managerButton->setText(QString());
        label_2->setText(QString());
#if QT_CONFIG(tooltip)
        readerButton->setToolTip(QCoreApplication::translate("MenuBar", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
#endif // QT_CONFIG(tooltip)
        readerButton->setText(QString());
#if QT_CONFIG(tooltip)
        logoutButton->setToolTip(QCoreApplication::translate("MenuBar", "\345\210\207\346\215\242\350\264\246\345\217\267", nullptr));
#endif // QT_CONFIG(tooltip)
        logoutButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuBar: public Ui_MenuBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUBAR_H
