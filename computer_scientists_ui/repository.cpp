#include "repository.h"
#include <QDebug>

using namespace std;

Repository::Repository()
{
    if(QSqlDatabase::contains(constants::CONNECTION_NAME))
        {
            db = QSqlDatabase::database(constants::CONNECTION_NAME);
        }
        else
        {
            db = QSqlDatabase::addDatabase("QSQLITE", constants::CONNECTION_NAME);
            db.setDatabaseName(constants::DATABASE_NAME);
            db.open();
        }
    /* Býr til töflur ef þær eru ekki til fyrir
     *
     */
        QSqlQuery query(db);
        query.exec(constants::CREATE_SCIENTISTS_TABLE);
        query.exec(constants::CREATE_COMPUTERS_TABLE);
        query.exec(constants::CREATE_OWNERS_TABLE);
}

QSqlDatabase Repository::get_db()
{
    return db;
}

vector<Scientist> Repository::open_scientist_db(QString sql_command)
{
    vector<Scientist> data;
    QSqlQuery query(db);
    query.exec(sql_command);
    while (query.next())
    {
        string first, last;
        QDate b, d;
        bool g, a, act;
        int id_n;
        first = query.value("firstname").toString().toStdString();
        last = query.value("lastname").toString().toStdString();
        b = QDate::fromString(query.value("birth").toString(), constants::IMPORT_DATE_FORMAT);
        d = QDate::fromString(query.value("death").toString(), constants::IMPORT_DATE_FORMAT);
        id_n = query.value("id").toInt();
        g = query.value("gender").toBool();
        a = query.value("alive").toBool();
        act = query.value("active").toBool();
        Scientist temp(first, last, g, b, d, a, id_n, act);
        data.push_back(temp);
    }
    query.exec(constants::SCIENTIST_JOIN);
    return data;
}

vector<Computers> Repository::open_computer_db(QString sql_command)
{
    vector<Computers> data;
    QSqlQuery query(db);
    query.exec(sql_command);
    while (query.next())
    {
        string name;
        int year, id_n;
        bool b;
        int ct;

        name = query.value("name").toString().toStdString();
        ct = (query.value("type").toInt());
        year = query.value("built_year").toInt();
        id_n = query.value("id").toInt();
        b = query.value("built").toBool();
        Computers temp(name, year, b, ct, id_n);
        data.push_back(temp);
    }
    return data;    
}

vector<string> Repository::connected(QString command, QString column)
{
    vector<string> data;
    QSqlQuery query(db);
    query.exec(command);
    while (query.next())
    {
        string name;
        name = query.value(column).toString().toStdString();
        data.push_back(name);
    }
    return data;
}

vector<Scientist> Repository::connected_to_delete(QString command)
{
    vector<Scientist> data;
    QSqlQuery query(db);
    query.exec(command);
    Scientist temp;
    while (query.next())
    {
        string name;
        int id;
        name = query.value("lastname").toString().toStdString();
        id = query.value("scientist_id").toInt();
        temp.set_last(name);
        temp.set_id(id);
        data.push_back(temp);
    }
    return data;
}

void Repository::add_to_db(QSqlQuery query)
{
    query.exec();
}

void Repository::edit_remove(QString command)
{
    QSqlQuery query(db);
    query.exec(command);
}

