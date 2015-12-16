#ifndef ADD_COMPUTER_H
#define ADD_COMPUTER_H

#include <QDialog>
#include "computer_service.h"
#include "scientist_service.h"

namespace Ui {
class Add_computer;
}

class Add_computer : public QDialog
{
    Q_OBJECT

public:
    explicit Add_computer(QWidget *parent = 0);
    ~Add_computer();

private slots:
    void on_add_button_clicked();
    void on_cancel_button_clicked();

    // void on_check_was_built_toggled(bool checked);

private:
    Ui::Add_computer *ui;
    Computer_service computer_service;
};

#endif // ADD_COMPUTER_H
