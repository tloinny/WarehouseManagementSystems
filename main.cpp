#include "mainwindow.h"
#include "SignInWindow.h"
#include <QApplication>
#include<QSqlDatabase>
#include "sql.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug()<<QSqlDatabase::drivers();
    SQL Mysql("QMYSQL","127.0.0.1",3306,"root","123456");
    SignInWindow MySignInWindow;
    if(MySignInWindow.Sign_In_Success_flag!=0)
    {
        MainWindow w;
        w.show();
    }
    return a.exec();
}
