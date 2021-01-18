#include "widget.h"
#include "ui_widget.h"
#include "librarydefine.h"

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
    connect(ui->personalCenterWidget, &PersonalCenter::sigReturn, ui->stackRoomWidget, &StackRoom::bookUpdate);
    connect(ui->loginWidget, &Login::sigLogin, ui->personalCenterWidget, &PersonalCenter::initialization);
    connect(ui->loginWidget, &Login::sigLogin, ui->stackRoomWidget, &StackRoom::initialization);
    connect(ui->loginWidget, &Login::sigManager, ui->managerWidget, &Manager::initialization);
    connect(ui->loginWidget, &Login::sigManager, ui->readerWidget, &Reader::initialization);
    connect(ui->readerWidget, &Reader::sigDelete, ui->personalCenterWidget, &PersonalCenter::clearAccount);
}
