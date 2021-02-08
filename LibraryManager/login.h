#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "sqltablemodel.h"
#include <QTimer>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    void tipsUpdate(const QString &tips);

private:
    Ui::Login *ui;

    SqlTableModel *m_model;
    QTimer *m_timer;

    void initialization();    // 初始化

    void initData();

    void connectConfig();    // 信号与槽的设置

    void changeWidget(int index);    // 切换窗口

signals:
    void sigManager();
    void sigLogin(const QString &account);

private slots:
    void login();    // 登录
    void moveToRegistered();    // 跳转注册页面
    void userUpdate(const QString &account);    // 更新提示
    void autoUpdate(bool isChecked);
    void rememberUpdate(bool isChecked);
    void autoLogin();
};

#endif // LOGIN_H
