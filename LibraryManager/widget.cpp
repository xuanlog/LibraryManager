#include "widget.h"
#include "ui_widget.h"
#include "librarydefine.h"
#include <windows.h>
#include <windowsx.h>
#include <QMenu>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    initialization();
    initTray();
    connectConfig();

    m_timer->start();
}

Widget::~Widget()
{
    delete ui;
}

// 初始化
void Widget::initialization()
{
    m_isClose = false;

    m_timer = new TimeManager(this);
    connect(m_timer, &TimeManager::sigTipsUpdate, this, &Widget::timeUpdate, Qt::BlockingQueuedConnection);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);    // 隐藏标题栏
}

// 系统托盘初始化
void Widget::initTray()
{
    // 托盘菜单
    QMenu *menu = new QMenu(this);
    QAction *openWindow = new QAction(QString::fromUtf8("打开主窗口"), this);
    QAction *closeWindow = new QAction(QString::fromUtf8("退出"), this);

    connect(openWindow, &QAction::triggered, this, [=](){
        this->show();
    });

    connect(closeWindow, &QAction::triggered, this, &Widget::exitWindow);

    menu->addAction(openWindow);
    menu->addSeparator();    // 添加分隔符
    menu->addAction(closeWindow);

    // 托盘
    m_tray = new QSystemTrayIcon(this);
    m_tray->setIcon(QIcon(":/Images/icon.png"));
    m_tray->setToolTip(QString::fromUtf8("图书管理系统"));
    m_tray->setContextMenu(menu);    // 菜单栏添加到托盘
    m_tray->show();
    connect(m_tray, &QSystemTrayIcon::activated, this, &Widget::showWindow);
}

// 控件信号链接
void Widget::connectConfig()
{
    connect(ui->stackRoomWidget, &StackRoom::sigBorrow, ui->personalCenterWidget, &PersonalCenter::addBook);
    connect(ui->stackRoomWidget, &StackRoom::sigReturn, ui->readerWidget, &Reader::bookUpdate);

    connect(ui->personalCenterWidget, &PersonalCenter::sigReturn, ui->stackRoomWidget, &StackRoom::bookUpdate);
    connect(ui->personalCenterWidget, &PersonalCenter::sigBorrow, ui->readerWidget, &Reader::bookUpdate);
    connect(ui->personalCenterWidget, &PersonalCenter::sigMessage, ui->readerWidget, &Reader::messageUpdate);
    connect(ui->personalCenterWidget, &PersonalCenter::sigMessage, ui->loginWidget, &Login::refresh);
    connect(ui->personalCenterWidget, &PersonalCenter::sigInfo, ui->messageWidget, &Message::infoUpdate);

    connect(ui->loginWidget, &Login::sigLogin, ui->stackRoomWidget, &StackRoom::refresh);
    connect(ui->loginWidget, &Login::sigLogin, ui->personalCenterWidget, &PersonalCenter::refresh);
    connect(ui->loginWidget, &Login::sigManager, ui->managerWidget, &Manager::refresh);
    connect(ui->loginWidget, &Login::sigManager, ui->readerWidget, &Reader::refresh);

    connect(ui->readerWidget, &Reader::sigDelete, ui->personalCenterWidget, &PersonalCenter::clearAccount);
    connect(ui->readerWidget, &Reader::sigReturn, ui->stackRoomWidget, &StackRoom::overdueBook);

    connect(ui->registeredWidget, &Registered::sigRegist, ui->readerWidget, &Reader::refresh);
    connect(ui->registeredWidget, &Registered::sigRegist, ui->loginWidget, &Login::refresh);

    connect(ui->aboutButton, &QPushButton::clicked, this, &Widget::showAbout);
}

// 关于窗口展示
void Widget::showAbout()
{
    m_w.show();
    int x = (this->width() - m_w.width()) / 2 + this->x();
    int y = (this->height() - m_w.height()) / 2 + this->y();
    m_w.move(x, y);
}

// 时间更新
void Widget::timeUpdate(const QString &time, const QString &tips, const QString &image)
{
    ui->timeLabel->setText(time);

    if (!tips.isEmpty())    // 为空则时间段未变，不更新
    {
        ui->loginWidget->tipsUpdate(tips);
        this->setStyleSheet(QString("#stackedWidget{border-image: url(:/Images/%1.jpg)}").arg(image));
    }
}

// 主窗口显示
void Widget::showWindow(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::Trigger)
    {
        this->show();
    }
}

// 窗口关闭
void Widget::exitWindow()
{
    m_isClose = true;    // 标志位置 true 后 close 才可关闭窗口
    m_w.close();
    this->close();
}

// 关闭事件
void Widget::closeEvent(QCloseEvent *event)
{
    if (!m_isClose)
    {
        // 不处理信号，隐藏窗口
        event->ignore();
        this->hide();
        return;
    }

    // 处理信号，关闭窗口
    m_isClose = false;
    event->accept();
}

// windows 消息事件
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
