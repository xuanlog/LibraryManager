#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>
#include "sqltablemodel.h"

namespace Ui {
class Manager;
}

class Manager : public QWidget
{
    Q_OBJECT

public:
    explicit Manager(QWidget *parent = nullptr);
    ~Manager();

protected:
    void connectConfig();    // 信号与槽的设置

private:
    Ui::Manager *ui;

    SqlTableModel *m_model;
    bool m_isHide;    // 窗口显示标志

public slots:
    void initialization();    // 初始化

private slots:
    void queryBook(const QString &info);    // 查询

    void changeType();    // 切换查询类型

    void changeWidgetState();    // 切换窗口状态

    void addBook();    // 添加书籍

    void deleteBook();    // 删除书籍
};

#endif // MANAGER_H
