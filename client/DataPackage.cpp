/*
** EPITECH PROJECT, 2020
**   
** File description:
** DataPackage
*/

#include "DataPackage.hpp"

DataPackage::DataPackage()
{
}

DataPackage::~DataPackage()
{
}

const std::string &DataPackage::getChatID() const
{
    return this->_chatID;
}

void DataPackage::setChatId(std::string &chatId)
{
    this->_chatID = chatId;
}

const std::vector<std::pair<std::string, std::string>> &DataPackage::getMessages() const
{
    return this->_messages;
}

void DataPackage::setMessages(std::vector<std::pair<std::string, std::string>> &messages)
{
    this->_messages = messages;
}

const std::vector<std::string> &DataPackage::getUsers() const
{
    return this->_users;
}

void DataPackage::setUsers(std::vector<std::string> &users)
{
    this->_users = users;
}

void DataPackage::addUser(std::string &user)
{
    this->_users.push_back(user);
}

void DataPackage::addMessage(std::pair<std::string, std::string> message)
{
    this->_messages.push_back(message);
}