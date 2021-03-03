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

    QString m_type;            ///< 类型
    QString m_status;          ///< 状态
    QString m_search;          ///< 搜索信息

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
    * @brief 过滤信息更新函数
    * @detail 过滤信息更新
    */
    void filterUpdate();

signals:
    /**
    * @brief 新消息信号
    * @detail 触发对应槽函数来改变按键状态
    */
    void sigNews();

public slots:
    /**
    * @brief 借/还书信息更新函数
    * @detail 更新借/还书信息
    *
    * @param info 相关信息
    * @param isBorrow 借/还书标志位
    */
    void infoUpdate(const QStringList &info, bool isBorrow);

    /**
    * @brief 刷新函数
    * @detail 刷新 m_model 对象、账号及地址的信息，更新书籍状态
    *
    * @note m_model 对象不会实时获取表中的数据，
    *       所以需要在表格更新后进行刷新
    */
    void refresh();

private slots:
    /**
    * @brief 处理信息函数
    * @detail 处理信息
    */
    void dispose();

    /**
    * @brief 状态更新函数
    * @detail 是否显示已处理信息
    *
    * @param isChecked 勾选框的状态
    */
    void changeStatus(bool isChecked);

    /**
    * @brief 类型更新函数
    * @detail 显示借书或还书信息
    *
    * @param index 项的位置
    */
    void changeType(int index);

    /**
    * @brief 搜索函数
    * @detail 搜索账号
    *
    * @param text 输入框内的信息
    */
    void search(const QString &text);
};

#endif // MESSAGE_H
