//
// Created by ultra on 22/05/2021.
//
#include<iostream>
#include<sstream>
#include "Application.h"
#include "interface.h"
using namespace std;

Application::Application() {
    currentMenu = buildMenu();
    menuStack.push(currentMenu);
    readGraph("resources/porto/full_edges.txt");
}

void Application::start(){
    bool isDone = false;
    std::string input;
    while(!isDone){
        cout << "Current Menu = " << currentMenu.getName() << "\n";
        currentMenu.printHelp();
        input = readInput();
        isDone = this->handleInput(input);
    }
}

bool Application::handleInput(string input) {
    bool isDone = false;
    if(input == "quit"){
        isDone = true;
    }
    else if(input == "back"){
        isDone = !this->goBack();
    }
    else if(this->advanceMenu(input)){
        if(!menuHandler(input, this)){
            this->goBack();
        }
    }
    return isDone;
}

bool Application::advanceMenu(string input) {
    stringstream ss(input);
    string menuName;
    ss >> menuName;
    if(currentMenu.contains(menuName)){
        currentMenu = currentMenu.get(menuName);
        menuStack.push(currentMenu);
        return true;
    }
    return false;
}

bool Application::goBack() {
    menuStack.pop();
    if(menuStack.empty()){
        return false;
    }
    currentMenu = menuStack.top();

    return true;
}

void Application::readGraph(std::string path){
    readNodes(path, this->graph);
    readEdges(path, this->graph);
}
