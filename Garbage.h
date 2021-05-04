//
// Created by Francisca on 04/05/2021.
//

#ifndef PROJ_GARBAGE_H
#define PROJ_GARBAGE_H
#include <string>

using namespace std;


class Garbage {
private:
    string type;
    int weight;
public:
    Garbage();
    Garbage(string type, int weigth);
    void setType(string type);
    void setWeight(int weight);
    string getType();
    int getWeight();

};


#endif //PROJ_GARBAGE_H
