#ifndef SQL_H
#define SQL_H
#include<QtSql>

class SQL
{
public:
    QSqlDatabase mysql;
    SQL(const QString db_type, const QString HostName, int port, const QString UserName, const QString UserPassWord);
    void CreateConnection(const QString name);
private:

};

#endif // SQL_H
