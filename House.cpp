//
// Created by furta on 19/05/2021.
//

#include "House.h"

House::House() : Address(){
    habitants.clear();
}

House::House(int id) : Address(id){
    habitants.clear();
}

House::House(int id, Location *location) : Address(id, location){
    habitants.clear();
}

void House::addHabitant(User habitant){
    habitants.push_back(habitant);
}

bool House::removeHabitant(User habitant){
    for(auto it = habitants.begin(); it!=habitants.end(); it++){
        if(habitant.getNIF() == it->getNIF()){
            habitants.erase(it);
            return true;
        }
    }
    return false;
}

int House::geNumHabitants(){
    return habitants.size();
}

vector<User> House::getHabitants(){
    return habitants;
}