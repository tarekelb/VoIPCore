project(Babel)
cmake_minimum_required(VERSION 2.8.12)
add_definitions("-fPIC")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)
find_package(Portaudio REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(${CMAKE_INCLUDE_PATH})
add_executable(babel_client ../client/main.cpp
                    ../Error.cpp
                    ../Error.hpp
                    ../Audio/Audio.cpp
                    ../Audio/Audio.hpp
                    ../Audio/Codec.hpp
                    ../Audio/Codec.cpp
                    ../Audio/AudioManager.hpp
                    ../Audio/AudioManager.cpp
                    ../client/AbstractTcpSocket.hpp
                    ../client/AbstractTcpSocket.cpp
                    ../client/DataPackage.hpp
                    ../client/DataPackage.cpp
                    ../client/Interface/UserInter.hpp
                    ../client/Interface/UserInter.cpp
                    ../client/Interface/LoginPage.hpp
                    ../client/Interface/LoginPage.cpp
                    ../client/TcpSocket.cpp
                    ../client/TcpSocket.hpp)
add_executable(babel_server ../server/main.cpp
                    ../server/Server.cpp
                    ../server/Connection.cpp
                    ../server/Server.hpp
                    ../Audio/Audio.cpp
                    ../Audio/Audio.hpp
                    ../Audio/Codec.hpp
                    ../Audio/Codec.cpp
                    ../Audio/AudioManager.hpp
                    ../Audio/AudioManager.cpp
                    ../server/Connection.hpp
                    ../Error.cpp
                    ../Error.hpp
                    ../Database/Data.cpp
                    ../Database/Data.hpp)
target_link_libraries(babel_server ${CONAN_LIBS} Qt5::Widgets)
target_link_libraries(babel_client ${CONAN_LIBS} Qt5::Network)
target_link_libraries(babel_client ${CONAN_LIBS} Qt5::Widgets)
