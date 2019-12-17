#ifndef OWNERDASHBROAD_H
#define OWNERDASHBROAD_H

#include <QWidget>

namespace Ui {
class OwnerDashBroad;
}

class OwnerDashBroad : public QWidget
{
    Q_OBJECT

public:
    explicit OwnerDashBroad(QWidget *parent = nullptr);
    ~OwnerDashBroad();

private:
    Ui::OwnerDashBroad *ui;
};

#endif // OWNERDASHBROAD_H
