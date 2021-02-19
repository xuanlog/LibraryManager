#include "registered.h"
#include "ui_registered.h"
#include "librarydefine.h"
#include <QStackedWidget>
#include "md5.h"
#include <QAction>

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
}

// 初始化
void Registered::initialization()
{
    m_model = new SqlTableModel(this);
    m_model->setTable("userInfo");
}

// 信号与槽的设置
void Registered::connectConfig()
{
    connect(ui->registeredButton, &QPushButton::clicked, this, &Registered::registered);
    connect(ui->backButton, &QPushButton::clicked, this, &Registered::back);
}

// 切换窗口
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

    if (account.isEmpty() || password.isEmpty() || confirmPassword.isEmpty())
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

    // userInfo 表添加信息
    QString value = QString("'%1', '%2', 0, 0").arg(account).arg(password);
    m_model->insertSqlRow(value);
    emit sigRegist();
    QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("注册成功!"),
                             QString::fromUtf8("确定"));

    changeWidget(PAGE_LOGIN);

    // 清除注册信息
    ui->accountEdit->clear();
    ui->passwordEdit->clear();
    ui->confirmEdit->clear();
}

// 返回登录
void Registered::back()
{
    changeWidget(PAGE_LOGIN);

    ui->accountEdit->clear();
    ui->passwordEdit->clear();
    ui->confirmEdit->clear();
}
