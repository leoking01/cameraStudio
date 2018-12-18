#include "mainwindow.h"
#include <QDateTime>
#include <QApplication>

#include "mainwindow.h"








int main(int argc, char *argv[])
{
//    func();


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
