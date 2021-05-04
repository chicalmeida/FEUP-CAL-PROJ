//
// Created by Francisca on 04/05/2021.
//

#include "Client.h"

using namespace std;

void Client::setNif(int nif) {
    this->NIF=nif;
}

void Client::setName(int name) {
    this->name=name;
}

void Client::setAddress(string address) {
    this->address=address;
}

int Client::getNIF() {
    return NIF;
}

string Client::getName() {
    return name;
}

string Client::getAddress() {
    return address;
}

Client::Client() {
    this->NIF=0;
    this->name="";
    this->address="";
}

Client::Client(int nif) {
    this->NIF=nif;
    this->name="";
    this->address="";
}

Client::Client(int nif, string name, string address) {
    this->NIF=nif;
    this->name=name;
    this->address=address;
}





