#include "edit_computer.h"
#include "ui_edit_computer.h"
#include "constants.h"
#include <QDate>
#include <QMessageBox>

Edit_computer::Edit_computer(int &id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_computer)
{
    ui->setupUi(this);
    this->id = id;
    temp = computer_service.from_id(id);
    QString name = QString::fromStdString(temp.get_name());
    int type_index = static_cast<int>(temp.get_type()) - 1;
    QDate year(temp.get_year(), 1, 1);
    ui->name_edit->setText(name);
    ui->year_edit->setMinimumDate(constants::MINDATE);
    ui->year_edit->setMaximumDate(constants::MAXDATE);
    ui->year_edit->setDate(year);
    ui->combo_type->setCurrentIndex(type_index);
    ui->check_was_built->setChecked(temp.get_built());
}

Edit_computer::~Edit_computer()
{
    delete ui;
}

void Edit_computer::on_save_button_clicked()
{
    bool valid = true;
    QString errormessage = "";
    string name = ui->name_edit->text().toStdString();
    int year = ui->year_edit->date().year();
    int type = ui->combo_type->currentIndex() + 1;
    bool built = ui->check_was_built->isChecked();
    Computers temp(name, year, built, type, id);
    if (!name.length())
    {
        valid = false;
        errormessage = "Name empty, please try again";
        ui->label_name->setText("<span style='color: #ff3366'>Please enter name>");
    }
    if (valid)
    {
        computer_service.edit_computer(temp);
        this->done(0);
    }
}

void Edit_computer::on_cancel_button_clicked()
{
    this->done(-1);
}
