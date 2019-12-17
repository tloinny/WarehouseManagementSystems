#include "mainwindow.h"
#include "SignInWindow.h"
#include <QApplication>
#include<QSqlDatabase>
#include "sql.h"
#include "signupwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    static SQL Mysql("QMYSQL","127.0.0.1",3306,"root","123456");

    MainWindow w(nullptr,&Mysql);
    SignUpWindow su_w(nullptr);
    SignInWindow MySignInWindow(&Mysql, &w, &su_w);

    return a.exec();
}
