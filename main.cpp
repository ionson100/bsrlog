#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //git push -u origin master
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
