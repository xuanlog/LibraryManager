#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <QThread>

/**
* @brief 时间管理线程类
* 实现根据时间段显示不同信息的功能
*/
class TimeManager : public QThread
{
    Q_OBJECT

public:
    explicit TimeManager(QObject *parent = nullptr);

    ~TimeManager();

protected:
    /**
    * @brief 线程函数
    * @detail 每隔一秒发送一次信号，实现实时显示时间以及不同时间段显示不同背景及提示
    */
    void run();

signals:
    /**
    * @brief 信息更新信号
    * @detail 更新时间、背景、提示
    *
    * @param time 当前时间
    * @param tips 提示，可不填
    * @param image 背景，可不填
    * @note 因为提示和背景是在进入不同时间段才更新，所以这两项可不填
    */
    void sigTipsUpdate(const QString &time, const QString &tips = "", const QString &image = "");
};

#endif // TIMEMANAGER_H
