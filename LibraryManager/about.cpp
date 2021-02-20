#include "about.h"
#include "ui_about.h"

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
