#ifndef RESETPASSWORD_H
#define RESETPASSWORD_H

#include <QWidget>
#include "sqltablemodel.h"

namespace Ui {
class ResetPassword;
}

class ResetPassword : public QWidget
{
    Q_OBJECT

public:
    explicit ResetPassword(QWidget *parent = nullptr);
    ~ResetPassword();

private:
    Ui::ResetPassword *ui;

    SqlTableModel *m_model;

    void initialization();    // 初始化

    void connectConfig();    // 信号与槽的设置

    void changeWidget(int index);    // 切换窗口

private slots:
    void reset();    // 重置
    void back();    // 返回登录
};

#endif // RESETPASSWORD_H
