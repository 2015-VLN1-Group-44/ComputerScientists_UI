#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
        ui->table_scientists->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_scientists->setItem(i, 1, new QTableWidgetItem(gender));
        ui->table_scientists->setItem(i, 2, new QTableWidgetItem(dob));
        ui->table_scientists->setItem(i, 3, new QTableWidgetItem(dod));
    }
    ui->table_scientists->resizeColumnsToContents();
}



void MainWindow::on_search_scientist_textChanged(const QString &arg1)
{
    QString search_term = ui->search_scientist->text();
    vector<Scientist> scientists = scientist_service.search(search_term, "lastname");
    display_scientists(scientists);
}
