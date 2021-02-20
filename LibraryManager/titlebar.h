#ifndef TITLEBAR_H
#define TITLEBAR_H

#include "widget.h"
#include <QMouseEvent>

namespace Ui {
class TitleBar;
}

/**
* @brief 标题栏窗口类
* 自写的标题栏，用来与软件样式相统一
*/
class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget *parent = nullptr);

    ~TitleBar();

protected:
    /**
    * @brief 鼠标双击事件
    * @detail 鼠标双击时进入，用来实现双击时最大化和正常化窗口
    *
    * @param event 鼠标相关事件
    */
    void mouseDoubleClickEvent(QMouseEvent *event);

    /**
    * @brief 鼠标拖动事件
    * @detail 鼠标左键按住拖动时进入，用来实现对窗口的拖动
    *
    * @param event 鼠标相关事件
    */
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::TitleBar *ui;

    /**
    * @brief 初始化函数
    * @detail 对部分控件进行初始化操作
    */
    void initialization();

    /**
    * @brief 控件信号链接函数
    * @detail 链接控件的信号，实现控件对应的功能
    */
    void connectConfig();

private slots:
    /**
    * @brief 最大化函数
    * @detail 控制窗口实现最大化与正常化的切换
    */
    void maxSize();
};

#endif // TITLEBAR_H
