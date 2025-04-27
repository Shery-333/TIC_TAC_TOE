#ifndef SIGN_IN_H
#define SIGN_IN_H

#include <QDialog>

namespace Ui {
class Dialog; // Matches <class>Dialog</class> in signin.ui
}

class SignIn : public QDialog
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = nullptr);
    ~SignIn();

private slots:
    void on_pushButton_clicked(); // Slot for Login button
    void on_pushButton_2_clicked(); // Slot for Sign_In button

private:
    Ui::Dialog *ui; // Use Ui::Dialog instead of Ui::SignIn
};

#endif // SIGN_IN_H
