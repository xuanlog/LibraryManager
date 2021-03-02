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

    // 设置多表查询所需条件
    m_model->setMultiTable("personalCenter, stackRoom");
    m_model->setMultiItem(QString::fromUtf8("借书时间, 还书时间, personalCenter.编号, 书名, 出版社, 作者"));

    // 设置列宽，Stretch：填充屏幕 ResizeToContents：根据内容长度设定 Fixed：固定
    ui->bookInfoView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->bookInfoView->setModel(m_model);
}

// 书籍状态初始化
void PersonalCenter::initStatus()
{   
    int maxRow = m_model->rowCount();

    for (int i = 0; i < maxRow; i++)
    {
        bookStatus(i);
    }
}

// 控件信号链接
void PersonalCenter::connectConfig()
{
    connect(ui->reBorrowButton, &QPushButton::clicked, this, &PersonalCenter::reBorrow);
    connect(ui->returnButton, &QPushButton::clicked, this, &PersonalCenter::returnBook);
    connect(ui->changeButton, &QPushButton::clicked, this, &PersonalCenter::messageUpdate);
}

// 添加书籍
void PersonalCenter::addBook(const QStringList &info)
{
    QString value = QString("'%1', '%2', %3, '%4', %5").arg(info.at(0)).arg(info.at(1))
            .arg(info.at(2)).arg(info.at(3)).arg(STATUS_NORMAL);

    m_model->insertSqlRow(value);
    m_model->multiSelect();
    emit sigBorrow(info.at(3), true);
}

// 书籍状态
int PersonalCenter::bookStatus(int row)
{
    QModelIndex index = m_model->index(row, PERSONAL_RTIME);
    QString returnTime = m_model->data(index).toString();
    QDateTime dateTime = QDateTime::fromString(returnTime, "yyyy-MM-dd:hh:mm:ss");
    QDateTime curTime = QDateTime::currentDateTime();

    // 判断是否逾期，未逾期则返回
    if (curTime < dateTime)
    { 
        return 0;
    }

    // 逾期
    index = m_model->index(row, PERSONAL_NUM);
    int bookNum = m_model->data(index).toInt();
    QString condition = QString::fromUtf8("账号 = '%1' AND 编号 = %2 AND 状态 = %3")
            .arg(ui->accountLabel->text()).arg(bookNum).arg(STATUS_OVERDUE);

    // 判断本书是否已经登记为逾期，登记则直接返回
    if (m_model->checkSqlData(condition))
    {
        return 1;
    }

    // 登记为逾期状态
    condition = QString::fromUtf8("账号 = '%1' AND 编号 = %2").arg(ui->accountLabel->text()).arg(bookNum);
    QString value = QString::fromUtf8("状态 = %1").arg(STATUS_OVERDUE);
    m_model->setSqlData(condition, value);
    return 1;
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
    QString condition = QString::fromUtf8("账号 = '%1' AND 编号 = %2 AND 状态 = %3")
            .arg(ui->accountLabel->text()).arg(bookNum).arg(STATUS_REBORROW);

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
    condition = QString::fromUtf8("账号 = '%1' AND 编号 = %2").arg(ui->accountLabel->text()).arg(bookNum);
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

        QString condition = QString::fromUtf8("账号 = '%1' AND 编号 = %2")
                .arg(ui->accountLabel->text()).arg(bookNum);

        m_model->removeSqlRow(condition);
        m_model->multiSelect();
        emit sigReturn(bookNum);
    }
}

// 账号信息清除
void PersonalCenter::clearAccount(const QString &account)
{
    QString condition = QString::fromUtf8("账号 = '%1'").arg(account);
    m_model->removeSqlRow(condition);
    QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("已删除账号!"),
                             QString::fromUtf8("确定"));
}

// 信息更新
void PersonalCenter::messageUpdate()
{
    QString address = ui->addressEdit->text();
    QString phone = ui->phoneEdit->text();

    // 正则表达式
    QRegExp re_phone("^[1][3-8]\\d{9}$");
    QRegExpValidator rev_phone(re_phone, 0);
    int pos = 0;

    // 判断是否为空
    if (address.isEmpty() || phone.isEmpty())
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("电话、地址不可为空!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    if (rev_phone.validate(phone, pos) != 2)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("电话填写错误!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 判断是否有违规字符
    if (address.contains(" ") || phone.contains(" "))
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("电话或地址包含违规字符!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 发送
    QString account = ui->accountLabel->text();
    QStringList userInfo = {account, phone, address};
    emit sigMessage(userInfo);
}

// 刷新
void PersonalCenter::refresh(const QStringList &userInfo)
{
    ui->accountLabel->setText(userInfo.at(0));
    ui->phoneEdit->setText(userInfo.at(1));
    ui->addressEdit->setText(userInfo.at(2));

    QString filter =
            QString::fromUtf8("personalCenter.账号 = '%1' AND personalCenter.编号 = stackRoom.编号")
            .arg(userInfo.at(0));

    m_model->setMultiFilter(filter);
    m_model->multiSelect();

    // 更新书籍状态
    initStatus();
}
