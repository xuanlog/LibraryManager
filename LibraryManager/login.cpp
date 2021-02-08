#include "login.h"
#include "ui_login.h"
#include "librarydefine.h"
#include <QStackedWidget>
#include "md5.h"
#include "base64.h"
#include "filemanager.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    initialization();
    connectConfig();
    initData();
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
    m_timer = new QTimer(this);
}

// 信号与槽的设置
void Login::connectConfig()
{
    connect(ui->loginButton, &QPushButton::clicked, this, &Login::login);
    connect(ui->registeredButton, &QPushButton::clicked, this, &Login::moveToRegistered);
    connect(ui->accountEdit, &QLineEdit::textChanged, this, &Login::userUpdate);
    connect(ui->autoCheckBox, &QCheckBox::clicked, this, &Login::autoUpdate);
    connect(ui->rememberCheckBox, &QCheckBox::clicked, this, &Login::rememberUpdate);
    connect(m_timer, &QTimer::timeout, this, &Login::autoLogin);
}

void Login::initData()
{
    QString account = FileManager::read("INFO/Account");
    QString isRemeber = FileManager::read("INFO/RememberFlag");
    ui->accountEdit->setText(account);

    if (isRemeber == "false")
    {
        return;
    }

    QString password = FileManager::read("INFO/Password");
    password = Base64::Decrypt(password);    // 解密
    ui->rememberCheckBox->setChecked(true);
    ui->passwordEdit->setText(password);

    // 自动登录
    QString isAuto = FileManager::read("INFO/AutoFlag");

    if (isAuto == "true")
    {
        ui->autoCheckBox->setChecked(true);
        m_timer->start(500);
    }
}

void Login::autoLogin()
{
    m_timer->stop();
    login();
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
    QString passwordMD5 = MD5::Encrypt(account + password);
    QString condition = QString::fromUtf8("账号 = '%1' AND 密码 = '%2'").arg(account).arg(passwordMD5);

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

    // 更新用户信息存储
    FileManager::write("INFO/Account", account);

    if (!ui->rememberCheckBox->isChecked())    // 不记住密码
    {
        FileManager::write("INFO/RememberFlag", "false");
        FileManager::remove("INFO/Password");
        ui->passwordEdit->clear();
        return;
    }

    QString passwordBase64 = Base64::Encrypt(password);
    FileManager::write("INFO/Password", passwordBase64);
    FileManager::write("INFO/RememberFlag", "true");

    if (ui->autoCheckBox->isChecked())
    {
        ui->autoCheckBox->setChecked(false);
        FileManager::write("INFO/AutoFlag", "true");
    }
}

// 跳转注册页面
void Login::moveToRegistered()
{
    changeWidget(PAGE_REGISTERED);
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

    // 账号与记住的不匹配则清除密码及勾选，如果相同，则读取文件进行信息的恢复
    QString remember = FileManager::read("INFO/Account");

    if (account != remember)
    {
        ui->passwordEdit->clear();
        ui->rememberCheckBox->setChecked(false);
        ui->autoCheckBox->setChecked(false);
        return;
    }

    initData();
}

void Login::autoUpdate(bool isChecked)
{
    if (isChecked)
    {
        ui->rememberCheckBox->setChecked(isChecked);
    }
}

void Login::rememberUpdate(bool isChecked)
{
    if (!isChecked)
    {
        ui->autoCheckBox->setChecked(isChecked);
    }
}

void Login::tipsUpdate(const QString &tips)
{
    ui->tipsLabel->setText(tips);
}
