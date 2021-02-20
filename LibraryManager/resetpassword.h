#ifndef RESETPASSWORD_H
#define RESETPASSWORD_H

#include <QWidget>
#include "sqltablemodel.h"

namespace Ui {
class ResetPassword;
}

/**
* @brief 重置密码界面类
* 实现重置密码功能
*/
class ResetPassword : public QWidget
{
    Q_OBJECT

public:
    explicit ResetPassword(QWidget *parent = nullptr);

    ~ResetPassword();

private:
    Ui::ResetPassword *ui;

    SqlTableModel *m_model;    ///< 操作 userInfo 表的对象

    /**
    * @brief 初始化函数
    * @detail 对内部成员进行初始化操作
    */
    void initialization();

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

private slots:
    /**
    * @brief 密码重置函数
    * @detail 修改用户密码并返回登录界面
    */
    void reset();

    /**
    * @brief 返回函数
    * @detail 返回登录界面并清除输入框信息
    */
    void back();
};

#endif // RESETPASSWORD_H
