#ifndef READER_H
#define READER_H

#include <QWidget>
#include "sqltablemodel.h"

namespace Ui {
class Reader;
}

class Reader : public QWidget
{
    Q_OBJECT

public:
    explicit Reader(QWidget *parent = nullptr);
    ~Reader();

private:
    Ui::Reader *ui;

    SqlTableModel *m_model;

    void initialization();    // 初始化

    void connectConfig();    // 信号与槽的设置

signals:
    void sigDelete(const QString &account);

public slots:
    void refresh();    // 刷新
    void bookUpdate(const QString &account, bool isBorrow);
    void statusUpdate(const QString &account);

private slots:
    void deleteAccount();    // 删除账号
};

#endif // READER_H
