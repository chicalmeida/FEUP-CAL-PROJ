//
// Created by ultra on 22/05/2021.
//
#include<iostream>
#include<sstream>
#include "Application.h"
#include "interface.h"
using namespace std;

Application::Application() {
    graph = Graph<Location>();
    currentMenu = buildMenu();
    menuStack.push(currentMenu);
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
        if(!menuHandler(input)){
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

void Application::loadgraph(string city){
    map<int,Vertex<Location>*> vertexmap;
    string strnodes = "resources/"+city+"/full_nodes_xy.txt";
    string stredges = "resources/"+city+"/full_edges.txt";
    readNodes(graph,strnodes,vertexmap);
    readEdges(graph,stredges,vertexmap);
}

double Application::getDistance(double x1, double x2, double y1, double y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

void Application::readEdges(Graph<Location> &graph, string path, map<int,Vertex<Location>*> &vertexmap){
    ifstream file(path);
    int size,id1,id2;
    int count =0;
    char comma;
    string line,str;

    if(getline(file,line)){
        size = stoi(line);
    }
    while(getline(file,line)) {
        count++;
        line.erase(line.begin());
        line.erase(line.end() - 1);
        stringstream ss(line);

        ss>>id1>>comma>>id2;

        Vertex<Location>* v1 = vertexmap.at(id1);
        Vertex<Location>* v2 = vertexmap.at(id2);
        double weight = getDistance(v1->getInfo().getX(),v2->getInfo().getX(),v1->getInfo().getY(),v1->getInfo().getY());
        v1->addEdge(v2,weight);
    }
    file.close();
}

void Application::readNodes(Graph<Location> &graph, string path, map<int,Vertex<Location>*> &vertexmap){
    ifstream file(path);
    int size,id;
    int count =0;
    double x,y;
    char comma;
    string line,str,gb;
    vertexmap.clear();

    if(getline(file,line)){
        size = stoi(line);
    }
    while(getline(file,line)){
        line.erase(line.begin());
        line.erase(line.end()-1);
        stringstream ss(line);

        ss>>id>>comma>>x>>comma>>y;

        Location location(id,x,y);
        Vertex<Location> *v = new Vertex<Location>(location);
        graph.addVertex(v);
        vertexmap.insert(pair<int,Vertex<Location>*>(id,v));
        count++;
    }
    file.close();
}

Graph<Location> Application::getGraph(){
    return graph;
}