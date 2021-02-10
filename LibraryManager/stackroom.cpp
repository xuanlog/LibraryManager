#include "stackroom.h"
#include "ui_stackroom.h"
#include "librarydefine.h"
#include "widget.h"
#include <QDateTime>
#include <QAction>

StackRoom::StackRoom(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StackRoom)
{
    ui->setupUi(this);

    initialization();
    initStyle();
    connectConfig();
}

StackRoom::~StackRoom()
{
    delete ui;
}

void StackRoom::initStyle()
{
    QAction *queryAction = new QAction(this);
    queryAction->setIcon(QIcon(":/Images/clear.png"));
    ui->queryEdit->addAction(queryAction, QLineEdit::TrailingPosition);
    connect(queryAction, &QAction::triggered, this, &StackRoom::changeType);
}

// 初始化
void StackRoom::initialization()
{
    m_account = "";
    m_model = new SqlTableModel(this);
    m_model->setTable("stackRoom");
    m_model->setSort(STACK_INVENTORY, Qt::DescendingOrder);    // 降序

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
    connect(ui->queryTypeComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &StackRoom::changeType);

    connect(ui->queryEdit, &QLineEdit::textChanged, this, &StackRoom::queryBook);
    connect(ui->borrowButton, &QPushButton::clicked, this, &StackRoom::borrowBook);
}

// 查询
void StackRoom::queryBook(const QString &info)
{
    int queryType = ui->queryTypeComboBox->currentIndex();
    QString filter = "";

    // LIKE '%%1%' 模糊搜索 %1：arg 里面的参数 前后两个 % 表示参数前或后可能有其他字符
    switch (queryType)
    {
    case STACK_NUM:
        filter = QString::fromUtf8("编号 LIKE '%%1%'").arg(info);
        break;
    case STACK_NAME:
        filter = QString::fromUtf8("书名 LIKE '%%1%'").arg(info);
        break;
    case STACK_PUBLISH:
        filter = QString::fromUtf8("出版社 LIKE '%%1%'").arg(info);
        break;
    case STACK_AUTHOR:
        filter = QString::fromUtf8("作者 LIKE '%%1%'").arg(info);
        break;
    case STACK_INVENTORY:
        filter = QString::fromUtf8("库存 LIKE '%%1%'").arg(info);
        break;
    }

    m_model->setFilter(filter);
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

    if (selectRow < 0)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("请选择需要借阅的书籍!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 获取库存
    QModelIndex index = m_model->index(selectRow, STACK_INVENTORY);
    int inventory = m_model->data(index).toInt();

    if (inventory == 0)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("该书暂无库存!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    QString condition = QString::fromUtf8("账号 = '%1' AND 已借书 = %2").arg(m_account).arg(MAX_BORROW);

    if (m_model->checkSqlData("userInfo", condition))
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("借书上限为 %1 本!")
                                 .arg(MAX_BORROW), QString::fromUtf8("确定"));
        return;
    }

    // 获取书籍编号
    index = m_model->index(selectRow, STACK_NUM);
    QString data = m_model->data(index).toString();
    condition = QString::fromUtf8("编号 = %1 AND 账号 = '%2'").arg(data).arg(m_account);

    if (m_model->checkSqlData("personalCenter", condition))
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("请不要重复借阅!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 更新库存
    condition = QString::fromUtf8("编号 = %1").arg(data);
    QString value = QString::fromUtf8("库存 = %1").arg(--inventory);
    m_model->setSqlData(condition, value);

    // 获取时间
    QDateTime curTime = QDateTime::currentDateTime();
    QString lendTime = curTime.toString("yyyy-MM-dd:hh:mm:ss");    // 借书时间
    QString returnTime = curTime.addDays(15).toString("yyyy-MM-dd:hh:mm:ss");    // 还书时间

    // 传输数据到 personalCenter 表
    QStringList info = {lendTime, returnTime, data, m_account};
    emit sigBorrow(info);
}

void StackRoom::bookUpdate(int bookNum)
{
    int maxRow = m_model->rowCount();

    for (int i = 0; i < maxRow; i++)
    {
        // 查找书籍所在行
        QModelIndex index = m_model->index(i, STACK_NUM);

        if (bookNum == m_model->data(index).toInt())
        {
            // 获取库存
            index = m_model->index(i, STACK_INVENTORY);
            int inventory = m_model->data(index).toInt();

            // 更新库存
            QString condition = QString::fromUtf8("编号 = %1").arg(bookNum);
            QString value = QString::fromUtf8("库存 = %1").arg(++inventory);
            m_model->setSqlData(condition, value);
            emit sigReturn(m_account, false);
            break;
        }
    }
}

// 刷新
void StackRoom::refresh(const QString &account)
{
    m_account = account;
    m_model->select();
    ui->queryTypeComboBox->setCurrentIndex(0);
}
