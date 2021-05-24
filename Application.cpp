//
// Created by ultra on 22/05/2021.
//
#include<iostream>
#include<sstream>
#include "Application.h"
#include "interface.h"
#include "exceptions.h"
#include "files.h"
#include "House.h"
#include "Central.h"
using namespace std;

Application::Application() {
    graph = Graph<Location*>();
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

void Application::loadgraph(string city){
    map<int,Vertex<Location*>*> vertexmap;
    string strnodes = "resources/"+city+"/strong_nodes_xy.txt";
    string stredges = "resources/"+city+"/strong_edges.txt";
    readNodes(graph,strnodes,vertexmap);
    readEdges(graph,stredges,vertexmap);
    viewer.graphtoview(graph);
}

double Application::getDistance(double x1, double x2, double y1, double y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

void Application::readEdges(Graph<Location*> &graph, string path, map<int,Vertex<Location*>*> &vertexmap){
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

        Vertex<Location*>* v1 = vertexmap.at(id1);
        Vertex<Location*>* v2 = vertexmap.at(id2);
        double weight = getDistance(v1->getInfo()->getX(),v2->getInfo()->getX(),v1->getInfo()->getY(),v1->getInfo()->getY());
        v1->addEdge(v2,weight);
    }
    file.close();
}

void Application::readNodes(Graph<Location*> &graph, string path, map<int,Vertex<Location*>*> &vertexmap){
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

        Location *location = new Location(id,x,y);
        Vertex<Location*> *v = new Vertex<Location*>(location);
        graph.addVertex(v, id);
        vertexmap.insert(pair<int,Vertex<Location*>*>(id,v));
        count++;
    }
    file.close();
}

Graph<Location*> Application::getGraph(){
    return graph;
}

void Application::addBins(int n){
    int i=0;
    while(i < n){
        int id = rand() % graph.getNumVertex();
        Vertex<Location*> *vertex = graph.getVertex(id);
        Location *location = vertex->getInfo();
        if(location->getBin() != nullptr){
            Bin *newBin = new Bin();
            GarbageType types[] = {paper, plastic, glass, organic, other };
            for(const GarbageType &type : types){
                newBin->addBin(type, 100);
            }
            bins.insert(std::pair<int, Bin*>(i+1, newBin));
            i++;
        }
    }
}

void Application::addCentrals(int n){
    int i=0;
    while(i < n){
        int id = rand() % graph.getNumVertex();
        Vertex<Location*> *vertex = graph.getVertex(id);
        Location *location = vertex->getInfo();
        Central central = Central(i+1, location);
        this->central = central;
        i++;
    }
}

void Application::addHouses(int n){
    int i=0;
    while(i < n){
        int id = rand() % graph.getNumVertex();
        Vertex<Location*> *vertex = graph.getVertex(id);
        Location *location = vertex->getInfo();
        if(true){
            House *newHouse = new House(id, location);
            houses.insert(std::pair<int, House*>(i+1, newHouse));
            i++;
            location->addAddress((Address *) newHouse);
        }
    }
}

void Application::addTrucks(int n){
    /*int i=0;
    while(i < n){
        int id = rand() % graph.getNumVertex();
        Vertex<Location*> *vertex = graph.getVertex(id);
        Location *location = vertex->getInfo();
        if(true){
            Truck *newTruck = new Truck(id, 100, location);
            trucks.insert(std::pair<int, Truck*>(i+1, newHouse));
            i++;
            location->addAddress((Address *) newHouse);
        }
    }*/
}
void Application::loadData() {
    string line;
    string path = "resources/data/";

    /*
    std::map<int, Client> clients;
    std::map<int, Truck> trucks;
    std::map<int, Bin> bins;
    std::map<int, User> users;
    std::map<int, House> houses;

     try {
        ifstream is(path + "bins.txt");
        //Load breads
        try {
            while (!is.eof() && is.is_open()) {
                getline(is, line);
                if (line.empty()) {
                    continue;
                }
                map<string, string> mapping = files::readData(line);
            }
            Bin *bin = new Bin(mapping);
            is.close();
        }catch(exception &e){
            throw ReadingDataException("Breads");
        }
    */
}

void Application::saveData(){
    string path = "resources/data";
    /*
    ofstream outCakes, outBreads, outEmployees, outStores, outClients, outSales;

    //Save products
    outCakes.open(path + Cake::FILENAME, ios::out);
    outBreads.open(path + Bread::FILENAME, ios::out);
    for(auto it : productsMapping){
        if(it.second->getCategory() == Category::bread){
            outBreads << *(Bread*) it.second;
        } else {
            outCakes << *(Cake*) it.second;
        }
    }
    outBreads.close();
    outCakes.close();

    //Save employees
    outEmployees.open(path + Employee::FILENAME, ios::out);
    for(auto it : employeesMapping){
        outEmployees << *(it.second);
    }
    outEmployees.close();

    //Save Stores
    outStores.open(path + Store::FILENAME, ios::out);
    for(auto it : storesMapping){
        outStores << *(it.second);
    }
    outStores.close();

    // Save Clients
    outClients.open(path + Client::FILENAME, ios::out);
    for(auto it: clientsMapping){
        outClients << *(it.second);
    }
    outClients.close();

    // Save Sales
    outSales.open(path + Sale::FILENAME, ios::out);
    for(Sale * sale : sales){
        outSales << *sale;
    }
    outSales.close();
     */
}

void Application::viewLocation(int id){
    viewer.focusLocation(id);
}

void Application::close(){
    viewer.close();
}

