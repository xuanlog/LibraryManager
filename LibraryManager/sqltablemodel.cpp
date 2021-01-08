#include "sqltablemodel.h"
#include <QSqlQuery>
#include <QDebug>

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
}

// 判断表中是否存在数据
bool SqlTableModel::checkData(const QString &condition)
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

// 新增一行
void SqlTableModel::insertRow(const QString &values)
{
    QString tableName = QSqlTableModel::tableName();
    QString cmd = QString("INSERT INTO %1 VALUES(%2)").arg(tableName).arg(values);
    m_query->exec(cmd);
    qDebug() << cmd;
}
