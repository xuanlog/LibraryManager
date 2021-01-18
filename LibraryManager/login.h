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

protected:
    void initialization();    // 初始化

    void connectConfig();    // 信号与槽的设置

    void changeWidget(int index);    // 切换窗口

private:
    Ui::Login *ui;

    SqlTableModel *m_model;

signals:
    void sigManager();
    void sigLogin(const QString &info);

private slots:
    void login();    // 登录
    void moveToRegistered();    // 跳转注册页面
};

#endif // LOGIN_H
