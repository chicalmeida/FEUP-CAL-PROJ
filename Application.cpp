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

        //Location * location = (Location *) malloc(sizeof(Location));

        Location *location = new Location(id,x,y);
        Vertex<Location*> *v = new Vertex<Location*>(location);
        graph.addVertex(v, id);
        vertexmap.insert(pair<int,Vertex<Location*>*>(id,v));
        locationMap.insert(pair<int,Location*>(id,location));
        count++;
    }
    file.close();
}

Graph<Location*> Application::getGraph(){
    return graph;
}

void Application::addBins(int n){
    int i=0, currentId = bins.size();
    while(i < n){
        int id = rand() % graph.getNumVertex();

        Location *location = locationMap.find(id)->second;
        if(locationMap.find(id) == locationMap.end()) continue;
        if(location->getBin() == nullptr){
            Bin *newBin = new Bin(location);
            GarbageType types[] = {paper, plastic, glass, organic, other };
            for(const GarbageType &type : types){
                newBin->addBin(type, 100);
            }
            location->setBin(newBin);
            bins.insert(std::pair<int, Bin*>(currentId + i+1, newBin));
            i++;
        }
    }
}

void Application::addCentrals(int n){
    int i=0;
    while(i < n){
        int id = rand() % graph.getNumVertex();
        Location *location = locationMap.find(id)->second;
        if(locationMap.find(id) == locationMap.end()) continue;
        Central central = Central(i+1, location);
        this->central = central;
        i++;
    }
}

void Application::addHouses(int n){
    int i=0, currentId = houses.size();
    while(i < n){
        int id = rand() % graph.getNumVertex();
        if(locationMap.find(id) == locationMap.end()) continue;
        Location *location = locationMap.find(id)->second;
        if(true){
            House *newHouse = new House(id, location);
            houses.insert(std::pair<int, House*>(currentId + i+1, newHouse));
            i++;
            location->addAddress((Address *) newHouse);
        }
    }
    int x = 0;
}

Address* Application::getRandomAddress(){
    do{
        int id = rand() % houses.size() ;
        auto p = houses.find(id);
        if(p == houses.end()) continue;
        return ((Address *) p->second);
    }while(true);
}

void Application::addClients(){
    addClient(1,"Jose");
    addClient(2,"Tiago");
    addClient(3,"Filipa");
    addClient(4,"Marcia");
    addClient(5,"Raquel");
    addClient(6,"Manel");
    addClient(7,"Francisco");
    addClient(8,"Conceicao");
    addClient(9,"Graca");
    addClient(10,"Martim");
}

void Application::addClient(int id, string name){
    Client *client = new Client(id, name);
    client->setAddress(*getRandomAddress());
    clients.insert(pair<int, Client*>(client->getNIF(), client));

}

void Application::getNearestBin(GarbageType type, Client *client){
    Location * location = client->getAddress().getLocation();
    Vertex<Location *> *firstNode = graph.getVertex(location->getId());
    stack<Vertex<Location *> *> nodeStack;
    stack<double> distanceStack;
    map<int, double> visited;
    nodeStack.push(firstNode);
    distanceStack.push(0.0);
    double currentDistance = 0;
    double minDistance = 999999.0;
    Location *chosenBin = nullptr;
    int i = 0;
    while(!nodeStack.empty()){
        i++;
        cout << i << "\n";
        Vertex<Location *> *node = nodeStack.top();
        currentDistance = distanceStack.top();
        nodeStack.pop();
        distanceStack.pop();
        Location *location = node->getInfo();

        if(minDistance < currentDistance)
            continue;

        if(visited.find(location->getId()) != visited.end()){
            if(visited.find(location->getId()) -> second > currentDistance){
                visited.insert(pair<int, double>(location->getId(), currentDistance));
            } else
                continue;
        } else {
            visited.insert(pair<int, double>(location->getId(), currentDistance));
        }

        if(location->getBin() != nullptr){

            if(location->getBin()->hasType(type)){
                if(currentDistance < minDistance){
                    minDistance = currentDistance;
                    chosenBin = location;
                    continue;
                }
            }
        }

        vector<Edge<Location *>> edges = node->getAdj();
        for(Edge<Location *> &edge : edges){
            Vertex<Location *> *next = edge.getDest();
            int id = next->getInfo()->getId();
            if(visited.find(id) == visited.end() || (visited.find(id)->second < currentDistance)){
                nodeStack.push(next);
                distanceStack.push(currentDistance + edge.getWeight());
            }
        }
    }
    cout << "Found with distance " << minDistance << "\n";
    //viewBin(location->getId());

}
void Application::addTrucks(int n){
    /*int i=0;
    while(i < n){
        int id = rand() % graph.getNumVertex();
        Location *location = locationMap.find(id)->second;
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

void Application::viewBin(int id){
    Bin* bin = bins.at(id);
    viewer.focusLocation(bin->getLocation()->getId());
}

void Application::close(){
    viewer.close();
}

Client* Application::getClient(int id){
    cout << "Entrou aqui??";
    return clients.at(id);
}

Truck* Application::getTruck(int id){
    return trucks.at(id);
}

