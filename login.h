#ifndef LOGIN_H
#define LOGIN_H

#include "qsqldatabase.h"
#include<QSqlDatabase>
#include<QtSql>
#include<QDebug>
#include<QMessageBox>
#include<QSqlQuery>
#include <QMainWindow>
#include <QDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"


namespace Ui {
class login;
}

class login : public QDialog
{   Q_OBJECT

public:

    QSqlDatabase db;
    void connclose(){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connopen(){
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/saubhagya singh/OneDrive/Documents/VScode/Sonic_Db/music.db");

        if(db.open())
        {
            qDebug()<<("Database connected successfully");
            return true;
        }
        else
        {
            qDebug()<<("Database is Not Connected");
            return false;
        }
    }
public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:


    void on_loginbt_clicked();

private:
    Ui::login *ui;
    MainWindow *me;

};

#endif // LOGIN_H
