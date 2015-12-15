#ifndef EDIT_SCIENTIST_H
#define EDIT_SCIENTIST_H

#include <QDialog>
#include "scientist_service.h"

namespace Ui {
class Edit_scientist;
}

class Edit_scientist : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_scientist(int &id, QWidget *parent = 0);
    ~Edit_scientist();

    void set_id(const int &id);
    int get_id();

private slots:
    void on_save_edit_button_clicked();

private:
    Ui::Edit_scientist *ui;
    int id;
    Scientist temp;
    Scientist_service scientist_service;
};

#endif // EDIT_SCIENTIST_H
