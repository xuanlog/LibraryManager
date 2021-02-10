#include "reader.h"
#include "ui_reader.h"
#include "librarydefine.h"

Reader::Reader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reader)
{
    ui->setupUi(this);

    initialization();
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
    // 不显示管理员账号
    QString filter = QString::fromUtf8("账号 NOT LIKE '%1'").arg(kManagerAccount);
    m_model->setFilter(filter);
    m_model->select();

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
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("请选择需要删除的账号!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    int ret = QMessageBox::question(this, QString::fromUtf8("提示"), QString::fromUtf8("操作不可逆，是否继续?"),
                                    QString::fromUtf8("确定"), QString::fromUtf8("取消"));

    if (ret == SELECT_OK)    // 确定删除
    {
        QModelIndex index = m_model->index(selectRow, USER_ACCOUNT);
        QString account = m_model->data(index).toString();

        QString condition = QString::fromUtf8("账号 = '%1'").arg(account);
        m_model->removeSqlRow(condition);
        emit sigDelete(account);
    }
}

// 刷新
void Reader::refresh()
{
    m_model->select();
}

void Reader::bookUpdate(const QString &account, bool isBorrow)
{
    int maxRow = m_model->rowCount();

    for (int i = 0; i < maxRow; i++)
    {
        // 查找账号所在行
        QModelIndex index = m_model->index(i, USER_ACCOUNT);

        if (account == m_model->data(index).toString())
        {
            // 获取已借和共借数量
            index = m_model->index(i, USER_BORROWED);
            int borrowed = m_model->data(index).toInt();
            index = m_model->index(i, USER_TOTAL);
            int total = m_model->data(index).toInt();

            // 更新
            QString condition = QString::fromUtf8("账号 = %1").arg(account);

            if (isBorrow)
            {
                // 借书
                QString value = QString::fromUtf8("已借书 = %1, 共借书 = %2").arg(++borrowed).arg(++total);
                m_model->setSqlData(condition, value);
                QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("借书成功!"),
                                         QString::fromUtf8("确定"));
                break;
            }

            // 还书
            QString value = QString::fromUtf8("已借书 = %1").arg(--borrowed);
            m_model->setSqlData(condition, value);
            QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("还书成功!"),
                                     QString::fromUtf8("确定"));
            break;
        }
    }
}
