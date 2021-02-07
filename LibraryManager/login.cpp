#include "login.h"
#include "ui_login.h"
#include "librarydefine.h"
#include <QStackedWidget>
#include "md5.h"

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

    QString account = ui->accountEdit->text();

    if (!account.isEmpty())
    {
        userUpdate(account);
    }
}

// 信号与槽的设置
void Login::connectConfig()
{
    connect(ui->loginButton, &QPushButton::clicked, this, &Login::login);
    connect(ui->registeredButton, &QPushButton::clicked, this, &Login::moveToRegistered);
    connect(ui->accountEdit, &QLineEdit::textChanged, this, &Login::userUpdate);
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

    // 加密
    password = MD5::Encrypt(account + password);

    QString condition = QString::fromUtf8("账号 = '%1' AND 密码 = '%2'").arg(account).arg(password);

    if (!m_model->checkSqlData(condition))
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("账号或密码错误!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    if (account == kManagerAccount)    // 管理员登录
    {
        emit sigManager();
        changeWidget(PAGE_MANAGER);
    }
    else    // 普通用户
    {
        emit sigLogin(account);
        changeWidget(PAGE_PERSONAL);
    }

    // 登陆成功后清除登录信息
    ui->passwordEdit->clear();
}

// 跳转注册页面
void Login::moveToRegistered()
{
    changeWidget(PAGE_REGISTERED);

    ui->passwordEdit->clear();
}

// 更新提示
void Login::userUpdate(const QString &account)
{
    if (account == kManagerAccount)
    {
        ui->userLabel->setText(QString::fromUtf8("亲爱的管理员"));
        return;
    }

    ui->userLabel->setText(QString::fromUtf8("亲爱的用户"));
}

void Login::tipsUpdate(const QString &tips)
{
    ui->tipsLabel->setText(tips);
}
