/*
** EPITECH PROJECT, 2020
**   
** File description:
** UserInter
*/

#include "UserInter.hpp"

UserInter::UserInter(QWidget *parent) : QWidget(parent)
{
    this->_selectedServer = "0";
    this->_AudioConnect = false;
    setStyleSheet("background-color:rgb(80, 80, 80);");

    this->_mainLayout = new QGridLayout(this);
    this->_mainLayout->setSpacing(0);
    this->_mainLayout->setMargin(0);
    this->_mainLayout->setRowStretch(0, 1);
    this->_mainLayout->setRowStretch(1, 9);
    this->_mainLayout->setColumnStretch(0, 2);
    this->_mainLayout->setColumnStretch(1, 8);

    this->_nameWidget = new QWidget();
    this->_sideWidget = new QWidget();
    this->_convWidget = new QWidget();
    this->_interfaceWidget = new QWidget();
    this->_nameWidget->setStyleSheet("background-color:rgb(50, 50, 50);");
    this->_sideWidget->setStyleSheet("background-color:rgb(60, 60, 60);");
    this->_convWidget->setStyleSheet("background-color:rgb(60, 60, 60);");
    this->_interfaceWidget->setStyleSheet("background-color:rgb(80, 80, 80);");

    QFont BasicFont("Arial", 14, QFont::DemiBold);
    QFont BoldFont("Arial", 14, QFont::Bold);
    QFont ItalicFont("Arial", 14, QFont::StyleOblique, QFont::DemiBold);

    this->_nameLayout = new QHBoxLayout(this->_nameWidget);
    this->_sideLayout = new QVBoxLayout(this->_sideWidget);
    this->_convLayout = new QHBoxLayout(this->_convWidget);
    this->_interfaceLayout = new QGridLayout(this->_interfaceWidget);
    this->_sideLayout->setSpacing(0);
    this->_sideLayout->setMargin(0);
    this->_interfaceLayout->setSpacing(0);
    this->_interfaceLayout->setMargin(0);
    this->_interfaceLayout->setRowStretch(0, 9);
    this->_interfaceLayout->setRowStretch(1, 1);
    this->_interfaceLayout->setColumnStretch(0, 8);
    this->_interfaceLayout->setColumnStretch(1, 2);
    
    this->_friendsWidget = new QWidget();
    this->_friendsWidget->setStyleSheet("background-color:rgb(80, 80, 80); border: 0px");
    this->_friendsLayout = new QVBoxLayout(this->_friendsWidget);
    this->_friendsLayout->setAlignment(Qt::AlignTop);
    this->_friendsScroll = new QScrollArea();
    this->_friendsScroll->setStyleSheet("margin: 15 10 0 10; border: 0px");
    this->_friendsScroll->setWidgetResizable(true);
    this->_friendsScroll->setWidget(this->_friendsWidget);
    this->_sideLayout->addWidget(this->_friendsScroll, 9);

    this->_addFriendsWidget = new QWidget();
    this->_addFriendsWidget->setStyleSheet("background-color:rgb(60, 60, 60); margin: 0 15 0 15");
    this->_addFriendsLayout = new QVBoxLayout(this->_addFriendsWidget);
    this->_addFriendsLine = new QLineEdit();
    this->_addFriendsLine->setStyleSheet("border: 1px solid black;border-radius: 5px;background-color: rgb(100, 100, 100); color: white; padding: 2 10 2 10");
    this->_addFriendsLine->setFont(BasicFont);
    this->_addFriendsLine->setMinimumWidth(150);
    this->_addFriendsButton = new QPushButton(tr("Add friend"));
    connect(this->_addFriendsButton, SIGNAL (released()), this, SLOT(StockAddUser()));
    this->_addFriendsButton->setStyleSheet(".QPushButton{border: 1px solid black;border-radius: 10px;background-color: rgb(200, 200, 200);padding: 5 10 5 10}");
    this->_addFriendsButton->setFont(BasicFont);
    this->_addFriendsLayout->addWidget(this->_addFriendsLine, 6);
    this->_addFriendsLayout->addWidget(this->_addFriendsButton, 4, Qt::AlignHCenter);
    this->_sideLayout->addWidget(this->_addFriendsWidget, 1);

    this->_mainLayout->addWidget(this->_nameWidget, 0, 0);
    this->_mainLayout->addWidget(this->_sideWidget, 1, 0);
    this->_mainLayout->addWidget(this->_convWidget, 0, 1);
    this->_mainLayout->addWidget(this->_interfaceWidget, 1, 1);

    this->_nameLabel = new QLabel(tr("Name"));
    this->_serverLabel = new QLabel(tr("Server"));
    this->_idLabel = new QLabel(tr("#0000"));
    this->_nameLabel->setStyleSheet("color: white");
    this->_serverLabel->setStyleSheet("color: white");
    this->_idLabel->setStyleSheet("color: white");
    this->_serverLabel->setFont(BoldFont);
    this->_nameLabel->setFont(BoldFont);
    this->_idLabel->setFont(ItalicFont);
    this->_nameLayout->addWidget(this->_nameLabel, 0, Qt::AlignCenter);
    this->_nameLayout->addWidget(this->_idLabel, 0, Qt::AlignCenter);
    this->_convLayout->addWidget(this->_serverLabel, 0, Qt::AlignCenter);

    //Deuxième partie

    this->_chatWidget = new QWidget();
    this->_connectWidget = new QWidget();
    this->_messageWidget = new QWidget();
    this->_vocalWidget = new QWidget();
    this->_chatWidget->setStyleSheet("background-color:rgb(100, 100, 100);");
    this->_connectWidget->setStyleSheet("background-color:rgb(80, 80, 80);");
    this->_messageWidget->setStyleSheet("background-color:rgb(80, 80, 80); margin: 0 15 0 15");
    this->_vocalWidget->setStyleSheet("background-color:rgb(60, 60, 60);");

    this->_chatLayout = new QGridLayout(this->_chatWidget);
    this->_connectLayout = new QVBoxLayout(this->_connectWidget);
    this->_messageLayout = new QHBoxLayout(this->_messageWidget);
    this->_vocalLayout = new QVBoxLayout(this->_vocalWidget);
    this->_connectLayout->setSpacing(0);
    this->_connectLayout->setMargin(0);
    this->_vocalButton = new QPushButton(tr("Join Vocal"));
    connect(this->_vocalButton, SIGNAL (released()), this, SLOT(SwapAudio()));
    this->_chatLayout->setColumnStretch(0, 5);
    this->_chatLayout->setColumnStretch(1, 5);
    this->_chatLayout->setAlignment(Qt::AlignTop);
    this->_vocalLayout->addWidget(this->_vocalButton, 0, Qt::AlignCenter);
    this->_vocalButton->setStyleSheet(".QPushButton{border: 1px solid black;border-radius: 10px;background-color: lightgreen;padding: 5 10 5 10}");
    this->_vocalButton->setFont(BasicFont);
    this->_vocalButton->setMinimumWidth(150);

    this->_chatScroll = new QScrollArea();
    this->_chatScroll->setWidgetResizable(true);
    this->_chatScroll->setWidget(this->_chatWidget);

    this->_interfaceLayout->addWidget(this->_chatScroll, 0, 0);
    this->_interfaceLayout->addWidget(this->_messageWidget, 1, 0);
    this->_interfaceLayout->addWidget(this->_connectWidget, 0, 1);
    this->_interfaceLayout->addWidget(this->_vocalWidget, 1, 1);

    this->_messageLine = new QLineEdit();
    this->_messageLine->setStyleSheet("border: 1px solid black;border-radius: 5px;background-color: rgb(100, 100, 100); color: white; padding: 2 10 2 10");
    this->_messageLine->setFont(BasicFont);
    this->_messageLine->setMinimumWidth(150);
    this->_messageButton = new QPushButton(tr("Send"));
    connect(this->_messageButton, SIGNAL (released()), this, SLOT(StockMessage()));
    this->_messageButton->setStyleSheet(".QPushButton{border: 1px solid black;border-radius: 10px;background-color: cyan;padding: 5 10 5 10}");
    this->_messageButton->setFont(BasicFont);
    this->_messageLayout->addWidget(this->_messageLine, 9);
    this->_messageLayout->addWidget(this->_messageButton, 1);

    this->_addUsersWidget = new QWidget();
    this->_addUsersWidget->setStyleSheet("background-color:rgb(80, 80, 80); margin: 0 15 0 15");
    this->_addUsersLayout = new QVBoxLayout(this->_addUsersWidget);
    this->_addUsersButton = new QPushButton(tr("Add User"));
    connect(this->_addUsersButton, SIGNAL (released()), this, SLOT(StockUser()));
    this->_addUsersButton->setStyleSheet(".QPushButton{border: 1px solid black;border-radius: 10px;background-color: rgb(200, 200, 200);padding: 5 10 5 10}");
    this->_addUsersButton->setFont(BasicFont);
    this->_addUsersLine = new QLineEdit();
    this->_addUsersLine->setStyleSheet("border: 1px solid black;border-radius: 5px;background-color: rgb(100, 100, 100); color: white; padding: 2 10 2 10");
    this->_addUsersLine->setFont(BasicFont);
    this->_addUsersLayout->addWidget(this->_addUsersButton, 0, Qt::AlignHCenter);
    this->_addUsersLayout->addWidget(this->_addUsersLine, 0);
    this->_connectLayout->addWidget(this->_addUsersWidget, 1, Qt::AlignTop);

    this->_listUsersWidget = new QWidget();
    this->_listUsersWidget->setStyleSheet("background-color:rgb(100, 100, 100); border: 0px");
    this->_listUsersLayout = new QVBoxLayout(this->_listUsersWidget);
    this->_listUsersLayout->setAlignment(Qt::AlignTop);
    this->_listUsersScroll = new QScrollArea();
    this->_listUsersScroll->setWidgetResizable(true);
    this->_listUsersScroll->setMinimumWidth(200);
    this->_listUsersScroll->setWidget(this->_listUsersWidget);
    this->_listUsersScroll->setStyleSheet("margin: 0 10 0 10; border: 0px");
    this->_connectLayout->addWidget(this->_listUsersScroll, 9);

    connect(&this->_login, SIGNAL(SendLogIn(const std::string &, const std::string &)), &this->_client, SLOT(GetLogIn(const std::string &, const std::string &)));
    connect(&this->_login, SIGNAL(SendSignIn(const std::string &, const std::string &)), &this->_client, SLOT(GetSignIn(const std::string &, const std::string &)));
    connect(&this->_client, SIGNAL(SendLogInId(const std::string &)), this, SLOT(GetLogInId(const std::string &)));
    connect(&this->_client, SIGNAL(SendSignInId(const std::string &)), this, SLOT(GetSignInId(const std::string &)));
    connect(&this->_client, SIGNAL(SendUpdate(const DataPackage &)), this, SLOT(GetUpdate(const DataPackage &)));
    connect(this, SIGNAL(SendMessage(const std::string &, const std::string &)), &this->_client, SLOT(GetMessage(const std::string &, const std::string &)));
    connect(this, SIGNAL(SendAddUsers(const std::string &, const std::string &)), &this->_client, SLOT(GetAddUsers(const std::string &, const std::string &)));
    connect(this, SIGNAL(SendAddConvUsers(const std::string &, const std::string &, const std::string &)), &this->_client, SLOT(GetAddConvUsers(const std::string &, const std::string &, const std::string &)));
    connect(this, SIGNAL(SendSwapServer(const std::string &)), &this->_client, SLOT(GetSwapServer(const std::string &)));
    connect(this, SIGNAL(SendConnectAudio(std::string &)), &this->_client, SLOT(GetConnectAudio(std::string &)));

    setLayout(this->_mainLayout);
    setWindowTitle(tr("Discord"));
    setWindowState(Qt::WindowMaximized);

    this->_login.show();
}

UserInter::~UserInter()
{
    
}

void UserInter::loopAudio()
{

}

void UserInter::SwapAudio()
{
    this->_AudioConnect = !this->_AudioConnect;

    if (this->_selectedServer == "0")
        return;

    if (!this->_AudioConnect) {
        this->_vocalButton->setStyleSheet(".QPushButton{border: 1px solid black;border-radius: 10px;background-color: lightgreen;padding: 5 10 5 10}");
        this->_vocalButton->setText("Join Vocal");
    } else {
        this->_vocalButton->setStyleSheet(".QPushButton{border: 1px solid black;border-radius: 10px;background-color: red;padding: 5 10 5 10}");
        this->_vocalButton->setText("Leave Vocal");
        this->loopAudio();
    }
}

void UserInter::GetUpdate(const DataPackage &package)
{
    const std::string chatId = package.getChatID();
    const std::vector<std::pair<std::string,std::string>> messages = package.getMessages();
    const std::vector<std::string> users = package.getUsers();
    std::string named = this->GenerateServerName(users);
    int create = -1;

    for (int i = 0; i < this->_listConvs.size(); i++) {
        create = (this->_listConvs[i].second == chatId) ? i : create;
    }
    if (this->_selectedServer == chatId || this->_selectedServer == "0") {
        if (create != -1) {
            this->_listConvs[create].first->setText(tr(named.c_str()));
            this->SetAllMessage(messages);
            this->SetConvUsers(users);
            this->_serverLabel->setText(tr(named.c_str()));
        } else {
            this->_selectedServer = chatId;
            this->AddConv(named, chatId, true);
            this->SetAllMessage(messages);
            this->SetConvUsers(users);
            this->_serverLabel->setText(tr(named.c_str()));
        }
    } else {
        if (create != -1) {
            this->_listConvs[create].first->setText(tr(named.c_str()));
        } else {
            this->_selectedServer = chatId;
            this->AddConv(named, chatId, false);
        }
    }
}

void UserInter::GetLogInId(const std::string &id)
{
    if (id == "Bad Request" || id == "0") {
        return;
    }
    if (id.size() == 1) {
        this->_nameId = "000" + id;
    } else if (id.size() == 2) {
        this->_nameId = "00" + id;
    } else {
        this->_nameId = "0" + id;
    }
    this->_name = this->_login.getName();
    this->_nameLabel->setText(tr(this->_name.c_str()));
    this->_idLabel->setText(tr(this->_nameId.c_str()));
    this->_login.hide();
    show();
}

void UserInter::GetSignInId(const std::string &id)
{
    if (id == "Bad Request" || id == "0") {
        return;
    }
    if (id.size() == 1) {
        this->_nameId = "000" + id;
    } else if (id.size() == 2) {
        this->_nameId = "00" + id;
    } else {
        this->_nameId = "0" + id;
    }
    this->_name = this->_login.getName();
    this->_nameLabel->setText(tr(this->_name.c_str()));
    this->_idLabel->setText(tr(this->_nameId.c_str()));
    this->_login.hide();
    show();
}

void UserInter::DeleteConvUser()
{
    QLayoutItem *child;
    
    while ((child = this->_listUsersLayout->takeAt(0)) != 0) {
        if (child->widget())
            delete child->widget();
        if (child->layout())
            delete child->widget();
        delete child;
    }
    this->_convUsers.clear();
}

void UserInter::DeleteChat()
{
    QLayoutItem *child;
    
    while ((child = this->_chatLayout->takeAt(0)) != 0) {
        if (child->widget())
            delete child->widget();
        if (child->layout())
            delete child->widget();
        delete child;
    }
    this->_chatMessages.clear();
}

void UserInter::AddConv(const std::string &named, const std::string &id, bool used)
{
    QFont BasicFont("Arial", 12, QFont::DemiBold);

    if (used) {
        for (int i = 0; i < this->_listConvs.size(); i++)
            this->_listConvs[i].first->setStyleSheet(".QPushButton{border: 1px solid black;border-radius: 10px;background-color: rgb(50, 50, 50);padding: 5 10 5 10}");
        this->_listConvs.push_back({new QPushButton(tr(named.c_str())), id});
        this->_listConvs.back().first->setStyleSheet(".QPushButton{border: 1px solid black;border-radius: 10px;background-color: rgb(200, 200, 200);padding: 5 10 5 10}");
    } else {
        this->_listConvs.push_back({new QPushButton(tr(named.c_str())), id});
        this->_listConvs.back().first->setStyleSheet(".QPushButton{border: 1px solid black;border-radius: 10px;background-color: rgb(50, 50, 50);padding: 5 10 5 10}");
    }
    this->_listConvs.back().first->setFont(BasicFont);
    connect(this->_listConvs.back().first, SIGNAL (released()), this, SLOT(SwapServer()));
    this->_friendsLayout->addWidget(this->_listConvs.back().first);
}

void UserInter::SetConvUsers(const std::vector<std::string> &users)
{
    QFont BasicFont("Arial", 12, QFont::DemiBold);

    this->DeleteConvUser();
    for (int i = 0; i < users.size(); i++) {
        this->_convUsers.push_back(new QLabel(tr(users[i].c_str())));
        this->_convUsers.back()->setStyleSheet("color: white");
        this->_convUsers.back()->setFont(BasicFont);
        this->_listUsersLayout->addWidget(this->_convUsers.back(), 0, Qt::AlignHCenter);
    }
}

void UserInter::SetAllMessage(const std::vector<std::pair<std::string,std::string>> &messages)
{
    this->DeleteChat();
    for (int i = 0; i < messages.size(); i++) {
        if (messages[i].first == this->_nameLabel->text().toLocal8Bit().data()) {
            this->AddMessage(messages[i].first, messages[i].second, 1);
        } else {
            this->AddMessage(messages[i].first, messages[i].second, 0);
        }
    }
}

const std::string UserInter::GenerateServerName(const std::vector<std::string> &users)
{
    std::string named;
    int i = 1;

    if (users.front() != this->_nameLabel->text().toLocal8Bit().data()) {
        named = users.front();
    } else if (users.size() > 1) {
        named = users[1];
        i = 2;
    }
    for (; i < users.size(); i++) {
        if (users[i] != this->_nameLabel->text().toLocal8Bit().data())
            named += ", " + users[i];
    }
    return named;
}

void UserInter::StockAddUser()
{
    std::string tmp(this->_addFriendsLine->text().toLocal8Bit().data());
    std::string bis;
    int pos = tmp.find('#');

    QFont BasicFont("Arial", 12, QFont::DemiBold);

    if (pos != tmp.npos && tmp.size() > 5 && tmp.substr(pos + 1).size() == 4) {
        bis = tmp.substr(pos + 1);
        for (int i = 0; i < 4; i++, tmp.pop_back()) {
            if (!std::isdigit(tmp.back())) {
                QMessageBox::information(
                    this,
                    tr("Warning"),
                    tr("name must be:\nName#0000")
                );
                return;
            }
        }
        tmp.pop_back();
        emit this->SendAddUsers(tmp, bis);
        this->_addFriendsLine->setText("");
    } else {
        QMessageBox::information(
            this,
            tr("Warning"),
            tr("name must be:\nName#0000")
        );
    }
}

void UserInter::SwapServer()
{
    QObject *obj = QObject::sender();
    int res = 0;

    if (this->_AudioConnect) {
        this->SwapAudio();
    }

    for (int i = 0; i < this->_listConvs.size(); i++) {
        if (this->_listConvs[i].first == obj) {
            res = i;
            this->_listConvs[i].first->setStyleSheet(".QPushButton{border: 1px solid black;border-radius: 10px;background-color: rgb(200, 200, 200);padding: 5 10 5 10}");
        } else {
            this->_listConvs[i].first->setStyleSheet(".QPushButton{border: 1px solid black;border-radius: 10px;background-color: rgb(50, 50, 50);padding: 5 10 5 10}");
        }
    }
    this->_selectedServer = this->_listConvs[res].second;
    emit this->SendSwapServer(this->_selectedServer);
}

void UserInter::StockUser()
{
    std::string tmp(this->_addUsersLine->text().toLocal8Bit().data());
    std::string bis;
    int pos = tmp.find('#');

    if (pos != tmp.npos && tmp.size() > 5 && tmp.substr(pos + 1).size() == 4) {
        bis = tmp.substr(pos + 1);
        for (int i = 0; i < 4; i++, tmp.pop_back()) {
            if (!std::isdigit(tmp.back())) {
                QMessageBox::information(
                    this,
                    tr("Warning"),
                    tr("name must be:\nName#0000")
                );
                return;
            }
        }
        tmp.pop_back();
        emit this->SendAddConvUsers(this->_selectedServer, bis, tmp);
        this->_addUsersLine->setText("");
    } else {
        QMessageBox::information(
            this,
            tr("Warning"),
            tr("name must be:\nName#0000")
        );
    }
}

void UserInter::StockMessage()
{
    if (this->_messageLine->text().isEmpty()) {
        QMessageBox::information(
            this,
            tr("Warning"),
            tr("Message can't be empty !")
        );
    } else {
        emit this->SendMessage(this->_selectedServer.c_str(), this->_messageLine->text().toLocal8Bit().data());
    }
    this->_messageLine->setText("");
}

void UserInter::AddMessage(const std::string &name, const std::string &message, const bool &side)
{
    QFont BoldFont("Arial", 14, QFont::Bold);
    QFont BasicFont("Arial", 12, QFont::DemiBold);

    this->_chatMessages.push_back(new QWidget());
    this->_chatMessages.back()->setMaximumHeight(50);

    QVBoxLayout *layout = new QVBoxLayout(this->_chatMessages.back());
    QLabel *nameLabel = new QLabel(tr(name.c_str()));
    nameLabel->setFont(BoldFont);
    QLabel *messageLabel = new QLabel(tr(message.c_str()));
    messageLabel->setFont(BasicFont);

    if (!side) {
        this->_chatMessages.back()->setStyleSheet(".QWidget{border: 1px solid black;border-radius: 10px;background-color: lightgray;}.QLabel{background-color: lightgray}");
        layout->addWidget(nameLabel, 6, Qt::AlignLeft);
        layout->addWidget(messageLabel, 4, Qt::AlignLeft);
        this->_chatLayout->addWidget(this->_chatMessages.back(), this->_chatLayout->count(), 0, Qt::AlignLeft);
    } else {
        this->_chatMessages.back()->setStyleSheet(".QWidget{border: 1px solid black;border-radius: 10px;background-color: lightblue;}.QLabel{background-color: lightblue}");
        layout->addWidget(nameLabel, 6, Qt::AlignRight);
        layout->addWidget(messageLabel, 4, Qt::AlignRight);
        this->_chatLayout->addWidget(this->_chatMessages.back(), this->_chatLayout->count(), 1, Qt::AlignRight);
    }
}