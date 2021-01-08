#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connectConfig();
}

Widget::~Widget()
{
    delete ui;
}

// 信号与槽的设置
void Widget::connectConfig()
{
    connect(ui->stackRoomWidget, &StackRoom::sigBorrowBook, ui->personalCenterWidget, &PersonalCenter::recvBookInfo);
    connect(ui->personalCenterWidget, &PersonalCenter::sigSuccessful, ui->stackRoomWidget, &StackRoom::inventoryUpdate);
    connect(ui->loginWidget, &Login::sigLogin, ui->personalCenterWidget, &PersonalCenter::addAcountInfo);
}
