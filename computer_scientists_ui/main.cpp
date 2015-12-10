#include "mainwindow.h"
#include "scientist.h"
#include "scientist_service.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    MainWindow window;
    window.show();

    return application.exec();
}
