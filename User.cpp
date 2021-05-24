//
// Created by furta on 12/05/2021.
//

#include "User.h"
using namespace std;

void User::setNif(int nif) {
    this->NIF=nif;
}

void User::setName(int name) {
    this->name=name;
}

void User::setAddress(Address address) {
    this->address=address;
}

int User::getNIF() {
    return NIF;
}

string User::getName() {
    return name;
}

Address User::getAddress() {
    return address;
}

User::User() {
    this->NIF=0;
    this->name="";
    this->address=Address();
}

User::User(int nif, string name) {
    this->NIF=nif;
    this->name=name;
    this->address=Address();
}

User::User(int nif, string name, Address address) {
    this->NIF=nif;
    this->name=name;
    this->address=address;
}

Location *User::getLocation(){
    return location;
}

