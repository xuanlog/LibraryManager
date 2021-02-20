#ifndef LIBRARYDEFINE_H
#define LIBRARYDEFINE_H

#include <QString>
#include <QMessageBox>
#include <QDebug>

#define MAX_BORROW 5      ///< 借书上限
#define MIN_LENGTH 6      ///< 账号密码最小长度
#define BORROW_TIME 30    ///< 借书时长

const QString kVersion = "1.1.0";           ///< 软件版本
const QString kManagerAccount = "admin";    ///< 管理员账号

/**
* @brief 窗口页面枚举
* 标识窗口页面
*/
enum WIDGET_PAGE
{
    PAGE_LOGIN = 0,     ///< 登录
    PAGE_RESET,         ///< 重置密码
    PAGE_REGISTERED,    ///< 注册
    PAGE_PERSONAL,      ///< 个人中心
    PAGE_STACK_ROOM,    ///< 书库大厅
    PAGE_MANAGER,       ///< 书籍管理
    PAGE_READER         ///< 读者管理
};

/**
* @brief 书库大厅表头枚举
* 标识书库大厅表头
*/
enum STACK_ROOM_HEADER
{
    STACK_NUM = 0,     ///< 编号
    STACK_NAME,        ///< 书名
    STACK_PUBLISH,     ///< 出版社
    STACK_AUTHOR,      ///< 作者
    STACK_INVENTORY    ///< 库存
};

/**
* @brief 个人中心表头枚举
* 标识个人中心表头
*/
enum PERSONAL_CENTER_HEADER
{
    PERSONAL_LTIME = 0,    ///< 借出时间
    PERSONAL_RTIME,        ///< 还书时间
    PERSONAL_NUM,          ///< 编号
    PERSONAL_NAME,         ///< 书名
    PERSONAL_PUBLISH,      ///< 出版社
    PERSONAL_AUTHOR        ///< 作者
};

/**
* @brief 用户信息表头枚举
* 标识用户信息表头
*/
enum USER_INFO_HEADER
{
    USER_ACCOUNT = 0,    ///< 账号
    USER_PASSWORD,       ///< 密码
    USER_BORROWED,       ///< 已借书数目
    USER_TOTAL,          ///< 共借书数目
    USER_ADDRESS         ///< 地址
};

/**
* @brief 书籍状态枚举
* 标识书籍借出后的状态
*/
enum STATUS
{
    STATUS_NORMAL = 0,    ///< 正常
    STATUS_REBORROW,      ///< 续借过
    STATUS_OVERDUE        ///< 逾期
};

/**
* @brief 选项枚举
* 标识选项作用
*/
enum SELECT_FLAG
{
    SELECT_OK = 0,    ///< 确定
    SELECT_CANCEL     ///< 取消
};

#endif // LIBRARYDEFINE_H
