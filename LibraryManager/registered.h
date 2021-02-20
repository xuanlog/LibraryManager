#ifndef REGISTERED_H
#define REGISTERED_H

#include <QWidget>
#include "sqltablemodel.h"

namespace Ui {
class Registered;
}

/**
* @brief 注册界面类
* 实现注册功能
*/
class Registered : public QWidget
{
    Q_OBJECT

public:
    explicit Registered(QWidget *parent = nullptr);

    ~Registered();

private:
    Ui::Registered *ui;

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

signals:
    /**
    * @brief 注册成功信号
    * @detail 触发对应槽函数刷新用户信息
    */
    void sigRegist();

private slots:
    /**
    * @brief 注册函数
    * @detail userInfo 表新增用户信息并返回登录界面
    */
    void registered();

    /**
    * @brief 返回函数
    * @detail 返回登录界面并清除输入框信息
    */
    void back();
};

#endif // REGISTERED_H
