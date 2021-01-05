#include "stackroom.h"
#include "ui_stackroom.h"
#include "librarydefine.h"
#include <QDateTime>

StackRoom::StackRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StackRoom)
{
    ui->setupUi(this);

    initialization();
    connectConfig();
}

StackRoom::~StackRoom()
{
    delete ui;
}

// 初始化
void StackRoom::initialization()
{
    m_model = new QSqlTableModel(this);
    m_model->setTable("stackRoom");
    m_model->select();

    // 更新方式，OnRowChange：切换选中行时更新 OnFieldChange：切换选中区更新 OnManualSubmit：手动更新
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 设置列宽，Stretch：填充屏幕 ResizeToContents：根据内容长度设定 Fixed：固定
    ui->bookInfoView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->bookInfoView->setModel(m_model);
}

// 信号与槽的设置
void StackRoom::connectConfig()
{
    /*
     * QComboBox 的 currentIndexChanged 有两个重载，一个参数是 int，一个参数是 QString，所以需要用下面的语句强制类型转换，否则
     * connect 不知道触发哪个信号，用 QT4 的写法则无此问题
    */
    connect(ui->queryTypeComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &StackRoom::changeType);
    connect(ui->queryEdit, &QLineEdit::textChanged, this, &StackRoom::queryBook);
    connect(ui->borrowButton, &QPushButton::clicked, this, &StackRoom::borrowBook);
}

// 查询
void StackRoom::queryBook(const QString &info)
{
    int queryType = ui->queryTypeComboBox->currentIndex();
    QString cmd = "";

    // like '%%1%' 模糊搜索 %1：arg 里面的参数 前后两个 % 表示参数前或后可能有其他字符
    switch (queryType)
    {
    case HEADER_NUM:
        cmd = QString::fromUtf8("编号 like '%%1%'").arg(info);
        break;
    case HEADER_NAME:
        cmd = QString::fromUtf8("书名 like '%%1%'").arg(info);
        break;
    case HEADER_PUBLISH:
        cmd = QString::fromUtf8("出版社 like '%%1%'").arg(info);
        break;
    case HEADER_AUTHOR:
        cmd = QString::fromUtf8("作者 like '%%1%'").arg(info);
        break;
    case HEADER_INVENTORY:
        cmd = QString::fromUtf8("库存 like '%%1%'").arg(info);
        break;
    }

    m_model->setFilter(cmd);
    m_model->select();
}

// 切换查询类型
void StackRoom::changeType()
{
    ui->queryEdit->clear();
}

// 借阅
void StackRoom::borrowBook()
{
    int selectRow = ui->bookInfoView->currentIndex().row();
    QModelIndex index = m_model->index(selectRow, HEADER_INVENTORY);
    int inventory = m_model->data(index).toInt();

    if (selectRow < 0)
    {
        QMessageBox::about(this, QString::fromUtf8("提示"), QString::fromUtf8("请选择需要借阅的书籍!"));
        return;
    }

    if (inventory == 0)
    {
        QMessageBox::about(this, QString::fromUtf8("提示"), QString::fromUtf8("该书暂无库存!"));
        return;
    }

    QDateTime curTime = QDateTime::currentDateTime();
    QString lendTime = curTime.toString("yyyy-MM-dd:hh:mm:ss");    // 获取当前时间
    QString returnTime = curTime.addDays(15).toString("yyyy-MM-dd:hh:mm:ss");    // 15 天后还书
    QStringList info = {lendTime, returnTime};

    for (int i = 0; i < MAX_COLUMN; i++)    // 获取书籍信息
    {
        index = m_model->index(selectRow, i);
        info.push_back(m_model->data(index).toString());
    }

    emit sigBorrowBook(info);
}

// 库存更新
void StackRoom::inventoryUpdate()
{
    int selectRow = ui->bookInfoView->currentIndex().row();
    QModelIndex index = m_model->index(selectRow, HEADER_INVENTORY);
    int inventory = m_model->data(index).toInt();
    m_model->setData(index, --inventory);
    commitData();
}

// 提交数据
void StackRoom::commitData()
{
    m_model->database().transaction();    // 开始事务操作

    if (m_model->submitAll())
    {
        m_model->database().commit();    // 提交
        return;
    }

    m_model->database().rollback();    // 回滚
}
