/*
** EPITECH PROJECT, 2020
**   
** File description:
** UserInter
*/

#ifndef USERINTER_HPP_
#define USERINTER_HPP_

#include <thread>
#include "LoginPage.hpp"
#include "../TcpSocket.hpp"
#include "../DataPackage.hpp"

class UserInter : public QWidget {
    Q_OBJECT

    public:
        UserInter(QWidget *parent = nullptr);
        ~UserInter();
        void AddMessage(const std::string &name, const std::string &message, const bool &side);

    protected:
    
    signals:
        void SendMessage(const std::string id, const std::string message);
        void SendAddUsers(const std::string &name, const std::string &id);
        void SendAddConvUsers(const std::string &convId, const std::string &id, const std::string &name);
        void SendSwapServer(const std::string &id);
        void SendConnectAudio(std::string &str);

    private slots:
        void DeleteConvUser();
        void StockMessage();
        void StockUser();
        void StockAddUser();
        void SwapServer();
        void SwapAudio();
        void GetLogInId(const std::string &id);
        void GetSignInId(const std::string &id);
        void GetUpdate(const DataPackage &package);

    private:
        AudioManager _audio;
        TcpSocket _client;
        LoginPage _login;

        std::thread _audioLoop;

        void loopAudio();
        void SetAllMessage(const std::vector<std::pair<std::string,std::string>> &messages);
        void SetConvUsers(const std::vector<std::string> &users);
        const std::string GenerateServerName(const std::vector<std::string> &users);
        void AddConv(const std::string &named, const std::string &id, bool used);
        void DeleteChat();

        std::string _name;
        std::string _nameId;
        std::string _serverId;

        std::string _selectedServer;
        bool _AudioConnect;

        std::vector<QLabel *> _convUsers;
        std::vector<std::pair<QPushButton *, std::string>> _listConvs;
        std::vector<QPushButton *> _listUsers;
        std::vector<QWidget *> _chatMessages;

        //Principale
        QGridLayout *_mainLayout;

        //Quatre au centre Widgets
        QWidget *_nameWidget;
        QWidget *_sideWidget;
        QWidget *_convWidget;
        QWidget *_interfaceWidget;

        //Friends list
        QWidget *_friendsWidget;
        QVBoxLayout *_friendsLayout;
        QScrollArea *_friendsScroll;

        QWidget *_addFriendsWidget;
        QVBoxLayout *_addFriendsLayout;
        QLineEdit *_addFriendsLine;
        QPushButton *_addFriendsButton;

        //Quatre au centre layout
        QHBoxLayout *_nameLayout;
        QVBoxLayout *_sideLayout;
        QHBoxLayout *_convLayout;
        QGridLayout *_interfaceLayout;

        //Texte angle droit
        QLabel *_nameLabel;
        QLabel *_idLabel;
        QLabel *_serverLabel;

        //deuxieme partie grand cadre

        //Quatre corner widgets
        QWidget *_chatWidget;
        QWidget *_connectWidget;
        QWidget *_messageWidget;
        QWidget *_vocalWidget;

        QScrollArea *_chatScroll;

        //Quatre corner Layout
        QGridLayout *_chatLayout;
        QVBoxLayout *_connectLayout;
        QHBoxLayout *_messageLayout;
        QPushButton *_vocalButton;
        QVBoxLayout *_vocalLayout;

        //Chat messages
        QLineEdit *_messageLine;
        QPushButton *_messageButton;

        //Add Users
        QWidget *_addUsersWidget;
        QVBoxLayout *_addUsersLayout;
        QPushButton *_addUsersButton;
        QLineEdit *_addUsersLine;

        //ListUsers
        QWidget *_listUsersWidget;
        QVBoxLayout *_listUsersLayout;

        QScrollArea *_listUsersScroll;
};

#endif /* !USERINTER_HPP_ */