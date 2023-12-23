/*
** EPITECH PROJECT, 2020
**   
** File description:
** Data
*/

#ifndef DATA_HPP_
#define DATA_HPP_

#include <iostream>
#include "../Error.hpp"
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <iterator>

class Data {
    public:
        Data();
        ~Data();
        int mCallback(int argc, char **argv, char **azColName);
        static int callback(void *data, int argc, char **argv, char **azColName);
        void createDatabase();
        std::string createChatGroup(const std::string &senderId, const std::string &receiverID, const std::string &receiverName);
        std::string createUser(const std::string &name, const std::string &password);
        std::string loginUser(const std::string &name, const std::string &password);
        bool isUserExist(const std::string &name, const std::string &id);
        bool isUserExist(const std::string &id);  
        std::vector<std::string> &getAllUserName();
        std::string getNameById(const std::string &id);
        std::vector<std::pair<std::string,std::string>> getAllMessageOfConv(const std::string &chatID);
        std::vector<std::pair<std::string, std::string>> getAllUsersOfConv(const std::string &chatID);
        std::vector<std::string> getAllConvOfUser(const std::string &userId);
        std::vector<std::string> getAllUsers();
        bool addUserInConv(const std::string &chatID, const std::string &userId, const std::string &name);
        bool addMessage(const std::string &chatID, const std::string &senderID, const std::string &content);
    protected:
    private:
        sqlite3 *_db;
        int _err;
        std::string _str;
        std::string _errMsg;
        bool _update;
        std::vector<std::string> _tables;
};

#endif /* !DATA_HPP_ */
