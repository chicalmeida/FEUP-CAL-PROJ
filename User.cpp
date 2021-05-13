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

void User::setAddress(string address) {
    this->address=address;
}

int User::getNIF() {
    return NIF;
}

string User::getName() {
    return name;
}

string User::getAddress() {
    return address;
}

User::User() {
    this->NIF=0;
    this->name="";
    this->address="";
}

User::User(int nif) {
    this->NIF=nif;
    this->name="";
    this->address="";
}

User::User(int nif, string name, string address) {
    this->NIF=nif;
    this->name=name;
    this->address=address;
}

