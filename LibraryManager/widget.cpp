#include "widget.h"
#include "ui_widget.h"
#include "librarydefine.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_timer = new TimeManager(this);
    m_timer->start();
    setWindowTitle(QString::fromUtf8("图书管理系统 v%1").arg(kVersion));
    connectConfig();
}

Widget::~Widget()
{
    delete ui;
}

// 信号与槽的设置
void Widget::connectConfig()
{
    connect(ui->stackRoomWidget, &StackRoom::sigBorrow, ui->personalCenterWidget, &PersonalCenter::addBook);
    connect(ui->stackRoomWidget, &StackRoom::sigReturn, ui->readerWidget, &Reader::bookUpdate);

    connect(ui->personalCenterWidget, &PersonalCenter::sigReturn, ui->stackRoomWidget, &StackRoom::bookUpdate);
    connect(ui->personalCenterWidget, &PersonalCenter::sigBorrow, ui->readerWidget, &Reader::bookUpdate);

    connect(ui->loginWidget, &Login::sigLogin, ui->stackRoomWidget, &StackRoom::refresh);
    connect(ui->loginWidget, &Login::sigLogin, ui->personalCenterWidget, &PersonalCenter::refresh);
    connect(ui->loginWidget, &Login::sigManager, ui->managerWidget, &Manager::refresh);
    connect(ui->loginWidget, &Login::sigManager, ui->readerWidget, &Reader::refresh);

    connect(ui->readerWidget, &Reader::sigDelete, ui->personalCenterWidget, &PersonalCenter::clearAccount);

    connect(ui->registeredWidget, &Registered::sigRegist, ui->readerWidget, &Reader::refresh);

    connect(m_timer, &TimeManager::sigTipsUpdate, this, &Widget::timeUpdate, Qt::BlockingQueuedConnection);
}

void Widget::timeUpdate(const QString &time, const QString &tips)
{
    ui->timeLabel->setText(time);

    if (!tips.isEmpty())    // 为空则不更新
    {
        ui->loginWidget->tipsUpdate(tips);
    }
}
