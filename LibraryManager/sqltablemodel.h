#ifndef SQLTABLEMODEL_H
#define SQLTABLEMODEL_H

#include <QSqlTableModel>

class SqlTableModel : public QSqlTableModel
{
    Q_OBJECT

public:
    SqlTableModel(QObject *parent = nullptr);
    ~SqlTableModel();

    bool checkData(const QString &condition);    // 判断表中是否存在数据

    void insertData(const QString &values);    // 新增一行

    void removeData(const QString &values);    // 删除相关行

protected:
    void initialization();    // 初始化

private:
    QSqlQuery *m_query;
};

#endif // SQLTABLEMODEL_H
