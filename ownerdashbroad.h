#ifndef OWNERDASHBROAD_H
#define OWNERDASHBROAD_H

#include <QWidget>
#include <QStandardItemModel>
#include "sql.h"
#include <QMessageBox>

namespace Ui {
class OwnerDashBroad;
}

class OwnerDashBroad : public QWidget
{
    Q_OBJECT

public:
    QStandardItemModel* model;

    explicit OwnerDashBroad(QWidget *parent = nullptr);
    ~OwnerDashBroad();

    void SetAccountInfo(QString Name, int id);
    void ShowAllTheAdmin();

private:
    Ui::OwnerDashBroad *ui;

signals:
    void sendsignal();
public slots:
    void DelectAdmin();
    void ExitClicked();
};

#endif // OWNERDASHBROAD_H
