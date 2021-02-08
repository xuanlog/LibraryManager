#include "menubar.h"
#include "ui_menubar.h"
#include <QStackedWidget>
#include "librarydefine.h"
#include "filemanager.h"

MenuBar::MenuBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuBar)
{
    ui->setupUi(this);

    initialization();
    connectConfig();
}

MenuBar::~MenuBar()
{
    delete ui;
}

// 初始化
void MenuBar::initialization()
{
    // 管理员与普通用户显示不同的菜单栏
    QString objectName = this->parent()->objectName();

    if (objectName == "Manager" || objectName == "Reader")
    {
        ui->userWidget->hide();
        return;
    }

    ui->managerWidget->hide();
}

// 信号与槽的设置
void MenuBar::connectConfig()
{
    connect(ui->personalButton, &QPushButton::clicked, this, &MenuBar::moveToPersonalCenter);
    connect(ui->stackRoomButton, &QPushButton::clicked, this, &MenuBar::moveToStackRoom);
    connect(ui->logoutButton, &QPushButton::clicked, this, &MenuBar::moveToLogin);
    connect(ui->managerButton, &QPushButton::clicked, this, &MenuBar::moveToManager);
    connect(ui->readerButton, &QPushButton::clicked, this, &MenuBar::moveToReader);
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

void MenuBar::moveToLogin()
{
    int ret = QMessageBox::question(this, QString::fromUtf8("提示"), QString::fromUtf8("确定退出登录?"),
                                    QString::fromUtf8("确定"), QString::fromUtf8("取消"));

    if (ret == 0)
    {
        changeWidget(PAGE_LOGIN);
        FileManager::write("INFO/AutoFlag", "false");
    }
}

void MenuBar::moveToManager()
{
    changeWidget(PAGE_MANAGER);
}

void MenuBar::moveToReader()
{
    changeWidget(PAGE_READER);
}
