#include "mainwindow.h"
#include "SignInWindow.h"
#include <QApplication>
#include<QSqlDatabase>
#include "sql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    static SQL Mysql("QMYSQL","127.0.0.1",3306,"root","123456");

    MainWindow w(nullptr,&Mysql);
    SignInWindow MySignInWindow(&Mysql, &w);
    return a.exec();
}
