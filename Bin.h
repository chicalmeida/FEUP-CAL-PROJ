//
// Created by Francisca on 04/05/2021.
//

#ifndef PROJ_BIN_H
#define PROJ_BIN_H
#include <vector>
#include <string>
#include "Garbage.h"
#include <iostream>

using namespace std;


class Bin {
private:
    vector<Garbage> content;
    double capacity;
public:
    Bin();
    Bin(double capacity);
    void setContent(vector<Garbage> content);
    void setCapacity(double capacity);
    void setCurrCapacity(double curr);
    vector<Garbage> getContent();
    double getCapacity();
    double getCurrCapacity();
    void addElem(Garbage elem);
    void resetBin();
};


#endif //PROJ_BIN_H
