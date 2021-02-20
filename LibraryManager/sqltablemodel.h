#ifndef SQLTABLEMODEL_H
#define SQLTABLEMODEL_H

#include <QSqlTableModel>

/**
* @brief 数据库操作类
* 实现数据库操作功能，基本都是对 SQL 语句操作的简单封装
*/
class SqlTableModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit SqlTableModel(QObject *parent = nullptr);

    ~SqlTableModel();

    /**
    * @brief 多表查询表名设置函数
    * @detail 设置多表查询的表名
    *
    * @param tableName 多表查询表名，如 "personalCenter, stackRoom"
    * @note 专门为多表查询编写的函数，不用多表查询则无需设置，相反，用多表的话请务必设置
    */
    void setMultiTable(const QString &tableName);

    /**
    * @brief 多表查询条件设置函数
    * @detail 设置多表查询的条件
    *
    * @param filter 多表查询条件，如 "personalCenter.编号 = stackRoom.编号"
    * @note 专门为多表查询编写的函数，不用多表查询则无需设置，相反，用多表的话请务必设置
    */
    void setMultiFilter(const QString &filter);

    /**
    * @brief 多表查询项设置函数
    * @detail 设置想要查询的项
    *
    * @param item 多表查询项，如 "借书时间, 还书时间"
    * @note 专门为多表查询编写的函数，不用多表查询则无需设置
    */
    void setMultiItem(const QString &item);

    /**
    * @brief 多表查询函数
    * @detail 多表查询相关的信息
    *
    * @note 专门为多表查询编写的函数，与 QSqlTableModel 的 select 二选其一
    */
    void multiSelect();

    /**
    * @brief 数据检测函数
    * @detail 检测表中是否存在相关数据
    *
    * @param condition 检测条件，如 "账号 = '123456'"
    * @return 数据是否存在
    *     @retval false 不存在
    *     @retval true 存在
    * @note 检测对象通过 setTable 设置的表中的数据
    */
    bool checkSqlData(const QString &condition);

    /**
    * @brief 数据检测函数
    * @detail 检测表中是否存在相关数据
    *
    * @param tableName 检测的表名，如 "userInfo"
    * @param condition 检测条件，如 "账号 = '123456'"
    * @return 数据是否存在
    *     @retval false 不存在
    *     @retval true 存在
    * @note 检测自定义的表中的数据
    */
    bool checkSqlData(const QString &tableName, const QString &condition);

    /**
    * @brief 行新增函数
    * @detail 在表中新增一行
    *
    * @param value 新增行的内容，如 "0, '123456'"
    */
    void insertSqlRow(const QString &value);

    /**
    * @brief 行删除函数
    * @detail 在表中删除已有行
    *
    * @param condition 删除行的条件，如 "账号 = '123456'"
    */
    void removeSqlRow(const QString &condition);

    /**
    * @brief 数据修改函数
    * @detail 在表中修改特定行数据
    *
    * @param condition 确定修改行的条件，如 "账号 = '123456'"
    * @param value 修改的内容，如 "状态 = 2"
    */
    void setSqlData(const QString &condition, const QString &value);

private:
    QSqlQuery *m_query;     ///< 操作数据库的对象

    QString m_tableName;    ///< 多表查询表名

    QString m_filter;       ///< 多表查询过滤条件

    QString m_item;         ///< 多表查询项

    /**
    * @brief 初始化函数
    * @detail 对内部成员进行初始化操作
    */
    void initialization();
};

#endif // SQLTABLEMODEL_H
