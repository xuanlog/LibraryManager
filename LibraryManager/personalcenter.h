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
    void initialization();    // 初始化

    void commitData();    // 提交数据

private:
    Ui::PersonalCenter *ui;

    SqlTableModel *m_model;

signals:
    void sigSuccessful();    // 借阅成功信号

public slots:
    void recvBookInfo(const QStringList &info);    // 获取书籍信息
    void addAcountInfo(const QString &info);    // 添加账号信息
};

#endif // PERSONALCENTER_H
