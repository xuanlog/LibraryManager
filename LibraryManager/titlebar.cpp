#include "titlebar.h"
#include "ui_titlebar.h"
#include "librarydefine.h"
#include <windows.h>

TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleBar)
{
    ui->setupUi(this);

    initialization();
    connectConfig();
}

TitleBar::~TitleBar()
{
    delete ui;
}

// 初始化
void TitleBar::initialization()
{
    // 设置标题
    ui->titleLabel->setText(QString::fromUtf8("图书管理系统 v%1").arg(kVersion));
}

// 控件信号链接
void TitleBar::connectConfig()
{
    connect(ui->maxButton, &QPushButton::clicked, this, &TitleBar::maxSize);

    connect(ui->minButton, &QPushButton::clicked, this, [=](){
        this->window()->showMinimized();    // 最小化
    });

    connect(ui->closeButton, &QPushButton::clicked, this, [=](){
        this->window()->close();    // 隐藏窗口
    });
}

// 最大化
void TitleBar::maxSize()
{
    bool isMax = this->window()->isMaximized();
    isMax ? this->window()->showNormal() : this->window()->showMaximized();
    isMax ? ui->maxButton->setIcon(QIcon(":/Images/max.png")) :
            ui->maxButton->setIcon(QIcon(":/Images/max_ok.png"));
}

// 鼠标双击事件
void TitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    if (event->button() == Qt::LeftButton)    // 仅对左键生效
    {
        maxSize();
    }
}

// 鼠标拖动事件
void TitleBar::mousePressEvent(QMouseEvent *event)
{
    if (ReleaseCapture())
    {
        if (this->window()->isTopLevel())
        {
            SendMessage(HWND(this->window()->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
        }
    }

    event->ignore();
}
