//
// Created by Francisca on 04/05/2021.
//

#ifndef PROJ_CLIENT_H
#define PROJ_CLIENT_H
#include "User.h"
#include "Bin.h"

using namespace std;


class Client : public User{
private:
    vector<Garbage> cContent;
public:
    Client();
    Client(int nif, string name);
    Client(int nif, string name, Address address);
    void setGarbage(vector<Garbage> garbage);
    vector<Garbage> getGarbage();
    void addGarbage(Garbage gb);
    void removeGarbage(Garbage gb);
    double getCurrWeight();
    void deposit(Bin bin);

    /**
     * Write client in the file.
     * @param os Stream where to save.
     * @param client Client to be saved.
     * @return Stream where was saved.
     */
    friend std::ostream& operator<< (std::ostream &os, const Client &client);
};


#endif //PROJ_CLIENT_H
