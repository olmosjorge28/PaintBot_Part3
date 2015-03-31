#include "mainwindow.h"
#include "myserver.h"
#include "client.h"



//! [0]

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    SocketClient test;
    test.Connect();
    MyServer mServer;
    w.show();\
    return a.exec();
}
