#include "widget.h"
#include "ui_widget.h"
#include "librarydefine.h"
#include <windows.h>
#include <windowsx.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_timer = new TimeManager(this);
    m_timer->start();
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);    // 隐藏标题栏
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

void Widget::timeUpdate(const QString &time, const QString &tips, const QString &image)
{
    ui->timeLabel->setText(time);

    if (!tips.isEmpty())    // 为空则不更新
    {
        ui->loginWidget->tipsUpdate(tips);
        this->setStyleSheet(QString("#stackedWidget{border-image: url(:/Images/%1.jpg)}").arg(image));
    }
}

bool Widget::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    Q_UNUSED(eventType)

    int boundaryWidth = 5;    // 可以缩放的范围
    MSG *msg = static_cast<MSG *>(message);

    // 非窗口缩放消息则返回 false，留给其他事件处理器处理
    if (msg->message != WM_NCHITTEST)
    {
        return false;
    }

    // 窗口缩放
    int xPos = GET_X_LPARAM(msg->lParam) - this->frameGeometry().x();
    int yPos = GET_Y_LPARAM(msg->lParam) - this->frameGeometry().y();

    if(xPos < boundaryWidth && yPos < boundaryWidth)    // 左上角
    {
        *result = HTTOPLEFT;
    }
    else if(xPos > this->width() - boundaryWidth && yPos < boundaryWidth)    // 右上角
    {
        *result = HTTOPRIGHT;
    }
    else if(xPos < boundaryWidth && yPos > this->height() - boundaryWidth)    // 左下角
    {
        *result = HTBOTTOMLEFT;
    }
    else if(xPos > this->width() - boundaryWidth && yPos > this->height() - boundaryWidth)    // 右下角
    {
        *result = HTBOTTOMRIGHT;
    }
    else if(xPos < boundaryWidth)    // 左边
    {
        *result = HTLEFT;
    }
    else if(xPos > this->width() - boundaryWidth)    // 右边
    {
        *result = HTRIGHT;
    }
    else if(yPos < boundaryWidth)    // 上边
    {
        *result = HTTOP;
    }
    else if(yPos > this->height() - boundaryWidth)    // 下边
    {
        *result = HTBOTTOM;
    }
    else    // 未缩放
    {
        return false;
    }

    return true;
}
