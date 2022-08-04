#include "mainwindow.h"

#include <QApplication>
#include <QStackedWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); //removes the default title bar. Custom title bar to be added in mainwindow.cpp
    w.show();
    return a.exec();
}
