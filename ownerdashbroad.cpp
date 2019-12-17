#include "ownerdashbroad.h"
#include "ui_ownerdashbroad.h"

OwnerDashBroad::OwnerDashBroad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OwnerDashBroad)
{
    ui->setupUi(this);
}

OwnerDashBroad::~OwnerDashBroad()
{
    delete ui;
}
