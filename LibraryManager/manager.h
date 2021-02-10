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

private:
    Ui::Manager *ui;

    SqlTableModel *m_model;
    bool m_isHide;    // 窗口显示标志

    void initialization();    // 初始化
    void initStyle();
    void connectConfig();    // 信号与槽的设置

public slots:
    void refresh();    // 刷新

private slots:
    void queryBook(const QString &info);    // 查询

    void changeType();    // 切换查询类型

    void changeWidgetState();    // 切换窗口状态

    void addBook();    // 添加书籍

    void deleteBook();    // 删除书籍
};

#endif // MANAGER_H
