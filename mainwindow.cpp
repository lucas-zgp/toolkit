#include "mainwindow.h"
#include "QDebug"
#include <QScreen>
#include "QGuiApplication"
#include <QRect>

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
}

MainWindow::~MainWindow()
{

}
