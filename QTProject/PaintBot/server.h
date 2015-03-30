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

        mainserver = new QTcpServer(init);
        QObject::connect(mainserver, SIGNAL(handler()), this, SLOT(handler()));
        if(!mainserver->listen(QHostAddress::Any, 50000)){
            flush("Server crashed\n");
        }
        else {
            flush("Server started\n");
        }
    }
    void handler(){

        QTcpSocket* soc = mainserver->nextPendingConnection();
        QByteArray input;
        while(soc->canReadLine()){
            input = soc->readAll();
            if(input == "Code:0"){

            }
            else{
                soc->close();
                cout<<"Server shutdown\n";
            }
        }
    }
};

#endif
