//
// Created by Francisca on 04/05/2021.
//

#include "Garbage.h"

void Garbage::setType(string type) {
    this->type=type;
}

void Garbage::setWeight(int weight) {
    this->weight=weight;
}

string Garbage::getType() {
    return type;
}

int Garbage::getWeight() {
    return weight;
}

Garbage::Garbage() {
    this->type="";
    this->weight=0;
}

Garbage::Garbage(string type, int weigth) {
    this->type=type;
    this->weight=weigth;
}

