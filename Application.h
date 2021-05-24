//
// Created by ultra on 22/05/2021.
//

#ifndef PROJECT_APPLICATION_H
#define PROJECT_APPLICATION_H
#include "Menu.h"
#include <stack>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Math.h"
#include "Viewer.h"
#include "Garbage.h"
#include "Bin.h"
#include "Client.h"
#include "User.h"
#include "Truck.h"
#include "House.h"
#include "Central.h"
class Application {
public:
    Application();
    void start();
    bool goBack();
    bool advanceMenu(std::string input);
    bool handleInput(std::string input);
    void loadgraph(string city);
    void addBins(int n);
    void addCentrals(int n);
    void addHouses(int n);
    void addTrucks();
    void addTruck(int id, double cap);
    void addClient(int id, string name);
    void addClients();
    void calculateRoute(Truck *truck, bool singleHouse);
    Address* getRandomAddress();
    void viewLocation(int id);
    //void viewLocation(int id);
    void viewBin(int id);
    void viewClient(int id);
    void viewTruck(int id);
    void viewBins();
    void viewClients();
    void viewTrucks();
    void viewCentral();
    void viewLocations();
    void close();
    Client* getClient(int id);
    Truck* getTruck(int id);
    Graph<Location *> getGraph();
    void getNearestBin(GarbageType type, Client *client);
private:
    Viewer viewer;
    Graph<Location*> graph;
    std::stack<Menu> menuStack;
    Central central;
    std::map<int, Client*> clients;
    std::map<int, Truck*> trucks;
    std::map<int, Bin*> bins;
    std::map<int, House*> houses;
    std::map<int, Location*> locationMap;
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
