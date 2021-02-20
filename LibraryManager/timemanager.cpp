#include "timemanager.h"
#include <QDateTime>
#include <windows.h>

TimeManager::TimeManager(QObject *parent)
    : QThread(parent)
{
}

TimeManager::~TimeManager()
{
    if (QThread::isRunning())
    {
        QThread::requestInterruption();    // 请求停止线程
        QThread::quit();
        QThread::wait();
    }
}

void TimeManager::run()
{
    QTime time;
    QString dateTime = "";

    // 时间段对应的时间
    QTime threeClock = QTime(3, 0);
    QTime sixClock = QTime(6, 0);
    QTime eightClock = QTime(8, 0);
    QTime elevenClock = QTime(11, 0);
    QTime thirteenClock = QTime(13, 0);
    QTime seventeenClock = QTime(17, 0);
    QTime nineteenClock = QTime(19, 0);
    QTime twentyThreeClock = QTime(23, 0);

    QString tips = "";
    QString curTips = "";
    QString image = "";

    // 用是否请求停止线程作为条件判断是否结束循环
    while (!QThread::isInterruptionRequested())
    {
        time = QTime::currentTime();    // 当前时间

        if (time > sixClock && time <= eightClock)    // 早上
        {
            tips = QString::fromUtf8("三更灯火五更鸡，正是男儿读书时");
            image = "bg001";
        }
        else if (time > eightClock && time <= elevenClock)    // 上午
        {
            tips = QString::fromUtf8("人之进学在于思，思则能知是与非");
            image = "bg002";
        }
        else if (time > elevenClock && time <= thirteenClock)    // 中午
        {
            tips = QString::fromUtf8("书到用时方恨少，事非经过不知难");
            image = "bg003";
        }
        else if (time > thirteenClock && time <= seventeenClock)    // 下午
        {
            tips = QString::fromUtf8("我闭南楼看道书，幽帘清寂在仙居");
            image = "bg004";
        }
        else if (time > seventeenClock && time <= nineteenClock)    // 傍晚
        {
            tips = QString::fromUtf8("书当快意读易尽，客有可人期不来");
            image = "bg005";
        }
        else if (time > nineteenClock && time <= twentyThreeClock)    // 晚上
        {
            tips = QString::fromUtf8("月过碧窗今夜酒，雨昏红壁去年书");
            image = "bg006";
        }
        else if (time > twentyThreeClock && time <= threeClock)    // 深夜
        {
            tips = QString::fromUtf8("晓月闲移三尺剑，孤灯苦读五更书\n夜已深了，还请早些休息");
            image = "bg007";
        }
        else if (time > threeClock && time <= sixClock)    // 凌晨
        {
            tips = QString::fromUtf8("读书切戒在慌忙，涵泳工夫兴味长\n已经凌晨了，请注意休息");
            image = "bg008";
        }

        // 获取时间
        dateTime = QDateTime::currentDateTime().toString("yyyy/M/d dddd\n   hh:mm:ss");

        // 判断是否进入其他时间段
        if (curTips != tips)
        {
            // 不同时间段，更新提示和背景
            curTips = tips;
            emit sigTipsUpdate(dateTime, tips, image);
        }
        else
        {
            // 相同时间段，仅更新时间
            emit sigTipsUpdate(dateTime);
        }

        Sleep(1000);
    }
}
