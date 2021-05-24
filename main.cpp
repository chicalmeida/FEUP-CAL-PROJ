#include <iostream>
#include "Application.h"
#include "Viewer.h"
using namespace std;

int main() {
    Application app = Application();
    //app.start();
    app.loadgraph("Penafiel");
    Viewer viewer;
    Graph<Location> graph= app.getGraph();
    viewer.graphtoview(graph,"Penafiel");
    return 0;
}
