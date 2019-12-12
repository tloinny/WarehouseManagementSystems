#include "sql.h"
#include <QMessageBox>

SQL::SQL(const QString db_type, const QString HostName, int port, const QString UserName, const QString UserPassWord)
{
    mysql = QSqlDatabase::addDatabase(db_type);
    mysql.setHostName(HostName);
    mysql.setPort(port);
    mysql.setUserName(UserName);
    mysql.setPassword(UserPassWord);

    bool ok = mysql.open(); /* try to open the DB */
    if(!ok)
    {
        QMessageBox::critical(nullptr,QObject::tr("Fail to connect the database..."), mysql.lastError().text());
        qDebug()<<mysql.lastError().text();
    }
    else
    {
//        QMessageBox::information(nullptr,QObject::tr("Tips"),QObject::tr("Successful to connect the database!"));
    }
}
