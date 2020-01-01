#include "ownerdashbroad.h"
#include "ui_ownerdashbroad.h"

OwnerDashBroad::OwnerDashBroad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OwnerDashBroad)
{
    update_flag = 0;
    model = new QStandardItemModel(this);
    model->setColumnCount(4);
    model->setHeaderData(0, Qt::Horizontal, "AdminID");
    model->setHeaderData(1, Qt::Horizontal, "AdminWarehouse");
    model->setHeaderData(2, Qt::Horizontal, "AdminName");
    model->setHeaderData(3, Qt::Horizontal, "AdminAccount");
    ui->setupUi(this);
    ui->UserNameLineEdit->setReadOnly(true);
    ui->UserIDLineEdit->setReadOnly(true);
    ui->AdminTable->setModel(model);
    connect(ui->DeleteButton,SIGNAL(clicked()),this,SLOT(DelectAdmin()));
    connect(ui->ExitButton,SIGNAL(clicked()),this,SLOT(ExitClicked()));
}

OwnerDashBroad::~OwnerDashBroad()
{
    delete ui;
}

void OwnerDashBroad::SetAccountInfo(QString Name, int id)
{
    ui->UserNameLineEdit->setText(Name);
    ui->UserIDLineEdit->setText(QString::number(id,10));
}

void OwnerDashBroad::ShowAllTheAdmin()
{
    disconnect(ui->AdminTable->model(),SIGNAL(itemChanged(QStandardItem *)),this,SLOT(ChangeItem(QStandardItem *)));
    QSqlQuery query;
    query.exec("SELECT * FROM warehouse_db.admin;");
    for(int i=0; query.next();++i)
    {
        for(int n = 0;n<4;++n)
            model->setItem(i, n, new QStandardItem(query.value(n).toString()));
    }
    connect(ui->AdminTable->model(),SIGNAL(itemChanged(QStandardItem *)),this,SLOT(ChangeItem(QStandardItem *)));
}

void OwnerDashBroad::DelectAdmin()
{
    QString id_selected = model->data(model->index(ui->AdminTable->currentIndex().row(),0)).toString();
    qDebug()<<id_selected;
    QSqlQuery query;
    QString sql;
    sql = QString("select * from warehouse_db.admin where AdminID = %1;").arg(id_selected);
    query.exec(sql);
    query.next();
    int result = QMessageBox::warning(nullptr, "warning", QString("Are you really sure you want to delete %1 from Database?").arg(query.value(2).toString()), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(result == QMessageBox::Yes)
    {
        sql = QString("delete from warehouse_db.admin where AdminID = %1;").arg(id_selected);
        query.exec(sql);
    }
    ShowAllTheAdmin();
}

void OwnerDashBroad::ExitClicked()
{
    emit sendsignal();
    this->hide();
}

void OwnerDashBroad::ChangeItem(QStandardItem* item)
{
    if(item->column() == 1)
    {
        QString new_warehouse_id = item->text();
        qDebug()<<new_warehouse_id;
        QString id_selected = model->data(model->index(item->row(),0)).toString();
        QSqlQuery query;
        QString sql;
        sql = QString("select * from warehouse_db.admin where AdminID = %1;").arg(id_selected);
        query.exec(sql);
        query.next();
        int result = QMessageBox::warning(nullptr, "warning", QString("Are you really sure you want to change warehouse of %1?").arg(query.value(2).toString()), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if(result == QMessageBox::Yes)
        {
            sql = QString("update warehouse_db.admin set AdminWarehouse = %1  where AdminID = %2;").arg(new_warehouse_id,id_selected);
            query.exec(sql);
        }
    }else
    {
        ShowAllTheAdmin();
    }
}
