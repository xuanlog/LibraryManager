#ifndef STACKROOM_H
#define STACKROOM_H

#include <QWidget>
#include "sqltablemodel.h"

namespace Ui {
class StackRoom;
}

/**
* @brief 书库大厅界面类
* 实现图书的查询、借阅功能
*/
class StackRoom : public QWidget
{
    Q_OBJECT

public:
    explicit StackRoom(QWidget *parent = nullptr);

    ~StackRoom();

private:
    Ui::StackRoom *ui;

    SqlTableModel *m_model;    ///< 操作 stackRoom 表的对象

    QString m_account;         ///< 用户的账号信息

    /**
    * @brief 初始化函数
    * @detail 对内部成员及部分控件进行初始化操作
    */
    void initialization();

    /**
    * @brief 控件风格初始化函数
    * @detail 对控件风格进行初始化操作，主要是给输入框添加图标
    */
    void initStyle();

    /**
    * @brief 控件信号链接函数
    * @detail 链接控件的信号，实现控件对应的功能
    */
    void connectConfig();

signals:
    /**
    * @brief 借书信号
    * @detail 触发对应槽函数更新用户借书信息
    *
    * @param info 借阅的书籍信息，包括借书时间、还书时间、编号、账号
    */
    void sigBorrow(const QStringList &info);

    /**
    * @brief 还书成功信号
    * @detail 触发对应槽函数更新用户已借书数目
    *
    * @param account 用户账号
    * @param isBorrow 是借书还是还书，此处填 false 即可
    */
    void sigReturn(const QString &account, bool isBorrow);

public slots:
    /**
    * @brief 刷新函数
    * @detail 刷新 m_model 对象及账号的信息，界面恢复成默认状态
    *
    * @param userInfo 用户相关信息，目前仅有账号与地址
    * @note m_model 对象不会实时获取表中的数据，
    *       所以需要在表格更新后进行刷新
    */
    void refresh(const QStringList &userInfo);

    /**
    * @brief 库存更新函数
    * @detail 用户还书后，相应书籍库存增加
    *
    * @param bookNum 书籍编号
    */
    void bookUpdate(int bookNum);

    /**
    * @brief 逾期书籍操作函数
    * @detail 逾期书籍的还书处理
    *
    * @param bookNum 书籍编号
    * @param account 账号
    */
    void overdueBook(int bookNum, const QString &account);

private slots:
    /**
    * @brief 模糊查询函数
    * @detail 根据查询类型查询相关书籍信息
    *
    * @param info 查询输入框内的信息
    */
    void queryBook(const QString &info);

    /**
    * @brief 借阅函数
    * @detail 借阅后相关书籍库存减少
    */
    void borrowBook();
};

#endif // STACKROOM_H
