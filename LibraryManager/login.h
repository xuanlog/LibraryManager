#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "sqltablemodel.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui;

    SqlTableModel *m_model;

    void initialization();    // 初始化

    void connectConfig();    // 信号与槽的设置

    void changeWidget(int index);    // 切换窗口

signals:
    void sigManager();
    void sigLogin(const QString &account);

private slots:
    void login();    // 登录
    void moveToRegistered();    // 跳转注册页面
};

#endif // LOGIN_H
