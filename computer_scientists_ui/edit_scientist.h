#ifndef EDIT_SCIENTIST_H
#define EDIT_SCIENTIST_H

#include <QDialog>
#include "scientist_service.h"
#include "constants.h"
#include <QMessageBox>

namespace Ui {
class edit_scientist;
}

class edit_scientist : public QDialog
{
    Q_OBJECT

public:
    explicit edit_scientist(QWidget *parent = 0);
    ~edit_scientist();

    void set_id(const int &id);

private slots:
    void on_save_button_clicked();

    void on_cancel_button_clicked();

private:
    Ui::edit_scientist *ui;
    Scientist_service scientist_service;
    int id;
};

#endif // EDIT_SCIENTIST_H
