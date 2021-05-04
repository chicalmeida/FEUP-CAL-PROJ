//
// Created by Francisca on 04/05/2021.
//

#ifndef PROJ_TRUCK_H
#define PROJ_TRUCK_H

#include "Garbage.h"
#include <vector>
#include <iostream>

using namespace std;


class Truck {
private:
    int id;
    double capacity;
    double currCapacity;
    vector<Garbage> tContent;
public:
    Truck();
    Truck(int id, double capacity, double curr);
    void setID(int id);
    void setCapacity(double capacity);
    void setCurrCapacity(double curr);
    void setTContent(vector<Garbage>Tcontent);
    int getID();
    double getCapacity();
    double getCurCapacity();
    vector<Garbage> getTContent();
    void addGarbage(Garbage elem);

};


#endif //PROJ_TRUCK_H
