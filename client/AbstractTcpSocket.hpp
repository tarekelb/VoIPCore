/*
** EPITECH PROJECT, 2020
** AbstractTcpSocket.hpp
** File description:
** AbstractTcpSocket
*/

#ifndef ABSTRACTTCPSOCKET_HPP_
#define ABSTRACTTCPSOCKET_HPP_

#include <QtWidgets>
#include <QtNetwork>
#include <QDataStream>
#include <QDialog>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
#include <QAbstractSocket>
#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include "DataPackage.hpp"
#include "../Audio/AudioManager.hpp"

class AbstractTcpSocket : public QDialog {
    Q_OBJECT

    public:
        explicit AbstractTcpSocket();

    signals:
        void SendLogInId(const std::string &id);
        void SendSignInId(const std::string &id);
        void SendUpdate(const DataPackage &data);
        
    private slots:
        void GetLogIn(const std::string &name, const std::string &pass);
        void GetSignIn(const std::string &name, const std::string &pass);
        void GetMessage(const std::string id, const std::string message);
        void GetAddUsers(const std::string &name, const std::string &id);
        void GetAddConvUsers(const std::string &convId, const std::string &id, const std::string &name);
        void GetSwapServer(const std::string &id);
        void GetConnectAudio(std::string &str);

    protected:
        void deserialization(const std::string &message);
        virtual void sendMessage(std::string &message) = 0;
        virtual void readMessage() = 0;
        virtual void disconnectSocket() = 0;
        virtual void connectSocket() = 0;

        QTcpSocket *_socket;
        QDataStream _in;
        QString _buffer;
        bool _isConnected;
    private:
        void update(const std::vector<std::string> parsedMessage);
};

#endif /* !ABSTRACTTCPSOCKET_HPP_ */