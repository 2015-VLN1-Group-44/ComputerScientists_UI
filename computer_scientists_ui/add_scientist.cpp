#include "add_scientist.h"
#include "ui_add_scientist.h"

Add_scientist::Add_scientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_scientist)
{
    ui->setupUi(this);
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
    if (alive)
    {
        death = QDate::fromString(0000-0-0, constants::IMPORT_DATE_FORMAT);
    }
    Scientist temp(firstname, lastname, gender, birth, death, alive);
    scientist_service.add_scientist(temp);
}
