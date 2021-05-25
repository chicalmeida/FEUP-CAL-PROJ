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
    //Menu addMenu = Menu("add", "add <type> -> add something [bin, client, truck, location, user, central, house]");
    //Menu removeMenu = Menu("remove", "remove <type> <id> -> remove something [bin, client, truck, location, user, central]");
    Menu clientMenu = Menu("login", "login client <id> -> Login as a client");
    Menu userMenu = Menu("login", "login truck <id> -> Login as a truck user");

    mainMenu.addMenu(viewMenu);
    //mainMenu.addMenu(addMenu);
    //mainMenu.addMenu(removeMenu);
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
    } else if(menu == "remove" and false){
        ss >> type >> id;
        removeHandler(type, id, application);
    } else if(menu == "login"){
        ss >> type >> id;
        loginHandler(type, id, application);
    }

    return false;
}

bool viewHandler(const string &type, const string &idStr, Application *application){
    if(!isNumber(idStr)){
        return false;
    }
    if(idStr!="") {
        int id;
        if (isNumber(idStr)) {
            stringstream ss(idStr);
            ss >> id;
        } else {
            id = -1;
        }
        if (type == "bin") {
            application->viewBin(id);
        } else if (type == "client") {
            application->viewClient(id);
        } else if (type == "truck") {
            application->viewTruck(id);
        } else if (type == "location") {
            application->focusLocation(id);
        } else if (type == "central") {
            application->viewCentral();
        } else {
            return false;
        }
    }
    else{
        if (type == "bin") {
            application->viewBins();
        } else if (type == "client") {
            application->viewClients();
        } else if (type == "truck") {
            application->viewTrucks();
        } else if (type == "location") {
            application->viewLocations();
        } else if (type == "central") {
            application->viewCentral();
        } else {
            return false;
        }
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

GarbageType getGbType(string str){
    if(str == "paper"){
        return paper;
    }
    else if(str == "plastic"){
        return plastic;
    }
    else if(str == "glass"){
        return glass;
    }
    else if(str == "organic"){
        return organic;
    }
    else {
        return other;
    }
}

bool loginclient(int id, Application *application){
    Client* client = application->getClient(id);
    string str,str1,str2;
    if(client==NULL){return false;}
    cout << "Welcome "<<client->getName()<<" !"<<endl;
    cout<<"find - find closest bin"<<endl;
    cout<<"set - set garbage"<<endl;
    cin>>str;
    if(str=="find"){
        application->getNearestBin(paper, client);
    }
    else if(str == "set"){
        cout<<"add (string type) (int weight) - add garbage of type(paper,plastic,glass,organic, other)"<<endl;
        cin>>str>>str1>>str2;
        if(str == "add" ){
            client->addGarbage(Garbage(getGbType(str1),stoi(str2)));
            cout<<"Success!"<<endl;
        }
        else{
            return false;
        }
    }
    else {
        return false;
    }
    return true;
}

bool logintruck(int id, Application *application){
    Truck* client = application->getTruck(id);
    string str,str1,str2;
    if(client==NULL){return false;}
    cout << "Welcome "<<client->getName()<<" !"<<endl;
    cout<<"find - find course ro collect garbage"<<endl;
    cout<<"set (int)- set capacity"<<endl;
    cin>>str;
    if(str=="find"){
        application->calculateRoute(client, false);
    }
    else if(str == "set"){
        cin>>str1;
        client->setCapacity(stod(str1));
    }
    else {
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
        loginclient(id, application);
    } else if (type == "truck"){
        logintruck(id, application);
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



