#include "reader.h"
#include "ui_reader.h"
#include "librarydefine.h"

Reader::Reader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reader)
{
    ui->setupUi(this);

    connectConfig();
}

Reader::~Reader()
{
    delete ui;
}

// 初始化
void Reader::initialization()
{
    m_model = new SqlTableModel(this);
    m_model->setTable("userInfo");
    QString filter = QString::fromUtf8("账号 NOT LIKE '%1'").arg(kManagerAccount);
    m_model->setFilter(filter);
    m_model->select();

    // 更新方式，OnRowChange：切换选中行时更新 OnFieldChange：切换选中区更新 OnManualSubmit：手动更新
    m_model->setEditStrategy(SqlTableModel::OnManualSubmit);

    // 设置列宽，Stretch：填充屏幕 ResizeToContents：根据内容长度设定 Fixed：固定
    ui->readerView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->readerView->setModel(m_model);
}

// 信号与槽的设置
void Reader::connectConfig()
{
    connect(ui->deleteButton, &QPushButton::clicked, this, &Reader::deleteAccount);
}

// 删除账号
void Reader::deleteAccount()
{
    int selectRow = ui->readerView->currentIndex().row();

    if (selectRow < 0)
    {
        QMessageBox::about(this, QString::fromUtf8("提示"), QString::fromUtf8("请选择需要删除的账号!"));
        return;
    }

    QModelIndex index = m_model->index(selectRow, 0);
    QString account = m_model->data(index).toString();
    int ret = QMessageBox::question(this, QString::fromUtf8("提示"), QString::fromUtf8("操作不可逆，是否继续?"),
                                    QString::fromUtf8("确定"), QString::fromUtf8("取消"));

    if (ret == 0)    // 确定删除
    {
        m_model->QSqlTableModel::removeRow(selectRow);
        m_model->submitAll();
        emit sigDelete(account);
    }
}
