#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>
#include "sqltablemodel.h"

namespace Ui {
class Manager;
}

/**
* @brief 书籍管理界面类
* 实现图书的增删等功能
*/
class Manager : public QWidget
{
    Q_OBJECT

public:
    explicit Manager(QWidget *parent = nullptr);

    ~Manager();

private:
    Ui::Manager *ui;

    SqlTableModel *m_model;    ///< 操作 stackRoom 表的对象

    bool m_isHide;             ///< 添加书籍窗口的显示与关闭标志位

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

    /**
    * @brief 清除信息函数
    * @detail 清除添加书籍的输入框的信息
    */
    void clearMessage();

public slots:
    /**
    * @brief 刷新函数
    * @detail 刷新 m_model 对象的信息，界面恢复成默认状态
    *
    * @note m_model 对象不会实时获取表中的数据，
    *       所以需要在表格更新后进行刷新
    */
    void refresh();

private slots:
    /**
    * @brief 模糊查询函数
    * @detail 根据查询类型查询相关书籍信息
    *
    * @param info 查询输入框内的信息
    */
    void queryBook(const QString &info);

    /**
    * @brief 切换窗口状态函数
    * @detail 添加书籍窗口的显示与隐藏控制
    */
    void changeWidgetState();

    /**
    * @brief 添加书籍函数
    * @detail 新增书籍信息
    */
    void addBook();

    /**
    * @brief 删除书籍函数
    * @detail 删除已有书籍
    */
    void deleteBook();
};

#endif // MANAGER_H
