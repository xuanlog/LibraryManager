#include "message.h"
#include "ui_message.h"
#include <QMessageBox>
#include <QDateTime>

Message::Message(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Message)
{
    ui->setupUi(this);

    initialization();
    connectConfig();
}

Message::~Message()
{
    delete ui;
}

// 初始化
void Message::initialization()
{
    m_model = new SqlTableModel(this);
    m_model->setTable("message");
    m_model->select();

    // 设置列宽，Stretch：填充屏幕 ResizeToContents：根据内容长度设定 Fixed：固定
    ui->messageView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->messageView->setModel(m_model);
}

// 控件信号链接
void Message::connectConfig()
{
    connect(ui->confirmButton, &QPushButton::clicked, this, &Message::dispose);
}

// 处理信息
void Message::dispose()
{
    int selectRow = ui->messageView->currentIndex().row();

    if (selectRow < 0)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("请选择处理信息!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    QModelIndex index = m_model->index(selectRow, 2);

    if (m_model->data(index).toString() == QString::fromUtf8("已处理"))
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("该信息已处理!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    m_model->setData(index, QString::fromUtf8("已处理"));

    QDateTime curTime = QDateTime::currentDateTime();
    QString time = curTime.toString("yyyy-MM-dd:hh:mm:ss");
    index = m_model->index(selectRow, 3);
    m_model->setData(index, time);
    m_model->submitAll();
    QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("处理成功!"),
                             QString::fromUtf8("确定"));
}

// 借/还书信息更新
void Message::infoUpdate(const QStringList &info, bool isBorrow)
{
    QString message = isBorrow ?
                QString::fromUtf8("用户 %1 于 %2 借阅编号为 %3 的书籍，该用户联系电话 %4，地址 %5，请尽快处理！")
                .arg(info.at(0)).arg(info.at(1)).arg(info.at(2)).arg(info.at(3)).arg(info.at(4)) :
                QString::fromUtf8("用户 %1 于 %2 归还编号为 %3 的书籍，该用户联系电话 %4，地址 %5，请尽快派人回收书籍！")
                .arg(info.at(0)).arg(info.at(1)).arg(info.at(2)).arg(info.at(3)).arg(info.at(4));

    QString type = isBorrow ? QString::fromUtf8("借书") : QString::fromUtf8("还书");
    QString value = QString("'%1', '%2', '未处理', ' '").arg(type).arg(message);
    m_model->insertSqlRow(value);
    m_model->select();
}
