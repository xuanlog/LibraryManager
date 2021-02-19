#include "reader.h"
#include "ui_reader.h"
#include "librarydefine.h"
#include <QAction>

Reader::Reader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reader)
{
    ui->setupUi(this);

    initialization();
    initStyle();
    connectConfig();
}

Reader::~Reader()
{
    delete ui;
}

// 初始化
void Reader::initialization()
{
    // 读者表
    m_model = new SqlTableModel(this);
    m_model->setTable("userInfo");
    // 不显示管理员账号
    QString filter = QString::fromUtf8("账号 NOT LIKE '%1'").arg(kManagerAccount);
    m_model->setFilter(filter);
    m_model->select();

    // 设置列宽，Stretch：填充屏幕 ResizeToContents：根据内容长度设定 Fixed：固定
    ui->readerView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->readerView->setModel(m_model);

    // 逾期书籍表
    m_pModel = new SqlTableModel(this);
    m_pModel->setTable("personalCenter");
    m_pModel->setMultiTable("personalCenter, stackRoom");
    m_pModel->setMultiItem(QString::fromUtf8("借书时间, 还书时间, personalCenter.编号, 书名, 出版社, 作者"));
    ui->bookInfoView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->bookInfoView->setModel(m_pModel);
}

void Reader::initStyle()
{
    QAction *accountTrail = new QAction(this);
    accountTrail->setIcon(QIcon(":/Images/clear.png"));
    ui->searchEdit->addAction(accountTrail, QLineEdit::TrailingPosition);
    connect(accountTrail, &QAction::triggered, this, [=](){
        ui->searchEdit->clear();
    });

}

// 信号与槽的设置
void Reader::connectConfig()
{
    connect(ui->deleteButton, &QPushButton::clicked, this, &Reader::deleteAccount);
    connect(ui->searchEdit, &QLineEdit::textChanged, this, &Reader::search);
    connect(ui->confirmButton, &QPushButton::clicked, this, &Reader::returnBook);
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
    ui->searchEdit->clear();
}

void Reader::search(const QString &account)
{
    QString filter =
            QString::fromUtf8(
                "personalCenter.账号 = '%1' AND personalCenter.编号 = stackRoom.编号 AND personalCenter.状态 = %2")
            .arg(account).arg(STATUS_OVERDUE);

    m_pModel->setMultiFilter(filter);
    m_pModel->multiSelect();

    filter = QString::fromUtf8("账号 NOT LIKE '%1' AND 账号 LIKE '%%2%'").arg(kManagerAccount).arg(account);
    m_model->setFilter(filter);
}

void Reader::returnBook()
{
    int selectRow = ui->bookInfoView->currentIndex().row();

    if (selectRow < 0)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("请选择书籍!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    int ret = QMessageBox::question(this, QString::fromUtf8("提示"), QString::fromUtf8("确认归还?"),
                                    QString::fromUtf8("确定"), QString::fromUtf8("取消"));

    if (ret == SELECT_OK)
    {
        QModelIndex index = m_pModel->index(selectRow, PERSONAL_NUM);
        int bookNum = m_pModel->data(index).toInt();

        QString condition = QString::fromUtf8("账号 = '%1' AND 编号 = %2")
                .arg(ui->searchEdit->text()).arg(bookNum);

        m_pModel->removeSqlRow(condition);
        m_pModel->multiSelect();
        emit sigReturn(bookNum);
    }
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
