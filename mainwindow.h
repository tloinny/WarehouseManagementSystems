#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "sql.h"
#include <QStandardItemModel>
#include <QDateTime>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, SQL *sqlptr = nullptr);
    ~MainWindow();

    void SetAccountInfo(int id, int w_id, QString name);

private:
    Ui::MainWindow *ui;
    SQL *mysql;

signals:
    void sendsignal();
public slots:
    void show_all_the_detail();
    void search();
    void entry_stock();
    void removal_stock();
    void change_password();
    void exit();
};
#endif // MAINWINDOW_H
