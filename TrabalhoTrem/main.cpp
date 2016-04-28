#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
/*
#include "../../../BlackLib/v3_0/BlackGPIO/BlackGPIO.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    BlackLib::BlackGPIO
    return 0;
}
*/
