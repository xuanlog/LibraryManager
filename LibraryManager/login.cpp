#include "login.h"
#include "ui_login.h"
#include "librarydefine.h"
#include <QStackedWidget>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    initialization();
    connectConfig();
}

Login::~Login()
{
    delete ui;
}

// 初始化
void Login::initialization()
{
    m_model = new SqlTableModel(this);
    m_model->setTable("userInfo");
}

// 信号与槽的设置
void Login::connectConfig()
{
    connect(ui->loginButton, &QPushButton::clicked, this, &Login::login);
    connect(ui->registeredButton, &QPushButton::clicked, this, &Login::moveToRegistered);
}

// 切换窗口
void Login::changeWidget(int index)
{
    QStackedWidget *widget = (QStackedWidget *)this->parent();
    widget->setCurrentIndex(index);
}

// 登录
void Login::login()
{
    QString account = ui->accountEdit->text();
    QString password = ui->passwordEdit->text();
    QString condition = QString::fromUtf8("账号 = '%1' AND 密码 = '%2'").arg(account).arg(password);

    if (!m_model->checkData(condition))
    {
        QMessageBox::about(this, QString::fromUtf8("提示"), QString::fromUtf8("账号或密码错误!"));
        return;
    }

    emit sigLogin(account);
    changeWidget(PAGE_PERSONAL);
}

// 跳转注册页面
void Login::moveToRegistered()
{
    changeWidget(PAGE_REGISTERED);
}
