#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class About;
}

/**
* @brief 关于界面类
* 展示使用说明
*/
class About : public QWidget
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = nullptr);

    ~About();

protected:
    /**
    * @brief 鼠标拖动事件
    * @detail 鼠标左键按住拖动时进入，用来实现对窗口的拖动
    *
    * @param event 鼠标相关事件
    */
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::About *ui;
};

#endif // ABOUT_H
