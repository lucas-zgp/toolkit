#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QToolButton>
#include <QToolBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QPushButton *pushButton1; /*声明一个QPushButton对象*/
    QPushButton *pushButton2; /*声明一个QPushButton对象*/
    QToolButton *tool_button; /*声明一个QToolButton对象*/
    QToolBar    *tool_bar;    /*声明一个QToolBar对象*/

private slots:
    void pushButton1_clicked();
    void pushButton2_clicked();
};

#endif // MAINWINDOW_H
