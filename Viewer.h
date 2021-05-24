//
// Created by furta on 24/05/2021.
//

#ifndef FEUP_CAL_PROJ_VIEWER_H
#define FEUP_CAL_PROJ_VIEWER_H
#include "Graph.h"
#include "Location.h"
#include <graphviewer.h>

class Viewer {
public:
    Viewer();
    void graphtoview(Graph<Location *> &graph);
    void printpath(vector<int> &path);
    void focusLocation(int idlocation);
    void viewLocation(int idlocation, string label);
    void resetappearance();
    void close();
private:
    vector<int> activeNodes;
    bool focused;
    int lastfocusid;
    GraphViewer gv;
    //map<int,GraphViewer::Node*> nodemap;
};

#endif //FEUP_CAL_PROJ_VIEWER_H
