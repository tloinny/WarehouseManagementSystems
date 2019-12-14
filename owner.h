#ifndef OWNER_H
#define OWNER_H
#include <QString>

class Owner
{
public:
    int ownerID;
    QString ownerName;

    Owner(int id, QString name);
};

#endif // OWNER_H
