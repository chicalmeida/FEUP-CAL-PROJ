//
// Created by Francisca on 04/05/2021.
//

#ifndef PROJ_BIN_H
#define PROJ_BIN_H
class Location;
#include <vector>
#include <string>
#include "Garbage.h"
#include "Location.h"
#include <iostream>
#include "SingleBin.h"
using namespace std;


class Bin {
private:
    vector<SingleBin> bins;
    //vector<Garbage> content;
    double capacity;
    Location *location;
public:
    Location * getLocation();
    Bin(Location *location);
    Bin(double capacity, Location *location);
    double getCurrCapacity();
    bool hasType(GarbageType type);
    void addBin(GarbageType type, int capacity);
    void addGarbage(Garbage elem);
    void resetBin();

    /**
     * Write garbage in the file.
     * @param os Stream where to save.
     * @param client Client to be saved.
     * @return Stream where was saved.
     */
    friend std::ostream& operator<< (std::ostream &os, const Bin &garbage);
};


#endif //PROJ_BIN_H
