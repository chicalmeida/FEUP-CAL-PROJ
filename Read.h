//
// Created by furta on 22/05/2021.
//

#ifndef LOCATION_CPP_READ_H
#define LOCATION_CPP_READ_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"
#include "Math.h"
#include "Location.h"

using namespace std;

void readEdges(string path){
    ifstream file(path);
    int size,id1,id2;
    int count =0;
    if(getline(file,line)){;
        size = stoi(line);
    }
    while(getline(file,line)) {
        line.erase(line.begin());
        line.erase(line.end() - 1);
        stringstream ss(line);

        getline(ss,str,',');
        id1 = stoi(str);
        getline(ss,str);
        id2 = stoi(str);
        //find1,find2, getdistance, addedge;
    }
    file.close();
}

double getDistance(double x1, double x2, double y1, double y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

void readNodes(string path){
    Graph<Location> graph;
    ifstream file(path);
    int size,id;
    int count =0;
    double x,y;
    string line,str,gb;

    if(getline(file,line)){;
        size = stoi(line);
    }
    while(getline(file,line)){
        line.erase(line.begin());
        line.erase(line.end()-1);
        stringstream ss(line);

        getline(ss,str,',');
        id = stoi(str);
        getline(ss,str,',');
        x = stod(str);
        getline(ss,str);
        y = stod(str);

        Location location(id,x,y);
        graph.addVertex(location);
    }
    file.close();
}

#endif //LOCATION_CPP_READ_H
