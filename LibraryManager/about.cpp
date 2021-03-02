#include "about.h"
#include "ui_about.h"
#include <windows.h>

About::About(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);    // 隐藏标题栏
    connect(ui->closeButton, &QPushButton::clicked, this, [=](){
        this->close();
    });
}

About::~About()
{
    delete ui;
}

// 鼠标拖动事件
void About::mousePressEvent(QMouseEvent *event)
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
