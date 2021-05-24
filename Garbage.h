//
// Created by Francisca on 04/05/2021.
//

#ifndef PROJ_GARBAGE_H
#define PROJ_GARBAGE_H
#include <string>
#include <iostream>

using namespace std;

enum GarbageType {paper,plastic,glass,organic, other};

class Garbage {
private:

    string type;
    int weight;
    GarbageType getType(string strtype);
    bool verifyGarbage(string type);
public:
    const static std::string FILENAME;
    Garbage();
    Garbage(GarbageType type, int weight);
    bool setType(string type);
    void setWeight(int weight);
    GarbageType getType();
    int getWeight();
    //bool operator==(Garbage gb);

    /**
     * Write garbage in the file.
     * @param os Stream where to save.
     * @param client Client to be saved.
     * @return Stream where was saved.
     */
    friend std::ostream& operator<< (std::ostream &os, const Garbage &garbage);
};


#endif //PROJ_GARBAGE_H
