//
// Created by furta on 12/05/2021.
//

#ifndef BIN_CPP_USER_H
#define BIN_CPP_USER_H

#include "Garbage.h"
#include <string>
#include <vector>
#include "Address.h"
using namespace std;

class User {
protected:
    int NIF;
    string name;
    Address address;
    Location *location;
public:
    User();
    User(int nif, string name);
    User(int nif, string name, Address address);
    void setNif(int nif);
    void setName(int name);
    void setAddress(Address address);
    int getNIF();
    string getName();
    Address getAddress();
};

#endif //BIN_CPP_USER_H
