#include "resetpassword.h"
#include "ui_resetpassword.h"
#include "librarydefine.h"
#include <QStackedWidget>
#include "md5.h"
#include <QAction>

ResetPassword::ResetPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResetPassword)
{
    ui->setupUi(this);

    initialization();
    initStyle();
    connectConfig();
}

ResetPassword::~ResetPassword()
{
    delete ui;
}

// 控件风格初始化
void ResetPassword::initStyle()
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

    // 名字
    QAction *nameLead = new QAction(this);
    nameLead->setIcon(QIcon(":/Images/name.png"));
    ui->nameEdit->addAction(nameLead, QLineEdit::LeadingPosition);

    QAction *nameTrail = new QAction(this);
    nameTrail->setIcon(QIcon(":/Images/clear.png"));
    ui->nameEdit->addAction(nameTrail, QLineEdit::TrailingPosition);
    connect(nameTrail, &QAction::triggered, this, [=](){
        ui->nameEdit->clear();
    });

    // 电话
    QAction *phoneLead = new QAction(this);
    phoneLead->setIcon(QIcon(":/Images/phone.png"));
    ui->phoneEdit->addAction(phoneLead, QLineEdit::LeadingPosition);

    QAction *phoneTrail = new QAction(this);
    phoneTrail->setIcon(QIcon(":/Images/clear.png"));
    ui->phoneEdit->addAction(phoneTrail, QLineEdit::TrailingPosition);
    connect(phoneTrail, &QAction::triggered, this, [=](){
        ui->phoneEdit->clear();
    });
}

// 初始化
void ResetPassword::initialization()
{
    m_model = new SqlTableModel(this);
    m_model->setTable("userInfo");
}

// 控件信号链接
void ResetPassword::connectConfig()
{
    connect(ui->confirmButton, &QPushButton::clicked, this, &ResetPassword::reset);
    connect(ui->backButton, &QPushButton::clicked, this, &ResetPassword::back);
}

// 界面切换
void ResetPassword::changeWidget(int index)
{
    QStackedWidget *widget = (QStackedWidget *)this->parent();
    widget->setCurrentIndex(index);
}

// 密码重置
void ResetPassword::reset()
{
    QString account = ui->accountEdit->text();
    QString password = ui->passwordEdit->text();
    QString confirmPassword = ui->confirmEdit->text();
    QString name = ui->nameEdit->text();
    QString phone = ui->phoneEdit->text();

    if (account.isEmpty() || password.isEmpty() || confirmPassword.isEmpty() ||
            name.isEmpty() || phone.isEmpty())
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("请将相关信息补充完整!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    if (password.length() < MIN_LENGTH)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("新密码过短!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    if (password.contains(" "))
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("密码含有非法字符!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    if (password != confirmPassword)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("两次密码不一致!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    QString condition = QString::fromUtf8("账号 = '%1' AND 姓名 = '%2' AND 电话 = '%3'")
            .arg(account).arg(name).arg(phone);

    if (!m_model->checkSqlData(condition))
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("信息错误，重置失败!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 加密
    password = MD5::Encrypt(account + password);
    condition = QString::fromUtf8("密码 = '%1'").arg(password);

    if (m_model->checkSqlData(condition))
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("新密码不可与旧密码相同!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 修改密码
    condition = QString::fromUtf8("账号 = '%1'").arg(account);
    QString value = QString::fromUtf8("密码 = '%1'").arg(password);
    m_model->setSqlData(condition, value);
    QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("修改成功!"),
                             QString::fromUtf8("确定"));
    // 返回登录
    back();
}

// 返回
void ResetPassword::back()
{
    changeWidget(PAGE_LOGIN);

    ui->accountEdit->clear();
    ui->passwordEdit->clear();
    ui->confirmEdit->clear();
}
