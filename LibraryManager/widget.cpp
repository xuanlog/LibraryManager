#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->stackRoomWidget, &StackRoom::sigBorrowBook, ui->personalCenterWidget, &PersonalCenter::recvBookInfo);
    connect(ui->personalCenterWidget, &PersonalCenter::sigSuccessful, ui->stackRoomWidget, &StackRoom::inventoryUpdate);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    if (ui->stackedWidget->currentIndex())
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
}
