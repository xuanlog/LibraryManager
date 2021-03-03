#include "manager.h"
#include "ui_manager.h"
#include "librarydefine.h"
#include <QAction>

Manager::Manager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Manager)
{
    ui->setupUi(this);

    initialization();
    initStyle();
    connectConfig();
}

Manager::~Manager()
{
    delete ui;
}

// 控件风格初始化
void Manager::initStyle()
{
    // 查询
    QAction *queryAction = new QAction(this);
    queryAction->setIcon(QIcon(":/Images/clear.png"));
    ui->queryEdit->addAction(queryAction, QLineEdit::TrailingPosition);
    connect(queryAction, &QAction::triggered, this, [=](){
        ui->queryEdit->clear();
    });

    // 编号
    QAction *numAction = new QAction(this);
    numAction->setIcon(QIcon(":/Images/clear.png"));
    ui->numEdit->addAction(numAction, QLineEdit::TrailingPosition);
    connect(numAction, &QAction::triggered, this, [=](){
        ui->numEdit->clear();
    });

    // 书名
    QAction *nameAction = new QAction(this);
    nameAction->setIcon(QIcon(":/Images/clear.png"));
    ui->nameEdit->addAction(nameAction, QLineEdit::TrailingPosition);
    connect(nameAction, &QAction::triggered, this, [=](){
        ui->nameEdit->clear();
    });

    // 作者
    QAction *authorAction = new QAction(this);
    authorAction->setIcon(QIcon(":/Images/clear.png"));
    ui->authorEdit->addAction(authorAction, QLineEdit::TrailingPosition);
    connect(authorAction, &QAction::triggered, this, [=](){
        ui->authorEdit->clear();
    });

    // 出版社
    QAction *publishAction = new QAction(this);
    publishAction->setIcon(QIcon(":/Images/clear.png"));
    ui->publishEdit->addAction(publishAction, QLineEdit::TrailingPosition);
    connect(publishAction, &QAction::triggered, this, [=](){
        ui->publishEdit->clear();
    });

    // 库存
    QAction *inventoryAction = new QAction(this);
    inventoryAction->setIcon(QIcon(":/Images/clear.png"));
    ui->inventoryEdit->addAction(inventoryAction, QLineEdit::TrailingPosition);
    connect(inventoryAction, &QAction::triggered, this, [=](){
        ui->inventoryEdit->clear();
    });
}

// 初始化
void Manager::initialization()
{
    m_isHide = true;          // 标志位置于 true 表示关闭
    ui->addWidget->hide();    // 添加书籍窗口初始隐藏

    m_model = new SqlTableModel(this);
    m_model->setTable("stackRoom");
    m_model->setSort(STACK_INVENTORY, Qt::DescendingOrder);    // 库存数量降序

    // 设置列宽，Stretch：填充屏幕 ResizeToContents：根据内容长度设定 Fixed：固定
    ui->bookInfoView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->bookInfoView->setModel(m_model);
}

// 控件信号链接
void Manager::connectConfig()
{
    // QComboBox 的 currentIndexChanged 有两个重载，一个参数是 int，一个参数是 QString，所以需要用下面的语句强制类型转换，
    // 否则 connect 不知道触发哪个信号，用 QT4 的写法则无此问题
    connect(ui->queryTypeComboBox, static_cast<void(QComboBox::*)(int)>
            (&QComboBox::currentIndexChanged), this, [=](){
        ui->queryEdit->clear();
    });

    connect(ui->queryEdit, &QLineEdit::textChanged, this, &Manager::queryBook);
    connect(ui->addButton, &QPushButton::clicked, this, &Manager::changeWidgetState);
    connect(ui->confirmButton, &QPushButton::clicked, this, &Manager::addBook);
    connect(ui->deleteButton, &QPushButton::clicked, this, &Manager::deleteBook);
}

// 模糊查询
void Manager::queryBook(const QString &info)
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
    }

    m_model->setFilter(filter);
    m_model->select();
}

// 切换窗口状态
void Manager::changeWidgetState()
{
    if (m_isHide)
    {
        ui->addWidget->show();
    }
    else
    {
        ui->addWidget->hide();
    }

    m_isHide = !m_isHide;
}

// 添加书籍
void Manager::addBook()
{
    // 判断书籍信息是否完整
    bool isEmpty = ui->numEdit->text().isEmpty() || ui->nameEdit->text().isEmpty() ||
            ui->publishEdit->text().isEmpty() || ui->authorEdit->text().isEmpty() ||
            ui->inventoryEdit->text().isEmpty();

    if (isEmpty)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("请填写完整的信息!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 判断书籍信息是否含有非法字符
    bool isSpace = ui->numEdit->text().contains(" ") || ui->nameEdit->text().contains(" ") ||
            ui->publishEdit->text().contains(" ") || ui->authorEdit->text().contains(" ") ||
            ui->inventoryEdit->text().contains(" ");

    if (isSpace)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("含有非法字符!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 判断编号是否存在
    QString condition = QString::fromUtf8("编号 = %1").arg(ui->numEdit->text());

    if (m_model->checkSqlData(condition))
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("编号已存在!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    // 添加
    QString value = QString("%1, '%2', '%3', '%4', %5")
            .arg(ui->numEdit->text()).arg(ui->nameEdit->text())
            .arg(ui->publishEdit->text()).arg(ui->authorEdit->text())
            .arg(ui->inventoryEdit->text());

    m_model->insertSqlRow(value);
    QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("添加成功!"),
                             QString::fromUtf8("确定"));

    // 清空信息
    clearMessage();
}

// 清除信息
void Manager::clearMessage()
{
    ui->numEdit->clear();
    ui->nameEdit->clear();
    ui->publishEdit->clear();
    ui->authorEdit->clear();
    ui->inventoryEdit->clear();
}

// 删除书籍
void Manager::deleteBook()
{
    int selectRow = ui->bookInfoView->currentIndex().row();

    if (selectRow < 0)
    {
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("请选择需要删除的书籍!"),
                                 QString::fromUtf8("确定"));
        return;
    }

    int ret = QMessageBox::question(this, QString::fromUtf8("提示"), QString::fromUtf8("确认删除该书籍?"),
                                    QString::fromUtf8("确定"), QString::fromUtf8("取消"));

    if (ret == SELECT_OK)
    {
        // 获取编号
        QModelIndex index = m_model->index(selectRow, STACK_NUM);
        int bookNum = m_model->data(index).toInt();

        // 删除
        QString condition = QString::fromUtf8("编号 = %1").arg(bookNum);
        m_model->removeSqlRow(condition);
        QMessageBox::information(this, QString::fromUtf8("提示"), QString::fromUtf8("已删除!"),
                                 QString::fromUtf8("确定"));
    }
}

// 刷新
void Manager::refresh()
{
    m_model->select();

    ui->addWidget->hide();
    m_isHide = true;
    clearMessage();
    ui->queryTypeComboBox->setCurrentIndex(0);
}
