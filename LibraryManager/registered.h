#ifndef REGISTERED_H
#define REGISTERED_H

#include <QWidget>
#include "sqltablemodel.h"

namespace Ui {
class Registered;
}

class Registered : public QWidget
{
    Q_OBJECT

public:
    explicit Registered(QWidget *parent = nullptr);
    ~Registered();

private:
    Ui::Registered *ui;

    SqlTableModel *m_model;

    void initialization();    // 初始化

    void connectConfig();    // 信号与槽的设置

    void changeWidget(int index);    // 切换窗口

signals:
    void sigRegist();

private slots:
    void registered();    // 注册
    void back();    // 返回登录
};

#endif // REGISTERED_H
