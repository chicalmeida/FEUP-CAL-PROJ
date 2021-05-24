//
// Created by Francisca on 04/05/2021.
//


#include "Bin.h"



void Bin::addBin(GarbageType type, int capacity) {
    SingleBin singleBin = SingleBin(type, capacity);
    bins.push_back(singleBin);
}

void Bin::addGarbage(Garbage elem) {
    for(SingleBin bin : bins){
        if(bin.getType() == elem.getType()){
            if(!bin.add(elem.getWeight())){
                cout <<"Couldn't add \n";
            }
        }
    }

}

Bin::Bin() {
    this->capacity=0;

}

Bin::Bin(double capacity) {
    this->capacity=capacity;

}

void Bin::resetBin(){
    this->bins = {};
}
