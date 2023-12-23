/*
** EPITECH PROJECT, 2020
** AbstractTcpSocket.cpp
** File description:
** AbstractTcpSocket
*/

#include "AbstractTcpSocket.hpp"

AbstractTcpSocket::AbstractTcpSocket()
{
}

void AbstractTcpSocket::deserialization(const std::string &message)
{
    std::vector<std::string> parsedMessage;
    boost::split(parsedMessage, message, boost::is_any_of("[|][\n]"));
    
    parsedMessage.pop_back();
    if (std::find(parsedMessage.begin(), parsedMessage.end(), "201") != parsedMessage.end() && parsedMessage.size() == 2) {
        emit SendSignInId(parsedMessage.at(1));
        return;
    }
    if (std::find(parsedMessage.begin(), parsedMessage.end(), "202") != parsedMessage.end() && parsedMessage.size() == 2) {
        emit SendLogInId(parsedMessage.at(1));
        return;
    }
    if (std::find(parsedMessage.begin(), parsedMessage.end(), "203") != parsedMessage.end()) {
        update(parsedMessage);
        return;
    }
    if (std::find(parsedMessage.begin(), parsedMessage.end(), "401") != parsedMessage.end()) {
        emit SendSignInId("Bad Request");
        return;
    }
    if (std::find(parsedMessage.begin(), parsedMessage.end(), "402") != parsedMessage.end()) {
        emit SendSignInId("Bad Request");
        return;
    }
}

void AbstractTcpSocket::GetConnectAudio(std::string &message)
{
    
}

void AbstractTcpSocket::update(std::vector<std::string> parsedMessage)
{
    DataPackage package;
    bool user = true;

    package.setChatId(parsedMessage.at(0));
    for (size_t i = 1, code = 0; i < parsedMessage.size(); i++) {
        if (parsedMessage.at(i) == "203") {
            user = false;
            code = i + 1;
        } else if (user == true) {
            package.addUser(parsedMessage.at(i));
        } else if (user == false && (i -code) % 2 == 0) {
            package.addMessage(std::pair<std::string, std::string>(parsedMessage.at(i), parsedMessage.at(i + 1)));
        }
    }
    emit SendUpdate(package);
}

void AbstractTcpSocket::GetLogIn(const std::string &name, const std::string &pass)
{
    std::string encryptedMessage = "/loginUser|";

    encryptedMessage.append(name + "|" + pass + "\n");
    sendMessage(encryptedMessage);
}

void AbstractTcpSocket::GetSignIn(const std::string &name, const std::string &pass)
{
    std::string encryptedMessage = "/createUser|";

    encryptedMessage.append(name + "|" + pass + "\n");
    sendMessage(encryptedMessage);
}

void AbstractTcpSocket::GetMessage(const std::string id, const std::string message)
{
    std::string encryptedMessage = "/sendMessage|";

    encryptedMessage.append(id + "|" + message + "\n");
    sendMessage(encryptedMessage);
}

void AbstractTcpSocket::GetAddUsers(const std::string &name, const std::string &id)
{
    std::string encryptedMessage = "/createConv|";

    encryptedMessage.append(id + "|" + name + "\n");
    sendMessage(encryptedMessage);

}

void AbstractTcpSocket::GetAddConvUsers(const std::string &convId, const std::string &id, const std::string &name)
{
    std::string encryptedMessage = "/addUserInConv|";

    encryptedMessage.append(convId + "|" + id + "|" + name + "\n");
    sendMessage(encryptedMessage);
}

void AbstractTcpSocket::GetSwapServer(const std::string &id)
{
    std::string encryptedMessage = "/update|";

    encryptedMessage.append(id + "\n");
    sendMessage(encryptedMessage);
}