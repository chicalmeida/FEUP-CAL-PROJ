//
// Created by ultra on 22/05/2021.
//

#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H
#include<vector>
#include<iostream>
class Menu {
public:
    Menu();
    Menu(const std::string &name, const std::string &info);
    void addMenu(Menu menu);
    std::string getName();
    std::string getInfo();
    void printHelp();
    bool contains(std::string menuName);
    Menu get(std::string menuName);
private:
    std::string name;
    std::string info;
    std::vector<Menu> availableMenus;
};


#endif //PROJECT_MENU_H
