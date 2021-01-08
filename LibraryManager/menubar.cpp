#include "menubar.h"
#include "ui_menubar.h"
#include <QStackedWidget>
#include "librarydefine.h"

MenuBar::MenuBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuBar)
{
    ui->setupUi(this);

    connectConfig();
}

MenuBar::~MenuBar()
{
    delete ui;
}

// 信号与槽的设置
void MenuBar::connectConfig()
{
    connect(ui->personalButton, &QPushButton::clicked, this, &MenuBar::moveToPersonalCenter);
    connect(ui->stackRoomButton, &QPushButton::clicked, this, &MenuBar::moveToStackRoom);
}

// 切换窗口
void MenuBar::changeWidget(int index)
{
    QStackedWidget *widget = (QStackedWidget *)this->parent()->parent();
    widget->setCurrentIndex(index);
}

void MenuBar::moveToStackRoom()
{
    changeWidget(PAGE_STACK_ROOM);
}

void MenuBar::moveToPersonalCenter()
{
    changeWidget(PAGE_PERSONAL);
}
