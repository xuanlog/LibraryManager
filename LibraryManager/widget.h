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

private:
    Ui::Widget *ui;

    TimeManager *m_timer;

    void connectConfig();    // 信号与槽的设置
    void timeUpdate(const QString &time, const QString &tips);
};
#endif // WIDGET_H
