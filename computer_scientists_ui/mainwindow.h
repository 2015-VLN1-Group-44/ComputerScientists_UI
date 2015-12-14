#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scientist_service.h"
#include "computer_service.h"
#include <vector>
#include "add_scientist.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void display_all_scientists();
    void display_scientists(vector<Scientist> scientists);
    void display_all_computers();
    void display_computers(vector<Computers> computers);
private slots:
    void on_search_scientist_textChanged(const QString &arg1);

    void on_search_computers_textChanged(const QString &arg1);

    void on_add_scientist_button_clicked();

private:

    Ui::MainWindow *ui;
    Scientist_service scientist_service;
    Computer_service computer_service;
};

#endif // MAINWINDOW_H
