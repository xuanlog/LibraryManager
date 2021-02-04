#ifndef SQLTABLEMODEL_H
#define SQLTABLEMODEL_H

#include <QSqlTableModel>

class SqlTableModel : public QSqlTableModel
{
    Q_OBJECT

public:
    SqlTableModel(QObject *parent = nullptr);
    ~SqlTableModel();

    void setMultiTable(const QString &tableName);

    void setMultiFilter(const QString &filter);
    void setMultiItem(const QString &item);

    void multiSelect();

    bool checkSqlData(const QString &condition);    // 判断表中是否存在数据
    bool checkSqlData(const QString &tableName, const QString &condition);

    void insertSqlRow(const QString &value);    // 新增一行

    void removeSqlRow(const QString &condition);    // 删除相关行

    void setSqlData(const QString &condition, const QString &value);    // 修改数据

private:
    QSqlQuery *m_query;

    QString m_tableName;
    QString m_filter;
    QString m_item;

    void initialization();    // 初始化
};

#endif // SQLTABLEMODEL_H
