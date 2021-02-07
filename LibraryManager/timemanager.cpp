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
    QString dateTime;
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

    // 用是否请求停止线程作为条件判断是否结束循环
    while (!QThread::isInterruptionRequested())
    {
        time = QTime::currentTime();

        if (time > sixClock && time <= eightClock)
        {
            tips = QString::fromUtf8("早上好");
        }
        else if (time > eightClock && time <= elevenClock)
        {
            tips = QString::fromUtf8("上午好");
        }
        else if (time > elevenClock && time <= thirteenClock)
        {
            tips = QString::fromUtf8("中午好");
        }
        else if (time > thirteenClock && time <= seventeenClock)
        {
            tips = QString::fromUtf8("下午好");
        }
        else if (time > seventeenClock && time <= nineteenClock)
        {
            tips = QString::fromUtf8("傍晚好");
        }
        else if (time > nineteenClock && time <= twentyThreeClock)
        {
            tips = QString::fromUtf8("晚上好");
        }
        else if (time > twentyThreeClock && time <= threeClock)
        {
            tips = QString::fromUtf8("深夜好");
        }
        else if (time > threeClock && time <= sixClock)
        {
            tips = QString::fromUtf8("凌晨好");
        }

        // 获取时间
        dateTime = QDateTime::currentDateTime().toString("yyyy/M/d dddd\n   hh:mm:ss");

        // 判断 tips 是否需要更新
        if (curTips != tips)
        {
            curTips = tips;
            emit sigTipsUpdate(dateTime, tips);
        }
        else
        {
            emit sigTipsUpdate(dateTime);
        }

        Sleep(1000);
    }
}
