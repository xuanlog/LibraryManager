#include "registered.h"
#include "ui_registered.h"
#include "librarydefine.h"
#include <QStackedWidget>

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
    QString condition = QString::fromUtf8("账号 = '%1'").arg(account);

    if (m_model->checkData(condition))
    {
        QMessageBox::about(this, QString::fromUtf8("提示"), QString::fromUtf8("该账号已存在!"));
        return;
    }

    if (password != confirmPassword)
    {
        QMessageBox::about(this, QString::fromUtf8("提示"), QString::fromUtf8("两次密码不一致!"));
        return;
    }

    QString values = QString("'%1', '%2'").arg(account).arg(password);
    m_model->insertRow(values);

    QMessageBox::about(this, QString::fromUtf8("提示"), QString::fromUtf8("注册成功!"));
    changeWidget(PAGE_LOGIN);
}

// 返回登录
void Registered::back()
{
    changeWidget(PAGE_LOGIN);
}
