#ifndef MENUBAR_H
#define MENUBAR_H

#include <QWidget>

namespace Ui {
class MenuBar;
}

class MenuBar : public QWidget
{
    Q_OBJECT

public:
    explicit MenuBar(QWidget *parent = nullptr);
    ~MenuBar();

protected:
    void connectConfig();    // 信号与槽的设置

    void changeWidget(int index);    // 切换窗口

private:
    Ui::MenuBar *ui;

private slots:
    void moveToStackRoom();    // 移动页面
    void moveToPersonalCenter();    // 移动页面
};

#endif // MENUBAR_H
