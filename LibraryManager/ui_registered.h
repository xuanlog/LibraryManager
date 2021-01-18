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
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *accountLabel;
    QLabel *passwordLabel;
    QLabel *confirmLabel;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *accountEdit;
    QLineEdit *passwordEdit;
    QLineEdit *confirmEdit;
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
        verticalLayout_3 = new QVBoxLayout(Registered);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, -1, 50);
        widget_5 = new QWidget(Registered);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        backButton = new QPushButton(widget_5);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        horizontalLayout_3->addWidget(backButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_3->addWidget(widget_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        widget_3 = new QWidget(Registered);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(widget_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        accountLabel = new QLabel(widget);
        accountLabel->setObjectName(QString::fromUtf8("accountLabel"));

        verticalLayout->addWidget(accountLabel);

        passwordLabel = new QLabel(widget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        verticalLayout->addWidget(passwordLabel);

        confirmLabel = new QLabel(widget);
        confirmLabel->setObjectName(QString::fromUtf8("confirmLabel"));

        verticalLayout->addWidget(confirmLabel);


        horizontalLayout->addWidget(widget);

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
        accountEdit->setMinimumSize(QSize(200, 0));
        accountEdit->setMaximumSize(QSize(16777215, 16777215));
        accountEdit->setMaxLength(20);
        accountEdit->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(accountEdit);

        passwordEdit = new QLineEdit(widget_2);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        sizePolicy.setHeightForWidth(passwordEdit->sizePolicy().hasHeightForWidth());
        passwordEdit->setSizePolicy(sizePolicy);
        passwordEdit->setMinimumSize(QSize(200, 0));
        passwordEdit->setMaximumSize(QSize(16777215, 16777215));
        passwordEdit->setMaxLength(20);
        passwordEdit->setEchoMode(QLineEdit::Password);
        passwordEdit->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(passwordEdit);

        confirmEdit = new QLineEdit(widget_2);
        confirmEdit->setObjectName(QString::fromUtf8("confirmEdit"));
        sizePolicy.setHeightForWidth(confirmEdit->sizePolicy().hasHeightForWidth());
        confirmEdit->setSizePolicy(sizePolicy);
        confirmEdit->setMinimumSize(QSize(200, 0));
        confirmEdit->setMaximumSize(QSize(16777215, 16777215));
        confirmEdit->setMaxLength(20);
        confirmEdit->setEchoMode(QLineEdit::Password);
        confirmEdit->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(confirmEdit);


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
        backButton->setText(QCoreApplication::translate("Registered", "\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
        accountLabel->setText(QCoreApplication::translate("Registered", "\350\264\246    \345\217\267:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("Registered", "\345\257\206    \347\240\201:", nullptr));
        confirmLabel->setText(QCoreApplication::translate("Registered", "\347\241\256\350\256\244\345\257\206\347\240\201:", nullptr));
        accountEdit->setPlaceholderText(QCoreApplication::translate("Registered", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("Registered", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        confirmEdit->setPlaceholderText(QCoreApplication::translate("Registered", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        registeredButton->setText(QCoreApplication::translate("Registered", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registered: public Ui_Registered {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERED_H
