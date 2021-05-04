//
// Created by Francisca on 04/05/2021.
//

#ifndef PROJ_CLIENT_H
#define PROJ_CLIENT_H
#include <string>

using namespace std;


class Client {
private:
    int NIF;
    string name;
    string address;
public:
    Client();
    Client(int nif);
    Client(int nif, string name, string address);
    void setNif(int nif);
    void setName(int name);
    void setAddress(string address);
    int getNIF();
    string getName();
    string getAddress();


};


#endif //PROJ_CLIENT_H
