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
    void graphtoview(Graph<Location> &graph, string city);
    void printpath(vector<int> &path)const;
private:
    GraphViewer gv;
    map<int,GraphViewer::Node*> nodemap;
    vector<GraphViewer::Node> gvnodes;
    vector<GraphViewer::Edge> gvedges;
};

Viewer::Viewer() {
    nodemap.clear();
    gvnodes.clear();
    gvedges.clear();
}

void Viewer::graphtoview(Graph<Location> &graph, string city) {
    vector<Vertex<Location> *> vertexset = graph.getVertexSet();
    int id=0;

    gv.setCenter(sf::Vector2f(0, 0));
    gv.createWindow(1500, 700);
    string bg = "resources/" + city + "/full.png";
    gv.setBackground(bg);

    for(auto vertex : vertexset){
        GraphViewer::Node node = gv.addNode(vertex->getInfo().getId(), sf::Vector2f(vertex->getInfo().getX(), vertex->getInfo().getY()));
        cout<<vertex->getInfo().getId()<<"  "<<vertex->getInfo().getX()<<"  "<<vertex->getInfo().getY()<<endl;
        gvnodes.push_back(node);
        nodemap.insert(pair<int,GraphViewer::Node*>(vertex->getInfo().getId(),&node));
    }

    for(auto vertex : vertexset){
        vector<Edge<Location> > edges = vertex->getAdj();
        for(auto edge : edges){
            GraphViewer::Edge adj = gv.addEdge(id,*nodemap.at(vertex->getInfo().getId()),*nodemap.at(edge.getDest()->getInfo().getId()), GraphViewer::Edge::EdgeType::DIRECTED);
            gvedges.push_back(adj);
            id++;
        }
    }
    gv.join();
}

void Viewer::printpath(vector<int> &path) const{
    for(auto point : path){
        nodemap.at(point)->setColor(GraphViewer::BLUE);
    }
}
#endif //FEUP_CAL_PROJ_VIEWER_H
