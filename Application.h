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
#include "Garbage.h"
#include "Client.h"
#include "User.h"
#include "Truck.h"
#include "House.h"

class Application {
public:
    Application();
    void start();
    bool goBack();
    bool advanceMenu(std::string input);
    bool handleInput(std::string input);
    void loadgraph(string city);
    void addBins(int n);
    Graph<Location *> getGraph();

private:
    Graph<Location*> graph;
    std::stack<Menu> menuStack;
    std::map<int, Client> clients;
    std::map<int, Truck> trucks;
    std::map<int, Garbage> garbages;
    std::map<int, User> users;
    std::map<int, House> houses;
    Menu currentMenu;
    double getDistance(double x1, double x2, double y1, double y2);
    void readNodes(Graph<Location*> &graph, string path, map<int,Vertex<Location*>*> &vertexmap);
    void readEdges(Graph<Location*> &graph, string path, map<int,Vertex<Location*>*> &vertexmap);
    /**
     * Save the current data in files with path ~/data/{breads, cakes, clients, employees, sales, stores}.txt
     */
    void saveData();
    /**
     * Read files with path ~/data/{breads, cakes, clients, employees, sales, stores}.txt
     * Initialize attributes of Menu with data loaded from these files.
     */
    void loadData();
};


#endif //PROJECT_APPLICATION_H
