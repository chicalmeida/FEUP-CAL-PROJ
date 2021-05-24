//
// Created by Francisca on 04/05/2021.
//

#ifndef PROJ_BIN_H
#define PROJ_BIN_H
#include <vector>
#include <string>
#include "Garbage.h"
#include <iostream>
#include "SingleBin.h"
using namespace std;


class Bin {
private:
    vector<SingleBin> bins;
    //vector<Garbage> content;
    double capacity;
public:
    Bin();
    Bin(double capacity);
    double getCurrCapacity();
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
