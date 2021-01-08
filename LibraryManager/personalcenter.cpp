#include "personalcenter.h"
#include "ui_personalcenter.h"
#include <QMessageBox>
#include <QDebug>

PersonalCenter::PersonalCenter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PersonalCenter)
{
    ui->setupUi(this);

    initialization();
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
    QString condition = QString::fromUtf8(
                "personalCenter.账号 = '1234'");
    //m_model->multiSelect(condition);
    m_model->setFilter(condition);
    m_model->select();
    // 更新方式，OnRowChange：切换选中行时更新 OnFieldChange：切换选中区时更新 OnManualSubmit：手动更新
    m_model->setEditStrategy(SqlTableModel::OnManualSubmit);

    // 设置列宽，Stretch：填充屏幕 ResizeToContents：根据内容长度设定 Fixed：固定
    ui->bookInfoView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->bookInfoView->setModel(m_model);
}

// 获取书籍信息
void PersonalCenter::recvBookInfo(const QStringList &info)
{      
    //    int maxRow = m_model->rowCount();
    //    int maxColumn = m_model->columnCount();
    QString account = ui->accountLabel->text();
    QString condition = QString::fromUtf8("编号 = %1 AND 账号 = '%2'").arg(info.at(2)).arg(account);

    if (m_model->checkData(condition))
    {
        QMessageBox::about(this, QString::fromUtf8("提示"), QString::fromUtf8("请不要重复借阅!"));
        return;
    }

    QString values = QString::fromUtf8("'%1', '%2', %3, '%4'").arg(info.at(0))
            .arg(info.at(1)).arg(info.at(2)).arg(account);
    m_model->insertRow(values);

    //    for (int i = 0; i < maxColumn; i++)    // 添加借阅书籍
    //    {
    //        QModelIndex index = m_model->index(maxRow, i);
    //        m_model->setData(index, info.at(i));
    //    }

    emit sigSuccessful();
    commitData();
}

// 添加账号信息
void PersonalCenter::addAcountInfo(const QString &info)
{
    ui->accountLabel->setText(info);
}

// 提交数据
void PersonalCenter::commitData()
{
    //    m_model->database().transaction();    // 开始事务操作

    //    if (m_model->submitAll())
    //    {
    //        m_model->database().commit();    // 提交
    //        return;
    //    }

    //    m_model->database().rollback();    // 回滚
}
