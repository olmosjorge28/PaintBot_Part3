#ifndef CLIENT
#define CLIENT

#include <QObject>
#include <QTcpSocket>
#include <QDebug>


class SocketClient : public QObject{

    Q_OBJECT
public:
    explicit SocketClient(QObject *parent = 0);
    void Connect();
    QTcpSocket *socket;
signals:

public slots:

private:
    //QTcpSocket *socket;
};





#endif // CLIENT

