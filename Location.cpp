//
// Created by furta on 19/05/2021.
//

#include "Location.h"

Location::Location(){
    bin = Bin();
    id = 0;
    addresses.clear();
}

Location::Location(int id){
    this->bin = Bin();
    this->id = id;
    addresses.clear();
}

Location::Location(int id, Bin bin){
    this->bin = bin;
    this->id = id;
    addresses.clear();
}

void Location::addAddress(Address address){
    addresses.push_back(address);
}

void Location::setBin(Bin bin){
    this->bin = bin;
}

void Location::resetBin(){
    bin.resetBin();
}

bool Location::removeAddress(Address address){
    for (auto it = addresses.begin(); it!=addresses.end(); it++){
        if(it->getId() == address.getId()){
            addresses.erase(it);
            return true;
        }
    }
    return false;
}

Bin Location::getBin(){
    return bin;
}

vector<Address> Location::getAddresses(){
    return addresses;
}

int Location::getId(){
    return id;
}