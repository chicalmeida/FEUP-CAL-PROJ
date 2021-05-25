//
// Created by furta on 13/05/2021.
//

#ifndef PROJ_HOUSE_H
#define PROJ_HOUSE_H

#include "User.h"
#include "Bin.h"
#include "Client.h"
using namespace std;


class House : public Address{
private:
    vector<Client *> habitants;
    int garbage;
public:
    House();
    House(int id);
    House(int id, Location *location);
    void addHabitant(Client  *habitant);
    bool removeHabitant(Client *habitant);
    int geNumHabitants();
    vector<Client *> getHabitants();
    int getGarbage();
    int setGarbage(int n);
};


#endif //PROJ_HOUSE_H



