#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlQuery>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

private slots:
    void on_pushButton_clicked();
};
#endif // WIDGET_H
