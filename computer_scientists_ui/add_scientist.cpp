#include "add_scientist.h"
#include "ui_add_scientist.h"
#include <QMessageBox>

Add_scientist::Add_scientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_scientist)
{
    ui->setupUi(this);

    ui->birth_edit->setMinimumDate(constants::MINDATE);
    ui->birth_edit->setMaximumDate(constants::MAXDATE);
    ui->death_edit->setMinimumDate(constants::MINDATE);
    ui->death_edit->setMaximumDate(constants::MAXDATE);
}

Add_scientist::~Add_scientist()
{
    delete ui;
}

void Add_scientist::on_add_button_clicked()
{
    string firstname = ui->edit_first->text().toStdString();
    string lastname = ui->edit_last->text().toStdString();
    QDate birth = ui->birth_edit->date();
    QDate death = ui->death_edit->date();
    bool gender = (bool) ui->gender_select->currentIndex();
    bool alive = ui->living->isChecked();
    bool valid_input = false;
    QString errormessage = "";
    if (alive)
    {
        death = QDate::fromString(0000-0-0, constants::IMPORT_DATE_FORMAT);
    }
    if (!alive && death < birth)
    {
        ui->label_dod->setText("<span style='color: #ff3366'>Date of death before date of birth. Please correct.</span>");
    }
    else if (!lastname.length())
    {
        ui->label_lastname->setText("<span style='color: #ff3366'>Please enter last name</span>");
    }
    else
    {
        valid_input = true;
    }
    if (!valid_input)
    {
        if (lastname.length())
            ui->label_lastname->setText("<span style='color: #000000'>Last name:</span>");
        if (!alive && death > birth)
            ui->label_dod->setText("<span style='color: #000000'>Date of death:</span>");
    }
    else
    {
        Scientist temp(firstname, lastname, gender, birth, death, alive);
        scientist_service.add_scientist(temp);
        this->done(0);
    }
}

void Add_scientist::on_cancel_button_clicked()
{
    this->done(1);
}

void Add_scientist::on_living_toggled(bool checked)
{
    if (checked)
    {
        ui->death_edit->setEnabled(false);
    }
    else
    {
        ui->death_edit->setEnabled(true);
    }
}
