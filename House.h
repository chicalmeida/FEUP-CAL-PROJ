//
// Created by furta on 13/05/2021.
//

#ifndef PROJ_HOUSE_H
#define PROJ_HOUSE_H

#include "User.h"
#include "Bin.h"

using namespace std;


class House : public Address{
private:
    vector<User> habitants;
public:
    House();
    House(int id);
    House(int id, Location location);
    void addHabitant(User habitant);
    bool removeHabitant(User habitant);
    int geNumHabitants();
    vector<User> getHabitants();
};


#endif //PROJ_HOUSE_H
