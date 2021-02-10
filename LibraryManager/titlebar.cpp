#include "titlebar.h"
#include "ui_titlebar.h"
#include "librarydefine.h"
#include <QMouseEvent>
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

// 信号与槽的设置
void TitleBar::connectConfig()
{
    connect(ui->maxButton, &QPushButton::clicked, this, &TitleBar::maxSize);

    connect(ui->minButton, &QPushButton::clicked, this, [=](){
        this->window()->showMinimized();
    });

    connect(ui->closeButton, &QPushButton::clicked, this, [=](){
        this->window()->close();
    });
}

void TitleBar::maxSize()
{
    bool isMax = this->window()->isMaximized();
    isMax ? this->window()->showNormal() : this->window()->showMaximized();
    isMax ? ui->maxButton->setIcon(QIcon(":/Images/max.png")) :
            ui->maxButton->setIcon(QIcon(":/Images/max_ok.png"));
}

void TitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    maxSize();
}

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
