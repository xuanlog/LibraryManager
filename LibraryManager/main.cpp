#include "widget.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QProcess>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include "md5.h"
#include <QFileDialog>

void sqlConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = MD5::Encrypt("library.db");
    QString path = QCoreApplication::applicationDirPath() + "/Data/";

    QDir dir(path);

    if (!dir.exists())
    {
        QDir().mkpath(path);
    }

    path += dbName;
    db.setDatabaseName(path);

    if (!db.open())
    {
        QMessageBox::information(nullptr, QString::fromUtf8("提示"), QString::fromUtf8("连接数据库失败!"),
                                 QString::fromUtf8("确定"));
        exit(-1);
    }

    QSqlQuery query(db);

    // 创建 stackRoom 表
    query.exec(QString::fromUtf8("CREATE TABLE IF NOT EXISTS stackRoom(编号 INT PRIMARY KEY, 书名 VARCHAR(20), 出版社 VARCHAR(20), 作者 VARCHAR(20), 库存 INT)"));
    query.exec(QString::fromUtf8("INSERT INTO stackRoom VALUES(0, '三国演义', '中国出版社', '罗贯中', 19)"));
    query.exec(QString::fromUtf8("INSERT INTO stackRoom VALUES(1, '水浒传', '中国出版社', '施耐庵', 18)"));
    query.exec(QString::fromUtf8("INSERT INTO stackRoom VALUES(2, '西游记', '中国出版社', '吴承恩', 10)"));
    query.exec(QString::fromUtf8("INSERT INTO stackRoom VALUES(3, '红楼梦', '中国出版社', '曹雪芹', 20)"));

    // 加密
    QString password = MD5::Encrypt("admin123456");

    // 创建 userInfo 表
    query.exec(QString::fromUtf8("CREATE TABLE IF NOT EXISTS userInfo(账号 VARCHAR(20) PRIMARY KEY, 密码 VARCHAR(20), 已借书 INT, 共借书 INT, 姓名 VARCHAR(10), 电话 VARCHAR(11), 地址 VARCHAR(64))"));
    query.exec(QString::fromUtf8("INSERT INTO userInfo VALUES('admin', '%1', 0, 0, 'admin', '11111111111', ' ')").arg(password));

    // 创建 personalCenter 表
    query.exec(QString::fromUtf8("CREATE TABLE IF NOT EXISTS personalCenter(借书时间 DATATIME, 还书时间 DATATIME, 编号 INT, 账号 VARCHAR(20), 状态 INT)"));

    // 创建 message 表
    query.exec(QString::fromUtf8("CREATE TABLE IF NOT EXISTS message(类别 VARCHAR(4), 信息 VARCHAR(255), 处理状态 VARCHAR(6), 处理时间 DATATIME)"));
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sqlConnection();
    Widget w;
    w.show();
    return a.exec();
}
