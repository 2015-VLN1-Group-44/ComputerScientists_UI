#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <iostream>
#include <vector>
#include <iomanip>
#include "scientist.h"
#include <QtSql>
#include <QString>
#include "constants.h"
#include "computers.h"

using namespace std;


class Repository
{
public:
    Repository();

    /* Tengist sql grunni og sækir scientista/tölvur
     * sorterað og filterað byggt á skipun: sql_command
     */
    QSqlDatabase get_db();
    vector<Scientist> open_scientist_db(QString sql_command);
    vector<Computers> open_computer_db(QString sql_command);

    // Sækir nöfn scientista/tölva og skilar sem vektor
    vector<string> connected(QString command, QString column);

    // Tekur skipun sem vinnur með grunninn, skilar engum gögnum
    void edit_remove(QString command);

    // Skilar vektor einungis með eftirnafni og id
    vector<Scientist> connected_to_delete(QString command);

    void add_to_db(QSqlQuery query);

private:
    QSqlDatabase db;
};

#endif // REPOSITORY_H
