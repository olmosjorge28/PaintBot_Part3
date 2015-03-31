#include "mainwindow.h"
#include "myserver.h"
#include "client.h"
#include <QTcpSocket>



//! [0]

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyServer* mServer = new MyServer();
    SocketClient* mClient = new SocketClient();
    MainWindow w(0,mServer, mClient);
    w.show();\
    //mServer.newConnection();
   // SocketClient test;
   // test.Connect();

    return a.exec();
}
