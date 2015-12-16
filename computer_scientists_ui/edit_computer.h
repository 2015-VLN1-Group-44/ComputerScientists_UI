#ifndef EDIT_COMPUTER_H
#define EDIT_COMPUTER_H

#include <QDialog>
#include "computer_service.h"
#include "edit_computer.h"


namespace Ui {
class Edit_computer;
}

class Edit_computer : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_computer(int &id, QWidget *parent = 0);
    ~Edit_computer();

private slots:
    void on_save_button_clicked();
    void on_cancel_button_clicked();

private:
    Ui::Edit_computer *ui;

    int id;
    Computers temp;
    Computer_service computer_service;
};

#endif // EDIT_COMPUTER_H
