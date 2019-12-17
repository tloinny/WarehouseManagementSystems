#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QWidget>
#include "sql.h"
#include <QMessageBox>
#include<QTime>
#include <QtGlobal>

namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpWindow(QWidget *parent = nullptr);
    ~SignUpWindow();

private:
    Ui::SignUpWindow *ui;

signals:
    void sendsignal();
public slots:
    void TypeChange(const QString & text);
    void CheckSignUp();
    void CancelSignUp();
};

#endif // SIGNUPWINDOW_H
