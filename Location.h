//
// Created by furta on 13/05/2021.
//

#ifndef PROJ_LOCATION_H
#define PROJ_LOCATION_H
class Address;


#include "Bin.h"
#include "Address.h"

using namespace std;


class Location{
private:
    Bin bin;
    vector<Address> addresses;
    int id;
    double x,y;
public:
    Location();
    Location(int id);
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
    bool operator==(const Location l) const;
};



#endif //PROJ_LOCATION_H
