//
// Created by bruno on 22/05/2021.
//

#ifndef PROJECT_INTERFACE_H
#define PROJECT_INTERFACE_H

#include "Menu.h"
#include "Application.h"
Menu buildMenu();
std::string readInput();
bool menuHandler(const std::string &input, Application *application);
bool viewHandler(const std::string &type,const  std::string &id, Application *application);
bool addHandler(const std::string &type, const std::string &id, Application *application);
bool removeHandler(const std::string &type, const std::string &id, Application *application);
bool loginHandler(const std::string &type, const std::string &id, Application *application);
#endif //PROJECT_INTERFACE_H
