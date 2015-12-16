#include "edit_scientist.h"
#include "ui_edit_scientist.h"
#include <QMessageBox>

Edit_scientist::Edit_scientist(int &id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_scientist)
{
    ui->setupUi(this);
    this->id = id;
    temp = scientist_service.find_from_id(id);
    QString first, last;
    first = QString::fromStdString(temp.get_first());
    last = QString::fromStdString(temp.get_last());
    ui->edit_first->setText(first);
    ui->edit_last->setText(last);
    ui->birth_edit->setMinimumDate(constants::MINDATE);
    ui->birth_edit->setMaximumDate(constants::MAXDATE);
    ui->death_edit->setMinimumDate(constants::MINDATE);
    ui->death_edit->setMaximumDate(constants::MAXDATE);
    ui->birth_edit->setDate(temp.get_birth());
    ui->death_edit->setDate(temp.get_death());
    ui->gender_select->setCurrentIndex(temp.get_gender());
    ui->living->setChecked(temp.get_living());
}

Edit_scientist::~Edit_scientist()
{
    delete ui;
}

void Edit_scientist::set_id(const int &id)
{
    this->id = id;
}

int Edit_scientist::get_id()
{
    return id;
}

void Edit_scientist::on_save_edit_button_clicked()
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
        //errormessage = "Date of death before date of birth. Please correct.";                                             ----------Má eyða
        ui->label_dod->setText("<span style='color: #ff3366'>Date of death before date of birth. Please correct.</span>");               //Edit Ingvi
    }
    else if (!lastname.length())
    {
        //errormessage = "No last name entered. Please correct";                                        -----------------------Má eyða
        ui->label_lastname->setText("<span style='color: #ff3366'>Please enter lastname</span>");               //Edit Ingvi
    }
    else
    {
        valid_input = true;
    }
    if (!valid_input)
    {
//        QMessageBox messageBox;
//        messageBox.critical(0, "Error", errormessage);                                                    --------------------má eyða
//        messageBox.setFixedSize(500,200);
        if (lastname.length())                                                                                           //Edit Ingvi
        ui->label_lastname->setText("<span style='color: #000000'>Last name:</span>");                                 //Edit Ingvi
        if (!alive && death > birth)                                                                                     //Edit Ingvi
        ui->label_dod->setText("<span style='color: #000000'>Date of death:</span>");                                 //Edit Ingvi
    }
    else
    {
        Scientist temp(firstname, lastname, gender, birth, death, alive, id, 1);
        scientist_service.edit_entry(temp);
        this->done(0);
    }
}

void Edit_scientist::on_living_toggled(bool checked)
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

void Edit_scientist::on_cancel_button_clicked()
{
    this->done(-1);
}
