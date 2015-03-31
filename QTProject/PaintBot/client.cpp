#include "client.h"

SocketClient::SocketClient(QObject *parent ) : QObject(parent){

}


void SocketClient::Connect(){
    socket = new QTcpSocket(this);
    socket->connectToHost("192.168.2.18", 5001);
    if(socket->waitForConnected(4000)){
        
        qDebug() << "Connected:";
        //socket->close();
    }
    else{
        qDebug() <<"Not Connected";
    }
    
    
}
