//
// Created by Francisca on 04/05/2021.
//

#ifndef PROJ_TRUCK_H
#define PROJ_TRUCK_H

#include "Garbage.h"
#include "User.h"
#include "Client.h"
#include <vector>
#include <iostream>

using namespace std;


class Truck : public User{
private:
    double capacity;
    vector<Garbage> tContent;
public:
    Truck();
    Truck(int nif, string name, double capacity);
    Truck(int nif, string name, double capacity, Address address);
    void setCapacity(double capacity);
    double getCapacity();
    double getCurCapacity();
    vector<Garbage> getTContent();
    void addGarbage(Garbage elem);
    void pickup(Client client);
    void deposit();
};


#endif //PROJ_TRUCK_H
