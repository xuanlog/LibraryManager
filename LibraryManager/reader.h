#ifndef READER_H
#define READER_H

#include <QWidget>
#include "sqltablemodel.h"

namespace Ui {
class Reader;
}

/**
* @brief 读者管理界面类
* 实现用户账号的删除、查询以及对逾期书籍的归还处理功能
*/
class Reader : public QWidget
{
    Q_OBJECT

public:
    explicit Reader(QWidget *parent = nullptr);

    ~Reader();

private:
    Ui::Reader *ui;

    SqlTableModel *m_model;     ///< 操作 userInfo 表的对象

    SqlTableModel *m_pModel;    ///< 操作 personalCenter 表的对象

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
    * @brief 账号删除信号
    * @detail 触发对应槽函数清除账号借书信息
    *
    * @param account 删除的账号
    */
    void sigDelete(const QString &account);

    /**
    * @brief 还书信号
    * @detail 触发对应槽函数更新图书库存
    *
    * @param bookNum 书籍编号
    */
    void sigReturn(int bookNum);

public slots:
    /**
    * @brief 刷新函数
    * @detail 刷新 m_model 对象的信息，界面恢复成默认状态
    *
    * @note m_model 对象不会实时获取表中的数据，
    *       所以需要在表格更新后进行刷新
    */
    void refresh();

    /**
    * @brief 账号借书数量更新函数
    * @detail 判断是借书还是还书，从而增加或减少借书数量的信息
    *
    * @param account 用户账号
    * @param isBorrow 借/还书标识符，true 为借书，false 为还书
    */
    void bookUpdate(const QString &account, bool isBorrow);

    /**
    * @brief 地址更新函数
    * @detail 更新用户的收货地址
    *
    * @param userInfo 用户相关信息，目前仅有账号与地址
    */
    void addressUpdate(const QStringList &userInfo);

private slots:
    /**
    * @brief 账号删除函数
    * @detail 删除相应用户账号
    */
    void deleteAccount();

    /**
    * @brief 查询函数
    * @detail 查询对应账号以及该账号逾期借书情况
    *
    * @param account 查询输入框内的信息
    */
    void search(const QString &account);

    /**
    * @brief 还书函数
    * @detail 逾期书籍可以归还，并从 personalCenter 表删除该书籍信息
    */
    void returnBook();
};

#endif // READER_H
