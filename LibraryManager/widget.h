#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "timemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

private:
    Ui::Widget *ui;

    TimeManager *m_timer;

    void connectConfig();    // 信号与槽的设置

private slots:
    void timeUpdate(const QString &time, const QString &tips, const QString &image);
};
#endif // WIDGET_H
