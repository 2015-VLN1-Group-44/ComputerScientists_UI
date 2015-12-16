#ifndef ADD_SCIENTIST_H
#define ADD_SCIENTIST_H

#include <QDialog>
#include "scientist.h"
#include "scientist_service.h"
#include "constants.h"

namespace Ui {
class Add_scientist;
}

class Add_scientist : public QDialog
{
    Q_OBJECT

public:
    explicit Add_scientist(QWidget *parent = 0);
    ~Add_scientist();

private slots:
    void on_add_button_clicked(); 
    void on_cancel_button_clicked();
    void on_living_toggled(bool checked);

private:
    Ui::Add_scientist *ui;
    Scientist_service scientist_service;
};

#endif // ADD_SCIENTIST_H
