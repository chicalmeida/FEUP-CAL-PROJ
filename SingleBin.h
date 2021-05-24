//
// Created by ultra on 24/05/2021.
//

#ifndef PROJECT_SINGLEBIN_H
#define PROJECT_SINGLEBIN_H
#include "Garbage.h"

class SingleBin {
private:
    GarbageType type;
    int current, capacity;
public:

    SingleBin(GarbageType type, int capacity) : type{ type} , capacity{capacity}{}
    int getCurrent(){return current;}
    int getCapacity(){return capacity;}
    GarbageType getType(){return type;}

    bool add(int amount){
        if(current + amount <= capacity){
            current += amount;
            return true;
        }
        return false;
    }

    void reset(){current = 0;}
};


#endif //PROJECT_SINGLEBIN_H
