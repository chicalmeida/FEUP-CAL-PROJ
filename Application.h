//
// Created by ultra on 22/05/2021.
//

#ifndef PROJECT_APPLICATION_H
#define PROJECT_APPLICATION_H
#include "Menu.h"
#include "Location.h"
#include "Graph.h"
#include <stack>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Math.h"

class Application {
public:
    Application();
    void start();
    bool goBack();
    bool advanceMenu(std::string input);
    bool handleInput(std::string input);
    void loadgraph(string city);
    Graph<Location> getGraph();
private:
    Graph<Location> graph;
    std::stack<Menu> menuStack;
    Menu currentMenu;
    double getDistance(double x1, double x2, double y1, double y2);
    void readNodes(Graph<Location> &graph, string path, map<int,Vertex<Location>*> &vertexmap);
    void readEdges(Graph<Location> &graph, string path, map<int,Vertex<Location>*> &vertexmap);
};


#endif //PROJECT_APPLICATION_H
