//
// Created by Francisca on 04/05/2021.
//

#include "Garbage.h"

garbageType Garbage::getType(string strtype){
    garbageType type;
    if(strtype == "paper"){
        type = paper;
    }
    else if (strtype == "plastic"){
        type = plastic;
    }
    else if (strtype == "glass"){
        type = glass;
    }
    else if (strtype == "metal"){
        type = metal;
    }
    else if (strtype == "organic"){
        type = organic;
    }
    else {
        cout<<strtype<<" trash type not accepted! (available types are only 'paper', 'plastic', 'glass', 'metal' and 'organic')"<<endl;
    }
}

bool Garbage::verifyGarbage(string type){
    if(type == "paper" || type == "plastic" || type == "glass" || type == "metal" || type == "organic"){
        return true;
    }
    return false;
}

bool Garbage::setType(string type) {
    if(verifyGarbage(type)) {
        this->type = type;
        return true;
    }
    return false;
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
    if(verifyGarbage(type)) {
        this->type = type;
    }
    else{
        this->type = "";
    }
    this->weight=weigth;
}

bool Garbage::operator==(Garbage gb){
    if(type == gb.getType() && weight == gb.getWeight()){
        return true;
    }
    return false;
}

