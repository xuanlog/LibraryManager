#ifndef STACKROOM_H
#define STACKROOM_H

#include <QWidget>
#include "sqltablemodel.h"

namespace Ui {
class StackRoom;
}

class StackRoom : public QWidget
{
    Q_OBJECT

public:
    explicit StackRoom(QWidget *parent = nullptr);
    ~StackRoom();

protected:
    void connectConfig();    // 信号与槽的设置
    void commitData();    // 提交数据

private:
    Ui::StackRoom *ui;

    SqlTableModel *m_model;
    SqlTableModel *m_tModel;

signals:
    void sigBorrowBook(const QStringList &info);    // 借阅信号

public slots:
    void initialization();    // 初始化
    void inventoryUpdate();    // 库存更新
    void bookUpdate(int bookNum);

private slots:
    void queryBook(const QString &info);    // 查询

    void changeType();    // 切换查询类型

    void borrowBook();    // 借阅

    void confirmBorrow();    // 确认借阅
};

#endif // STACKROOM_H
