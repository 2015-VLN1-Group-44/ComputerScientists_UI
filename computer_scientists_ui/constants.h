#ifndef CONSTANTS
#define CONSTANTS
#include <QString>
#include <QDate>

namespace constants
{
    const QString CONNECTION_NAME = "db_connection";
    const QString DATE_FORMAT = "dd/MM/yyyy";
    const QString IMPORT_DATE_FORMAT = "yyyy-MM-dd";
    const std::string MENU_DELIMITER(103, '-');
    const std::string SELECTION_PROMPT = "Enter selection: ";
    const std::string SELECTION_NOT_VALID = "Invalid selection. Please try again.";
    const int MAX_NAME_LENGTH = 36;
    const int MAX_COMP_NAME_LENGTH = 48;
    const QString SCIENTISTS_FILENAME = "scientists.sqlite";
    const QString SEARCH_SCIENTIST_TEMPLATE = "SELECT * FROM scientists WHERE %1 LIKE '%%2%' ";
    const std::string FOUND = "Found entries:";
    const QString SCIENTIST_EDIT = "UPDATE scientists SET %1 = '%2' WHERE id = %3";
    const QString SCIENTIST_UPDATE = "UPDATE scientists SET firstname = '%1', lastname = '%2', birth = '%3', death = '%4', gender = '%5', alive = '%6' WHERE id = %7 ";
    const QString COMPUTER_UPDATE = "UPDATE computers SET name = '%1', built_year = '%2', type = '%3', built = '%4' WHERE id = '%5' ";
    const QString SCIENTIST_FROM_ID = "SELECT * FROM scientists WHERE id LIKE '%%1%'";
    const QString SCIENTISTS_ORDER = "SELECT * FROM scientists ORDER BY %1 ";
    const QString INSERT_FORM =  "INSERT INTO scientists (firstname, lastname, birth, death, gender, alive, active)" 
                                 "VALUES (:first, :last, :b, :d, :g, :a, :act)";
    const QString INSERT_COMPUTER = "INSERT INTO computers (name, built_year, type, built)"
                                "VALUES (:name, :by, :type, :built)";
    const QString DATABASE_NAME = "db.sqlite";
    const QString COMPUTERS_ORDER = "SELECT * FROM computers ORDER BY %1";
    const QString COMPUTERS_SEARCH = "SELECT * FROM computers WHERE %1 LIKE '%%2%' ";
    const QString COMPUTERS_EDIT = "UPDATE computers SET %1 = '%2' WHERE id = %3";
    const QString COMPUTER_FROM_ID = "SELECT * FROM computers WHERE id LIKE '%%1%'";
    const QString DELETE_SCIENTIST = "DELETE FROM scientists WHERE id = %1";
    const QString DELETE_COMPUTER = "DELETE FROM computers WHERE id = %1";
    const QString CONNECTED_SCIENTIST_ID = "SELECT lastname, scientist_id FROM scientists s, owners o WHERE s.id = o.scientist_id AND o.computer_id = %1";
    // const QString SCIENTIST_JOIN =  "SELECT lastname FROM scientists s, owners o WHERE s.id = o.scientist_id AND %1 = o.computer_id";
    const QString SCIENTIST_JOIN =  "SELECT * FROM scientists s, owners o WHERE s.id = o.scientist_id AND %1 = o.computer_id";
    const QString COMPUTER_JOIN =  "SELECT name FROM computers c, owners o WHERE c.id = o.computer_id AND %1 = o.scientist_id";
    const QString CREATE_SCIENTISTS_TABLE = "CREATE TABLE IF NOT EXISTS Scientists(id INTEGER PRIMARY KEY AUTOINCREMENT, firstname VARCHAR NOT NULL, lastname VARCHAR NOT NULL, birth DATE NOT NULL, death DATE, gender BOOL, alive BOOL, active BOOL)";
    const QString CREATE_COMPUTERS_TABLE = "CREATE TABLE IF NOT EXISTS Computers(id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR NOT NULL, built_year DATETIME, type ENUM, built BOOL, active BOOL)";
    const QString CREATE_OWNERS_TABLE = "CREATE TABLE IF NOT EXISTS Owners(scientist_id INTEGER, computer_id INTEGER, FOREIGN KEY (scientist_id) REFERENCES Scientists(id), FOREIGN KEY (computer_id) REFERENCES Computers(id), PRIMARY KEY (scientist_id, computer_id))";
    const QString ADD_CONNECTION = "INSERT INTO owners (scientist_id, computer_id) VALUES (%1, %2)";
    const QString DELETE_CONNECTION = "DELETE FROM owners WHERE scientist_id = %1 AND computer_id = %2";
    const QString DELETE_SCIENTIST_CONNECTIONS = "DELETE FROM owners WHERE scientist_id = %1 ";
    const QString DELETE_COMPUTER_CONNECTIONS = "DELETE FROM owners WHERE computer_id = %1 ";
    const QDate MINDATE(100, 1, 1);
    const QDate MAXDATE(QDate::currentDate());
}



#endif // CONSTANTS

