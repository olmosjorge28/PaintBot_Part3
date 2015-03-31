#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
//#include "mainwindow.h"

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);
    ~MyServer();
    int read();
    bool write(char* data);
    void close();
    friend class MainWindow;
signals:

public slots:
    void newConnection();

private:
    QTcpServer *server;
    QTcpSocket *socket;
};

#endif // MYSERVER_H
