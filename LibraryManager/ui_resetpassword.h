/********************************************************************************
** Form generated from reading UI file 'resetpassword.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETPASSWORD_H
#define UI_RESETPASSWORD_H

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

class Ui_ResetPassword
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
    QLineEdit *nameEdit;
    QLineEdit *phoneEdit;
    QLineEdit *passwordEdit;
    QLineEdit *confirmEdit;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *confirmButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ResetPassword)
    {
        if (ResetPassword->objectName().isEmpty())
            ResetPassword->setObjectName(QString::fromUtf8("ResetPassword"));
        ResetPassword->resize(729, 590);
        ResetPassword->setStyleSheet(QString::fromUtf8("QLabel,\n"
"QPushButton \n"
"{\n"
"	border: none;\n"
"	color: #1296db;\n"
"	font: 14px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
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
"	color: #ffffff;\n"
"}\n"
"\n"
"QMessageBox\n"
"{\n"
"	border-image: url(:/Images/dialog.jpg);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(ResetPassword);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, -1, 50);
        widget_5 = new QWidget(ResetPassword);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        backButton = new QPushButton(widget_5);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setMinimumSize(QSize(32, 32));
        backButton->setFocusPolicy(Qt::NoFocus);
        backButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;\n"
"	border-image: url(:/Images/back.png);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;\n"
"	border-image: url(:/Images/back_pre.png);\n"
"}"));
        backButton->setFlat(true);

        horizontalLayout_3->addWidget(backButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label = new QLabel(widget_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color: rgba(255, 255, 255, 0.7);\n"
"    border-radius: 4px;  \n"
"	color: #1296db;\n"
"	font: 25px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(32, 32));

        horizontalLayout_3->addWidget(label_2);


        verticalLayout_3->addWidget(widget_5);

        verticalSpacer_2 = new QSpacerItem(20, 113, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        widget_3 = new QWidget(ResetPassword);
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

        nameEdit = new QLineEdit(widget_2);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        sizePolicy.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy);
        nameEdit->setMinimumSize(QSize(230, 0));
        nameEdit->setMaximumSize(QSize(16777215, 16777215));
        nameEdit->setFocusPolicy(Qt::StrongFocus);
        nameEdit->setMaxLength(20);
        nameEdit->setClearButtonEnabled(false);

        verticalLayout_2->addWidget(nameEdit);

        phoneEdit = new QLineEdit(widget_2);
        phoneEdit->setObjectName(QString::fromUtf8("phoneEdit"));
        sizePolicy.setHeightForWidth(phoneEdit->sizePolicy().hasHeightForWidth());
        phoneEdit->setSizePolicy(sizePolicy);
        phoneEdit->setMinimumSize(QSize(230, 0));
        phoneEdit->setMaximumSize(QSize(16777215, 16777215));
        phoneEdit->setFocusPolicy(Qt::StrongFocus);
        phoneEdit->setMaxLength(20);
        phoneEdit->setClearButtonEnabled(false);

        verticalLayout_2->addWidget(phoneEdit);

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


        horizontalLayout->addWidget(widget_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(widget_3);

        widget_4 = new QWidget(ResetPassword);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        confirmButton = new QPushButton(widget_4);
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

        horizontalLayout_2->addWidget(confirmButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_3->addWidget(widget_4);

        verticalSpacer = new QSpacerItem(20, 112, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(ResetPassword);

        QMetaObject::connectSlotsByName(ResetPassword);
    } // setupUi

    void retranslateUi(QWidget *ResetPassword)
    {
        ResetPassword->setWindowTitle(QCoreApplication::translate("ResetPassword", "Form", nullptr));
        backButton->setText(QString());
        label->setText(QCoreApplication::translate("ResetPassword", "\351\207\215\347\275\256\345\257\206\347\240\201", nullptr));
        label_2->setText(QString());
        accountEdit->setPlaceholderText(QCoreApplication::translate("ResetPassword", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        nameEdit->setPlaceholderText(QCoreApplication::translate("ResetPassword", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215", nullptr));
        phoneEdit->setPlaceholderText(QCoreApplication::translate("ResetPassword", "\350\257\267\350\276\223\345\205\245\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("ResetPassword", "\350\257\267\350\276\223\345\205\2456-20\344\275\215\345\257\206\347\240\201", nullptr));
        confirmEdit->setPlaceholderText(QCoreApplication::translate("ResetPassword", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        confirmButton->setText(QCoreApplication::translate("ResetPassword", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetPassword: public Ui_ResetPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETPASSWORD_H
