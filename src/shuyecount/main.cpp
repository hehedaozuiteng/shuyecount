#include "mainwindow.h"
#include "loginwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow();
    loginWindow L(nullptr,w);
    L.show();

    return a.exec();
}
