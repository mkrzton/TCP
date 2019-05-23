#include <QCoreApplication>
#include "tcpsocket.h"

int main(int argc, char *argv[]){

    QCoreApplication a(argc, argv);

    TcpSocket server;
    server.EstablishConnection();

    return a.exec();
}
