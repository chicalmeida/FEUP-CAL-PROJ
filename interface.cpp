//
// Created by bruno on 22/05/2021.
//
#include <iostream>
#include<string>
#include<sstream>
#include <algorithm>
#include "interface.h"
#include "Application.h"
using namespace std;
Menu buildMenu(){
    Menu mainMenu = Menu("mainMenu", "");

    Menu viewMenu = Menu("view", "view <type> <id> -> view information on something [bin, client, truct, location, user, central]");
    Menu addMenu = Menu("add", "add <type> -> add something [bin, client, truck, location, user, central, house]");
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

bool menuHandler(const std::string &input, Application *application){
    stringstream ss(input);
    string menu, type, id;
    ss >> menu;
    if(menu == "view"){
        ss >> type >> id;
        viewHandler(type, id, application);
    } else if(menu == "add"){
        ss >> type >> id;
        addHandler(type, id, application);
    } else if(menu == "remove"){
        ss >> type >> id;
        removeHandler(type, id, application);
    } else if(menu == "login"){
        ss >> type >> id;
        loginHandler(type, id, application);
    }

    return false;
}

bool viewHandler(const string &type, const string &idStr, Application *application){
    if(idStr != "" && !isNumber(idStr)){
        return false;
    }
    int id;
    if(isNumber(idStr)){
        stringstream ss(idStr);
        ss >> id;
    } else {
        id = -1;
    }
    if(type == "bin"){
        application->viewBin(id);
    } else if (type == "client"){
        //application->viewClient(id);
    } else if (type == "truck"){
        //application->viewTruck(id);
    } else if (type == "location"){
        application->viewLocation(id);
    } else if(type == "user"){

    } else if(type == "central"){

    } else {
        return false;
    }
    return true;
}
bool addHandler(const string &type, const string &idStr, Application *application){
    if(idStr != "" && !isNumber(idStr)){
        return false;
    }
    int id;
    if(isNumber(idStr)){
        stringstream ss(idStr);
        ss >> id;
    } else {
        id = -1;
    }
    if(type == "bin"){
        addBin(application);
    } else if (type == "client"){
        //viewClient(id);
    } else if (type == "truck"){
        //viewTruck(id);
    } else if (type == "location"){
        //viewLocation(id);
    } else if(type == "central"){

    } else {
        return false;
    }
    return true;

}
bool removeHandler(const string &type, const string &idStr, Application *application){
    if(idStr != "" && !isNumber(idStr)){
        return false;
    }
    int id;
    if(isNumber(idStr)){
        stringstream ss(idStr);
        ss >> id;
    } else {
        id = -1;
    }
    if(type == "bin"){
        //viewBin(type, id);
    } else if (type == "client"){
        //viewClient(id);
    } else if (type == "truck"){
        //viewTruck(id);
    } else if (type == "location"){
        //viewLocation(id);
    } else if(type == "user"){

    } else if(type == "central"){

    } else {
        return false;
    }
    return true;
}
bool loginHandler(const string &type, const string &idStr, Application *application){
    if(idStr != "" && !isNumber(idStr)){
        return false;
    }
    int id;
    if(isNumber(idStr)){
        stringstream ss(idStr);
        ss >> id;
    } else {
        id = -1;
    }
    if(type == "client"){
        //loginclient(id, application);
    } else if (type == "truck"){
        //logintruck(id, application);
    } else {
        return false;
    }
    return true;
}

void addBin(Application *application){
    int n;
    do{
        cout << "Type the number of bins you wish to add( > 0)\n";
        cin >> n;
    }while (n > 0);

    application->addBins(n);
}

bool isNumber(const std::string &idstr){return std::all_of(idstr.begin(), idstr.end(), ::isdigit);}

/*bool loginclient(int id, Application *application){
    Client* client = application->getClient(id);
    string str,str1,str2;
    if(client==NULL){return false;}
    cout << "Welcome "<<client->getName()<<" !"<<endl;
    cout<<"find - find closest bin"<<endl;
    cout<<"set - set garbage"<<endl;
    cin>>str;
    if(str=="find"){
        return false;
    }
    else if(str == "set"){
        cout<<"add (string type) (int weight)- add garbage"<<endl;
        cin>>str>>str1>>str2;
        if(str == "add"){

        }
    }
    else {
        return false;
    }
    return true;
}*/

