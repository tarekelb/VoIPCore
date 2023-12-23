/*
** EPITECH PROJECT, 2020
**   
** File description:
** connection
*/

#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_

#include <iostream>
#include <string>
#include <ctime>
#include <boost/bind/bind.hpp>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <vector>
#include "../Database/Data.hpp"
#include "../Audio/AudioManager.hpp"

class Connection : public boost::enable_shared_from_this<Connection>
{
    public:
        Connection(boost::asio::io_context& io_context, Data &data);
        boost::asio::ip::tcp::socket &getSocket();
        std::string getMessage();
        std::string createStringFromVector();
        std::string getID() const;
        void start();
        void handle_write(const boost::system::error_code& err,size_t size);
        void handle_read(const boost::system::error_code& err,size_t size);
        void createUser();
        void loginUser();
        void createConv();
        void forceUpdate(const std::string &userID);
        void sendMessage();
        void addUserInConv();
        std::string getConvID() const;
        void setConvID(const std::string &convID);
        void setUpdate(const bool &state);
        bool isUpdate() const;
        void forceUpdate();
        void update(const std::vector<std::pair<std::string, std::string>> &users, const std::vector<std::pair<std::string, std::string>> &messages, const std::string &chatID);
    private:
        boost::asio::ip::tcp::socket _socket;
        std::string _message_write;
        std::string _message_read;
        std::string _actual_message;
        Data &_data;
        std::string _id;
        std::string _convID;
        bool _isUpdate;
};

#endif /* !CONNECTION_HPP_ */
