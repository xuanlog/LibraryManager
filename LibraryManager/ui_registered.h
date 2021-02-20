/********************************************************************************
** Form generated from reading UI file 'registered.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERED_H
#define UI_REGISTERED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registered
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *accountEdit;
    QLineEdit *passwordEdit;
    QLineEdit *confirmEdit;
    QLineEdit *addressEdit;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *registeredButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Registered)
    {
        if (Registered->objectName().isEmpty())
            Registered->setObjectName(QString::fromUtf8("Registered"));
        Registered->resize(733, 511);
        Registered->setStyleSheet(QString::fromUtf8("QLabel,\n"
"QPushButton \n"
"{\n"
"	border: none;\n"
"	color: #1296db;\n"
"	font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLabel:hover,\n"
"QPushButton:hover\n"
"{\n"
"	color: #ffffff;\n"
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
"QPushButton:pressed\n"
"{\n"
"	color: #00aaff;\n"
"}\n"
"\n"
"QMessageBox\n"
"{\n"
"	border-image: url(:/Images/dialog.jpg);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(Registered);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, -1, 50);
        widget_5 = new QWidget(Registered);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        backButton = new QPushButton(widget_5);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setMinimumSize(QSize(32, 32));
        backButton->setFocusPolicy(Qt::NoFocus);
        backButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-image: url(:/Images/back.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-image: url(:/Images/back_hover.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	border-image: url(:/Images/back_pre.png);\n"
"}\n"
"\n"
"\n"
""));
        backButton->setIconSize(QSize(32, 32));
        backButton->setFlat(true);

        horizontalLayout_3->addWidget(backButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label = new QLabel(widget_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 25px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(32, 32));

        horizontalLayout_3->addWidget(label_2);


        verticalLayout_3->addWidget(widget_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        widget_3 = new QWidget(Registered);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        accountEdit = new QLineEdit(widget_2);
        accountEdit->setObjectName(QString::fromUtf8("accountEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(accountEdit->sizePolicy().hasHeightForWidth());
        accountEdit->setSizePolicy(sizePolicy);
        accountEdit->setMinimumSize(QSize(230, 0));
        accountEdit->setMaximumSize(QSize(16777215, 16777215));
        accountEdit->setFocusPolicy(Qt::StrongFocus);
        accountEdit->setMaxLength(20);
        accountEdit->setClearButtonEnabled(false);

        verticalLayout_2->addWidget(accountEdit);

        passwordEdit = new QLineEdit(widget_2);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        sizePolicy.setHeightForWidth(passwordEdit->sizePolicy().hasHeightForWidth());
        passwordEdit->setSizePolicy(sizePolicy);
        passwordEdit->setMinimumSize(QSize(230, 0));
        passwordEdit->setMaximumSize(QSize(16777215, 16777215));
        passwordEdit->setFocusPolicy(Qt::StrongFocus);
        passwordEdit->setMaxLength(20);
        passwordEdit->setEchoMode(QLineEdit::Password);
        passwordEdit->setClearButtonEnabled(false);

        verticalLayout_2->addWidget(passwordEdit);

        confirmEdit = new QLineEdit(widget_2);
        confirmEdit->setObjectName(QString::fromUtf8("confirmEdit"));
        sizePolicy.setHeightForWidth(confirmEdit->sizePolicy().hasHeightForWidth());
        confirmEdit->setSizePolicy(sizePolicy);
        confirmEdit->setMinimumSize(QSize(230, 0));
        confirmEdit->setMaximumSize(QSize(16777215, 16777215));
        confirmEdit->setFocusPolicy(Qt::StrongFocus);
        confirmEdit->setMaxLength(20);
        confirmEdit->setEchoMode(QLineEdit::Password);
        confirmEdit->setClearButtonEnabled(false);

        verticalLayout_2->addWidget(confirmEdit);

        addressEdit = new QLineEdit(widget_2);
        addressEdit->setObjectName(QString::fromUtf8("addressEdit"));
        sizePolicy.setHeightForWidth(addressEdit->sizePolicy().hasHeightForWidth());
        addressEdit->setSizePolicy(sizePolicy);
        addressEdit->setMinimumSize(QSize(230, 0));
        addressEdit->setMaximumSize(QSize(16777215, 16777215));
        addressEdit->setFocusPolicy(Qt::StrongFocus);
        addressEdit->setMaxLength(20);
        addressEdit->setEchoMode(QLineEdit::Normal);
        addressEdit->setClearButtonEnabled(false);

        verticalLayout_2->addWidget(addressEdit);


        horizontalLayout->addWidget(widget_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(widget_3);

        widget_4 = new QWidget(Registered);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        registeredButton = new QPushButton(widget_4);
        registeredButton->setObjectName(QString::fromUtf8("registeredButton"));
        registeredButton->setMinimumSize(QSize(75, 0));
        registeredButton->setFocusPolicy(Qt::NoFocus);
        registeredButton->setStyleSheet(QString::fromUtf8("QPushButton \n"
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

        horizontalLayout_2->addWidget(registeredButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_3->addWidget(widget_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(Registered);

        QMetaObject::connectSlotsByName(Registered);
    } // setupUi

    void retranslateUi(QWidget *Registered)
    {
        Registered->setWindowTitle(QCoreApplication::translate("Registered", "Form", nullptr));
        backButton->setText(QString());
        label->setText(QCoreApplication::translate("Registered", "\346\263\250\345\206\214", nullptr));
        label_2->setText(QString());
        accountEdit->setPlaceholderText(QCoreApplication::translate("Registered", "\350\257\267\350\276\223\345\205\2456-20\344\275\215\350\264\246\345\217\267", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("Registered", "\350\257\267\350\276\223\345\205\2456-20\344\275\215\345\257\206\347\240\201", nullptr));
        confirmEdit->setPlaceholderText(QCoreApplication::translate("Registered", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        addressEdit->setPlaceholderText(QCoreApplication::translate("Registered", "\350\257\267\350\276\223\345\205\245\346\224\266\350\264\247\345\234\260\345\235\200", nullptr));
        registeredButton->setText(QCoreApplication::translate("Registered", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registered: public Ui_Registered {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERED_H
