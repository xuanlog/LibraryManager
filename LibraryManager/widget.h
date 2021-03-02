#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "timemanager.h"
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include "about.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

/**
* @brief 主窗口类
* 软件主窗口
*/
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget();

protected:
    /**
    * @brief windows 消息事件
    * @detail 用来实现窗口的拉伸与收缩
    *
    * @param eventType 事件类型，不使用
    * @param message 消息
    * @param result 消息处理的句柄
    * @return 消息是否被处理
    *     @retval false 未处理
    *     @retval true 处理
    * @note 个人理解
    */
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

    /**
    * @brief 关闭事件
    * @detail 重写关闭事件，只有右键系统托盘才能关闭窗口，否则只隐藏窗口
    *
    * @param event 关闭相关事件
    */
    void closeEvent(QCloseEvent *event);

private:
    Ui::Widget *ui;

    TimeManager *m_timer;       ///< 时间管理线程对象

    QSystemTrayIcon *m_tray;    ///< 系统托盘对象

    bool m_isClose;             ///< 是否关闭窗口的标志位

    About m_w;                 ///< 关于软件的窗口

    /**
    * @brief 初始化函数
    * @detail 对内部成员进行初始化操作
    */
    void initialization();

    /**
    * @brief 系统托盘初始化函数
    * @detail 对系统托盘进行初始化操作
    */
    void initTray();

    /**
    * @brief 控件信号链接函数
    * @detail 链接控件的信号，实现控件对应的功能
    */
    void connectConfig();

private slots:
    /**
    * @brief 时间更新函数
    * @detail 实时更新时间以及提示与背景
    *
    * @param time 当前时间
    * @param tips 提示
    * @param image 背景
    */
    void timeUpdate(const QString &time, const QString &tips, const QString &image);

    /**
    * @brief 主窗口显示函数
    * @detail 显示主窗口
    *
    * @param reason 鼠标点击的键
    */
    void showWindow(QSystemTrayIcon::ActivationReason reason);

    /**
    * @brief 窗口关闭函数
    * @detail 关闭所有窗口，退出程序
    */
    void exitWindow();

    /**
    * @brief 关于窗口展示函数
    * @detail 打开关于界面
    */
    void showAbout();
};

#endif // WIDGET_H
