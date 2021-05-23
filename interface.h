//
// Created by bruno on 22/05/2021.
//

#ifndef PROJECT_INTERFACE_H
#define PROJECT_INTERFACE_H

#include "Menu.h"

Menu buildMenu();
std::string readInput();
bool menuHandler(std::string input);
bool viewHandler(std::string type, std::string id);
bool addHandler(std::string type, std::string id);
bool removeHandler(std::string type, std::string id);
bool loginHandler(std::string type, std::string id);
#endif //PROJECT_INTERFACE_H
