#ifndef STACKROOM_H
#define STACKROOM_H

#include <QWidget>
#include <QSqlTableModel>

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
    void initialization();    // 初始化
    void connectConfig();    // 信号与槽的设置

private:
    void commitData();    // 提交数据

    Ui::StackRoom *ui;

    QSqlTableModel *m_model;

signals:
    void sigBorrowBook(const QStringList &info);    // 借阅信号

public slots:
    void inventoryUpdate();    // 库存更新

private slots:
    void queryBook(const QString &info);    // 查询

    void changeType();    // 切换查询类型

    void borrowBook();    // 借阅
};

#endif // STACKROOM_H
