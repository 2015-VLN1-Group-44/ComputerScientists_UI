#ifndef COMPUTER_SERVICE_H
#define COMPUTER_SERVICE_H

#include "computers.h"
#include "repository.h"

class Computer_service
{
public:
    Computer_service();

    /* Tekur dálk til að raða sem input
     * skilar vektor af tölvum
     */
    vector<Computers> sort(QString sort_order);

    /* Tekur leitardálk og leit sem input
     * skilar vektor af tölvum sem passa við leitarskilyrði
     */
    vector<Computers> search(QString column, QString search_arg);

    void edit_computer (Computers c);

    /* Tekur við id-númeri, skilar samsvarandi tölvu
     */
    Computers from_id(int id);

    // tekur við id, eyðir viðkomandi tölvu
    void delete_id(int id);

    // tekur tölvu id, skilar nöfnum tengdra tölvunarfræðinga
    vector<string> connected_scientists(int id);

    vector<Scientist> joined_scientists(int id);

    // tengir saman tölvuid og scientist id
    void add_connection(int sci_id, int comp_id);

    /* Skilar scientists tengdum tölvu
     * breytan id inniheldur einstakt id-númer tölvunnar
     * sem þeir eru tengdir
     */
    vector<Scientist> connected_sci(int id);

    // Eyðir tengingu scientists við tölvu
    void remove_connection(int scient_id, int comp_id);

    void add_computer_db(Computers c);


private:
    Repository computer_repo;
};

#endif // COMPUTER_SERVICE_H
