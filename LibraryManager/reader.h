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
    SqlTableModel *m_pModel;

    void initialization();    // 初始化
    void initStyle();

    void connectConfig();    // 信号与槽的设置

signals:
    void sigDelete(const QString &account);
    void sigReturn(int bookNum);

public slots:
    void refresh();    // 刷新
    void bookUpdate(const QString &account, bool isBorrow);

private slots:
    void deleteAccount();    // 删除账号
    void search(const QString &account);
    void returnBook();
};

#endif // READER_H
