#include "mainwindow.h"
#include "SignInWindow.h"
#include <QApplication>
#include<QSqlDatabase>
#include "sql.h"
#include "signupwindow.h"
#include "ownerdashbroad.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    static SQL Mysql("QMYSQL","127.0.0.1",3306,"root","123456");

    MainWindow w(nullptr,&Mysql);
    SignUpWindow su_w(nullptr);
    OwnerDashBroad O_DB(nullptr);
    SignInWindow MySignInWindow(&Mysql, &w, &su_w, &O_DB);

    return a.exec();
}
