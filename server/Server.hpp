/*
** EPITECH PROJECT, 2020
**   
** File description:
** server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <iostream>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <chrono>
#include <thread>
#include <mutex>
#include "Connection.hpp"
#include "../Database/Data.hpp"

class Server
{
    public:
        Server(boost::asio::io_context& io_context);
        void start_accept();
        void handle_accept(boost::shared_ptr<Connection> new_connection, const boost::system::error_code& error);
        void update();
    private:
        std::vector<boost::shared_ptr<Connection>> _all_sockets;
        boost::asio::ip::tcp::acceptor _acceptor;
        boost::asio::io_context &_io_context;
        Data _data;
        std::thread _routine;
};

#endif /* !TCP_SERVER_HPP_ */
