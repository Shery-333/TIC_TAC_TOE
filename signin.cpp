#include "signin.h"
#include "ui_signin.h" // Generated from signin.ui
#include <QMessageBox>
#include <QSqlQuery>
#include <QCryptographicHash>

SignIn::SignIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog) // Use Ui::Dialog
{
    ui->setupUi(this);
    // Optional: Set password field to hide input
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::on_pushButton_clicked()
{
    // Handle Login button click
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login", "Please fill all fields.");
        return;
    }

    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec()) {
        if (query.next()) {
            QString storedPassword = query.value(0).toString();
            if (storedPassword == hashedPassword.toHex()) {
                QMessageBox::information(this, "Login", "Login successful!");
                this->accept();
            } else {
                QMessageBox::warning(this, "Login", "Wrong password.");
            }
        } else {
            QMessageBox::warning(this, "Login", "Username does not exist.");
        }
    } else {
        QMessageBox::warning(this, "Login", "Login query failed.");
    }
}

void SignIn::on_pushButton_2_clicked()
{
    // Handle Sign_In button click
    // Add logic to open a sign-up dialog
    this->accept();
}
