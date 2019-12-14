#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, SQL *sqlptr)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    mysql = sqlptr;
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    connect(ui->ShowAll,SIGNAL(clicked()),this,SLOT(show_all_the_detail()));
    connect(ui->Search_action,SIGNAL(clicked()),this,SLOT(search()));
    connect(ui->EN_confrim,SIGNAL(clicked()),this,SLOT(entry_stock()));
    connect(ui->EX_confrim,SIGNAL(clicked()),this,SLOT(removal_stock()));
    connect(ui->actionchange_password,SIGNAL(clicked()),this,SLOT(change_password()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetAccountInfo(int id, int w_id, QString name)
{
    ui->UserIDLine->setText(QString::number(id,10));
    ui->UserWarehouseIDLine->setText(QString::number(w_id,10));
    ui->UserNameLine->setText(name);
    ui->UserIDLine->setReadOnly(true);
    ui->UserWarehouseIDLine->setReadOnly(true);
    ui->UserNameLine->setReadOnly(true);
}

void MainWindow::show_all_the_detail()
{
    QStandardItemModel* model_temp = new QStandardItemModel(this);
    model_temp->setColumnCount(2);
    model_temp->setHeaderData(0, Qt::Horizontal, "SKU");
    model_temp->setHeaderData(1, Qt::Horizontal, "Stock");
    QSqlQuery query;
    query.exec("SELECT * FROM warehouse_db.warehouse_detail_"+ui->UserWarehouseIDLine->text()+";");
    for(int i=0; query.next();++i)
    {
        model_temp->setItem(i, 0, new QStandardItem(query.value(0).toString()));
        model_temp->setItem(i, 1, new QStandardItem(query.value(1).toString()));
        ui->SQLTable->setModel(model_temp);
    }
}

void MainWindow::search()
{
    QString Key = ui->Search_Key->text();
    QStandardItemModel* model_temp = new QStandardItemModel(this);
    model_temp->setColumnCount(2);
    model_temp->setHeaderData(0, Qt::Horizontal, "SKU");
    model_temp->setHeaderData(1, Qt::Horizontal, "Stock");
    QSqlQuery query;
    if(ui->SearchBy_comboBox->currentText() == "SKU")
    {
        query.exec("SELECT * FROM warehouse_db.warehouse_detail_"+ui->UserWarehouseIDLine->text()+" where detailsku = \'"+Key+"\';");
        if(query.size()<0) QMessageBox::critical(nullptr,QObject::tr("error..."), "No result");
        for(int i=0; query.next();++i)
        {
            model_temp->setItem(i, 0, new QStandardItem(query.value(0).toString()));
            model_temp->setItem(i, 1, new QStandardItem(query.value(1).toString()));
            ui->SQLTable->setModel(model_temp);
        }
    }else if (ui->SearchBy_comboBox->currentText() == "Name")
    {
        query.exec("SELECT MapSKU FROM warehouse_db.sku_map_"+ui->UserWarehouseIDLine->text()+" where MapCargoName like \'%"+Key+"%\'"+";");
        if(query.size()>0)
        {
            for(int i=0; query.next();++i)
            {
                QSqlQuery sub_query;
                sub_query.exec("SELECT * FROM warehouse_db.warehouse_detail_"+ui->UserWarehouseIDLine->text()+" where detailsku = \'"+query.value(0).toString()+"\'"+";");
                sub_query.next();
                model_temp->setItem(i, 0, new QStandardItem(sub_query.value(0).toString()));
                model_temp->setItem(i, 1, new QStandardItem(sub_query.value(1).toString()));
                ui->SQLTable->setModel(model_temp);
            }
        }else
        {
            QMessageBox::critical(nullptr,QObject::tr("error..."), "No result");
        }
    }
}

void MainWindow::entry_stock()
{
    if(ui->EN_SKU->text()!="")
    {
        if(ui->EN_Num->text().toInt(nullptr,10) > 0)
        {
            QDateTime current_date_time = QDateTime::currentDateTime();
            QString timestamp = current_date_time.toString("yyyyMMddhhmmss");
            QSqlQuery query;
            QString sql = QString("select MapCargoName from warehouse_db.sku_map_%1 where MapSKU = %2").arg(ui->UserWarehouseIDLine->text(),ui->EN_SKU->text());
            query.exec(sql);
            if(query.size()>0)
            {
                sql = QString("INSERT INTO warehouse_db.entry_log_%1 (`EntryLogTimeStamp`, `EntryLogSKU`,`EntryLogNum`,`EntryLogComment`) VALUES ('%2', '%3','%4','%5');").arg(ui->UserWarehouseIDLine->text(),timestamp,ui->EN_SKU->text(),ui->EN_Num->text(),ui->EN_comment->text());
                query.exec(sql);
                sql = QString("update warehouse_db.warehouse_detail_%1 set DetailStocks = DetailStocks+%2 where DetailSKU = %3;").arg(ui->UserWarehouseIDLine->text(),ui->EN_Num->text(),ui->EN_SKU->text());
                query.exec(sql);
                QMessageBox::information(nullptr,QObject::tr("information"), "entry success!");
            }else
            {
                QMessageBox::critical(nullptr,QObject::tr("error..."), "The SKU you try to entry is not include by the map!");
            }
        }else
        {
            QMessageBox::critical(nullptr,QObject::tr("error..."), "The Number should be bigger than zero!");
        }
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("error..."), "Can't entry a empty SKU!");
    }
}

void MainWindow::removal_stock()
{
    if(ui->EX_SKU->text()!="")
    {
        if(ui->EX_Num->text().toInt(nullptr,10) > 0)
        {
            QDateTime current_date_time = QDateTime::currentDateTime();
            QString timestamp = current_date_time.toString("yyyyMMddhhmmss");
            QSqlQuery query;
            QString sql = QString("select MapCargoName from warehouse_db.sku_map_%1 where MapSKU = %2").arg(ui->UserWarehouseIDLine->text(),ui->EX_SKU->text());
            query.exec(sql);
            if(query.size()>0)
            {
                sql = QString("select DetailStocks from warehouse_db.warehouse_detail_%1 where DetailSKU = %2;").arg(ui->UserWarehouseIDLine->text(),ui->EX_SKU->text());
                query.exec(sql);
                query.next();
                if(query.value(0).toInt() - (ui->EX_Num->text().toInt(nullptr,10)) >= 0)
                {
                    sql = QString("INSERT INTO warehouse_db.removal_log_%1 (`RemovalLogTimeStamp`, `RemovalLogSKU`,`RemovalLogNum`,`RemovalLogComment`) VALUES ('%2', '%3','%4','%5');").arg(ui->UserWarehouseIDLine->text(),timestamp,ui->EX_SKU->text(),ui->EX_Num->text(),ui->EX_comment->text());
                    query.exec(sql);
                    sql = QString("update warehouse_db.warehouse_detail_%1 set DetailStocks = DetailStocks-%2 where DetailSKU = %3;").arg(ui->UserWarehouseIDLine->text(),ui->EX_Num->text(),ui->EX_SKU->text());
                    query.exec(sql);
                    QMessageBox::information(nullptr,QObject::tr("information"), "remove success!");
                }else
                {
                    QMessageBox::critical(nullptr,QObject::tr("error..."), QString("The stock of the specific SKU is lass than %1!").arg(ui->EX_Num->text()));
                }
            }else
            {
                QMessageBox::critical(nullptr,QObject::tr("error..."), "The SKU you try to remove is not include by the map!");
            }
        }else
        {
            QMessageBox::critical(nullptr,QObject::tr("error..."), "The Number should be bigger than zero!");
        }
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("error..."), "Can't remove a empty SKU!");
    }
}

void MainWindow::change_password()
{

}
