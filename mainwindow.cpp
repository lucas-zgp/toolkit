#include "mainwindow.h"
#include "QDebug"
#include "QScreen"
#include "QGuiApplication"
#include "QRect"
#include "QApplication"
#include "QStyle"
#include <QProcess>

#define MAINWINDOW_WIDTH  600
#define MAINWINDOW_HEIGHT 600

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QList<QScreen *> list_screen =  QGuiApplication::screens();  /*多显示器*/
    QRect rect = list_screen.at(0)->geometry();
    this->setGeometry((rect.width() - MAINWINDOW_WIDTH)/2,
                      (rect.height() - MAINWINDOW_HEIGHT)/2,
                      MAINWINDOW_WIDTH,MAINWINDOW_HEIGHT);
    this->setStyleSheet("QMainWindow {background-color: rgba(128, 128, 128, 100%);}");

    radio_button1 = new QRadioButton(this);
    radio_button2 = new QRadioButton(this);

    radio_button1->setGeometry(200,200,100,50);
    radio_button2->setGeometry(300,200,100,50);
    radio_button1->setChecked(false);
    radio_button2->setChecked(true);

    check_box1  = new QCheckBox(this);
    check_box1->setGeometry(100,100,150,150);
    check_box1->setCheckable(true);
    check_box1->setChecked(true);
    check_box1->setTristate(true);
    connect(check_box1,SIGNAL(stateChanged(int)),this,SLOT(checkbox_state_changed(int)));

    command_link_button = new QCommandLinkButton("打开我的电脑","点击此按钮将打开我的电脑",this);
    command_link_button->setGeometry(0,0, 250, 60);
    connect(command_link_button,SIGNAL(clicked()),this,SLOT(command_link_button_clicked()));

    dialog_button_box = new QDialogButtonBox(this);
    dialog_button_box->setGeometry(400,400,200,200);
    dialog_button_box->addButton(QDialogButtonBox::Yes);
    dialog_button_box->addButton(QDialogButtonBox::No);
    dialog_button_box->button(QDialogButtonBox::Yes)->setText("同意");
    dialog_button_box->button(QDialogButtonBox::No)->setText("不同意");
    pushButton = new QPushButton("自定义按钮");
    dialog_button_box->addButton(pushButton,QDialogButtonBox::ActionRole);
    connect(dialog_button_box,SIGNAL(clicked(QAbstractButton *)),
            this,SLOT(dialog_button_box_clicked(QAbstractButton *)));
}

void MainWindow::command_link_button_clicked()
{
    QProcess *poc = new QProcess;
    poc->start("explorer.exe");
}


void MainWindow::dialog_button_box_clicked(QAbstractButton *btn)
{
    if(btn == dialog_button_box->button(QDialogButtonBox::No))
    {
        qDebug()<<"不同意";
    }
    else if (btn == dialog_button_box->button(QDialogButtonBox::Yes))
    {
        qDebug()<<"同意";
    }
    else if (btn == pushButton)
    {
        qDebug()<<"自定义按钮";
    }
}

void MainWindow::checkbox_state_changed(int state)
{
    switch (state)
    {
    case Qt::Checked:
        check_box1->setText("选中");
        break;
    case Qt::Unchecked:
        check_box1->setText("未选中");
        break;
    case Qt::PartiallyChecked:
        check_box1->setText("部分选中");
        break;
    default:
        break;
    }
}


MainWindow::~MainWindow()
{
    qDebug()<<"析构函数";
}

