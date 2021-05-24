#include <iostream>
#include "Application.h"
#include "Viewer.h"
using namespace std;

int main() {
    Application app = Application();
    //app.start();
    app.loadgraph("Penafiel");
    Viewer viewer;
    Graph<Location*> graph= app.getGraph();
    viewer.graphtoview(graph);
    viewer.viewcentered(5142);

    app.addBins(400);
    app.addCentrals(1);
    app.addHouses(800);
    return 0;
}
