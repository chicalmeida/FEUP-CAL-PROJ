//
// Created by bruno on 22/05/2021.
//
#include <iostream>
#include<string>
#include<sstream>
#include "interface.h"
using namespace std;
Menu buildMenu(){
    Menu mainMenu = Menu("mainMenu", "");

    Menu viewMenu = Menu("view", "view <type> <id> -> view information on something [bin, client, truct, location, user, central]");
    Menu addMenu = Menu("add", "add <type> -> add something [bin, client, truck, location, user, central]");
    Menu removeMenu = Menu("remove", "remove <type> <id> -> remove something [bin, client, truck, location, user, central]");
    Menu clientMenu = Menu("client", "login client <id> -> Login as a client");
    Menu userMenu = Menu("user", "login user <id> -> Login as an user");

    mainMenu.addMenu(viewMenu);
    mainMenu.addMenu(addMenu);
    mainMenu.addMenu(removeMenu);
    mainMenu.addMenu(clientMenu);
    mainMenu.addMenu(userMenu);

    //Add client menus


    //Add user menus


    return mainMenu;

}

string readInput(){
    string input;
    getline(cin, input);
    return input;
}

bool menuHandler(std::string input){
    stringstream ss(input);
    string menu, type, id;
    ss >> menu;
    if(menu == "view"){
        ss >> type >> id;
        viewHandler(type, id);
    } else if(menu == "add"){
        ss >> type >> id;
        addHandler(type, id);
    } else if(menu == "remove"){
        ss >> type >> id;
        removeHandler(type, id);
    } else if(menu == "login"){
        ss >> type >> id;
        loginHandler(type, id);
    }

    return false;
}

bool viewHandler(string type, string id){
    return true;
}
bool addHandler(string type, string id){
    return true;
}
bool removeHandler(string type, string id){
    return true;
}
bool loginHandler(string type, string id){
    return true;
}


