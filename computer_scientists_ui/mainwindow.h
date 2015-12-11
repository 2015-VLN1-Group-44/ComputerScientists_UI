#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scientist_service.h"
#include "computer_service.h"
#include <vector>


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
private:



    Ui::MainWindow *ui;
    Scientist_service scientist_service;
    Computer_service computer_service;
};

#endif // MAINWINDOW_H
