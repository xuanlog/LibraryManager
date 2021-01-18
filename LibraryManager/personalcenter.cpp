#include "personalcenter.h"
#include "ui_personalcenter.h"
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>

PersonalCenter::PersonalCenter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PersonalCenter)
{
    ui->setupUi(this);

    connectConfig();
}

PersonalCenter::~PersonalCenter()
{
    delete ui;
}

// 初始化
void PersonalCenter::initialization(const QString &info)
{
    m_account = info;
    ui->accountLabel->setText(info);

    m_model = new SqlTableModel(this);
    m_model->setTable("personalCenter");
    m_model->setSort(0, Qt::AscendingOrder);
    QString condition = QString::fromUtf8("personalCenter.账号 = '%1'").arg(m_account);
    m_model->setFilter(condition);
    m_model->select();
    // 更新方式，OnRowChange：切换选中行时更新 OnFieldChange：切换选中区时更新 OnManualSubmit：手动更新
    m_model->setEditStrategy(SqlTableModel::OnManualSubmit);

    // 设置列宽，Stretch：填充屏幕 ResizeToContents：根据内容长度设定 Fixed：固定
    ui->bookInfoView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->bookInfoView->setModel(m_model);
}

// 信号与槽的设置
void PersonalCenter::connectConfig()
{
    connect(ui->reBorrowButton, &QPushButton::clicked, this, &PersonalCenter::reBorrow);
    connect(ui->returnButton, &QPushButton::clicked, this, &PersonalCenter::returnBook);
}

// 获取书籍信息
void PersonalCenter::recvBookInfo(const QStringList &info)
{
    QString condition = QString::fromUtf8("编号 = %1 AND 账号 = '%2'").arg(info.at(2)).arg(m_account);

    if (m_model->checkData(condition))
    {
        QMessageBox::about(this, QString::fromUtf8("提示"), QString::fromUtf8("请不要重复借阅!"));
        return;
    }

    QString values = QString("'%1', '%2', %3, '%4', '%5', '%6', '%7'").arg(info.at(0))
            .arg(info.at(1)).arg(info.at(2)).arg(info.at(3))
            .arg(info.at(4)).arg(info.at(5)).arg(m_account);

    m_model->insertRow(values);

    emit sigSuccessful();
}

// 续借
void PersonalCenter::reBorrow()
{
    int selectRow = ui->bookInfoView->currentIndex().row();

    if (selectRow < 0)
    {
        QMessageBox::about(this, QString::fromUtf8("提示"), QString::fromUtf8("请选择需要续借的书籍!"));
        return;
    }

    QModelIndex index = m_model->index(selectRow, 1);
    QString returnTime = m_model->data(index).toString();
    QDateTime dateTime = QDateTime::fromString(returnTime, "yyyy-MM-dd:hh:mm:ss");
    returnTime = dateTime.addDays(15).toString("yyyy-MM-dd:hh:mm:ss");    // 续借 15 天
    m_model->setData(index, returnTime);
    commitData();
}

// 还书
void PersonalCenter::returnBook()
{
    int selectRow = ui->bookInfoView->currentIndex().row();

    if (selectRow < 0)
    {
        QMessageBox::about(this, QString::fromUtf8("提示"), QString::fromUtf8("请选择需要归还的书籍!"));
        return;
    }

    QModelIndex index = m_model->index(selectRow, 2);
    int bookNum = m_model->data(index).toInt();
    m_model->removeRow(selectRow);

    int ret = QMessageBox::question(this, QString::fromUtf8("提示"), QString::fromUtf8("确认归还该书籍?"),
                                    QString::fromUtf8("确定"), QString::fromUtf8("取消"));

    switch (ret)
    {
    case 0:
        m_model->submitAll();
        emit sigReturn(bookNum);
        break;
    case 1:
        m_model->revertAll();
        break;
    default:
        break;
    }
}

// 清除账号信息
void PersonalCenter::clearAccount(const QString &account)
{

}

// 提交数据
void PersonalCenter::commitData()
{
    m_model->database().transaction();    // 开始事务操作

    if (m_model->submitAll())
    {
        m_model->database().commit();    // 提交
        return;
    }

    m_model->database().rollback();    // 回滚
}
