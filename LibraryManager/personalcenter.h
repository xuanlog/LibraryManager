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

protected:
    void connectConfig();    // 信号与槽的设置
    void commitData();    // 提交数据

private:
    Ui::PersonalCenter *ui;

    SqlTableModel *m_model;
    QString m_account;    // 账号

signals:
    void sigSuccessful();    // 借阅成功信号
    void sigReturn(int num);    // 归还信号

public slots:
    void initialization(const QString &info);    // 初始化
    void recvBookInfo(const QStringList &info);    // 获取书籍信息
    void clearAccount(const QString &account);    // 清除账号信息

private slots:
    void reBorrow();    // 续借
    void returnBook();    // 还书
};

#endif // PERSONALCENTER_H
