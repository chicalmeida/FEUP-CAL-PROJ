//
// Created by furta on 19/05/2021.
//

#include "Address.h"

Address::Address(){
    id = 0;
}

Address::Address(int id){
    this->id=id;
}

Address::Address(int id, Location *location,AddressType type){
    this->id=id;
    this->location = location;
    this->type = type;
}

void Address::setLocation(Location *location){
    this->location = location;
}

int Address::getId(){
    return id;
}

Location* Address::getLocation(){
    return location;
}

