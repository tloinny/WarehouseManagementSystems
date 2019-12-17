/********************************************************************************
** Form generated from reading UI file 'SignInWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SIGNINWINDOW_H
#define SIGNINWINDOW_H

#include <QObject>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QMessageBox>
#include "mainwindow.h"
#include "sql.h"
#include "administrator.h"
#include "owner.h"
#include "signupwindow.h"
#include "ownerdashbroad.h"

QT_BEGIN_NAMESPACE

class SignInWindow : public QWidget
{
    Q_OBJECT
public:
    QWidget *parent;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label;

    SQL *mysql;

    administrator *admin;
    Owner *owner;
    MainWindow * w;
    SignUpWindow * SignUp_w;
    OwnerDashBroad * O_DB;

    SignInWindow(SQL * sqlptr = nullptr, MainWindow * W = nullptr, SignUpWindow * su_w = nullptr, OwnerDashBroad * q_db = nullptr)
    {
        mysql = sqlptr;
        w = W;
        SignUp_w = su_w;
        O_DB = q_db;
        parent = new QWidget;
        setupUi(parent);
        connect(pushButton, SIGNAL(clicked()), this, SLOT(CheckSignIn()));
        connect(pushButton_2, SIGNAL(clicked()), this, SLOT(SignUpClicked()));
        connect(w,SIGNAL(sendsignal()),this,SLOT(reshow()));
        connect(SignUp_w,SIGNAL(sendsignal()),this,SLOT(reshow()));
        connect(O_DB,SIGNAL(sendsignal()),this,SLOT(reshow()));
        parent->setWindowFlags(parent->windowFlags() &~ (Qt::WindowMinMaxButtonsHint));
        parent->setFixedSize(parent->width(),parent->height());
        parent->show();
    }

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->setWindowModality(Qt::WindowModal);
        Form->resize(400, 300);
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        Form->setFont(font);
        verticalLayoutWidget = new QWidget(Form);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(80, 63, 241, 162));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4, 0, Qt::AlignHCenter);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_2, 2, 1, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 4, 1, 1, 1);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 1, 1, 1);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "", nullptr));
        label_4->setText(QApplication::translate("Form", "Warehouse Management System", nullptr));
        label_2->setText(QApplication::translate("Form", "Password", nullptr));
        pushButton_2->setText(QApplication::translate("Form", "Sign up", nullptr));
        pushButton->setText(QApplication::translate("Form", "Log In", nullptr));
        comboBox->setItemText(1, QApplication::translate("Form", "Owner", nullptr));
        comboBox->setItemText(0, QApplication::translate("Form", "Admin", nullptr));

        label_3->setText(QApplication::translate("Form", "Type", nullptr));
        label->setText(QApplication::translate("Form", "Account", nullptr));
    } // retranslateUi

signals:
public slots:
    void CheckSignIn()
    {
        QString Type = comboBox->currentText();
        QString Account = lineEdit->text();
        QString Password = lineEdit_2->text();
        if(Account != "" && Password != "")
        {
            QSqlQuery query;
            QString sql;
            if(comboBox->currentText() == "Admin")
            {
                sql = "select adminpassword from warehouse_db.admin where adminaccount = \'"+Account+"\';";
                qDebug()<<sql;
                query.exec(sql);
                qDebug()<<query.lastError();
                query.next();
                if(query.value(0).toString()==Password)
                {
                    qDebug()<<"admin log in success";
                    sql = "select adminid, adminwarehouse, adminname from warehouse_db.admin where adminaccount = \'"+Account+"\';";
                    query.exec(sql);
                    query.next();
                    qDebug()<<query.value(0).toString()<<query.value(1).toString()<<query.value(2).toString();
                    admin = new administrator((query.value(0).toString()).toInt(nullptr,10),(query.value(1).toString()).toInt(nullptr,10),query.value(2).toString());
                    //Sign_In_Success_flag = 1;
                    w->SetAccountInfo(admin->adminID,admin->adminWarehouseID,admin->adminName);
                    w->show();
                    parent->hide();
                }else
                {
                    QMessageBox::critical(nullptr,QObject::tr("Fail to log in..."), "account or password doesn't right");
                    lineEdit->clear();
                    lineEdit_2->clear();
                }
            }else if(comboBox->currentText() == "Owner")
            {
                sql = "select ownerpassword from warehouse_db.owner where owneraccount = \'"+Account+"\';";
                qDebug()<<sql;
                query.exec(sql);
                qDebug()<<query.lastError();
                query.next();
                if(query.value(0).toString()==Password)
                {
                    qDebug()<<"owner log in success";
                    sql = "select ownerid, ownername from warehouse_db.owner where owneraccount = \'"+Account+"\';";
                    query.exec(sql);
                    query.next();
                    qDebug()<<query.value(0).toString()<<query.value(1).toString();
                    owner = new Owner((query.value(0).toString()).toInt(nullptr,10),query.value(1).toString());
                    O_DB->SetAccountInfo(owner->ownerName,owner->ownerID);
                    O_DB->ShowAllTheAdmin();
                    O_DB->show();
                    parent->hide();
                }else
                {
                    QMessageBox::critical(nullptr,QObject::tr("Fail to log in..."), "account or password doesn't right");
                    lineEdit->clear();
                    lineEdit_2->clear();
                }
            }
        }else
        {
            QMessageBox::critical(nullptr,QObject::tr("Fail to log in..."), "account or password can't be empty");
        }
    }
    void SignUpClicked()
    {
        SignUp_w->show();
        parent->hide();
    }

    void reshow()
    {
        lineEdit->clear();
        lineEdit_2->clear();
        parent->show();
    }
};

namespace Ui {
    class Form: public SignInWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SIGNINWINDOW_H
