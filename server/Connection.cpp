/*
** EPITECH PROJECT, 2020
**   
** File description:
** Connection
*/

#include "Connection.hpp"

Connection::Connection(boost::asio::io_context& io_context, Data &data) : _socket(io_context), _data(data)
{
    this->_id = "0000";
    this->_isUpdate = false;
}

boost::asio::ip::tcp::socket &Connection::getSocket()
{
    return this->_socket;
}

void Connection::start()
{
    this->_message_write = "Hello, you are connected to Babybel server !\n";

    boost::asio::async_write(this->_socket, boost::asio::buffer(this->_message_write), boost::bind(&Connection::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    boost::asio::async_read_until(this->_socket, boost::asio::dynamic_buffer(this->_message_read), "\n", boost::bind(&Connection::handle_read, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Connection::handle_write(const boost::system::error_code& err,size_t size)
{
}

void Connection::handle_read(const boost::system::error_code& err,size_t size)
{
    this->_actual_message = this->_message_read;
    if (!this->_actual_message.empty())
        this->_actual_message.pop_back();
    if (!this->_message_read.empty() && this->_message_read.find("createUser") != std::string::npos) {
        createUser();
    } else if (!this->_message_read.empty() && this->_message_read.find("loginUser") != std::string::npos) {
        loginUser();
    } else if (!this->_message_read.empty() && this->_message_read.find("createConv") != std::string::npos) {
        createConv();
    } else if (!this->_message_read.empty() && this->_message_read.find("sendMessage") != std::string::npos) {
        sendMessage();
    } else if (!this->_message_read.empty() && this->_message_read.find("addUserInConv") != std::string::npos) {
        addUserInConv();
    }
    else if (!this->_message_read.empty() && this->_message_read.find("update") != std::string::npos) {
        forceUpdate();
    }
    this->_message_read = "";
    boost::asio::async_read_until(this->_socket, boost::asio::dynamic_buffer(this->_message_read), "\n", boost::bind(&Connection::handle_read, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Connection::forceUpdate()
{
    std::vector<std::string> tmp;
    boost::split(tmp, this->_actual_message, boost::is_any_of("|"));
    if (tmp.size() > 1) {
        std::vector<std::pair<std::string, std::string>> users = this->_data.getAllUsersOfConv(tmp[1]);
        std::vector<std::pair<std::string, std::string>> messages = this->_data.getAllMessageOfConv(tmp[1]);
        this->update(users, messages, tmp[1]);
    }
    this->_message_write = "400\n";
    boost::asio::async_write(this->_socket, boost::asio::buffer(this->_message_write), boost::bind(&Connection::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Connection::forceUpdate(const std::string &userID)
{
    std::vector<std::string> tmp = this->_data.getAllConvOfUser(userID);

    for (size_t i = 0; i < tmp.size(); i += 1) {
        std::vector<std::pair<std::string, std::string>> users = this->_data.getAllUsersOfConv(tmp[i]);
        std::vector<std::pair<std::string, std::string>> messages = this->_data.getAllMessageOfConv(tmp[i]);
        this->update(users, messages, tmp[i]);
    }
}

void Connection::createUser()
{
    std::vector<std::string> tmp;
    std::string id;
    boost::split(tmp, this->_actual_message, boost::is_any_of("|"));
    if ((id = this->_data.createUser(tmp[1], tmp[2])) != "") {
        this->_id = id;
        this->_message_write = "201|" + id;
        this->_message_write = this->_message_write + "\n";
        boost::asio::async_write(this->_socket, boost::asio::buffer(this->_message_write), boost::bind(&Connection::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
        this->forceUpdate(id);
        return;
    }
    this->_message_write = "401\n";
    boost::asio::async_write(this->_socket, boost::asio::buffer(this->_message_write), boost::bind(&Connection::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Connection::loginUser()
{
    std::vector<std::string> tmp;
    std::string id;
    boost::split(tmp, this->_actual_message, boost::is_any_of("|"));
    if ((id = this->_data.loginUser(tmp[1], tmp[2])) != "") {
        this->_id = id;
        this->_message_write = "202|" + id;
        this->_message_write = this->_message_write + "\n";
        boost::asio::async_write(this->_socket, boost::asio::buffer(this->_message_write), boost::bind(&Connection::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
        this->forceUpdate(id);
        return;
    }
    this->_message_write = "402\n";
    boost::asio::async_write(this->_socket, boost::asio::buffer(this->_message_write), boost::bind(&Connection::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Connection::createConv()
{
    std::vector<std::string> tmp;
    std::string id;
    boost::split(tmp, this->_actual_message, boost::is_any_of("|"));
    if ((id = this->_data.createChatGroup(this->_id, tmp[1], tmp[2])) != "") {
        this->_convID = id;
        this->_isUpdate = true;
        this->_message_write = "204\n";
        boost::asio::async_write(this->_socket, boost::asio::buffer(this->_message_write), boost::bind(&Connection::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
        return;
    }
    this->_message_write = "405\n";
    boost::asio::async_write(this->_socket, boost::asio::buffer(this->_message_write), boost::bind(&Connection::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Connection::sendMessage()
{
    std::vector<std::string> tmp;
    boost::split(tmp, this->_actual_message, boost::is_any_of("|"));
    if (this->_data.addMessage(tmp[1], this->_id, tmp[2])) {
        this->_convID = tmp[1];
        this->_isUpdate = true;
        this->_message_write = "200\n";
        boost::asio::async_write(this->_socket, boost::asio::buffer(this->_message_write), boost::bind(&Connection::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
        return;
    }
    this->_message_write = "403\n";
    boost::asio::async_write(this->_socket, boost::asio::buffer(this->_message_write), boost::bind(&Connection::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Connection::addUserInConv()
{
    std::string id;
    std::vector<std::string> tmp;
    boost::split(tmp, this->_actual_message, boost::is_any_of("|"));
    id = this->_data.loginUser(tmp[1], tmp[2]);
    if (this->_data.addUserInConv(tmp[1], tmp[2], tmp[3])) {
        this->_convID = tmp[1];
        this->_isUpdate = true;
        this->_message_write = "200\n";
        boost::asio::async_write(this->_socket, boost::asio::buffer(this->_message_write), boost::bind(&Connection::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
        return;
    }
    this->_message_write = "404\n";
    boost::asio::async_write(this->_socket, boost::asio::buffer(this->_message_write), boost::bind(&Connection::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

std::string Connection::getID() const
{
    return this->_id;
}

std::string Connection::getConvID() const
{
    return this->_convID;
}

bool Connection::isUpdate() const
{
    return this->_isUpdate;
}

void Connection::setConvID(const std::string &convID)
{
    this->_convID = convID;
}

void Connection::setUpdate(const bool &state)
{
    this->_isUpdate = state;
}

void Connection::update(const std::vector<std::pair<std::string, std::string>> &users, const std::vector<std::pair<std::string, std::string>> &messages, const std::string &convID)
{
    this->_message_write = convID;
    for (size_t it = 0; it < users.size(); it++)
        this->_message_write = this->_message_write + "|" + users[it].first;
    this->_message_write = this->_message_write + "|203";
    for (size_t it = 0; it < messages.size(); it++) {
        this->_message_write = this->_message_write + "|" + messages[it].first;
        this->_message_write = this->_message_write + "|" + messages[it].second;
    }
    this->_message_write = this->_message_write + "\n";
    boost::asio::async_write(this->_socket, boost::asio::buffer(this->_message_write), boost::bind(&Connection::handle_write, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}