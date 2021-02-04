#ifndef PERSONALCENTER_H
#define PERSONALCENTER_H

#include <QWidget>
#include "sqltablemodel.h"

namespace Ui {
class PersonalCenter;
}

class PersonalCenter : public QWidget
{
    Q_OBJECT

public:
    explicit PersonalCenter(QWidget *parent = nullptr);
    ~PersonalCenter();

private:
    Ui::PersonalCenter *ui;

    SqlTableModel *m_model;

    void initialization();    // 初始化
    void connectConfig();    // 信号与槽的设置

signals:
    void sigReturn(int num);    // 归还信号
    void sigBorrow(const QString &account, bool isBorrow);

public slots:
    void refresh(const QString &account);    // 刷新
    void addBook(const QStringList &info);    // 获取书籍信息
    void clearAccount(const QString &account);    // 清除账号信息

private slots:
    void reBorrow();    // 续借
    void returnBook();    // 还书
};

#endif // PERSONALCENTER_H
