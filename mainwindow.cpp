#include "mainwindow.h"
#include "QDebug"
#include "QScreen"
#include "QGuiApplication"
#include "QRect"



#define MAINWINDOW_WIDTH  480
#define MAINWINDOW_HEIGHT 320

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QList<QScreen *> list_screen =  QGuiApplication::screens();  /*多显示器*/
    QRect rect = list_screen.at(0)->geometry();
    this->setGeometry((rect.width() - MAINWINDOW_WIDTH)/2,
                      (rect.height() - MAINWINDOW_HEIGHT)/2,
                      MAINWINDOW_WIDTH,MAINWINDOW_HEIGHT);

    pushButton1 = new QPushButton("pushButton1",this);
    pushButton2 = new QPushButton("pushButton2",this);

    pushButton1->setGeometry(this->width()/2,this->height()/2,100,100);
    pushButton2->setGeometry(this->width()/4,this->height()/4,100,100);

    connect(pushButton1,SIGNAL(clicked()),this,SLOT(pushButton1_clicked()));
    connect(pushButton2,SIGNAL(clicked()),this,SLOT(pushButton2_clicked()));
}

MainWindow::~MainWindow()
{
    qDebug()<<"析构函数";
}

void MainWindow::pushButton1_clicked()
{
    qDebug()<<"btn1";
    this->setStyleSheet("QMainWindow { background-color: rgba(0, 255,255, 100%); }");
}

void MainWindow::pushButton2_clicked()
{
    qDebug()<<"btn2";
    this->setStyleSheet("QMainWindow { background-color: rgba(255, 0,255, 100%); }");
}
