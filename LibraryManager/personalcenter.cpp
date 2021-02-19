#include "personalcenter.h"
#include "ui_personalcenter.h"
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include "librarydefine.h"

PersonalCenter::PersonalCenter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PersonalCenter)
{
    ui->setupUi(this);

    initialization();
    connectConfig();
}

PersonalCenter::~PersonalCenter()
{
    delete ui;
}

// 初始化
void PersonalCenter::initialization()
{
    m_model = new SqlTableModel(this);
    m_model->setTable("personalCenter");
    m_model->setSort(PERSONAL_RTIME, Qt::AscendingOrder);   // 以还书时间升序排列

    // 设置多表查询所需条件
    m_model->setMultiTable("personalCenter, stackRoom");
    m_model->setMultiItem(QString::fromUtf8("借书时间, 还书时间, personalCenter.编号, 书名, 出版社, 作者"));

    // 设置列宽，Stretch：填充屏幕 ResizeToContents：根据内容长度设定 Fixed：固定
    ui->bookInfoView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->bookInfoView->setModel(m_model);
}

void PersonalCenter::initStatus()
{
    for (int i = 0; i < MAX_BORROW; i++)
    {
        int ret = bookStatus(i);

        if (ret == -1)
        {
            break;
        }
        else if (ret == 0)
        {
            continue;
        }

        emit sigStatus(ui->accountLabel->text());
        break;
    }
}

// 信号与槽的设置
void PersonalCenter::connectConfig()
{
    connect(ui->reBorrowButton, &QPushButton::clicked, this, &PersonalCenter::reBorrow);
    connect(ui->returnButton, &QPushButton::clicked, this, &PersonalCenter::returnBook);
}

// 获取书籍信息
void PersonalCenter::addBook(const QStringList &info)
{
    QString value = QString("'%1', '%2', %3, '%4', %5").arg(info.at(0)).arg(info.at(1))
            .arg(info.at(2)).arg(info.at(3)).arg(STATUS_NORMAL);

    m_model->insertSqlRow(value);
    m_model->multiSelect();
    emit sigBorrow(info.at(3), true);
}

int PersonalCenter::bookStatus(int row)
{
    QModelIndex index = m_model->index(row, PERSONAL_RTIME);
    QString returnTime = m_model->data(index).toString();

    if (returnTime.isEmpty())
    {
        return -1;
    }

    QDateTime dateTime = QDateTime::fromString(returnTime, "yyyy-MM-dd:hh:mm:ss");
    QDateTime curTime = QDateTime::currentDateTime();

    if (curTime > dateTime)
    {
        return 1;
    }

    return 0;
}

// 续借
void PersonalCenter::reBorrow()
{
    int selectRow = ui->bookInfoView->currentIndex().row();

    if (selectRow < 0)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("请选择需要续借的书籍!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 获取编号
    QModelIndex index = m_model->index(selectRow, PERSONAL_NUM);
    int bookNum = m_model->data(index).toInt();

    // 判断是否逾期
    if (bookStatus(selectRow) == 1)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"),
                                 QString::fromUtf8("该书已逾期，\n请到图书馆柜台办理还书并缴纳滞纳金!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 判断是否续借过
    QString condition = QString::fromUtf8("编号 = %1 AND 状态 = %2").arg(bookNum).arg(STATUS_REBORROW);

    if (m_model->checkSqlData(condition))
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("每本书仅可续借一次!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 续借后的还书时间
    index = m_model->index(selectRow, PERSONAL_RTIME);
    QString returnTime = m_model->data(index).toString();
    QDateTime dateTime = QDateTime::fromString(returnTime, "yyyy-MM-dd:hh:mm:ss");
    returnTime = dateTime.addDays(BORROW_TIME).toString("yyyy-MM-dd:hh:mm:ss");

    // 更新还书时间
    condition = QString::fromUtf8("编号 = %1").arg(bookNum);
    QString value = QString::fromUtf8("还书时间 = '%1', 状态 = %2").arg(returnTime).arg(STATUS_REBORROW);
    m_model->setSqlData(condition, value);
    m_model->multiSelect();
    QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("续借成功!"),
                             QString::fromUtf8("确定"));
}

// 还书
void PersonalCenter::returnBook()
{
    int selectRow = ui->bookInfoView->currentIndex().row();

    if (selectRow < 0)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("请选择需要归还的书籍!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 判断是否逾期
    if (bookStatus(selectRow) == 1)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"),
                                 QString::fromUtf8("该书已逾期，\n请到图书馆柜台办理还书并缴纳滞纳金!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 还书
    int ret = QMessageBox::question(this, QString::fromUtf8("提示"), QString::fromUtf8("确认归还该书籍?"),
                                    QString::fromUtf8("确定"), QString::fromUtf8("取消"));

    if (ret == SELECT_OK)
    {
        QModelIndex index = m_model->index(selectRow, PERSONAL_NUM);
        int bookNum = m_model->data(index).toInt();

        QString condition = QString::fromUtf8("编号 = %1").arg(bookNum);
        m_model->removeSqlRow(condition);
        m_model->multiSelect();
        emit sigReturn(bookNum);
    }
}

// 清除账号信息
void PersonalCenter::clearAccount(const QString &account)
{
    QString condition = QString::fromUtf8("账号 = '%1'").arg(account);
    m_model->removeSqlRow(condition);
    QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("已删除账号!"),
                             QString::fromUtf8("确定"));
}

// 刷新
void PersonalCenter::refresh(const QString &account)
{
    ui->accountLabel->setText(account);

    QString filter =
            QString::fromUtf8("personalCenter.账号 = '%1' AND personalCenter.编号 = stackRoom.编号")
            .arg(account);

    m_model->setMultiFilter(filter);
    m_model->multiSelect();

    initStatus();
}
