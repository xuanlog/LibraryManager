#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>
#include "sqltablemodel.h"

namespace Ui {
class Message;
}

/**
* @brief 消息界面类
* 查看用户的借书还书消息以及处理
*/
class Message : public QWidget
{
    Q_OBJECT

public:
    explicit Message(QWidget *parent = nullptr);

    ~Message();

private:
    Ui::Message *ui;

    SqlTableModel *m_model;    ///< 操作 message 表的对象

    /**
    * @brief 初始化函数
    * @detail 对内部成员及部分控件进行初始化操作
    */
    void initialization();

    /**
    * @brief 控件信号链接函数
    * @detail 链接控件的信号，实现控件对应的功能
    */
    void connectConfig();

public slots:
    /**
    * @brief 借/还书信息更新函数
    * @detail 更新借/还书信息
    *
    * @param info 相关信息
    * @param isBorrow 借/还书标志位
    */
    void infoUpdate(const QStringList &info, bool isBorrow);

private slots:
    /**
    * @brief 处理信息函数
    * @detail 处理信息
    */
    void dispose();
};

#endif // MESSAGE_H
