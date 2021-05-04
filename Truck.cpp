//
// Created by Francisca on 04/05/2021.
//

#include "Truck.h"

Truck::Truck() {
    this->id=0;
    this->tContent={};
    this->currCapacity=0;
    this->capacity=0;
}

Truck::Truck(int id, double capacity, double curr) {
    this->id=id;
    this->capacity=capacity;
    this->currCapacity=curr;
    this->tContent={};
}

void Truck::setID(int id) {
    this->id=id;
}

void Truck::setCapacity(double capacity) {
    this->capacity=capacity;
}

void Truck::setCurrCapacity(double curr) {
    this->currCapacity=curr;
}

void Truck::setTContent(vector<Garbage> Tcontent) {
    for(int i=0; i<Tcontent.size(); i++){
        this->tContent[i]=Tcontent[i];
    }
}

int Truck::getID() {
    return id;
}

double Truck::getCapacity() {
    return capacity;
}

double Truck::getCurCapacity() {
    return currCapacity;
}

vector<Garbage> Truck::getTContent() {
    return tContent;
}

void Truck::addGarbage(Garbage elem) {
    if(currCapacity<capacity){
        tContent.push_back(elem);
        currCapacity+=elem.getWeight();
    }
    else{
        cout<<"Truck is full\n";
    }
}




