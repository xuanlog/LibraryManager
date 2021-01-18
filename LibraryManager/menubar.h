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
    void initialization();    // 初始化
    void connectConfig();    // 信号与槽的设置

    void changeWidget(int index);    // 切换窗口

private:
    Ui::MenuBar *ui;

private slots:
    void moveToStackRoom();    // 移动页面
    void moveToPersonalCenter();    // 移动页面
    void moveToLogin();    // 移动页面
    void moveToManager();
    void moveToReader();
    void showWidget(int index);    // 显示窗口
};

#endif // MENUBAR_H
