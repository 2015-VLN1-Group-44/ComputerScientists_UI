#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <QString>
#include <QDate>
#include "scientist_service.h"
#include <fstream> 
#include <sstream>


using namespace std;

Scientist_service::Scientist_service()
{
}

vector<Scientist> Scientist_service::sort(QString order)
{
    QString command = QString(constants::SCIENTISTS_ORDER.arg(order));
    return scientist_repo.open_scientist_db(command);
}

vector<Scientist> Scientist_service::search(QString search_arg, QString column)
{
    QString command = QString(constants::SEARCH_SCIENTIST_TEMPLATE.arg(column).arg(search_arg));
    return scientist_repo.open_scientist_db(command);
}

Scientist Scientist_service::find_from_id(int scientist_id)
{
    QString command = QString(constants::SCIENTIST_FROM_ID.arg(scientist_id));
    return scientist_repo.open_scientist_db(command)[0];
}

void Scientist_service::edit_entry(QString column, QString insert, int id)
{
    QString command = QString(constants::SCIENTIST_EDIT.arg(column).arg(insert).arg(id));
    scientist_repo.edit_remove(command);
}

void Scientist_service::delete_id(int id)
{
    QString command = QString(constants::DELETE_SCIENTIST.arg(id));
    scientist_repo.edit_remove(command);
}


vector <string> Scientist_service::connected_computers(int id)
{
    QString command = QString(constants::COMPUTER_JOIN.arg(id));
    vector<string> scientist_names = scientist_repo.connected(command, "name");
    return scientist_names;
}

void Scientist_service::add_scientist(Scientist s)
{
    QSqlQuery query(scientist_repo.get_db());
    query.prepare(constants::INSERT_FORM);
    query.bindValue(":first", QString::fromStdString(s.get_first()));
    query.bindValue(":last", QString::fromStdString(s.get_last()));
    query.bindValue(":b", s.get_birth());
    query.bindValue(":d", s.get_death());
    query.bindValue(":g", s.get_gender());
    query.bindValue(":a", s.get_living());
    query.bindValue(":act", 1);
    scientist_repo.add_to_db(query);
}

