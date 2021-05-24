//
// Created by furta on 19/05/2021.
//

#include "Location.h"

Location::Location(){
    bin = new Bin(this);
    id = 0;
    x=0;
    y=0;
    addresses.clear();
}

Location::Location(int id){
    bin = new Bin(this);
    this->id = id;
    x=0;
    y=0;
    addresses.clear();
}

Location::Location(int id, double x, double y){
    this->bin = new Bin(this);
    this->id = id;
    this->x=x;
    this->y=y;
    addresses.clear();
}

Location::Location(int id, double x, double y, Bin *bin){
    this->bin = bin;
    this->id = id;
    this->x=x;
    this->y=y;
    addresses.clear();
}

void Location::addAddress(Address *address){
    addresses.push_back(address);
}

void Location::setBin(Bin *bin){
    this->bin = bin;
}

void Location::resetBin(){
    bin->resetBin();
}

bool Location::removeAddress(Address address){
    /*
    for (auto it = addresses.begin(); it!=addresses.end(); it++){
        if(it->getId() == address.getId()){
            addresses.erase(it);
            return true;
        }
    }
     */
    return false;
}

Bin *Location::getBin(){
    return bin;
}

vector<Address *> Location::getAddresses(){
    return addresses;
}

int Location::getId(){
    return id;
}

double Location::getX(){
    return x;
}
double Location::getY(){
    return y;
}

bool Location::operator==(Location l) const{
    return (this->id==l.getId());
}