#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setupDatabase();  // Declare the setupDatabase function here
private slots:
    void on_pushButton_register_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    //QSqlDatabase sqlitedb;
};
#endif // MAINWINDOW_H
