/*
** EPITECH PROJECT, 2020
** TcpSocket.cpp
** File description:
** TcpSocket
*/

#include "TcpSocket.hpp"

TcpSocket::TcpSocket()
{
    this->_isConnected = false;
    this->_socket = new QTcpSocket(this);

    connect(this->_socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &TcpSocket::displayError);
    connectSocket();
}

TcpSocket::~TcpSocket()
{
}

void TcpSocket::connectSocket()
{
    if (this->_isConnected == true) {
        return;
    }
    this->_socket->connectToHost("localhost", 7171);
    connect(this->_socket, &QIODevice::readyRead, this, &TcpSocket::readMessage);
    this->_isConnected = true;
}

void TcpSocket::disconnectSocket()
{
    if (this->_isConnected == false)
        return;
    if (this->_socket->isOpen())
        this->_socket->disconnectFromHost();
    this->_isConnected = false;
}

void TcpSocket::sendMessage(std::string &message)
{
    if (this->_isConnected == false)
        return;
    this->_socket->write(message.c_str());
}

void TcpSocket::readMessage()
{
    this->_buffer.clear();

    while (this->_socket->canReadLine()) {
        this->_buffer = this->_socket->readLine();
        std::string message = this->_buffer.toUtf8().constData();

        deserialization(message);
    }
}

void TcpSocket::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
            break;
        case QAbstractSocket::HostNotFoundError:
            std::cout << "Host not found" << std::endl;
            break;
        case QAbstractSocket::ConnectionRefusedError:
            std::cout << "Connection was refused by the peer" << std::endl;
            break;
        case QAbstractSocket::OperationError:
            std::cout << "Operation Error" << std::endl;
            break;
        default:
            std::cout << "Some unknow error" << std::endl;
            break;
    }
}