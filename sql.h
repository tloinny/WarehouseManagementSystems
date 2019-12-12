#ifndef SQL_H
#define SQL_H
#include<QtSql>
class SQL
{
public:
    SQL(const QString db_type, const QString HostName, int port, const QString UserName, const QString UserPassWord);
    void CreateConnection(const QString name);
private:
    QSqlDatabase mysql;

};

#endif // SQL_H
