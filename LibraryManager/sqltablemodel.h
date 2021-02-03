#ifndef SQLTABLEMODEL_H
#define SQLTABLEMODEL_H

#include <QSqlTableModel>

class SqlTableModel : public QSqlTableModel
{
    Q_OBJECT

public:
    SqlTableModel(QObject *parent = nullptr);
    ~SqlTableModel();

    bool checkSqlData(const QString &condition);    // 判断表中是否存在数据

    void insertSqlRow(const QString &values);    // 新增一行

    void removeSqlRow(const QString &values);    // 删除相关行

protected:
    void initialization();    // 初始化

private:
    QSqlQuery *m_query;
};

#endif // SQLTABLEMODEL_H
