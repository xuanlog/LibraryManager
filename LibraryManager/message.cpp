#include "message.h"
#include "ui_message.h"
#include <QMessageBox>
#include <QDateTime>
#include "librarydefine.h"
#include <QAction>

Message::Message(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Message)
{
    ui->setupUi(this);

    initialization();
    filterUpdate();
    initStyle();
    connectConfig();
}

Message::~Message()
{
    delete ui;
}

// 初始化
void Message::initialization()
{
    m_type = "";
    m_status = QString::fromUtf8("未处理");
    m_search = "";

    m_model = new SqlTableModel(this);
    m_model->setTable("message");

    // 设置列宽，Stretch：填充屏幕 ResizeToContents：根据内容长度设定 Fixed：固定
    ui->messageView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->messageView->setModel(m_model);
}

// 控件风格初始化
void Message::initStyle()
{
    QAction *searchAction = new QAction(this);
    searchAction->setIcon(QIcon(":/Images/clear.png"));
    ui->searchEdit->addAction(searchAction, QLineEdit::TrailingPosition);
    connect(searchAction, &QAction::triggered, this, [=](){
        ui->searchEdit->clear();
    });
}

// 过滤信息更新
void Message::filterUpdate()
{
    m_model->setFilter(QString::fromUtf8("处理状态 LIKE '%%1%' ").arg(m_status) +
                       QString::fromUtf8("AND 类型 LIKE '%%1%' ").arg(m_type) +
                       QString::fromUtf8("AND 信息 LIKE '%%1%'").arg(m_search));
}

// 控件信号链接
void Message::connectConfig()
{
    connect(ui->confirmButton, &QPushButton::clicked, this, &Message::dispose);
    connect(ui->statusCheckBox, &QCheckBox::clicked, this, &Message::changeStatus);
    connect(ui->typeComboBox, static_cast<void(QComboBox::*)(int)>
            (&QComboBox::currentIndexChanged), this, &Message::changeType);

    connect(ui->searchEdit, &QLineEdit::textChanged, this, &Message::search);
}

// 类型更新
void Message::changeType(int index)
{
    switch (index)
    {
    case 0:
        m_type = "";
        break;
    case 1:
        m_type = QString::fromUtf8("借书");
        break;
    case 2:
        m_type = QString::fromUtf8("还书");
        break;
    }

    filterUpdate();
    refresh();
}

// 搜索
void Message::search(const QString &text)
{
    m_search = text;
    filterUpdate();
    refresh();
}

// 状态更新
void Message::changeStatus(bool isChecked)
{
    m_status = isChecked ? "" : QString::fromUtf8("未处理");
    filterUpdate();
    refresh();
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

    // 信息已被处理的情况
    QModelIndex index = m_model->index(selectRow, MESSAGE_STATUS);

    if (m_model->data(index).toString() == QString::fromUtf8("已处理"))
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("该信息已处理!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 处理
    m_model->setData(index, QString::fromUtf8("已处理"));
    QDateTime curTime = QDateTime::currentDateTime();
    QString time = curTime.toString("yyyy-MM-dd:hh:mm:ss");
    index = m_model->index(selectRow, MESSAGE_TIME);
    m_model->setData(index, time);
    m_model->submitAll();    // 提交
    QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("处理成功!"),
                             QString::fromUtf8("确定"));

    refresh();
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
    refresh();
}

// 刷新
void Message::refresh()
{
    m_model->select();
}
