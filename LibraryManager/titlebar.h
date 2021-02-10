#ifndef TITLEBAR_H
#define TITLEBAR_H

#include "widget.h"

namespace Ui {
class TitleBar;
}

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget *parent = nullptr);
    ~TitleBar();

protected:
    void mouseDoubleClickEvent(QMouseEvent *event);    // 双击事件
    void mousePressEvent(QMouseEvent *event);    // 拖动事件

private:
    Ui::TitleBar *ui;

    void initialization();    // 初始化
    void connectConfig();    // 信号与槽的设置

private slots:
    void maxSize();
};

#endif // TITLEBAR_H
