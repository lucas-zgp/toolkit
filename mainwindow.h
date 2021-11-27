#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QPushButton *pushButton1;
    QPushButton *pushButton2;

private slots:
    void pushButton1_clicked();
    void pushButton2_clicked();
};

#endif // MAINWINDOW_H
