 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QCryptographicHash>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)


 , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    setupDatabase();  // Call to setup the database
}

MainWindow::~MainWindow() {
    // Destructor code
}

void MainWindow::setupDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
    } else {
        qDebug() << "Database: connection ok";

        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS users ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "username TEXT UNIQUE,"
                   "password TEXT"
                   ")");
    }
}

void MainWindow::on_pushButton_register_clicked(){
    QString username = ui->username->text();
    QString password = ui->password->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Register", "Please fill all fields.");
        return;
    }

    // Hash the password
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", hashedPassword.toHex());

    if (query.exec()) {

    QMessageBox::information(this, "Success", "Registration successful!");

    } else {

    QMessageBox::information(this, "Database Error", "Registration failed");
    }
}

