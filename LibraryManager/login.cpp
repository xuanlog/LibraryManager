#include "login.h"
#include "ui_login.h"
#include "librarydefine.h"
#include <QStackedWidget>
#include "md5.h"
#include "base64.h"
#include "filemanager.h"
#include <QAction>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    initialization();
    initStyle();
    connectConfig();
    initData();
}

Login::~Login()
{
    delete ui;
}

// 控件风格初始化
void Login::initStyle()
{
    // 账号
    QAction *accountLead = new QAction(this);
    accountLead->setIcon(QIcon(":/Images/account.png"));
    ui->accountEdit->addAction(accountLead, QLineEdit::LeadingPosition);

    QAction *accountTrail = new QAction(this);
    accountTrail->setIcon(QIcon(":/Images/clear.png"));
    ui->accountEdit->addAction(accountTrail, QLineEdit::TrailingPosition);
    connect(accountTrail, &QAction::triggered, this, [=](){
        ui->accountEdit->clear();
    });

    // 密码
    QAction *passwordLead = new QAction(this);
    passwordLead->setIcon(QIcon(":/Images/password.png"));
    ui->passwordEdit->addAction(passwordLead, QLineEdit::LeadingPosition);

    QAction *passwordTrail = new QAction(this);
    passwordTrail->setIcon(QIcon(":/Images/clear.png"));
    ui->passwordEdit->addAction(passwordTrail, QLineEdit::TrailingPosition);
    connect(passwordTrail, &QAction::triggered, this, [=](){
        ui->passwordEdit->clear();
    });
}

// 初始化
void Login::initialization()
{
    m_model = new SqlTableModel(this);
    m_model->setTable("userInfo");
    m_model->select();

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Login::autoLogin);
}

// 控件信号链接
void Login::connectConfig()
{
    connect(ui->loginButton, &QPushButton::clicked, this, &Login::login);

    connect(ui->registeredButton, &QPushButton::clicked, this, [=](){
        changeWidget(PAGE_REGISTERED);
    });

    connect(ui->resetButton, &QPushButton::clicked, this, [=](){
        changeWidget(PAGE_RESET);
    });

    connect(ui->accountEdit, &QLineEdit::textChanged, this, &Login::userUpdate);
    connect(ui->autoCheckBox, &QCheckBox::clicked, this, &Login::rememberUpdate);
    connect(ui->rememberCheckBox, &QCheckBox::clicked, this, &Login::autoUpdate);
}

// 用户数据初始化
void Login::initData()
{
    // 账号信息
    QString account = FileManager::read("INFO/Account");
    QString isRemeber = FileManager::read("INFO/RememberFlag");
    ui->accountEdit->setText(account);

    if (isRemeber != "true")    // 判断是否记住了密码
    {
        return;
    }

    // 记住的密码
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

// 自动登录
void Login::autoLogin()
{
    m_timer->stop();
    login();
}

// 界面切换
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
    QString passwordMD5 = MD5::Encrypt(account + password);    // MD5 加密

    // 判断账号密码是否正确
    QString condition = QString::fromUtf8("账号 = '%1' AND 密码 = '%2'").arg(account).arg(passwordMD5);

    if (!m_model->checkSqlData(condition))
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("账号或密码错误!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 判断管理员或普通用户登录
    if (account == kManagerAccount)    // 管理员
    {
        emit sigManager();
        changeWidget(PAGE_MANAGER);
    }
    else    // 普通用户
    {
        QStringList userInfo = getUserInfo(account);
        emit sigLogin(userInfo);
        changeWidget(PAGE_PERSONAL);
    }

    // 更新用户信息存储
    dataUpdate(account, password);
}

// 用户数据更新
void Login::dataUpdate(const QString &account, const QString &password)
{
    FileManager::write("INFO/Account", account);

    if (!ui->rememberCheckBox->isChecked())    // 不记住密码
    {
        FileManager::write("INFO/RememberFlag", "false");
        FileManager::remove("INFO/Password");
        ui->passwordEdit->clear();
        return;
    }

    // 记住密码
    QString passwordBase64 = Base64::Encrypt(password);
    FileManager::write("INFO/Password", passwordBase64);
    FileManager::write("INFO/RememberFlag", "true");

    // 下次自动登录
    if (ui->autoCheckBox->isChecked())
    {
        ui->autoCheckBox->setChecked(false);
        FileManager::write("INFO/AutoFlag", "true");
    }
}

// 用户信息获取
QStringList Login::getUserInfo(const QString &account)
{
    int maxRow = m_model->rowCount();
    QStringList userInfo = {account};

    for (int i = 0; i < maxRow; i++)
    {
        // 查找账号所在行
        QModelIndex index = m_model->index(i, USER_ACCOUNT);

        if (account == m_model->data(index).toString())
        {
            // 获取电话
            index = m_model->index(i, USER_PHONE);
            QString phone = m_model->data(index).toString();
            userInfo.append(phone);
            // 获取地址
            index = m_model->index(i, USER_ADDRESS);
            QString address = m_model->data(index).toString();
            userInfo.append(address);
            break;
        }
    }

    return userInfo;
}

// 用户提示更新
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

    // 读取文件进行信息的恢复
    initData();
}

// 记住密码勾选框更新
void Login::rememberUpdate(bool isChecked)
{
    if (isChecked)
    {
        ui->rememberCheckBox->setChecked(isChecked);
    }
}

// 自动登录勾选框更新
void Login::autoUpdate(bool isChecked)
{
    if (!isChecked)
    {
        ui->autoCheckBox->setChecked(isChecked);
    }
}

// 诗句更新
void Login::tipsUpdate(const QString &tips)
{
    ui->tipsLabel->setText(tips);
}

// 刷新
void Login::refresh()
{
    m_model->select();
}
