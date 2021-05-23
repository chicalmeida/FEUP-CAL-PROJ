//
// Created by ultra on 22/05/2021.
//
#include<iostream>
#include "Menu.h"
using namespace std;
Menu::Menu(){

}
Menu::Menu(const string &name, const string &info){
    this->name = name;
    this->info = info;
}

void Menu::addMenu(Menu menu) {
    availableMenus.push_back(menu);
}

void Menu::printHelp(){
    for(Menu menu : availableMenus){
        cout << menu.getInfo() << endl;
    }
}

string Menu::getInfo(){
    return this->info;
}

string Menu::getName(){
    return this->name;
}

bool Menu::contains(std::string menuName){
    for(Menu menu : availableMenus){
        if(menu.getName() == menuName){
            return true;
        }
    }
    return false;
}
Menu Menu::get(std::string menuName){
    for(Menu menu : availableMenus){
        if(menu.getName() == menuName){
            return menu;
        }
    }
    return *this;
}

