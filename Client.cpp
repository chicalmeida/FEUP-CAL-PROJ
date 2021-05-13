//
// Created by Francisca on 04/05/2021.
//

#include "Client.h"

using namespace std;

Client::Client() : User(){
    cContent = {};
}

Client::Client(int nif) : User(nif){
    cContent = {};
}

Client::Client(int nif, string name, string address) : User(nif, name, address){
    cContent = {};
}

void Client::setGarbage(vector<Garbage> garbage){
    cContent = garbage;
}

vector<Garbage> Client::getGarbage(){
    return cContent;
}

void Client::addGarbage(Garbage gb){
    cContent.push_back(gb);
}
void Client::removeGarbage(Garbage gb){
    for(auto it = cContent.begin(); it!=cContent.end(); it++){
        if(*it == gb){
            cContent.erase(it);
            return;
        }
    }
}

double Client::getCurrWeight(){
    double total = 0;
    for(auto elem : cContent){
        total+=elem.getWeight();
    }
    return total;
}

void Client::deposit(Bin bin){
    for(auto garbage : cContent){
        bin.addElem(garbage);
        removeGarbage(garbage);
    }
}








