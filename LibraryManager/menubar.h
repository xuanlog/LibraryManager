#ifndef MENUBAR_H
#define MENUBAR_H

#include <QWidget>

namespace Ui {
class MenuBar;
}

/**
* @brief 菜单栏界面类
* 实现系统的菜单栏功能
*/
class MenuBar : public QWidget
{
    Q_OBJECT

public:
    explicit MenuBar(QWidget *parent = nullptr);

    ~MenuBar();

private:
    Ui::MenuBar *ui;

    /**
    * @brief 初始化函数
    * @detail 对控件进行初始化操作
    */
    void initialization();

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
    * @brief 退出登录函数
    * @detail 退出登录，回到登录界面
    *
    * @note 退出登录时，会将自动登录功能取消
    */
    void moveToLogin();
};

#endif // MENUBAR_H
