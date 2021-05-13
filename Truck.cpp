//
// Created by Francisca on 04/05/2021.
//

#include "Truck.h"

Truck::Truck() : User(){
    this->tContent={};
    this->capacity=0;
}

Truck::Truck(int nif, double capacity, double curr) : User(nif){
    this->capacity=capacity;
    this->tContent={};
}

Truck::Truck(int nif, string name, string address, double capacity, double curr) : User(nif,name,address){
    this->capacity=capacity;
    this->tContent={};
}

void Truck::setCapacity(double capacity) {
    this->capacity=capacity;
}

double Truck::getCapacity() {
    return capacity;
}

double Truck::getCurCapacity() {
    double total = 0;
    for (auto garbage : tContent ){
        total+=garbage.getWeight();
    }
    return total;
}

vector<Garbage> Truck::getTContent() {
    return tContent;
}

void Truck::addGarbage(Garbage elem) {
    if(getCurCapacity()<capacity){
        tContent.push_back(elem);
    }
    else{
        cout<<"Truck is full\n";
    }
}

void Truck::pickup(Client client) {
    auto garbage = client.getGarbage();
    for(auto elem : garbage){
        addGarbage(elem);
        client.removeGarbage(elem);
    }
}




