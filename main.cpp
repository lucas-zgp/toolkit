#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(":/style.qss");

    /*判断文件是否存在*/
    if(file.exists())
    {
        printf("123");
        file.open(QFile::ReadOnly); /*以只读的方式打开*/
        QString style_sheet = QLatin1String(file.readAll());/*以字符串的方式保存读出的结果*/
        qApp->setStyleSheet(style_sheet);  /*设置全局样式*/
        file.close();                      /*关闭文件*/
    }
    printf("321");

    MainWindow w;
    w.show();
    return a.exec();
}
