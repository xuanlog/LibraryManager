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

protected:
    void connectConfig();    // 信号与槽的设置

private:
    Ui::Reader *ui;

    SqlTableModel *m_model;

signals:
    void sigDelete(const QString &account);

public slots:
    void initialization();    // 初始化

private slots:
    void deleteAccount();    // 删除账号
};

#endif // READER_H
