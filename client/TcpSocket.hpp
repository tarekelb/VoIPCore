/*
** EPITECH PROJECT, 2020
** TcpSocket.hpp
** File description:
** TcpSocket
*/

#ifndef TCPSOCKET_HPP_
#define TCPSOCKET_HPP_

#include "AbstractTcpSocket.hpp"

class TcpSocket : public AbstractTcpSocket {

    public:
        TcpSocket();
        ~TcpSocket();

    protected:

    private:
        void sendMessage(std::string &message) override;
        void readMessage() override;
        void connectSocket() override;
        void disconnectSocket() override;
        void displayError(QAbstractSocket::SocketError socketError);
};

#endif /* !TCPSOCKET_HPP_ */
