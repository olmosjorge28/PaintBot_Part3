#include "myserver.h"


QHostAddress hostadd("192.168.2.18");

MyServer::MyServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);

    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));

     if(!server->listen(hostadd,5001))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
}

MyServer::~MyServer()
{

}

void MyServer::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();

    socket->write("hello bitch\r\n");
    socket->flush();
    //socket->read(len);
    //if (len == 5){

      //  return;
    //}
    socket->waitForBytesWritten(4000);

    socket->close();

}
