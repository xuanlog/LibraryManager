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

    // 管理员
    if (objectName == "Manager" || objectName == "Reader" || objectName == "Message")
    {
        ui->userWidget->hide();
        return;
    }

    // 用户
    ui->managerWidget->hide();
}

// 控件信号链接
void MenuBar::connectConfig()
{
    connect(ui->personalButton, &QPushButton::clicked, this, [=](){
        changeWidget(PAGE_PERSONAL);
    });

    connect(ui->stackRoomButton, &QPushButton::clicked, this, [=](){
        changeWidget(PAGE_STACK_ROOM);
    });

    connect(ui->managerButton, &QPushButton::clicked, this, [=](){
        changeWidget(PAGE_MANAGER);
    });

    connect(ui->readerButton, &QPushButton::clicked, this, [=](){
        changeWidget(PAGE_READER);
    });

    connect(ui->messageButton, &QPushButton::clicked, this, [=](){
        changeWidget(PAGE_MESSAGE);
    });

    connect(ui->logoutButton, &QPushButton::clicked, this, &MenuBar::moveToLogin);
}

// 界面切换
void MenuBar::changeWidget(int index)
{
    QStackedWidget *widget = (QStackedWidget *)this->parent()->parent();
    widget->setCurrentIndex(index);
}

// 退出登录
void MenuBar::moveToLogin()
{
    int ret = QMessageBox::question(this, QString::fromUtf8("提示"), QString::fromUtf8("确定退出登录?"),
                                    QString::fromUtf8("确定"), QString::fromUtf8("取消"));

    if (ret == SELECT_OK)
    {
        changeWidget(PAGE_LOGIN);
        FileManager::write("INFO/AutoFlag", "false");
    }
}
