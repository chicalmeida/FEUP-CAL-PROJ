#include <iostream>
#include "Application.h"
#include <unistd.h>
using namespace std;

int main() {
    Application app;
    app.loadgraph("Penafiel");
    app.addBins(400);
    app.addCentrals(1);
    app.addHouses(800);
    
    app.start();
    /*Viewer viewer;
    viewer.graphtoview(graph);
    viewer.focusLocation(5142);
    usleep(3* 1000000);
    viewer.focusLocation(5145);
    viewer.close();*/


    return 0;
}
