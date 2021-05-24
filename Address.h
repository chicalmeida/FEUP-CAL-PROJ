//
// Created by furta on 13/05/2021.
//

#ifndef PROJ_ADDRESS_H
#define PROJ_ADDRESS_H
class Location;
#include "Bin.h"
#include "Location.h"

using namespace std;
enum AddressType {house, central};
class Address{
private:
    int id;
    Location *location;
    AddressType type;
public:
    Address();
    Address(int id);
    Address(int id, Location *location, AddressType type);
    void setLocation(Location *location);
    int getId();
    Location* getLocation();
};


#endif //PROJ_ADDRESS_H
