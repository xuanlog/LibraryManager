#include "sqltablemodel.h"
#include <QSqlQuery>

SqlTableModel::SqlTableModel(QObject *parent)
    : QSqlTableModel(parent)
{
    initialization();
}

SqlTableModel::~SqlTableModel()
{
    delete m_query;
}

// 初始化
void SqlTableModel::initialization()
{
    m_query = new QSqlQuery(QSqlTableModel::database());
    m_tableName = "";
    m_filter = "";
    m_item = "*";
}

void SqlTableModel::setMultiTable(const QString &tableName)
{
    m_tableName = tableName;
}

void SqlTableModel::setMultiFilter(const QString &filter)
{
    m_filter = filter;
}

void SqlTableModel::setMultiItem(const QString &item)
{
    m_item = item;
}

void SqlTableModel::multiSelect()
{
    QString cmd = QString::fromUtf8("SELECT %1 FROM %2 WHERE %3").arg(m_item)
            .arg(m_tableName).arg(m_filter);

    if (m_filter.isEmpty())
    {
        cmd = QString::fromUtf8("SELECT %1 FROM %2").arg(m_item).arg(m_tableName);
    }

    QSqlQueryModel::setQuery(cmd);
}

// 判断表中是否存在数据
bool SqlTableModel::checkSqlData(const QString &condition)
{
    QString tableName = QSqlTableModel::tableName();
    QString cmd = QString("SELECT * FROM %1 WHERE %2").arg(tableName).arg(condition);

    /*
     * 刚执行完 query.exec() 时，query 是指向结果集以外的，
     * 利用 query.next() 使得 query 指向结果集的第一条记录
     */
    m_query->exec(cmd);
    return m_query->next();
}

bool SqlTableModel::checkSqlData(const QString &tableName, const QString &condition)
{
    QString cmd = QString("SELECT * FROM %1 WHERE %2").arg(tableName).arg(condition);

    /*
     * 刚执行完 query.exec() 时，query 是指向结果集以外的，
     * 利用 query.next() 使得 query 指向结果集的第一条记录
     */
    m_query->exec(cmd);
    return m_query->next();
}

// 修改数据
void SqlTableModel::setSqlData(const QString &condition, const QString &value)
{
    QString tableName = QSqlTableModel::tableName();
    QString cmd = QString("UPDATE %1 SET %2 WHERE %3").arg(tableName).arg(value).arg(condition);
    m_query->exec(cmd);
    QSqlTableModel::select();
}

// 新增一行
void SqlTableModel::insertSqlRow(const QString &value)
{
    QString tableName = QSqlTableModel::tableName();
    QString cmd = QString("INSERT INTO %1 VALUES(%2)").arg(tableName).arg(value);
    m_query->exec(cmd);
    QSqlTableModel::select();
}

// 删除相关行
void SqlTableModel::removeSqlRow(const QString &condition)
{
    QString tableName = QSqlTableModel::tableName();
    QString cmd = QString("DELETE FROM %1 WHERE %2").arg(tableName).arg(condition);
    m_query->exec(cmd);
    QSqlTableModel::select();
}
