#include "mainwindow.h"
#include "myserver.h"




//! [0]

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

   MyServer mServer;
    w.show();\
    return a.exec();
}
