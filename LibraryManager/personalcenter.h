#ifndef PERSONALCENTER_H
#define PERSONALCENTER_H

#include <QWidget>
#include "sqltablemodel.h"

namespace Ui {
class PersonalCenter;
}

/**
* @brief 个人中心界面类
* 实现查看个人借书情况，续借以及还书等功能
*/
class PersonalCenter : public QWidget
{
    Q_OBJECT

public:
    explicit PersonalCenter(QWidget *parent = nullptr);

    ~PersonalCenter();

private:
    Ui::PersonalCenter *ui;

    SqlTableModel *m_model;    ///< 操作 personalCenter 表的对象

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

    /**
    * @brief 书籍状态函数
    * @details 判断书籍是否逾期
    *
    * @param row 书籍所在行号
    * @return 书籍是否逾期
    *     @retval 0 未逾期
    *     @retval 1 逾期
    */
    int bookStatus(int row);

    /**
    * @brief 书籍状态初始化函数
    * @details 对书籍是否逾期进行初始化
    */
    void initStatus();

signals:
    /**
    * @brief 还书信号
    * @detail 触发对应槽函数更新图书库存
    *
    * @param num 书籍编号
    */
    void sigReturn(int num);

    /**
    * @brief 借书成功信号
    * @detail 触发对应槽函数更新用户已借书与共借书数目
    *
    * @param account 用户账号
    * @param isBorrow 是借书还是还书，此处填 true 即可
    */
    void sigBorrow(const QString &account, bool isBorrow);

    /**
    * @brief 信息修改信号
    * @detail 触发对应槽函数修改用户信息
    *
    * @param userInfo 用户相关信息
    */
    void sigMessage(const QStringList &userInfo);

public slots:
    /**
    * @brief 刷新函数
    * @detail 刷新 m_model 对象、账号及地址的信息，更新书籍状态
    *
    * @param userInfo 用户相关信息，目前仅有账号与地址
    * @note m_model 对象不会实时获取表中的数据，
    *       所以需要在表格更新后进行刷新
    */
    void refresh(const QStringList &userInfo);

    /**
    * @brief 添加书籍函数
    * @detail 借书之后，personalCenter 表增加借阅的书籍
    *
    * @param info 书籍相关信息，包括借书时间、还书时间、编号、账号、书籍状态
    */
    void addBook(const QStringList &info);

    /**
    * @brief 账号信息清除函数
    * @detail 账号删除之后，清理掉该账号的借书信息
    *
    * @param account 删除的账号
    */
    void clearAccount(const QString &account);

private slots:
    /**
    * @brief 续借函数
    * @detail 对未续借过且未逾期的书籍延长还书时间
    */
    void reBorrow();

    /**
    * @brief 还书函数
    * @detail 未逾期的书籍可以归还，personalCenter 表删除该书籍信息
    */
    void returnBook();

    /**
    * @brief 信息更新函数
    * @detail 将更新后的信息通过信号发送出去
    */
    void messageUpdate();
};

#endif // PERSONALCENTER_H
