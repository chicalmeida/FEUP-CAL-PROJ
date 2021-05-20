//
// Created by furta on 13/05/2021.
//

#ifndef PROJ_CENTRAL_H
#define PROJ_CENTRAL_H

#include "User.h"
#include "Bin.h"

using namespace std;


class Central : public Address{
private:
public:
    Central();
    Central(int id);
    Central(int id, Location location);
};


#endif //PROJ_CENTRAL_H
