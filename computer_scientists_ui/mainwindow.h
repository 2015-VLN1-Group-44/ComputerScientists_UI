#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scientist_service.h"
#include "computer_service.h"
#include <vector>
#include "add_scientist.h"
#include "edit_scientist.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void display_all_scientists();
    void display_scientists(vector<Scientist> scientists);
    void display_all_computers();
    void display_computers(vector<Computers> computers);

    void display_connected_computers();
    void display_connected_scientists();

    void on_search_scientist_textChanged(const QString &arg1);

    void on_search_computers_textChanged(const QString &arg1);

    void on_add_scientist_button_clicked();

    void on_table_scientists_clicked(const QModelIndex &index);

    void on_remove_scientist_button_clicked();

    void on_edit_scientist_button_clicked();

    void on_table_computers_clicked(const QModelIndex &index);

private:

    Ui::MainWindow *ui;
    Scientist_service scientist_service;
    Computer_service computer_service;

    int current_scientist_id;
    int current_computer_id;
};

#endif // MAINWINDOW_H
