#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sql.h"

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
};
#endif // MAINWINDOW_H
