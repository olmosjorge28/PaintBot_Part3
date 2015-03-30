#include "mainwindow.h"
#include "server.h"
#include "QtNetwork/qtcpserver.h"
#include "QtNetwork/qtcpsocket.h"




//! [0]

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    RobotServer* serv = new RobotServer(0);

    w.show();\
    return a.exec();
}
