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

vector<Garbage> Bin::getContent() {
    return content;
}

double Bin::getCapacity() {
    return capacity;
}

double Bin::getCurrCapacity() {
    double total = 0;
    for(auto garbage : content){
        total+=garbage.getWeight();
    }
    return total;
}

void Bin::addElem(Garbage elem) {
    if(getCurrCapacity()<capacity){
        content.push_back(elem);
    }
    else{
        cout<<"Bin is full\n";
    }

}

Bin::Bin() {
    this->capacity=0;
    this->content={};
}

Bin::Bin(double capacity) {
    this->capacity=capacity;
    this->content={};
}

void Bin::resetBin(){
    content.clear();
}
