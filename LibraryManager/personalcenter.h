#ifndef PERSONALCENTER_H
#define PERSONALCENTER_H

#include <QWidget>
#include <QSqlTableModel>

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

private:
    void commitData();    // 提交数据

    Ui::PersonalCenter *ui;

    QSqlTableModel *m_model;

signals:
    void sigSuccessful();    // 借阅成功信号

public slots:
    void recvBookInfo(const QStringList &info);    // 获取书籍信息
};

#endif // PERSONALCENTER_H
