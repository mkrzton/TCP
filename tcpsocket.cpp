#include "tcpsocket.h"

TcpSocket::TcpSocket(QObject *parent) : QObject(parent){

}
void TcpSocket::EstablishConnection(){

    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));

    qDebug() << "Establishing connection";

    socket->connectToHost("youtube.com", 80);

    if(!socket->waitForConnected(5000)){

        qDebug() << "Problem with connection " << socket->errorString();
    }

}

void TcpSocket::connected(){

    qDebug() << "Connected";

    socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
}

void TcpSocket::readyRead(){

    qDebug() << "Writing to file";

    QFile *f = new QFile("C:/Users/Marcin/Documents/TCPSocket/tcp.txt");

    if(f->open(QFile::Append)){

        f->write(socket->readAll());
        f->flush();
        f->close();
    }

    delete f;
}
void TcpSocket::bytesWritten(qint64 bytes){

    qDebug() << "Number of bytes written: " <<bytes ;
}


void TcpSocket::disconnected(){

    qDebug() << "Disconnected";
}

