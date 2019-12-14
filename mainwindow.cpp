#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, SQL *sqlptr)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    mysql = sqlptr;
    ui->setupUi(this);
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
