//
// Created by Francisca on 04/05/2021.
//

#ifndef PROJ_GARBAGE_H
#define PROJ_GARBAGE_H
#include <string>
#include <iostream>

using namespace std;

enum garbageType {paper,plastic,glass,metal,organic};

class Garbage {
private:

    string type;
    int weight;
    garbageType getType(string strtype);
    bool verifyGarbage(string type);
public:
    const static std::string FILENAME;
    Garbage();
    Garbage(string type, int weight);
    bool setType(string type);
    void setWeight(int weight);
    string getType();
    int getWeight();
    bool operator==(Garbage gb);

    /**
     * Write garbage in the file.
     * @param os Stream where to save.
     * @param client Client to be saved.
     * @return Stream where was saved.
     */
    friend std::ostream& operator<< (std::ostream &os, const Garbage &garbage);
};


#endif //PROJ_GARBAGE_H
