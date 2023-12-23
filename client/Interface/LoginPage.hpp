/*
** EPITECH PROJECT, 2020
**   
** File description:
** LoginPage
*/

#ifndef LOGINPAGE_HPP_
#define LOGINPAGE_HPP_

#include <stdio.h>
#include <iostream>
#include <memory>
#include <tuple>
#include <vector>
#include <opus/opus.h>
#include <portaudio.h>
#include <QtCore/QCoreApplication>
#include <QtWidgets/QApplication>
#include <QtCore/QSignalMapper>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>

class LoginPage : public QWidget {
    Q_OBJECT

    public:
        LoginPage(QWidget *parent = nullptr);
        ~LoginPage();
        const std::string &getName() const;

    protected:

    signals:
        void SendLogIn(const std::string &name, const std::string &pass);
        void SendSignIn(const std::string &name, const std::string &pass);

    private slots:
        void ClickLogIn();
        void ClickSignIn();

    private:
        std::string _name;

        QHBoxLayout *_mainLayout;

        QWidget *_connectionWidget;
        QVBoxLayout *_connectionLayout;
        QLabel *_connectionLabel;
        QLabel *_connectionNameLabel;
        QLineEdit *_connectionName;
        QLabel *_connectionPassLabel;
        QLineEdit *_connectionPass;
        QPushButton *_connectionButton;

        QWidget *_signInWidget;
        QVBoxLayout *_signInLayout;
        QLabel *_signInLabel;
        QLabel *_signInNameLabel;
        QLineEdit *_signInName;
        QLabel *_signInFirstPassLabel;
        QLineEdit *_signInFirstPass;
        QLabel *_signInSecondPassLabel;
        QLineEdit *_signInSecondPass;
        QPushButton *_signInButton;
};

#endif /* !LOGINPAGE_HPP_ */
