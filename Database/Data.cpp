/*
** EPITECH PROJECT, 2020
**   
** File description:
** data
*/

#include "Data.hpp"

Data::Data() : _db(0)
{
    this->_err = sqlite3_open("../database.db", &this->_db);
    this->createDatabase();
    if (this->_err != SQLITE_OK)
        throw Error("Constructor Database");
    this->_update = false;
}

Data::~Data()
{
    sqlite3_close(this->_db);
}

int Data::mCallback(int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++) {
        this->_tables.push_back(argv[i]);
    }
    return 0;
}

int Data::callback(void *data, int argc, char **argv, char **azColName)
{
    return reinterpret_cast<Data *>(data)->mCallback(argc, argv, azColName);
}

void Data::createDatabase()
{
    char *errMsg = 0;
    this->_str = "CREATE TABLE IF NOT EXISTS User("  \
        "UserID INTEGER PRIMARY KEY NOT NULL," \
        "Name TEXT NOT NULL," \
        "Password TEXT NOT NULL);" \

        "CREATE TABLE IF NOT EXISTS Message("  \
        "MessageID INTEGER PRIMARY KEY NOT NULL," \
        "Content TEXT NOT NULL," \
        "UserID INTEGER NOT NULL," \
        "FOREIGN KEY(UserID) REFERENCES User(UserID));" \
        
        "CREATE TABLE IF NOT EXISTS Chat("  \
        "ChatID INTEGER PRIMARY KEY NOT NULL," \
        "UserID INTEGER NOT NULL," \
        "User2ID INTEGER NOT NULL," \
        "User3ID INTEGER," \
        "User4ID INTEGER," \
        "ChatMessageID INTEGER NOT NULL," \
        "FOREIGN KEY(UserID) REFERENCES User(UserID)," \
        "FOREIGN KEY(User2ID) REFERENCES User(UserID)," \
        "FOREIGN KEY(User3ID) REFERENCES User(UserID)," \
        "FOREIGN KEY(User4ID) REFERENCES User(UserID));" \

        "CREATE TABLE IF NOT EXISTS ChatMessage("  \
        "ChatMessageID INTEGER NOT NULL," \
        "MessageID INTEGER," \
        "FOREIGN KEY(MessageID) REFERENCES Message(MessageID));";

    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), NULL, NULL, &errMsg);
    if (this->_err != SQLITE_OK)
        throw Error(errMsg);
    else
        std::cout << "Database successfully initialized" << std::endl;
    sqlite3_free(errMsg);
}

std::vector<std::string> Data::getAllConvOfUser(const std::string &userId)
{
    char *errMsg = new char[512];

    this->_tables.clear();
    std::cout << "USER ID => " << userId << std::endl;
    this->_str = "SELECT chatID FROM Chat WHERE UserID=" + userId + " OR "\
    "User2ID=" + userId + " OR " \
    "User3ID=" + userId  + " OR " \
    "User4ID=" + userId + ";";
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), &Data::callback, this, &errMsg);
    if (this->_err != SQLITE_OK)
        throw Error(errMsg);
    sqlite3_free(errMsg);

    return this->_tables;
}


std::string Data::loginUser(const std::string &name, const std::string &password)
{
    char *errMsg = new char[512];

    this->_tables.clear();
    this->_str = "SELECT UserID FROM User WHERE Name='" + name + "' AND Password='" + password + "'";
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), &Data::callback, this, &errMsg);
    if (this->_err != SQLITE_OK)
        throw Error(errMsg);
    sqlite3_free(errMsg);
    if (this->_tables.empty())
        return "";
    return this->_tables[0];
}

bool Data::isUserExist(const std::string &name, const std::string &id)
{
    char *errMsg = new char[512];

    this->_tables.clear();
    this->_str = "SELECT * FROM User WHERE Name='" + name + "' AND UserID='" + id + "'";
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), &Data::callback, this, &errMsg);
    if (this->_err != SQLITE_OK)
        throw Error(errMsg);
    sqlite3_free(errMsg);
    if (this->_tables.empty())
        return false;
    return true;
}

bool Data::isUserExist(const std::string &id)
{
    char *errMsg = new char[512];

    this->_tables.clear();
    this->_str = "SELECT * FROM User WHERE UserID=" + id + "";
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), &Data::callback, this, &errMsg);
    if (this->_err != SQLITE_OK)
        throw Error(errMsg);
    sqlite3_free(errMsg);
    if (this->_tables.empty())
        return false;
    return true;
}

std::string Data::createUser(const std::string &name, const std::string &password)
{
    char *errMsg = new char[512];

    if (loginUser(name, password) != "") {
        std::cout << "User already exist" << std::endl;
        return "";
    }
    this->_str = "INSERT INTO User(Name, Password) " \
                "VALUES ('" + name + "', '" + password + "');";
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), NULL, NULL, &errMsg);
    if (this->_err != SQLITE_OK)
        throw Error(errMsg);

    this->_tables.clear();
    this->_str = "SELECT MAX(UserID) FROM User";
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), &Data::callback, this, &errMsg);
    if (this->_err != SQLITE_OK)
        throw Error(errMsg);
    sqlite3_free(errMsg);
    return this->_tables[0];
}

std::vector<std::pair<std::string,std::string>> Data::getAllMessageOfConv(const std::string &chatID)
{
    char *errMsg = new char[512];

    std::vector<std::pair<std::string,std::string>> message;

    this->_tables.clear();
    this->_str = "SELECT User.Name, Message.Content FROM Message, ChatMessage, User " \
    "WHERE Message.MessageID=ChatMessage.MessageID AND Message.UserID=User.UserID AND ChatMessageID=" + chatID;
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), &Data::callback, this, &errMsg);
    if (this->_err != SQLITE_OK)
        throw Error(errMsg);
    
    for (size_t i = 0; i < this->_tables.size(); i +=2 ) {
        message.push_back(std::make_pair(this->_tables[i], this->_tables[i+1]));
    }
    sqlite3_free(errMsg);
    return message;
}

std::vector<std::string> &Data::getAllUserName()
{
    char *errMsg = new char[512];

    this->_tables.clear();
    this->_str = "SELECT Name FROM User";
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), &Data::callback, this, &errMsg);
    if (this->_err != SQLITE_OK)
        throw Error(errMsg);
    sqlite3_free(errMsg);
    return this->_tables;
}

std::string Data::getNameById(const std::string &id)
{
    char *errMsg = new char[512];

    this->_tables.clear();
    this->_str = "SELECT Name FROM User WHERE UserID=" + id;
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), &Data::callback, this, &errMsg);
    if (this->_err != SQLITE_OK)
        throw Error(errMsg);
    sqlite3_free(errMsg);
    return this->_tables.empty() ? "" : this->_tables[0];
}

std::string Data::createChatGroup(const std::string &senderId, const std::string &receiverID, const std::string &receiverName)
{
    char *errMsg = new char[512];

    if (!this->isUserExist(receiverName, receiverID)) {
        std::cout << "ERROR CHAT GROUP" << std::endl;
        return "";
    }

    this->_tables.clear();
    this->_str = "SELECT COALESCE(MAX(`ChatID`), 0) FROM Chat";
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), &Data::callback, this, &errMsg);
    if (this->_err != SQLITE_OK)
        std::cerr << errMsg << std::endl;
    
    std::string chatID = (this->_tables[0] == "0" ? "1" : this->_tables[0]);
    this->_str = "INSERT INTO ChatMessage(ChatMessageID, MessageID) " \
                "VALUES (" + (this->_tables[0] == "0" ? "1" : std::to_string(std::stoi(this->_tables[0]) + 1)) + ", null);";
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), &Data::callback, this, &errMsg);
    if (this->_err != SQLITE_OK)
        std::cerr << errMsg << std::endl;
    this->_str = "INSERT INTO Chat(UserID, User2ID, ChatMessageID) " \
                "VALUES (" + senderId + ", " + receiverID + ", "  + (this->_tables[0] == "0" ? "1" : std::to_string(std::stoi(this->_tables[0]) + 1)) + ");";
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), &Data::callback, this, &errMsg);
    if (this->_err != SQLITE_OK)
        throw Error(errMsg);
    sqlite3_free(errMsg);
    return (this->_tables[0] == "0" ? "1" : std::to_string(std::stoi(this->_tables[0]) + 1));
}

bool Data::addMessage(const std::string &chatID, const std::string &senderID, const std::string &content)
{
    char *errMsg = new char[512];

    if (!this->isUserExist(senderID))
        return false;
    this->_str = "INSERT INTO Message(Content, UserID) " \
                "VALUES ('" + content + "', " + senderID + ");";
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), NULL, NULL, &errMsg);
    if (this->_err != SQLITE_OK) {
        throw Error(errMsg);
        return false;
    }

    this->_tables.clear();
    this->_str = "SELECT MAX(MessageID) FROM Message";
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), &Data::callback, this, &errMsg);
    if (this->_err != SQLITE_OK) {
        throw Error(errMsg);
        return false;
    }

    this->_str = "INSERT or IGNORE INTO ChatMessage(ChatMessageID, MessageID) " \
                "VALUES (" + chatID + ", " + this->_tables[0] + ");";
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), &Data::callback, this, &errMsg);
    if (this->_err != SQLITE_OK) {
        std::cerr << errMsg << std::endl;
        return false;
    }
    sqlite3_free(errMsg);
    return true;
}

std::vector<std::pair<std::string, std::string>> Data::getAllUsersOfConv(const std::string &chatID)
{
    char *errMsg = new char[512];
    std::vector<std::pair<std::string, std::string>> users;

    this->_tables.clear();
    this->_str = "SELECT User.Name, User.UserID FROM Chat, User WHERE " \
    "User.UserID=Chat.UserID AND ChatID=" + chatID + \
    " OR User.UserID=Chat.User2ID AND ChatID=" + chatID + \
    " OR User.UserID=Chat.User3ID AND ChatID=" + chatID + \
    " OR User.UserID=Chat.User4ID AND ChatID=" + chatID;

    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), &Data::callback, this, &errMsg);
    if (this->_err != SQLITE_OK)
       std::cerr << errMsg << std::endl;
    for (size_t i = 0; i < this->_tables.size(); i += 2) {
        users.push_back(std::make_pair(this->_tables[i], this->_tables[i + 1]));
    }
    return users;
}

std::vector<std::string> Data::getAllUsers()
{
    char *errMsg = new char[512];

    this->_tables.clear();
    this->_str = "SELECT Name FROM User";
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), &Data::callback, this, &errMsg);
    if (this->_err != SQLITE_OK)
       std::cerr << errMsg << std::endl;
    sqlite3_free(errMsg);
    return this->_tables;
}

bool Data::addUserInConv(const std::string &chatID, const std::string &userId, const std::string &name)
{
    if (!this->isUserExist(name, userId)) {
        std::cout << "ERROR USER DONT EXIST" << std::endl;
        return false;
    }

    char *errMsg = new char[512];

    this->_tables.clear();
    this->_str = "UPDATE Chat SET UserID= case when UserID is null then " + userId + " else UserID end, " \
    "User2ID= case when UserID != " + userId + " AND User2ID is null then " + userId + " else User2ID end, " \
    "User3ID= case when User2ID != " + userId  + " AND User3ID is null then " + userId + " else User3ID end, " \
    "User4ID= case when User3ID != " + userId  + " AND User3ID is null then " + userId + " else User4ID end; ";
    this->_err = sqlite3_exec(this->_db, this->_str.c_str(), &Data::callback, this, &errMsg);
    if (this->_err != SQLITE_OK) {
       std::cerr << errMsg << std::endl;
       return false;
    }
    sqlite3_free(errMsg);
    this->_update = true;
    return true;
}