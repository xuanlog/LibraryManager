#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "timemanager.h"
#include <QSystemTrayIcon>
#include <QCloseEvent>

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
    void closeEvent(QCloseEvent *event);

private:
    Ui::Widget *ui;

    TimeManager *m_timer;
    QSystemTrayIcon *m_tray;    // 系统托盘
    bool m_isClose;

    void initTray();
    void connectConfig();    // 信号与槽的设置

private slots:
    void timeUpdate(const QString &time, const QString &tips, const QString &image);
    void showWindow(QSystemTrayIcon::ActivationReason reason);
    void exitWindow();
};
#endif // WIDGET_H
