//
// Created by furta on 12/05/2021.
//

#ifndef BIN_CPP_USER_H
#define BIN_CPP_USER_H

#include "Garbage.h"
#include <string>
#include <vector>
using namespace std;

class User {
protected:
    int NIF;
    string name;
    string address;
public:
    User();
    User(int nif);
    User(int nif, string name, string address);
    void setNif(int nif);
    void setName(int name);
    void setAddress(string address);
    int getNIF();
    string getName();
    string getAddress();
};

#endif //BIN_CPP_USER_H
