#include "computer_service.h"

Computer_service::Computer_service()
{
}

vector<Computers> Computer_service::sort(QString sort_order)
{
    QString command = QString(constants::COMPUTERS_ORDER.arg(sort_order));
    return computer_repo.open_computer_db(command);
}

vector<Computers> Computer_service::search(QString column, QString search_arg)
{
    QString command = QString(constants::COMPUTERS_SEARCH.arg(column).arg(search_arg));
    return computer_repo.open_computer_db(command);
}

void Computer_service::edit_computer(Computers c)
{
    QString name = QString::fromStdString(c.get_name());
    int year = c.get_year();
    bool built = c.get_built();
    int type = static_cast<int>(c.get_type());
    int id = c.get_id();

    QString command = QString(constants::COMPUTER_UPDATE.arg(name).arg(year).arg(type).arg(built).arg(id));
    computer_repo.edit_remove(command);
}

Computers Computer_service::from_id(int id)
{
    QString command = QString(constants::COMPUTER_FROM_ID.arg(id));
    return computer_repo.open_computer_db(command)[0];
}

void Computer_service::delete_id(int id)
{
    QString command = QString(constants::DELETE_COMPUTER.arg(id));
    computer_repo.edit_remove(command);
    command = QString(constants::DELETE_COMPUTER_CONNECTIONS.arg(id));
    computer_repo.edit_remove(command);
}

vector<string> Computer_service::connected_scientists(int id)
{
    QString command = QString(constants::SCIENTIST_JOIN.arg(id));
    vector<string> scientist_names = computer_repo.connected(command, "lastname");
    return scientist_names;
}

vector<Scientist> Computer_service::joined_scientists(int id)
{
    QString command = QString(constants::SCIENTIST_JOIN.arg(id));
    return computer_repo.open_scientist_db(command);
}

void Computer_service::add_connection(int sci_id, int comp_id)
{
    QString command = QString(constants::ADD_CONNECTION.arg(sci_id).arg(comp_id));
    computer_repo.edit_remove(command);
}

vector<Scientist> Computer_service::connected_sci(int id)
{
    QString command = QString(constants::CONNECTED_SCIENTIST_ID.arg(id));
    return computer_repo.connected_to_delete(command);
}

void Computer_service::remove_connection(int scient_id, int comp_id)
{
    QString command = QString(constants::DELETE_CONNECTION.arg(scient_id).arg(comp_id));
    computer_repo.edit_remove(command);
}

void Computer_service::add_computer_db(Computers c)
{
    QSqlQuery query(computer_repo.get_db());
    query.prepare(constants::INSERT_COMPUTER);
    query.bindValue(":name", QString::fromStdString(c.get_name()));
    if (c.get_year())
    {
        query.bindValue(":by", c.get_year());
    }
    else
    {
        query.bindValue(":by", "NULL");
    }
    query.bindValue(":type", c.get_type());
    query.bindValue(":built", c.get_built());
    computer_repo.add_to_db(query);
}
