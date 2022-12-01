#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "qaudiooutput.h"
#include "qmediaplayer.h"
#include "qprogressbar.h"
#include "qsqldatabase.h"
#include "ui_login.h"
#include<QSqlDatabase>
#include<QtSql>
#include<QDebug>
#include<QMessageBox>
#include<QSqlQuery>
#include <QMainWindow>
#include<QMediaPlayer>
#include<QVideoWidget>
#include<QFileDialog>
#include<QSlider>
#include<QProgressBar>
#include<QAudioOutput>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QSqlDatabase db;
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
    void connclose(){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_play_toggled(bool checked);

    void on_like_toggled(bool checked);

    void on_load_clicked();

    void on_play_clicked();

    void on_refresh_clicked();

    void on_requestbutton_clicked();


private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QVideoWidget* vw;
    QProgressBar* bar;
    QSlider* slider;
    QAudioOutput* audioOutput;

};
#endif // MAINWINDOW_H
