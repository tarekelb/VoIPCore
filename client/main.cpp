/*
** EPITECH PROJECT, 2020
**   
** File description:
** main
*/

#include "../Audio/Audio.hpp"
#include "../Audio/Codec.hpp"
#include "../Database/Data.hpp"
#include "../client/Interface/UserInter.hpp"
#include <QtCore/QCoreApplication>
#include <QtWidgets/QApplication>

int main(int argc, char **argv)
{
    try {
        QApplication app(argc, argv);
        UserInter Interface;
        return app.exec();
    } catch(std::exception const &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
    return (0);
}