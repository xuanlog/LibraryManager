#include "manager.h"
#include "ui_manager.h"
#include "librarydefine.h"

Manager::Manager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Manager)
{
    ui->setupUi(this);

    connectConfig();
}

Manager::~Manager()
{
    delete ui;
}

// 初始化
void Manager::initialization()
{
    m_isHide = true;
    ui->addWidget->hide();    // 添加窗口初始隐藏

    m_model = new SqlTableModel(this);
    m_model->setTable("stackRoom");
    m_model->setSort(0, Qt::AscendingOrder);
    m_model->select();

    // 更新方式，OnRowChange：切换选中行时更新 OnFieldChange：切换选中区更新 OnManualSubmit：手动更新
    m_model->setEditStrategy(SqlTableModel::OnManualSubmit);

    // 设置列宽，Stretch：填充屏幕 ResizeToContents：根据内容长度设定 Fixed：固定
    ui->bookInfoView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->bookInfoView->setModel(m_model);
}

// 信号与槽的设置
void Manager::connectConfig()
{
    /*
     * QComboBox 的 currentIndexChanged 有两个重载，一个参数是 int，一个参数是 QString，所以需要用下面的语句强制类型转换，否则
     * connect 不知道触发哪个信号，用 QT4 的写法则无此问题
     */
    connect(ui->queryTypeComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &Manager::changeType);
    connect(ui->queryEdit, &QLineEdit::textChanged, this, &Manager::queryBook);
    connect(ui->addButton, &QPushButton::clicked, this, &Manager::changeWidgetState);
    connect(ui->confirmButton, &QPushButton::clicked, this, &Manager::addBook);
    connect(ui->deleteButton, &QPushButton::clicked, this, &Manager::deleteBook);
}

// 查询
void Manager::queryBook(const QString &info)
{
    int queryType = ui->queryTypeComboBox->currentIndex();
    QString filter = "";

    // LIKE '%%1%' 模糊搜索 %1：arg 里面的参数 前后两个 % 表示参数前或后可能有其他字符
    switch (queryType)
    {
    case HEADER_NUM:
        filter = QString::fromUtf8("编号 LIKE '%%1%'").arg(info);
        break;
    case HEADER_NAME:
        filter = QString::fromUtf8("书名 LIKE '%%1%'").arg(info);
        break;
    case HEADER_PUBLISH:
        filter = QString::fromUtf8("出版社 LIKE '%%1%'").arg(info);
        break;
    case HEADER_AUTHOR:
        filter = QString::fromUtf8("作者 LIKE '%%1%'").arg(info);
        break;
    case HEADER_INVENTORY:
        filter = QString::fromUtf8("库存 LIKE '%%1%'").arg(info);
        break;
    }

    m_model->setFilter(filter);
    m_model->select();
}

// 切换查询类型
void Manager::changeType()
{
    ui->queryEdit->clear();
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
    bool isEmpty = ui->numEdit->text().isEmpty() || ui->nameEdit->text().isEmpty() ||
            ui->publishEdit->text().isEmpty() || ui->authorEdit->text().isEmpty() ||
            ui->inventoryEdit->text().isEmpty();

    if (isEmpty)
    {
        QMessageBox::about(this, QString::fromUtf8("提示"), QString::fromUtf8("请填写完整的信息!"));
        return;
    }

    QString values = QString("%1, '%2', '%3', '%4', %5")
            .arg(ui->numEdit->text()).arg(ui->nameEdit->text())
            .arg(ui->publishEdit->text()).arg(ui->authorEdit->text())
            .arg(ui->inventoryEdit->text());

    m_model->insertData(values);
}

// 删除书籍
void Manager::deleteBook()
{
    int selectRow = ui->bookInfoView->currentIndex().row();

    if (selectRow < 0)
    {
        QMessageBox::about(this, QString::fromUtf8("提示"), QString::fromUtf8("请选择需要删除的书籍!"));
        return;
    }

    m_model->removeRow(selectRow);

    int ret = QMessageBox::question(this, QString::fromUtf8("提示"), QString::fromUtf8("确认删除该书籍?"),
                                    QString::fromUtf8("确定"), QString::fromUtf8("取消"));

    switch (ret)
    {
    case 0:
        m_model->submitAll();
        break;
    case 1:
        m_model->revertAll();
        break;
    default:
        break;
    }
}
