#include "registered.h"
#include "ui_registered.h"
#include "librarydefine.h"
#include <QStackedWidget>
#include "md5.h"
#include <QAction>
#include <QRegExpValidator>

Registered::Registered(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registered)
{
    ui->setupUi(this);

    initialization();
    initStyle();
    connectConfig();
}

Registered::~Registered()
{
    delete ui;
}

// 控件风格初始化
void Registered::initStyle()
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

    // 确认
    QAction *confirmLead = new QAction(this);
    confirmLead->setIcon(QIcon(":/Images/password.png"));
    ui->confirmEdit->addAction(confirmLead, QLineEdit::LeadingPosition);

    QAction *confirmTrail = new QAction(this);
    confirmTrail->setIcon(QIcon(":/Images/clear.png"));
    ui->confirmEdit->addAction(confirmTrail, QLineEdit::TrailingPosition);
    connect(confirmTrail, &QAction::triggered, this, [=](){
        ui->confirmEdit->clear();
    });

    // 地址
    QAction *addressLead = new QAction(this);
    addressLead->setIcon(QIcon(":/Images/address.png"));
    ui->addressEdit->addAction(addressLead, QLineEdit::LeadingPosition);

    QAction *addressTrail = new QAction(this);
    addressTrail->setIcon(QIcon(":/Images/clear.png"));
    ui->addressEdit->addAction(addressTrail, QLineEdit::TrailingPosition);
    connect(addressTrail, &QAction::triggered, this, [=](){
        ui->addressEdit->clear();
    });

    // 名字
    QAction *nameLead = new QAction(this);
    nameLead->setIcon(QIcon(":/Images/address.png"));
    ui->nameEdit->addAction(nameLead, QLineEdit::LeadingPosition);

    QAction *nameTrail = new QAction(this);
    nameTrail->setIcon(QIcon(":/Images/clear.png"));
    ui->nameEdit->addAction(nameTrail, QLineEdit::TrailingPosition);
    connect(nameTrail, &QAction::triggered, this, [=](){
        ui->nameEdit->clear();
    });

    // 电话
    QAction *phoneLead = new QAction(this);
    phoneLead->setIcon(QIcon(":/Images/address.png"));
    ui->phoneEdit->addAction(phoneLead, QLineEdit::LeadingPosition);

    QAction *phoneTrail = new QAction(this);
    phoneTrail->setIcon(QIcon(":/Images/clear.png"));
    ui->phoneEdit->addAction(phoneTrail, QLineEdit::TrailingPosition);
    connect(phoneTrail, &QAction::triggered, this, [=](){
        ui->phoneEdit->clear();
    });
}

// 初始化
void Registered::initialization()
{
    m_model = new SqlTableModel(this);
    m_model->setTable("userInfo");
}

// 控件信号链接
void Registered::connectConfig()
{
    connect(ui->registeredButton, &QPushButton::clicked, this, &Registered::registered);
    connect(ui->backButton, &QPushButton::clicked, this, &Registered::back);
}

// 界面切换
void Registered::changeWidget(int index)
{
    QStackedWidget *widget = (QStackedWidget *)this->parent();
    widget->setCurrentIndex(index);
}

// 注册
void Registered::registered()
{
    QString account = ui->accountEdit->text();
    QString password = ui->passwordEdit->text();
    QString confirmPassword = ui->confirmEdit->text(); 
    QString address = ui->addressEdit->text();
    QString name = ui->nameEdit->text();
    QString phone = ui->phoneEdit->text();

    // 正则表达式
    QRegExp re_phone("^[1][3-8]\\d{9}$");
    QRegExpValidator rev_phone(re_phone, 0);
    int pos = 0;

    if (account.isEmpty() || password.isEmpty() || confirmPassword.isEmpty() ||
        address.isEmpty() || name.isEmpty() || phone.isEmpty())
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("请将相关信息补充完整!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    if (account.length() < MIN_LENGTH || password.length() < MIN_LENGTH)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("账号或密码过短!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    if (rev_phone.validate(phone, pos) != 2)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("电话填写错误!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    if (account.contains(" ") || password.contains(" ") || address.contains(" ") ||
        name.contains(" ") || phone.contains(" "))
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("相关信息含有非法字符!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    if (password != confirmPassword)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("两次密码不一致!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    QString condition = QString::fromUtf8("账号 = '%1'").arg(account);

    if (m_model->checkSqlData(condition))
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("账号已存在!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 加密
    password = MD5::Encrypt(account + password);

    // 注册
    QString value = QString("'%1', '%2', 0, 0, '%3', '%4', '%5'")
            .arg(account).arg(password).arg(name).arg(phone).arg(address);

    m_model->insertSqlRow(value);
    emit sigRegist();
    QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("注册成功!"),
                             QString::fromUtf8("确定"));
    // 返回登录
    back();
}

// 返回
void Registered::back()
{
    changeWidget(PAGE_LOGIN);

    ui->accountEdit->clear();
    ui->passwordEdit->clear();
    ui->confirmEdit->clear();
    ui->addressEdit->clear();
    ui->nameEdit->clear();
    ui->phoneEdit->clear();
}
