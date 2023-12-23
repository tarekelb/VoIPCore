/*
** EPITECH PROJECT, 2020
**   
** File description:
** DataPackage
*/

#ifndef DATAPACKAGE_HPP_
#define DATAPACKAGE_HPP_

#include <vector>
#include <iostream>

class DataPackage {
    public:
        DataPackage();
        ~DataPackage();
        const std::string &getChatID() const;
        void setChatId(std::string &chatId);
        const std::vector<std::pair<std::string, std::string>> &getMessages() const;
        void setMessages(std::vector<std::pair<std::string, std::string>> &messages);
        const std::vector<std::string> &getUsers() const;
        void setUsers(std::vector<std::string> &users);
        void addUser(std::string &user);
        void addMessage(std::pair<std::string, std::string> message);

    protected:

    private:
        std::string _chatID;
        std::vector<std::pair<std::string,std::string>> _messages;
        std::vector<std::string> _users;
};

#endif /* !DATAPACKAGE_HPP_ */
