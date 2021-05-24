//
// Created by Francisca on 04/05/2021.
//

#include "Garbage.h"
#include "files.h"

const string Garbage::FILENAME =  "garbages.txt";



bool Garbage::setType(GarbageType type) {
    this->type = type;
    return true;
}

void Garbage::setWeight(int weight) {
    this->weight=weight;
}

GarbageType Garbage::getType() {
    return type;
}

int Garbage::getWeight() {
    return weight;
}

Garbage::Garbage() {
    this->type=other;
    this->weight=0;
}

Garbage::Garbage(GarbageType type, int weigth) {
    this->type = type;
    this->weight=weigth;
}


bool Garbage::operator==(Garbage gb){
    if(type == gb.getType() && weight == gb.getWeight()){
        return true;
    }
    return false;
}


ostream& operator<< (ostream &os, const Garbage &garbage){
    //files::writeVariable(os, "name", garbage.name);
    os << "\n";
    return os;
}

