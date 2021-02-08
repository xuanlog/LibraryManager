#include "resetpassword.h"
#include "ui_resetpassword.h"
#include "librarydefine.h"
#include <QStackedWidget>
#include "md5.h"

ResetPassword::ResetPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResetPassword)
{
    ui->setupUi(this);

    initialization();
    connectConfig();
}

ResetPassword::~ResetPassword()
{
    delete ui;
}

// 初始化
void ResetPassword::initialization()
{
    m_model = new SqlTableModel(this);
    m_model->setTable("userInfo");
}

// 信号与槽的设置
void ResetPassword::connectConfig()
{
    connect(ui->confirmButton, &QPushButton::clicked, this, &ResetPassword::reset);
    connect(ui->backButton, &QPushButton::clicked, this, &ResetPassword::back);
}

// 切换窗口
void ResetPassword::changeWidget(int index)
{
    QStackedWidget *widget = (QStackedWidget *)this->parent();
    widget->setCurrentIndex(index);
}

// 重置密码
void ResetPassword::reset()
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

    if (password.length() < 6)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("新密码过短!"),
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

    if (!m_model->checkSqlData(condition))
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("账号不存在!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 加密
    password = MD5::Encrypt(account + password);

    // userInfo 表修改信息
    condition = QString::fromUtf8("账号 = '%1'").arg(account);
    QString value = QString::fromUtf8("密码 = '%1'").arg(password);
    m_model->setSqlData(condition, value);
    QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("修改成功!"),
                             QString::fromUtf8("确定"));

    changeWidget(PAGE_LOGIN);

    // 清除信息
    ui->accountEdit->clear();
    ui->passwordEdit->clear();
    ui->confirmEdit->clear();
}

// 返回登录
void ResetPassword::back()
{
    changeWidget(PAGE_LOGIN);

    ui->accountEdit->clear();
    ui->passwordEdit->clear();
    ui->confirmEdit->clear();
}
