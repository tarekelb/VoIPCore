/*
** EPITECH PROJECT, 2020
**   
** File description:
** main
*/

#include <boost/asio.hpp>
#include "../Error.hpp"
#include "Server.hpp"

int main()
{
    try {
        boost::asio::io_context io_context;
        Server server(io_context);
        io_context.run();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}