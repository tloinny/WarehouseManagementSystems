#include "ownerdashbroad.h"
#include "ui_ownerdashbroad.h"

OwnerDashBroad::OwnerDashBroad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OwnerDashBroad)
{
    model = new QStandardItemModel(this);
    ui->setupUi(this);
    ui->UserNameLineEdit->setReadOnly(true);
    ui->UserIDLineEdit->setReadOnly(true);
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
    model->setColumnCount(4);
    model->setHeaderData(0, Qt::Horizontal, "AdminID");
    model->setHeaderData(1, Qt::Horizontal, "AdminWarehouse");
    model->setHeaderData(2, Qt::Horizontal, "AdminName");
    model->setHeaderData(3, Qt::Horizontal, "AdminAccount");
    QSqlQuery query;
    query.exec("SELECT * FROM warehouse_db.admin;");
    for(int i=0; query.next();++i)
    {
        for(int n = 0;n<4;++n)
            model->setItem(i, n, new QStandardItem(query.value(n).toString()));
        ui->AdminTable->setModel(model);
    }
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
}

void OwnerDashBroad::ExitClicked()
{
    emit sendsignal();
    this->hide();
}
