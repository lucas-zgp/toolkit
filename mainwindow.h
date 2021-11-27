#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QToolButton>
#include <QToolBar>
#include <QRadioButton>
#include <QCheckBox>
#include <QCommandLinkButton>
#include <QDialogButtonBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QPushButton  *pushButton;                 /*声明一个QPushButton对象*/
    QRadioButton *radio_button1;              /*声明一个QRadioButton对象*/
    QRadioButton *radio_button2;              /*声明一个QRadioButton对象*/
    QCheckBox *check_box1;                    /*声明一个QCheckBox对象*/
    QCommandLinkButton *command_link_button;  /*声明一个QCommandLinkButton对象*/
    QDialogButtonBox *dialog_button_box;      /*声明一个QDialogButtonBox对象*/

private slots:
    void checkbox_state_changed(int);
    void command_link_button_clicked();
    void dialog_button_box_clicked(QAbstractButton *);
};

#endif // MAINWINDOW_H
