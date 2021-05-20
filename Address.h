//
// Created by furta on 13/05/2021.
//

#ifndef PROJ_ADDRESS_H
#define PROJ_ADDRESS_H

#include "User.h"
#include "Bin.h"
#include "Location.h"

using namespace std;

class Address{
private:
    int id;
    Location location;
public:
    Address();
    Address(int id);
    Address(int id, Location location);
    void setLocation(Location location);
    int getId();
    Location getLocation();
};


#endif //PROJ_ADDRESS_H
