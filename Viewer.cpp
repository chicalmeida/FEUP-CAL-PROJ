//
// Created by furta on 24/05/2021.
//

#include "Viewer.h"

Viewer::Viewer() {focused=false;}

void Viewer::graphtoview(Graph<Location *> &graph) {
    vector<Vertex<Location *> *> vertexset = graph.getVertexSet();
    int id=0;

    gv.setCenter(sf::Vector2f(0, 0));
    gv.createWindow(1000, 600);
    /*string bg = "resources/" + city + "/strong_component.png";
    gv.setBackground(bg);*/

    for(auto vertex : vertexset){
        GraphViewer::Node node = gv.addNode(vertex->getInfo()->getId(), sf::Vector2f(vertex->getInfo()->getX(), vertex->getInfo()->getY()));
        //cout<<vertex->getInfo()->getId()<<"  "<<vertex->getInfo()->getX()<<"  "<<vertex->getInfo()->getY()<<endl;
        //nodemap.insert(pair<int,GraphViewer::Node*>(vertex->getInfo().getId(),&node));
    }

    for(auto vertex : vertexset){
        vector<Edge<Location *> > edges = vertex->getAdj();
        for(auto edge : edges){
            GraphViewer::Edge adj = gv.addEdge(id,gv.getNode(vertex->getInfo()->getId()),gv.getNode(edge.getDest()->getInfo()->getId()), GraphViewer::Edge::EdgeType::DIRECTED);
            id++;
        }
    }
}

void Viewer::printpath(vector<int> &path){
    for(int point : path){
        //nodemap.at(point)->setColor(GraphViewer::BLUE);
        try{
        gv.getNode(point).setColor(GraphViewer::BLUE);
        gv.getNode(point).setSize(15);
        } catch(int e){

        }
    }
}

void Viewer::focusLocation(int idlocation){
    if(focused){
        gv.getNode(lastfocusid).setColor(GraphViewer::RED);
        gv.getNode(lastfocusid).setSize(10);
        gv.getNode(lastfocusid).setLabel("");
    }
    gv.setCenter(gv.getNode(idlocation).getPosition());
    gv.setScale(0.5);
    gv.getNode(idlocation).setColor(GraphViewer::YELLOW);
    gv.getNode(idlocation).setSize(100);
    //gv.getNode(idlocation).setLabel("HERE");
    lastfocusid = idlocation;
}

void Viewer::viewLocation(int idlocation, string label){
    gv.getNode(idlocation).setColor(GraphViewer::YELLOW);
    gv.getNode(idlocation).setSize(100);
    gv.getNode(idlocation).setLabel(label);
    activeNodes.push_back(idlocation);
}

void Viewer::resetappearance(){
    for(auto id : activeNodes){
        gv.getNode(id).setColor(GraphViewer::RED);
        gv.getNode(id).setSize(10);
        gv.getNode(id).setLabel("");
    }
}

void Viewer::close(){
    gv.join();
}

