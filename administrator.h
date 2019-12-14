#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <QString>

class administrator
{
public:
    int adminID;
    int adminWarehouseID;
    QString adminName;

    administrator(int id, int w_id, QString name);
};

#endif // ADMINISTRATOR_H
