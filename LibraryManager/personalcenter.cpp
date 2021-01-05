#include "personalcenter.h"
#include "ui_personalcenter.h"
#include "librarydefine.h"
#include <QStackedWidget>

PersonalCenter::PersonalCenter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalCenter)
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
    m_model = new QSqlTableModel(this);
    m_model->setTable("personalCenter, stackRoom");
    m_model->select();    // 显示全表

    // 更新方式，OnRowChange：切换选中行时更新 OnFieldChange：切换选中区时更新 OnManualSubmit：手动更新
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 设置列宽，Stretch：填充屏幕 ResizeToContents：根据内容长度设定 Fixed：固定
    ui->bookInfoView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->bookInfoView->setModel(m_model);
}

// 获取书籍信息
void PersonalCenter::recvBookInfo(const QStringList &info)
{      
    int maxRow = m_model->rowCount();
    int maxColumn = m_model->columnCount();

    for (int i = 0; i < maxRow; i++)    // 判断是否已借阅该书籍
    {
        if (info.at(1) == m_model->data(m_model->index(i, 1)))
        {
            QMessageBox::about(this, QString::fromUtf8("提示"), QString::fromUtf8("请不要重复借阅!"));
            return;
        }
    }

    m_model->insertRow(maxRow);

    for (int i = 0; i < maxColumn; i++)    // 添加借阅书籍
    {
        QModelIndex index = m_model->index(maxRow, i);
        m_model->setData(index, info.at(i));
    }

    emit sigSuccessful();
    commitData();
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
