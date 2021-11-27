#include "mainwindow.h"
#include "QDebug"
#include "QScreen"
#include "QGuiApplication"
#include "QRect"
#include "QApplication"
#include "QStyle"

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

    pushButton1 = new QPushButton("pushButton1",this); /*实例化QPushButton对象*/
    pushButton2 = new QPushButton("pushButton2",this); /*实例化QPushButton对象*/
    tool_bar    = new QToolBar(this);                  /*实例化QToolBar对象*/
    tool_button = new QToolButton(this);

    QStyle *style = QApplication::style();
    QIcon icon = style->standardIcon(QStyle::SP_TitleBarContextHelpButton);

    tool_button->setIcon(icon);
    tool_button->setText("Help");
    tool_button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    tool_bar->addWidget(tool_button);

    /*设置控件位置*/
    pushButton1->setGeometry(100,50,100,50);
    pushButton2->setGeometry(100,100,100,50);
    tool_bar->setGeometry(100,150,100,50);

    /*信号与槽连接*/
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
