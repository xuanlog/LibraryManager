#include "widget.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QProcess>
#include <QDebug>

void sqlConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");

    if (!db.open())
    {
        QMessageBox::about(nullptr, QString::fromUtf8("提示"), QString::fromUtf8("无法创建数据库连接!"));
        exit(-1);
    }

    // 如果 MySQL 数据库中已经存在同名的表, 那么下面的代码不会执行
    QSqlQuery query(db);
    // 创建书库表
    query.exec(QString::fromUtf8("create table stackRoom(编号 int primary key, 书名 varchar(20), 出版社 varchar(20), 作者 varchar(20), 库存 int)"));
    query.exec(QString::fromUtf8("insert into stackRoom values(0, '三国演义', '中国出版社', '罗贯中', 2)"));
    query.exec(QString::fromUtf8("insert into stackRoom values(1, '水浒传', '中国出版社', '施耐庵', 1)"));
    query.exec(QString::fromUtf8("insert into stackRoom values(2, '西游记', '中国出版社', '吴承恩', 0)"));

    // 创建个人中心表
    //query.exec(QString::fromUtf8("create table personalCenter(借出时间 datetime, 还书时间 datetime, 编号 int primary key, 书名 varchar(20), 出版社 varchar(20), 作者 varchar(20))"));
    query.exec(QString::fromUtf8("create table personalCenter(借出时间 datetime, 还书时间 datetime, 编号 int, foreign key(编号) references stackRoom(编号))"));
    query.exec(QString::fromUtf8("insert into personalCenter values(0, 0, 0)"));
    query.exec(QString::fromUtf8("insert into personalCenter values(1, 1, 1)"));
    query.exec(QString::fromUtf8("PRAGMA foreign_keys = ON"));
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sqlConnection();
    Widget w;
    w.show();
    return a.exec();
}
