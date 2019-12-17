#include "signupwindow.h"
#include "ui_signupwindow.h"

SignUpWindow::SignUpWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
    if(ui->SignUpTypeComboBox->currentText() == "admin")
    {
        QSqlQuery query;
        QString sql = QString("select WarehouseName from warehouse_db.warehouse;");
        query.exec(sql);
        query.next();
        for(int i=0;i<query.size();++i)
        {
            ui->SignUpBelongComboBox->addItem(query.value(i).toString());
        }
    }else
    {
        ui->SignUpBelongComboBox->clear();
    }
    connect(ui->SignUpTypeComboBox,SIGNAL(currentTextChanged(const QString &)),this,SLOT(TypeChange(const QString &)));
    connect(ui->SignUpConfirm,SIGNAL(clicked()),this,SLOT(CheckSignUp()));
    connect(ui->SignUpCancel,SIGNAL(clicked()),this,SLOT(CancelSignUp()));
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::TypeChange(const QString & text)
{
    if(text == "admin")
    {
        QSqlQuery query;
        QString sql = QString("select WarehouseName from warehouse_db.warehouse;");
        query.exec(sql);
        query.next();
        for(int i=0;i<query.size();++i)
        {
            ui->SignUpBelongComboBox->addItem(query.value(i).toString());
        }
    }else
    {
        ui->SignUpBelongComboBox->clear();
    }
}

void SignUpWindow::CheckSignUp()
{
    QString Name = ui->SignUpNameLine->text();
    QString Password = ui->SignUpPasswordLine->text();
    QString Warehouse = ui->SignUpBelongComboBox->currentText();
    int WarehouseID = 0;
    int account = 0;
    if(Name != "" && Password != "")
    {
        QSqlQuery query;
        QString sql;
        if(ui->SignUpTypeComboBox->currentText() == "admin")
        {
            sql = QString("select WarehouseID from warehouse_db.warehouse where WarehouseName = '%1';").arg(Warehouse);
            query.exec(sql);
            qDebug()<<query.lastError();
            query.next();
            if(query.size()>0)
            {
                WarehouseID = query.value(0).toString().toInt();
                int i;
                for(i=0;i<100;++i)
                {
                    account = QRandomGenerator::global()->bounded(100000000,999999999);
                    sql = QString("SELECT * FROM warehouse_db.admin where AdminAccount = '%1';").arg(QString::number(account,10));
                    query.exec(sql);
                    if(query.size()==0) break;
                }
                if(i>=99)
                {
                    QMessageBox::critical(nullptr,QObject::tr("Fail to sign in..."), "There is something wrong with the Database. Please try angin later.");
                }else
                {
                    sql = QString("select MAX(AdminID) from warehouse_db.admin;");
                    query.exec(sql);
                    query.next();
                    int max_id = query.value(0).toString().toInt(nullptr,10);
                    qDebug()<<max_id;
                    sql = QString("insert into warehouse_db.admin (`AdminID`, `AdminWarehouse`, `AdminName`, `AdminAccount`, `AdminPassWord`) VALUES ('%1', '%2', '%3', '%4', '%5');").arg(QString::number((++max_id),10),QString::number(WarehouseID,10),Name,QString::number(account,10),Password);
                    query.exec(sql);
                    qDebug()<<query.lastError();
                    QMessageBox::information(nullptr,QObject::tr("information"), QString("hello new administrator, please note down your account: %1 !").arg(QString::number(account,10)));
                    ui->SignUpNameLine->clear();
                    ui->SignUpPasswordLine->clear();
                    this->hide();
                    emit sendsignal();
                }
            }else
            {
                QMessageBox::critical(nullptr,QObject::tr("Fail to sign in..."), "There are no such warehouse in the list.");
            }
        }else if(ui->SignUpTypeComboBox->currentText() == "owner")
        {
            int i;
            for(i=0;i<100;++i)
            {
                account = QRandomGenerator::global()->bounded(100000000,999999999);
                sql = QString("SELECT * FROM warehouse_db.owner where OwnerAccount = '%1';").arg(QString::number(account,10));
                query.exec(sql);
                if(query.size()==0) break;
            }
            if(i>=99)
            {
                QMessageBox::critical(nullptr,QObject::tr("Fail to sign in..."), "There is something wrong with the Database. Please try angin later.");
            }else
            {
                sql = QString("select MAX(OwnerID) from warehouse_db.owner;");
                query.exec(sql);
                query.next();
                int max_id = query.value(0).toString().toInt(nullptr,10);
                qDebug()<<max_id;
                sql = QString("insert into warehouse_db.owner (`OwnerID`, `OwnerName`, `OwnerAccount`, `OwnerPassword`) VALUES ('%1', '%2', '%3', '%4');").arg(QString::number((++max_id),10),Name,QString::number(account,10),Password);
                query.exec(sql);
                qDebug()<<query.lastError();
                QMessageBox::information(nullptr,QObject::tr("information"), QString("hello new owner, please note down your account: %1 !").arg(QString::number(account,10)));
                ui->SignUpNameLine->clear();
                ui->SignUpPasswordLine->clear();
                this->hide();
                emit sendsignal();
            }
        }
    }else
    {
        QMessageBox::critical(nullptr,QObject::tr("Fail to sign in..."), "account or password can't be empty");
    }
}

void SignUpWindow::CancelSignUp()
{
    this->hide();
    emit sendsignal();
}
