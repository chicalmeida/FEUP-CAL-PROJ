#include <iostream>
#include "Application.h"
#include "Viewer.h"
using namespace std;

int main() {
    Application app = Application();
    //app.start();
    app.loadgraph("Porto");
    Viewer viewer;
    Graph<Location> graph= app.getGraph();
    viewer.graphtoview(graph,"Porto");
    return 0;
}
