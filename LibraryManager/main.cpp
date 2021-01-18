#include "widget.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QProcess>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>

void sqlConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");

    if (!db.open())
    {
        QMessageBox::about(nullptr, QString::fromUtf8("提示"), QString::fromUtf8("连接数据库失败!"));
        exit(-1);
    }

    // 如果 MySQL 数据库中已经存在同名的表, 那么下面的代码不会执行
    QSqlQuery query(db);

    // 创建书库表
    query.exec(QString::fromUtf8("CREATE TABLE IF NOT EXISTS stackRoom(编号 INT PRIMARY KEY, 书名 VARCHAR(20), 出版社 VARCHAR(20), 作者 VARCHAR(20), 库存 INT)"));
    query.exec(QString::fromUtf8("INSERT INTO stackRoom VALUES(0, '三国演义', '中国出版社', '罗贯中', 19)"));
    query.exec(QString::fromUtf8("INSERT INTO stackRoom VALUES(1, '水浒传', '中国出版社', '施耐庵', 18)"));
    query.exec(QString::fromUtf8("INSERT INTO stackRoom VALUES(2, '西游记', '中国出版社', '吴承恩', 10)"));

    // 创建用户表
    query.exec(QString::fromUtf8("CREATE TABLE IF NOT EXISTS userInfo(账号 VARCHAR(20) PRIMARY KEY, 密码 VARCHAR(20))"));
    query.exec(QString::fromUtf8("INSERT INTO userInfo VALUES('admin', '123456')"));

    /*
     * 技术有限，QSqlTableModel 只能访问单表，
     * QSqlQueryModel 不能实时刷新且操作繁琐，
     * 故采用全单表设计了，以后有机会再改吧
     */
    // 创建个人中心表
    query.exec(QString::fromUtf8("CREATE TABLE IF NOT EXISTS personalCenter(借出时间 DATATIME, 还书时间 DATATIME, 编号 INT, 书名 VARCHAR(20), 出版社 VARCHAR(20), 作者 VARCHAR(20), 账号 VARCHAR(20))"));

    // 创建暂存表
    query.exec(QString::fromUtf8("CREATE TABLE IF NOT EXISTS temporary(编号 INT PRIMARY KEY, 书名 VARCHAR(20), 出版社 VARCHAR(20), 作者 VARCHAR(20), 库存 INT)"));
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sqlConnection();
    Widget w;
    w.show();
    return a.exec();
}
