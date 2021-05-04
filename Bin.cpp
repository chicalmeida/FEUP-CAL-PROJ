//
// Created by Francisca on 04/05/2021.
//


#include "Bin.h"

void Bin::setContent(vector<Garbage> content) {
    for(int j=0; j<content.size();j++){
        this->content[j]=content[j];
    }
}

void Bin::setCapacity(double capacity) {
    this->capacity=capacity;
}

void Bin::setLocation(string location) {
    this->location=location;
}

vector<Garbage> Bin::getContent() {
    return content;
}

double Bin::getCapacity() {
    return capacity;
}

string Bin::getLocation() {
    return location;
}

void Bin::setCurrCapacity(double curr) {
    this->currCapacity=curr;
}

double Bin::getCurrCapacity() {
    return currCapacity;
}

void Bin::addElem(Garbage elem) {
    if(currCapacity<capacity){
        content.push_back(elem);
        currCapacity+=elem.getWeight();
    }
    else{
        cout<<"Bin is full\n";
    }

}

Bin::Bin() {
    this->capacity=0;
    this->currCapacity=0;
    this->location="";
    this->content={};
}

Bin::Bin(double capacity, string location, double currCapacity) {
    this->capacity=capacity;
    this->location=location;
    this->currCapacity=currCapacity;
    this->content={};
}
