//
// Created by furta on 19/05/2021.
//

#include "Central.h"

Central::Central() : Address(){

}

Central::Central(int id) : Address(id){

}

Central::Central(int id, Location *location) : Address(id,location, central){

}


