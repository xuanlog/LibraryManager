#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "sqltablemodel.h"
#include <QTimer>

namespace Ui {
class Login;
}

/**
* @brief 登录界面类
* 实现登录功能
*/
class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

    ~Login();

    /**
    * @brief 诗句更新函数
    * @detail 更新在登录界面显示的诗句
    *
    * @param tips 待更新的诗句内容
    * @note 实现在不同的时间段显示不同的诗句
    */
    void tipsUpdate(const QString &tips);

private:
    Ui::Login *ui;

    SqlTableModel *m_model;    ///< 操作 userInfo 表的对象

    QTimer *m_timer;           ///< 用来自动登录的定时器

    /**
    * @brief 初始化函数
    * @detail 对内部成员进行初始化操作
    */
    void initialization();

    /**
    * @brief 用户数据初始化函数
    * @detail 对登录界面进行初始化操作
    *
    * @note 通过读取配置文档获取用户上一次的相关登录信息以及是否进行自动登录，
    *       并显示到界面上
    */
    void initData();

    /**
    * @brief 控件风格初始化函数
    * @detail 对控件风格进行初始化操作，主要是给输入框添加图标
    */
    void initStyle();

    /**
    * @brief 控件信号链接函数
    * @detail 链接控件的信号，实现控件对应的功能
    */
    void connectConfig();

    /**
    * @brief 界面切换函数
    * @detail 切换到相应的界面
    *
    * @param index 界面的页码
    */
    void changeWidget(int index);

    /**
    * @brief 用户信息获取函数
    * @detail 获取用户相关信息
    *
    * @param account 用户账号
    * @return 用户相关的信息
    */
    QStringList getUserInfo(const QString &account);

    /**
    * @brief 用户数据更新函数
    * @detail 更新并存储用户登录信息
    *
    * @param account 用户账号
    * @param password 用户密码
    */
    void dataUpdate(const QString &account, const QString &password);

signals:
    /**
    * @brief 管理员登录信号
    * @detail 触发对应槽函数刷新管理员相关界面
    */
    void sigManager();

    /**
    * @brief 用户登录信号
    * @detail 触发对应槽函数刷新用户相关界面
    *
    * @param userInfo 用户相关信息，目前仅有账号与地址
    */
    void sigLogin(const QStringList &userInfo);

public slots:
    /**
    * @brief 刷新函数
    * @detail 刷新 m_model 对象的信息
    *
    * @note m_model 对象不会实时获取表中的数据，
    *       所以需要在表格更新后进行刷新
    */
    void refresh();

private slots:
    /**
    * @brief 登录函数
    * @detail 进行登录操作
    */
    void login();

    /**
    * @brief 用户提示更新函数
    * @detail 更新管理员或普通用户的提示以及清除或恢复界面登录信息
    *
    * @param account 账号输入框内的信息
    */
    void userUpdate(const QString &account);

    /**
    * @brief 自动登录勾选框更新函数
    * @detail 自动登录与记住密码联动
    *
    * @param isChecked 记住密码勾选框的状态
    * @note 记住密码取消勾选则自动登录也取消勾选
    */
    void autoUpdate(bool isChecked);

    /**
    * @brief 记住密码勾选框更新函数
    * @detail 自动登录与记住密码联动
    *
    * @param isChecked 自动登录勾选框的状态
    * @note 自动登录勾选则记住密码也勾选
    */
    void rememberUpdate(bool isChecked);

    /**
    * @brief 自动登录函数
    * @detail 进行自动登录操作
    */
    void autoLogin();
};

#endif // LOGIN_H
