//
// Created by ultra on 22/05/2021.
//

#ifndef PROJECT_APPLICATION_H
#define PROJECT_APPLICATION_H
#include "Menu.h"
#include "Read.h"
#include <stack>
#include "User.h"


class Application {
public:

    Application();
    void start();
    bool goBack();
    bool advanceMenu(std::string input);
    bool handleInput(std::string input);
    void readGraph(std::string path);
    void addUser();
private:
    Graph<Location> graph;
    std::stack<Menu> menuStack;
    Menu currentMenu;
};


#endif //PROJECT_APPLICATION_H
