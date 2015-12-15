#include "add_computer.h"
#include "ui_add_computer.h"
#include "constants.h"
#include <QMessageBox>

Add_computer::Add_computer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_computer)
{
    ui->setupUi(this);
    ui->year_edit->setMaximumDate(constants::MAXDATE);
}

Add_computer::~Add_computer()
{
    delete ui;
}

void Add_computer::on_add_button_clicked()
{
    bool valid = true;
    QString errormessage = "";
    string name = ui->name_edit->text().toStdString();
    int year;
    year = ui->year_edit->text().toInt();
    bool built = ui->check_was_built->isChecked();
    int ct = ui->combo_type->currentIndex() + 1;
    Computers temp(name, year, built, ct);
    if (!name.length())
    {
        valid = false;
        errormessage = "Name empty, please try again";
    }
    if (!valid)
    {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", errormessage);
        messageBox.setFixedSize(500,200);
    }
    else
    {
        computer_service.add_computer_db(temp);
        this->done(0);
    }
}

void Add_computer::on_cancel_button_clicked()
{
    this->done(-1);
}

void Add_computer::on_check_was_built_toggled(bool checked)
{
    if (!checked)
    {
        ui->year_edit->setEnabled(false);
    }
    else
    {
        ui->year_edit->setEnabled(true);
    }
}
