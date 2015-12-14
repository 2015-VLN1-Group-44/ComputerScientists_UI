#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    display_all_computers();
    display_all_scientists();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display_all_scientists()
{
    vector<Scientist> list_scientists = scientist_service.sort("lastname");
    display_scientists(list_scientists);
}

void MainWindow::display_scientists(vector<Scientist> scientists)
{
    ui->table_scientists->setRowCount(scientists.size());
    ui->table_scientists->setSelectionBehavior(QAbstractItemView::SelectRows);
    for (unsigned int i = 0; i < scientists.size(); i++)
    {
        Scientist current = scientists[i];
        QString name = QString::fromStdString(current.get_last() + ", " + current.get_first());
        QString gender = "";
        if (current.get_gender())
        {
            gender = "Male";
        }
        else
        {
            gender = "Female";
        }
        QString dob = current.get_birth().toString(constants::IMPORT_DATE_FORMAT);
        QString dod = current.get_death().toString(constants::IMPORT_DATE_FORMAT);
        QString id = QString::number(current.get_id());
        ui->table_scientists->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_scientists->setItem(i, 1, new QTableWidgetItem(gender));
        ui->table_scientists->setItem(i, 2, new QTableWidgetItem(dob));
        ui->table_scientists->setItem(i, 3, new QTableWidgetItem(dod));
        ui->table_scientists->setItem(i, 4, new QTableWidgetItem(id));
    }
    ui->table_scientists->setColumnHidden(4, true);
    ui->table_scientists->resizeColumnsToContents();
}

void MainWindow::display_all_computers()
{
    vector<Computers> list_computers = computer_service.sort("name");
    display_computers(list_computers);
}

void MainWindow::display_computers(vector<Computers> computers)
{
    ui->table_computers->setRowCount(computers.size());
    ui->table_computers->setSelectionBehavior(QAbstractItemView::SelectRows);
    for (unsigned int i = 0; i < computers.size(); i++)
    {
        Computers current = computers[i];
        QString name = QString::fromStdString(current.get_name());
        QString type = "";
        QString was_built = "";
        QString id = QString::number(current.get_id());
        int type_nr = static_cast<int>(current.get_type());
        if (type_nr == 1)
        {
            type = "Mechanical";
        }
        else if (type_nr == 2)
        {
            type = "Transistor";
        }
        else
        {
            type = "Electronic";
        }
        int year = current.get_year();
        if (current.get_built())
        {
            was_built = "Yes";
        }
        else
            was_built = "No";
        ui->table_computers->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_computers->setItem(i, 1, new QTableWidgetItem(type));
        ui->table_computers->setItem(i, 2, new QTableWidgetItem(QString::number(year)));
        ui->table_computers->setItem(i, 3, new QTableWidgetItem(was_built));
        ui->table_computers->setItem(i, 4, new QTableWidgetItem(id));
    }
    ui->table_computers->setColumnHidden(4, true);
}



void MainWindow::on_search_scientist_textChanged(const QString &arg1)
{
    vector<Scientist> scientists = scientist_service.search(arg1, "lastname");
    display_scientists(scientists);
}

void MainWindow::on_search_computers_textChanged(const QString &arg1)
{
    // QString search_term = ui->search_computers->text();
    vector<Computers> computers = computer_service.search("name", arg1);
    display_computers(computers);
}

void MainWindow::on_add_scientist_button_clicked()
{
    Add_scientist *add_scientist;
    add_scientist = new Add_scientist;
    int success = add_scientist->exec();
    if (success == 0)
    {
        display_all_scientists();
    }

}
