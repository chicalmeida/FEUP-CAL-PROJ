#include <iostream>
#include <graphviewer.h>
#include "Graph.h"
#include "Location.h"
#include "Application.h"

void graphtoview(Graph<Location> graph){

}


int main() {
    //Application app = Application();
    //app.start();
    GraphViewer gv;
    gv.setCenter(sf::Vector2f(300, 300));
    gv.createWindow(600, 600);
    gv.join();

    return 0;
}
