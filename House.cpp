//
// Created by furta on 19/05/2021.
//

#include "House.h"
#include "Client.h"

House::House() : Address(){
    habitants.clear();
}

House::House(int id) : Address(id){
    habitants.clear();
}

House::House(int id, Location *location) : Address(id, location, house){
    habitants.clear();
}

void House::addHabitant(Client *habitant){
    habitants.push_back(habitant);
}

bool House::removeHabitant(Client *habitant){
    for(auto it = habitants.begin(); it!=habitants.end(); it++){
        if(habitant->getNIF() == (*it)->getNIF()){
            habitants.erase(it);
            return true;
        }
    }
    return false;
}

int House::geNumHabitants(){
    return habitants.size();
}

vector<Client *> House::getHabitants(){
    return habitants;
}

int House::setGarbage(int n){
    garbage = n;
}

int House::getGarbage(){
    return garbage;
    int weight = 0;
    for(Client *client : habitants){
        for(Garbage garbage : client->getGarbage()){
            if(true){
                weight+= garbage.getWeight();
            }
        }
    }
    return weight;
}