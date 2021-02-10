/********************************************************************************
** Form generated from reading UI file 'titlebar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEBAR_H
#define UI_TITLEBAR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TitleBar
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *minButton;
    QPushButton *maxButton;
    QPushButton *closeButton;

    void setupUi(QWidget *TitleBar)
    {
        if (TitleBar->objectName().isEmpty())
            TitleBar->setObjectName(QString::fromUtf8("TitleBar"));
        TitleBar->resize(840, 32);
        TitleBar->setStyleSheet(QString::fromUtf8("#TitleBar\n"
"{\n"
"	border-image: url(:/Images/bar.jpg);\n"
"}"));
        horizontalLayout = new QHBoxLayout(TitleBar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, 0, 0, 0);
        label = new QLabel(TitleBar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(16, 16));
        label->setMaximumSize(QSize(16, 16));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/Images/icon.png);"));
        label->setScaledContents(false);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(TitleBar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(6, 0));

        horizontalLayout->addWidget(label_2);

        titleLabel = new QLabel(TitleBar);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	font: 12px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));

        horizontalLayout->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(565, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        minButton = new QPushButton(TitleBar);
        minButton->setObjectName(QString::fromUtf8("minButton"));
        minButton->setMinimumSize(QSize(45, 32));
        minButton->setMaximumSize(QSize(45, 32));
        minButton->setFocusPolicy(Qt::NoFocus);
        minButton->setStyleSheet(QString::fromUtf8("QPushButton:pressed\n"
"{\n"
"	background-color: rgb(72, 72, 72);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/min.png"), QSize(), QIcon::Normal, QIcon::Off);
        minButton->setIcon(icon);
        minButton->setFlat(true);

        horizontalLayout->addWidget(minButton);

        maxButton = new QPushButton(TitleBar);
        maxButton->setObjectName(QString::fromUtf8("maxButton"));
        maxButton->setMinimumSize(QSize(45, 32));
        maxButton->setMaximumSize(QSize(45, 32));
        maxButton->setFocusPolicy(Qt::NoFocus);
        maxButton->setStyleSheet(QString::fromUtf8("QPushButton:pressed\n"
"{\n"
"	background-color: rgb(72, 72, 72);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/max.png"), QSize(), QIcon::Normal, QIcon::Off);
        maxButton->setIcon(icon1);
        maxButton->setFlat(true);

        horizontalLayout->addWidget(maxButton);

        closeButton = new QPushButton(TitleBar);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMinimumSize(QSize(45, 32));
        closeButton->setMaximumSize(QSize(45, 32));
        closeButton->setFocusPolicy(Qt::NoFocus);
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton:pressed\n"
"{\n"
"	background-color: rgb(72, 72, 72);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon2);
        closeButton->setFlat(true);

        horizontalLayout->addWidget(closeButton);


        retranslateUi(TitleBar);

        QMetaObject::connectSlotsByName(TitleBar);
    } // setupUi

    void retranslateUi(QWidget *TitleBar)
    {
        TitleBar->setWindowTitle(QCoreApplication::translate("TitleBar", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        titleLabel->setText(QCoreApplication::translate("TitleBar", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237 v0.0.0", nullptr));
        minButton->setText(QString());
        maxButton->setText(QString());
        closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TitleBar: public Ui_TitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEBAR_H
