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
public:
    Location();
    Location(int id);
    Location(int id,Bin bin);
    void addAddress(Address address);
    Bin getBin();
    vector<Address> getAddresses();
    int getId();
    void setBin(Bin bin);
    void resetBin();
    bool removeAddress(Address address);
};



#endif //PROJ_LOCATION_H
