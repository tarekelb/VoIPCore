/*
** EPITECH PROJECT, 2020
**   
** File description:
** server
*/

#include "Server.hpp"

Server::Server(boost::asio::io_context &io_context)
    : _io_context(io_context), _acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 7171))
{
    std::cout << "Port : " << 7171 << std::endl;
    this->start_accept();
    this->_routine = std::thread(&Server::update, this);
}

void Server::start_accept()
{
    boost::shared_ptr<Connection> new_connection(new Connection(this->_io_context, this->_data));
    this->_acceptor.async_accept(new_connection->getSocket(), boost::bind(&Server::handle_accept, this, new_connection, boost::asio::placeholders::error));
    this->_all_sockets.push_back(new_connection);
}

void Server::handle_accept(boost::shared_ptr<Connection> new_connection, const boost::system::error_code& error)
{
    if (!error) {
        std::cout << "Get one client!" << std::endl;
        new_connection->start();
    }
    start_accept();
}

void Server::update()
{
    while (1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        if (this->_all_sockets.size() > 1 ) {
        for (size_t it = 0; it < this->_all_sockets.size(); it++) {
            if (this->_all_sockets[it] && this->_all_sockets[it].get()) {
                if (this->_all_sockets[it].get()->isUpdate()) {
                    std::vector<std::pair<std::string, std::string>> users = this->_data.getAllUsersOfConv(this->_all_sockets[it]->getConvID());
                    std::vector<std::pair<std::string, std::string>> messages = this->_data.getAllMessageOfConv(this->_all_sockets[it]->getConvID());
                    for (size_t b = 0; b < this->_all_sockets.size(); b++) {
                        for (size_t c = 0; c < users.size(); c++) {
                            if (this->_all_sockets[b]->getID() == users[c].second) {
                                this->_all_sockets[b]->update(users, messages, this->_all_sockets[it]->getConvID());
                            }
                        }
                    }
                    this->_all_sockets[it]->setUpdate(false);
                }
            }
        }
    }
    }
}