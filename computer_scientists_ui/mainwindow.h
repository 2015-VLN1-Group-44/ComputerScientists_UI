#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scientist_service.h"
#include "computer_service.h"
#include <vector>
#include "add_scientist.h"
#include "edit_scientist.h"
#include "add_computer.h"
#include "edit_computer.h"
#include <QTableWidgetItem>


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

    // Sækir alla vísindamenn og birtir þá í töflu
    void display_all_scientists();
    void display_scientists(vector<Scientist> scientists);

    void display_all_computers();
    void display_computers(vector<Computers> computers);

    // Birtir allar tölvur tengdar völdum vísindamanni
    void display_connected_computers();

    // Birtir alla vísindamenn tengda valinni tölvu
    void display_connected_scientists();

    /* Tekur við texta úr leitarglugga og birtir stök sem
     * uppfylla leitarskilyrðu
     */
    void on_search_scientist_textChanged(const QString &arg1);
    void on_search_computers_textChanged(const QString &arg1);

    // Birtir valmynd til að bæta við scientist
    void on_add_scientist_button_clicked();

    /* Virkjar takka sem geta breytt/eytt vísindamönnum og birtir
     * lista af tengdum tölvum
     */
    void on_table_scientists_clicked(const QModelIndex &index);

    // Eyðir völdum vísindamanni úr gagnagrunni
    void on_remove_scientist_button_clicked();

    // Birtir valmynd til að breyta völdum vísindamanni
    void on_edit_scientist_button_clicked();

    /* Virkjar takka sem geta breytt/eytt tölvum og birtir lista
     * af tengdum tölvum
     */
    void on_table_computers_clicked(const QModelIndex &index);

    // Birtir lista af tengjanlegum vísindamönnum í comboboxi
    void list_scientists_to_connect();


    void on_add_computer_button_clicked();

    void on_edit_computer_button_clicked();

    void on_remove_computer_button_clicked();

    // Virkjar möguleika til að eyða tengingu tölvu við vísindamann
    void on_table_connected_scientists_clicked(const QModelIndex &index);
    void on_add_connection_clicked();

    void on_remove_connection_clicked();

    // Afvirkjar takka þegar flett er milli flipa scientists/computers
    void on_tabWidget_tabBarClicked(int index);

    // Fylgir breytingum á völdum vísindamanni/tölvu í töflum
    void on_table_scientists_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous);
    void on_table_computers_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous);

private:

    Ui::MainWindow *ui;
    Scientist_service scientist_service;
    Computer_service computer_service;

    vector<Scientist> current_list_of_scientists;

    int current_scientist_id;
    int current_computer_id;
    int connected_scientist_id;
};

#endif // MAINWINDOW_H
