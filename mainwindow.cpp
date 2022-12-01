#include "mainwindow.h"
#include "qmessagebox.h"
#include "qpushbutton.h"
#include "QSqlquery.h"
#include "qsqlquerymodel.h"
#include "ui_mainwindow.h"
#include <QPixmap>//helps to add image





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //logo
    QPixmap pix("C:/Users/saubhagya singh/OneDrive/Documents/VScode/Sonic_Db/images/logo1.png"); // the object pix stores the path for the file
    ui->label_logo->setPixmap(pix.scaled(50,50,Qt::KeepAspectRatio));//the ui pointer accesses the label which calls the setpixmap func with pix as an argument.
    ui->like->setIcon(QIcon("C:/Users/saubhagya singh/OneDrive/Documents/VScode/Sonic_Db/images/like.png"));
    ui->like->setCheckable(true);
    ui->next->setIcon(QIcon("C:/Users/saubhagya singh/OneDrive/Documents/VScode/Sonic_Db/images/next.png"));
    ui->previous->setIcon(QIcon("C:/Users/saubhagya singh/OneDrive/Documents/VScode/Sonic_Db/images/back.png"));
    ui->play->setIcon(QIcon("C:/Users/saubhagya singh/OneDrive/Documents/VScode/Sonic_Db/images/play.png"));
    ui->play->setCheckable(true);
    ui->volume->setIcon(QIcon("C:/Users/saubhagya singh/OneDrive/Documents/VScode/Sonic_Db/images/volume.png"));
    QPixmap q2("C:/Users/saubhagya singh/OneDrive/Documents/VScode/Sonic_Db/images/music.png"); // the object pix stores the path for the file
    ui->music_label->setPixmap(q2.scaled(50,50,Qt::KeepAspectRatio));//the ui pointer accesses the label which calls the setpixmap func with pix as an argument.
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_play_toggled(bool checked)
{
    if(checked){
        ui->play->setIcon(QIcon("C:/Users/saubhagya singh/OneDrive/Documents/VScode/Sonic_Db/images/pause.png"));
    }
    else{
        ui->play->setIcon(QIcon("C:/Users/saubhagya singh/OneDrive/Documents/VScode/Sonic_Db/images/play.png"));
    }
}

void MainWindow::on_like_toggled(bool checked)
{
    if(checked){
        ui->like->setIcon(QIcon("C:/Users/saubhagya singh/OneDrive/Documents/VScode/Sonic_Db/images/liked.png"));
    }
    else{
        ui->like->setIcon(QIcon("C:/Users/saubhagya singh/OneDrive/Documents/VScode/Sonic_Db/images/like.png"));

    }
}

void MainWindow::on_load_clicked()
{
connopen();
QSqlQueryModel *modal =new QSqlQueryModel();
QSqlQuery *qry =new QSqlQuery(db);
qry->exec("select *from songs");
modal->setQuery(*qry);
ui->tableView->setModel(modal);
connclose();
}
/*
QSqlQuery qry=new QSqlQuery("");
qry.exec("Select * from songs");
*/

void MainWindow::on_play_clicked()
{

}
void MainWindow::on_refresh_clicked()
{
    connopen();
    QSqlQueryModel *modal2 =new QSqlQueryModel();
    QSqlQuery *qry2 =new QSqlQuery(db);
    qry2->exec("select *from requested_songs");
    modal2->setQuery(*qry2);
    ui->request_table->setModel(modal2);
    connclose();
}


void MainWindow::on_requestbutton_clicked()
{
    connopen();
    QString requested;
    QMessageBox msgbox;
    requested=ui->requested->text();
    QSqlQuery qry;
    if(qry.exec("insert into requested_songs (request) values ('"+requested+"')"))
        {
        QMessageBox::critical(this,tr("Sucess"),tr("Song saved"));

        }
    else{
           QMessageBox::critical(this,tr("error::"),tr("Something unusual occured"));
        }
    connclose();
}

