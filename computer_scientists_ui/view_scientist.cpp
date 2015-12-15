#include "view_scientist.h"
#include "ui_view_scientist.h"
#include "constants.h"
#include "Computers.h"
view_scientist::view_scientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::view_scientist)
{
    ui->setupUi(this);
    Scientist scientist_temp;
    QString firstname = Scientist_temp.get_first();
    QString lastname = Scientist_temp.get_last();
    QString fullname = firstname + " " + lastname;
    ui->NameView->setText(fullname);
    QString gender = scientist_temp.get_gender();
    ui->GenderView->setText(gender);
    QDate birth;
    QString birthdate = birth.toString(constants::IMPORT_DATE_FORMAT);
    ui->DateBView->setText(birthdate);
    QDate death;
    QString deathdate = death.toString(constants::IMPORT_DATE_FORMAT);
    ui ->DateDView->setText(deathdate);
    Computer computer_temp;
    QString name = computer_temp.get_name();
    ui->ComputerView->setText(name);
    QString type;
    if(computer_temp.get_type() == '1')
    {
        type="Mechanical";
    }
    else if(computer_temp.get_type() == '2')
    {
        type ="Transistor";
    }
    else if(computer_temp.get_type() == '3')
    {
        type="Electronic";
    }
    ui->TypeView->setText(type);
    QString yearbuilt = computer_temp.get_year_built();
    ui->Year_built->setText(yearbuilt);
}
view_scientist::~view_scientist()
{
    delete ui;
}
void view_scientist::on_label_linkActivated(const QString &link)
{
    SqlDataAdapter dataAdapter = new SqlDataAdapter(new SqlCommand("SELECT pic FROM imageTest WHERE pic_id = 1", yourConnectionReference));
    DataSet dataSet = new DataSet();
    dataAdapter.Fill(dataSet);
    MemoryStream mem = new MemoryStream(data);
    ui->PictureCS.Image= Image.FromStream(mem);
}
