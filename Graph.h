//
// Created by Francisca on 18/05/2021.
//

/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include "MutablePriorityQueue.h"
#include "Path.h"
#include<map>

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

template <class T>
class Vertex {
    T info;						// content of the vertex
    std::vector<Edge<T> > adj;		// outgoing edges

    double dist = 0;
    Vertex<T> *path = NULL;
    // required by MutablePriorityQueue

    bool visited = false;		// auxiliary field
    bool processing = false;	// auxiliary field

public:
    Vertex(T in);
    T getInfo() const;
    double getDist() const;
    Vertex *getPath() const;
    std::vector<Edge<T> > getAdj() const;
    void addEdge(Vertex<T> *dest, double w);
    bool operator<(Vertex<T> & vertex) const; // // required by MutablePriorityQueue
    friend class Graph<T>;
    //friend class MutablePriorityQueue<Vertex<T>>;
    int queueIndex = 0;
};


template <class T>
Vertex<T>::Vertex(T in): info(in) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
    adj.push_back(Edge<T>(d, w));
}

template <class T>
bool Vertex<T>::operator<(Vertex<T> & vertex) const {
    return this->dist < vertex.dist;
}

template <class T>
T Vertex<T>::getInfo() const {
    return this->info;
}

template <class T>
double Vertex<T>::getDist() const {
    return this->dist;
}

template <class T>
Vertex<T> *Vertex<T>::getPath() const {
    return this->path;
}

template <class T>
std::vector<Edge<T> > Vertex<T>::getAdj() const {
    return adj;
}


/********************** Edge  ****************************/

template <class T>
class Edge {
    Vertex<T> * dest;      // destination vertex
    double weight;         // edge weight
public:
    Edge(Vertex<T> *d, double w);
    Vertex<T> * getDest() const;
    double getWeight() const {return weight;}
    friend class Graph<T>;
    friend class Vertex<T>;
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {}

template <class T>
Vertex<T> * Edge<T>::getDest() const {
    return dest;
}


/*************************** Graph  **************************/

template <class T>
class Graph {
    std::vector<Vertex<T> *> vertexSet;    // vertex set
	map<int, Vertex<T> *> vertexMap;
public:
    Vertex<T> *findVertex(const T &in) const;
    void addVertex(Vertex<T> * in);
    bool addVertex(const T &in);
    void addVertex(Vertex<T> *in, int id);
    bool addEdge(const T &sourc, const T &dest, double w);
    int getNumVertex() const;
    std::vector<Vertex<T> *> getVertexSet() const;
    Vertex<T>* getVertex(int id);

    Vertex<T> * initSingleSource(const T &origin);
    inline bool relax(Vertex<T> *v, Vertex<T> *w, double weight);
    void unweightedShortestPath(const T &s);
    void dijkstraShortestPath(const T &s);
    std::vector<T> getPath(const T &origin, const T &dest) const;
    std::vector<T> dfs() const;
    void dfsVisit(Vertex<T> *v, std::vector<T> & res) const;
    Path aStarShortestPath(const int id_src, const int id_dest);


};



template <class T>
int Graph<T>::getNumVertex() const {
    return vertexSet.size();
}

template <class T>
Vertex<T> * Graph<T>::getVertex(int id){
    return vertexMap.find(id)->second;
}

template <class T>
std::vector<Vertex<T> *> Graph<T>::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return NULL;
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const T &in) {
    if ( findVertex(in) != NULL)
        return false;
    vertexSet.push_back(new Vertex<T>(in));
    return true;
}

template <class T>
void Graph<T>::addVertex(Vertex<T>  *in, int id) {
    vertexSet.push_back(in);
    vertexMap.insert(std::pair<int, Vertex<T>*>(id, in));
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    v1->addEdge(v2,w);
    return true;
}



template<class T>
Vertex<T> * Graph<T>::initSingleSource(const T &origin) {
    for(auto v : vertexSet) {
        v->dist = INF;
        v->path = nullptr;
    }
    auto s = findVertex(origin);
    s->dist = 0;
    return s;
}

template<class T>
inline bool Graph<T>::relax(Vertex<T> *v, Vertex<T> *w, double weight) {
    if (v->dist + weight < w->dist) {
        w->dist = v->dist + weight;
        w->path = v;
        return true;
    }
    else
        return false;
}

template<class T>
void Graph<T>::unweightedShortestPath(const T &orig) {
    auto s = initSingleSource(orig);
    queue< Vertex<T>* > q;
    q.push(s);
    while( ! q.empty() ) {
        auto v = q.front();
        q.pop();
        for(auto e: v->adj)
            if (relax(v, e.dest, 1))
                q.push(e.dest);
    }
}


template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
    auto s = initSingleSource(origin);
    MutablePriorityQueue<Vertex<T>> q;
    q.insert(s);
    while( ! q.empty() ) {
        auto v = q.extractMin();
        for (auto e : v->adj) {
            auto oldDist = e.dest->dist;
            if (relax(v, e.dest, e.weight)) {
                if (oldDist == INF)
                    q.insert(e.dest);
                else
                    q.decreaseKey(e.dest);
            }
        }
    }
}


template<class T>
std::vector<T> Graph<T>::getPath(const T &origin, const T &dest) const{
    vector<T> res;
    auto v = findVertex(dest);
    if (v == nullptr || v->dist == INF) // missing or disconnected
        return res;
    for ( ; v != nullptr; v = v->path)
        res.push_back(v->info);
    reverse(res.begin(), res.end());
    return res;
}

template <class T>
std::vector<T> Graph<T>::dfs() const {
    std::vector<T> res;
    for (auto v : vertexSet)
        v->visited = false;
    for (auto v : vertexSet)
        if (! v->visited)
            dfsVisit(v, res);
    return res;
}

template <class T>
void Graph<T>::dfsVisit(Vertex<T> *v, std::vector<T> & res) const {
    v->visited = true;
    res.push_back(v->info);
    for (auto & e : v->adj) {
        auto w = e.dest;
        if ( ! w->visited)
            dfsVisit(w, res);
    }
}



#endif /* GRAPH_H_ */

