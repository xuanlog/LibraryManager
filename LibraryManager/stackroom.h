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

private:
    Ui::StackRoom *ui;

    SqlTableModel *m_model;
    QString m_account;    // 账号

    void initialization();    // 初始化
    void initStyle();
    void connectConfig();    // 信号与槽的设置

signals:
    void sigBorrow(const QStringList &info);    // 借阅信号
    void sigReturn(const QString &account, bool isBorrow);

public slots:
    void refresh(const QString &account);    // 刷新
    void bookUpdate(int bookNum);

private slots:
    void queryBook(const QString &info);    // 查询

    void changeType();    // 切换查询类型

    void borrowBook();    // 借阅
};

#endif // STACKROOM_H
