#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QFile>


class TcpSocket : public QObject{

    Q_OBJECT

public:

    explicit TcpSocket(QObject *parent = nullptr);
    void EstablishConnection();

signals:

public slots:

    void connected();
    void readyRead();
    void bytesWritten(qint64 bytes);
    void disconnected();

private:

    QTcpSocket *socket;

};

#endif // TCPSOCKET_H
