//
// Created by furta on 13/05/2021.
//

#ifndef PROJ_LOCATION_H
#define PROJ_LOCATION_H

#include "User.h"
#include "Bin.h"

using namespace std;


class Location{
private:
    Bin bin;
    vector<Address> addresses;
    int id;
    double x,y;
public:
    Location();
    Location(int id, double x, double y);
    Location(int id,double x, double y, Bin bin);
    void addAddress(Address address);
    Bin getBin();
    vector<Address> getAddresses();
    int getId();
    void setBin(Bin bin);
    void resetBin();
    bool removeAddress(Address address);
    double getX();
    double getY();
    bool operator==(Location l);
};



#endif //PROJ_LOCATION_H
