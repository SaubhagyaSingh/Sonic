#include "login.h"
#include "qsqlquery.h"
#include "ui_login.h"
#include "mainwindow.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    if(!connopen())
        ui->status->setText("Failed to open the database");
    else
        ui->status->setText("Connected...");
}

login::~login()
{
    delete ui;
}


void login::on_loginbt_clicked()
{
    if (!connopen())
    {
        qDebug()<<"Failed to connect to the database";
        return;
    }
    else
    {
        qDebug()<<"Connected to the db";
    }

    QSqlQuery qry;
    QString username,password;
    username=ui->usernamebox->text();
    password=ui->passwordbox->text();
   //qDebug()<<qry.exec("select * from loginpage where username='"+username+"'and password='"+password+"'");

    if(qry.exec("select * from loginpage where username='"+username+"'and password='"+password+"'"))
    {
        int count=0;
        //qDebug()<<qry.next();
        while(qry.next()){
            count++;
        }
        if(count==1)
        {
            login::ui->status->setText("Username and password is correct");
            connclose();
            this->hide();
            me=new MainWindow(this);

            me->show();
        }
        /*if(count>1){
         login::ui->status->setText("Duplicate Username and password");
        }*/
        //if(count<1)
            else {
         login::ui->status->setText("Username and password is incorrect");
                 qDebug()<<count;  }
        }
    }

