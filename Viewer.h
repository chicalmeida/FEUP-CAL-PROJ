//
// Created by furta on 24/05/2021.
//

#ifndef FEUP_CAL_PROJ_VIEWER_H
#define FEUP_CAL_PROJ_VIEWER_H
#include "Graph.h"
#include <graphviewer.h>

class Viewer {
public:
    Viewer();
    void graphtoview(Graph<Location *> &graph, string city);
    void printpath(vector<int> &path);
    void viewcentered(int idlocation);
private:
    GraphViewer gv;
    //map<int,GraphViewer::Node*> nodemap;
};

Viewer::Viewer() {}

void Viewer::graphtoview(Graph<Location *> &graph) {
    vector<Vertex<Location *> *> vertexset = graph.getVertexSet();
    int id=0;

    gv.setCenter(sf::Vector2f(0, 0));
    gv.createWindow(1000, 600);
    /*string bg = "resources/" + city + "/strong_component.png";
    gv.setBackground(bg);*/

    for(auto vertex : vertexset){
        GraphViewer::Node node = gv.addNode(vertex->getInfo()->getId(), sf::Vector2f(vertex->getInfo()->getX(), vertex->getInfo()->getY()));
        cout<<vertex->getInfo()->getId()<<"  "<<vertex->getInfo()->getX()<<"  "<<vertex->getInfo()->getY()<<endl;
        //nodemap.insert(pair<int,GraphViewer::Node*>(vertex->getInfo().getId(),&node));
    }

    for(auto vertex : vertexset){
        vector<Edge<Location *> > edges = vertex->getAdj();
        for(auto edge : edges){
            GraphViewer::Edge adj = gv.addEdge(id,gv.getNode(vertex->getInfo()->getId()),gv.getNode(edge.getDest()->getInfo()->getId()), GraphViewer::Edge::EdgeType::DIRECTED);
            id++;
        }
    }
    gv.join();
}

void Viewer::printpath(vector<int> &path){
    for(auto point : path){
        //nodemap.at(point)->setColor(GraphViewer::BLUE);
        gv.getNode(point).setColor(GraphViewer::BLUE);
    }
}

void Viewer::viewcentered(int idlocation){
    gv.getNode(idlocation).setColor(GraphViewer::YELLOW);
    gv.getNode(idlocation).setSize(1000);
    gv.getNode(idlocation).setLabel("HERE");
}

#endif //FEUP_CAL_PROJ_VIEWER_H
