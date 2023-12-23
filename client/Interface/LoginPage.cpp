/*
** EPITECH PROJECT, 2020
**   
** File description:
** LoginPage
*/

#include "LoginPage.hpp"

LoginPage::LoginPage(QWidget *parent) : QWidget(parent)
{
    this->_mainLayout = new QHBoxLayout(this);
    setStyleSheet("background-color: rgb(50, 50, 50)");
    setMaximumWidth(750);
    setMaximumHeight(425);

    QFont BasicFont("Arial", 13, QFont::DemiBold);
    QFont BoldFont("Arial", 14, QFont::Bold);
    QFont ItalicFont("Arial", 12, QFont::StyleOblique, QFont::DemiBold);

    this->_connectionWidget = new QWidget();
    this->_connectionLayout = new QVBoxLayout(this->_connectionWidget);
    this->_connectionLayout->setAlignment(Qt::AlignVCenter);
    this->_connectionWidget->setStyleSheet(".QWidget{border: 2px solid black;border-radius: 30px;background-color: rgb(80, 80, 80);margin: 20px}.QLabel{background-color: rgb(80, 80, 80)}.QPushButton{border: 2px solid black;border-radius: 5px; background-color: cyan; padding: 5 10 5 10}.QLineEdit{border: 1px solid black;border-radius: 5px; color: white; padding: 2 10 2 10}");
    this->_connectionWidget->setMinimumWidth(275);
    this->_connectionWidget->setMaximumWidth(350);

    this->_connectionLabel = new QLabel(tr("connection"));
    this->_connectionLabel->setStyleSheet("border: 2px solid black;border-radius: 5px;background-color: lightgray; padding: 2 10 2 10");
    this->_connectionLabel->setFont(BoldFont);
    this->_connectionNameLabel = new QLabel(tr("name:"));
    this->_connectionNameLabel->setStyleSheet("color: rgb(200, 200, 200)");
    this->_connectionNameLabel->setFont(ItalicFont);
    this->_connectionName = new QLineEdit();
    this->_connectionName->setFont(BasicFont);
    this->_connectionName->setMaximumWidth(400);
    this->_connectionName->setMinimumWidth(100);
    this->_connectionPassLabel = new QLabel(tr("password:"));
    this->_connectionPassLabel->setStyleSheet("color: rgb(200, 200, 200)");
    this->_connectionPassLabel->setFont(ItalicFont);
    this->_connectionPass = new QLineEdit();
    this->_connectionPass->setEchoMode(QLineEdit::Password);
    this->_connectionPass->setFont(BasicFont);
    this->_connectionPass->setMaximumWidth(400);
    this->_connectionPass->setMinimumWidth(100);
    this->_connectionButton = new QPushButton(tr("Log in"));
    this->_connectionButton->setFont(BasicFont);
    connect(this->_connectionButton, SIGNAL (released()), this, SLOT(ClickLogIn()));

    this->_connectionLayout->addWidget(this->_connectionLabel, 0, Qt::AlignHCenter);
    this->_connectionLayout->addWidget(this->_connectionNameLabel, 0, Qt::AlignHCenter);
    this->_connectionLayout->addWidget(this->_connectionName, 0, Qt::AlignHCenter);
    this->_connectionLayout->addWidget(this->_connectionPassLabel, 0, Qt::AlignHCenter);
    this->_connectionLayout->addWidget(this->_connectionPass, 0, Qt::AlignHCenter);
    this->_connectionLayout->addWidget(this->_connectionButton, 0, Qt::AlignHCenter);

    this->_signInWidget = new QWidget();
    this->_signInLayout = new QVBoxLayout(this->_signInWidget);
    this->_signInLayout->setAlignment(Qt::AlignVCenter);
    this->_signInWidget->setStyleSheet(".QWidget{border: 2px solid black;border-radius: 30px;background-color: rgb(80, 80, 80);margin: 20px}.QLabel{background-color: rgb(80, 80, 80)}.QPushButton{border: 2px solid black;border-radius: 5px; background-color: lightgreen; padding: 5 10 5 10}.QLineEdit{border: 1px solid black;border-radius: 5px; color: white; padding: 2 10 2 10}");
    this->_signInWidget->setMinimumWidth(275);
    this->_signInWidget->setMaximumWidth(350);

    this->_signInLabel = new QLabel(tr("Register"));
    this->_signInLabel->setStyleSheet("border: 2px solid black;border-radius: 5px;background-color: lightgray; padding: 2 10 2 10");
    this->_signInLabel->setFont(BoldFont);
    this->_signInNameLabel = new QLabel(tr("name:"));
    this->_signInNameLabel->setStyleSheet("color: rgb(200, 200, 200)");
    this->_signInNameLabel->setFont(ItalicFont);
    this->_signInName = new QLineEdit();
    this->_signInName->setFont(BasicFont);
    this->_signInName->setMaximumWidth(400);
    this->_signInName->setMinimumWidth(100);
    this->_signInFirstPassLabel = new QLabel(tr("password:"));
    this->_signInFirstPassLabel->setStyleSheet("color: rgb(200, 200, 200)");
    this->_signInFirstPassLabel->setFont(ItalicFont);
    this->_signInFirstPass = new QLineEdit();
    this->_signInFirstPass->setEchoMode(QLineEdit::Password);
    this->_signInFirstPass->setFont(BasicFont);
    this->_signInFirstPass->setMaximumWidth(400);
    this->_signInFirstPass->setMinimumWidth(100);
    this->_signInSecondPassLabel = new QLabel(tr("repeat password:"));
    this->_signInSecondPassLabel->setStyleSheet("color: rgb(200, 200, 200)");
    this->_signInSecondPassLabel->setFont(ItalicFont);
    this->_signInSecondPass = new QLineEdit();
    this->_signInSecondPass->setEchoMode(QLineEdit::Password);
    this->_signInSecondPass->setFont(BasicFont);
    this->_signInSecondPass->setMaximumWidth(400);
    this->_signInSecondPass->setMinimumWidth(100);
    this->_signInButton = new QPushButton(tr("Sign in"));
    this->_signInButton->setFont(BasicFont);
    connect(this->_signInButton, SIGNAL (released()), this, SLOT(ClickSignIn()));

    this->_signInLayout->addWidget(this->_signInLabel, 0, Qt::AlignHCenter);
    this->_signInLayout->addWidget(this->_signInNameLabel, 0, Qt::AlignHCenter);
    this->_signInLayout->addWidget(this->_signInName, 0, Qt::AlignHCenter);
    this->_signInLayout->addWidget(this->_signInFirstPassLabel, 0, Qt::AlignHCenter);
    this->_signInLayout->addWidget(this->_signInFirstPass, 0, Qt::AlignHCenter);
    this->_signInLayout->addWidget(this->_signInSecondPassLabel, 0, Qt::AlignHCenter);
    this->_signInLayout->addWidget(this->_signInSecondPass, 0, Qt::AlignHCenter);
    this->_signInLayout->addWidget(this->_signInButton, 0, Qt::AlignHCenter);

    this->_mainLayout->addWidget(this->_connectionWidget, 5, Qt::AlignVCenter);
    this->_mainLayout->addWidget(this->_signInWidget, 5, Qt::AlignVCenter);

    setLayout(this->_mainLayout);
    setWindowTitle(tr("Discord"));
}

LoginPage::~LoginPage()
{
}

void LoginPage::ClickLogIn()
{
    if (this->_connectionName->text().isEmpty()) {
        this->_connectionName->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
        this->_connectionPass->setStyleSheet("border: 1px solid gray;border-radius: 5px; padding: 2 10 2 10");
        QMessageBox::information(
            this,
            tr("Warning"),
            tr("Name can't be empty")
        );
        return;
    } else if (this->_connectionPass->text().isEmpty()) {
        this->_connectionPass->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
        this->_connectionName->setStyleSheet("border: 1px solid gray;border-radius: 5px; padding: 2 10 2 10");
        QMessageBox::information(
            this,
            tr("Warning"),
            tr("Password can't be empty")
        );
        return;
    } else if (this->_connectionName->text().size() > 12) {
        this->_connectionName->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
        this->_connectionPass->setStyleSheet("border: 1px solid gray;border-radius: 5px; padding: 2 10 2 10");
        QMessageBox::information(
            this,
            tr("Warning"),
            tr("Maximum character for name is 12")
        );
        return;
    } else if (this->_connectionPass->text().size() > 21) {
        this->_connectionName->setStyleSheet("border: 1px solid gray;border-radius: 5px; padding: 2 10 2 10");
        this->_connectionPass->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
        QMessageBox::information(
            this,
            tr("Warning"),
            tr("Maximum character for password is 21")
        );
        return;
    }
    for (int i = 0; i < this->_connectionName->text().size(); i++) {
        if (this->_connectionName->text()[i].cell() == 124 || this->_connectionName->text()[i].cell() == 32) {
            this->_connectionName->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
            this->_connectionPass->setStyleSheet("border: 1px solid gray;border-radius: 5px; padding: 2 10 2 10");
            QMessageBox::information(
                this,
                tr("Warning"),
                tr("Name can't contain SPACE or '|'")
            );
            return;
        }
    }
    for (int i = 0; i < this->_connectionPass->text().size(); i++) {
        if (this->_connectionPass->text()[i].cell() == 124 || this->_connectionPass->text()[i].cell() == 32) {
            this->_connectionName->setStyleSheet("border: 1px solid gray;border-radius: 5px; padding: 2 10 2 10");
            this->_connectionPass->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
            QMessageBox::information(
                this,
                tr("Warning"),
                tr("Password can't contain SPACE or '|'")
            );
            return;
        }
    }
    this->_name = this->_connectionName->text().toLocal8Bit().data();
    emit this->SendLogIn(this->_connectionName->text().toLocal8Bit().data(), this->_connectionPass->text().toLocal8Bit().data());
    this->_connectionName->setText("");
    this->_connectionPass->setText("");
}

void LoginPage::ClickSignIn()
{
    if (this->_signInName->text().isEmpty()) {
        this->_signInName->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
        this->_signInFirstPass->setStyleSheet("border: 1px solid gray;border-radius: 5px; padding: 2 10 2 10");
        this->_signInSecondPass->setStyleSheet("border: 1px solid gray;border-radius: 5px; padding: 2 10 2 10");
        QMessageBox::information(
            this,
            tr("Warning"),
            tr("Name can't be empty")
        );
        return;
    } else if (this->_signInFirstPass->text().isEmpty() && this->_signInSecondPass->text().isEmpty()) {
        this->_signInName->setStyleSheet("border: 1px solid gray;border-radius: 5px; padding: 2 10 2 10");
        this->_signInFirstPass->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
        this->_signInSecondPass->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
        QMessageBox::information(
            this,
            tr("Warning"),
            tr("Password can't be empty")
        );
        return;
    } else if (this->_signInFirstPass->text() != this->_signInSecondPass->text()) {
        this->_signInName->setStyleSheet("border: 1px solid gray;border-radius: 5px; padding: 2 10 2 10");
        this->_signInFirstPass->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
        this->_signInSecondPass->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
        QMessageBox::information(
            this,
            tr("Warning"),
            tr("Mismatch Password")
        );
        return;
    } else if (this->_signInName->text().size() > 12) {
        this->_signInName->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
        this->_signInFirstPass->setStyleSheet("border: 1px solid gray;border-radius: 5px; padding: 2 10 2 10");
        this->_signInSecondPass->setStyleSheet("border: 1px solid gray;border-radius: 5px; padding: 2 10 2 10");
        QMessageBox::information(
            this,
            tr("Warning"),
            tr("Maximum character for name is 12")
        );
        return;
    } else if (this->_signInFirstPass->text().size() > 21) {
        this->_signInName->setStyleSheet("border: 1px solid gray;border-radius: 5px; padding: 2 10 2 10");
        this->_signInFirstPass->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
        this->_signInSecondPass->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
        QMessageBox::information(
            this,
            tr("Warning"),
            tr("Maximum character for password is 21")
        );
        return;
    }
    for (int i = 0; i < this->_signInName->text().size(); i++) {
        if (this->_signInName->text()[i].cell() == 124 || this->_signInName->text()[i].cell() == 32) {
            this->_signInName->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
            this->_signInFirstPass->setStyleSheet("border: 1px solid gray;border-radius: 5px; padding: 2 10 2 10");
            this->_signInSecondPass->setStyleSheet("border: 1px solid gray;border-radius: 5px; padding: 2 10 2 10");
            QMessageBox::information(
                this,
                tr("Warning"),
                tr("Name can't contain SPACE or '|'")
            );
            return;
        }
    }
    for (int i = 0; i < this->_signInFirstPass->text().size(); i++) {
        if (this->_signInFirstPass->text()[i].cell() == 124 || this->_signInFirstPass->text()[i].cell() == 32) {
            this->_signInName->setStyleSheet("border: 1px solid gray;border-radius: 5px; padding: 2 10 2 10");
            this->_signInFirstPass->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
            this->_signInSecondPass->setStyleSheet("border: 2px solid red;border-radius: 5px; padding: 2 10 2 10");
            QMessageBox::information(
                this,
                tr("Warning"),
                tr("Password can't contain SPACE or '|'")
            );
            return;
        }
    }
    this->_name = this->_signInName->text().toLocal8Bit().data();
    emit this->SendSignIn(this->_signInName->text().toLocal8Bit().data(), this->_signInFirstPass->text().toLocal8Bit().data());
    this->_signInName->setText("");
    this->_signInFirstPass->setText("");
    this->_signInSecondPass->setText("");
}

const std::string &LoginPage::getName() const
{
    return this->_name;
}
