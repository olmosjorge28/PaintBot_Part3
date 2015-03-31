#include "myserver.h"


QHostAddress hostadd("192.168.2.27");


MyServer::MyServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
    //connect(server,SIGNAL(write()),this,SLOT(write()));
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


    socket = server->nextPendingConnection();

    //socket->write("hello bitch\r\n");
    //socket->write("3\r\n");

    socket->flush();
    
    socket->waitForBytesWritten(4000);

    //socket->close();
}


int MyServer::read(){
    //socket->read()
    return 0;
}

bool MyServer::write(char* data){
    //socket->write("hello bitch\r\n");
    return socket->write(data);
    socket->flush();
}

void MyServer::close(){
    socket->close();
}

