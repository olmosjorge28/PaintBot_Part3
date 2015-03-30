#ifndef SERVER_H
#define SERVER_H


#include <QtNetwork/qtcpserver.h>
#include <QtNetwork/qtcpsocket.h>
#include <QDialog>
#include <QObject>
#include <iostream>

using namespace std;

class RobotServer: public QObject{
    Q_OBJECT
private:
    QTcpServer* mainserver;
public:
    RobotServer(QObject* init){

       mainserver = new QTcpServer(this);
       QObject::connect(mainserver, SIGNAL(RobotServer::handler()), this, SLOT(RobotServer::handler()));
       if(!mainserver->listen(QHostAddress::Any, 50000)){
            cout<<"Server crashed\n"<<endl;
            cout.flush();
        }
        else {
            unsigned short portnum =  mainserver->serverPort();
            cout<<"Portnum: "<<portnum<<endl;
            cout<<"Server started at: "<<mainserver->serverAddress().toString().toStdString()<<endl;
            cout<<"Is listening: "<<mainserver->isListening()<<endl;
            cout.flush();
        }
    }
    void handler(){

        QTcpSocket* soc = mainserver->nextPendingConnection();
        //QObject::connect(soc,SIGNAL(disconnected()), soc, SLOT(deleteLater()));
        QByteArray input;
        soc->write("Hello!\r\n");
        soc->flush();
        soc->waitForBytesWritten(3000);
        //while(soc->canReadLine()){
        //input = soc->readAll();
        //    if(input == "Code:0"){

        //    }
        //    else{
        soc->close();
        cout<<"Server shutdown\n";
        cout.flush();
         //   }
        // }
    }
};

#endif
