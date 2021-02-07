#include "registered.h"
#include "ui_registered.h"
#include "librarydefine.h"
#include <QStackedWidget>
#include "md5.h"

Registered::Registered(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registered)
{
    ui->setupUi(this);

    initialization();
    connectConfig();
}

Registered::~Registered()
{
    delete ui;
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

    if (account.isEmpty() || password.isEmpty())
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("请将相关信息补充完整!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    if (account.length() < 6 || password.length() < 6)
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
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("该账号已存在!"),
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
