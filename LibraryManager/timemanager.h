#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <QThread>

class TimeManager : public QThread
{
    Q_OBJECT

public:
    explicit TimeManager(QObject *parent = nullptr);
    ~TimeManager();

protected:
    void run();

signals:
    void sigTipsUpdate(const QString &time, const QString &tips = "");
};

#endif // TIMEMANAGER_H
