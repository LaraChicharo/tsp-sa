#include "Graph.h"
#include <iostream>

using namespace std;


Vertice::Vertice(
    int id,
    double lat,
    double lon,
    long long population
): id(id), lat(lat), lon(lon), population(population) {}

int Vertice::GetId() const {
    return id;
}

double Vertice::GetLat() const {
    return lat;
}

double Vertice::GetLon() const {
    return lon;
}

long long Vertice::GetPopulation() const {
    return population;
}


Graph::Graph(
    vector<int> vertices,
    vector<Vertice> all_vertices,
    vector<pair<pair<int, int>, double>> original_edges
):
    all_vertices(all_vertices), vertices(vertices)
    {
        this->original_edges_exists = new bool*[MAX_VERTICES];
        
        this->edges = new double*[MAX_VERTICES];
        this->edges_exists = new bool*[MAX_VERTICES];
        for (int i = 0; i < MAX_VERTICES; i++) {
            this->original_edges_exists[i] = new bool[MAX_VERTICES];
            
            this->edges[i] = new double[MAX_VERTICES];
            this->edges_exists[i] = new bool[MAX_VERTICES];
        
            for (int j=0; j<MAX_VERTICES; j++) {
                this->original_edges_exists[i][j] = false;
                
                this->edges[i][j] = 0;
                this->edges_exists[i][j] = false;
            }
        
        }

        for (pair<pair<int, int>, double> e : original_edges) {
            this->edges[e.first.first][e.first.second] = e.second;
            this->edges[e.first.second][e.first.first] = e.second;
        }
        for (pair<pair<int, int>, double> e : original_edges) {
            original_edges_exists[e.first.first][e.first.second] = true;
            original_edges_exists[e.first.second][e.first.first] = true;
            
            edges_exists[e.first.first][e.first.second] = true;
            edges_exists[e.first.second][e.first.first] = true;
        }
    }

Graph::~Graph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        delete [] original_edges_exists[i];
        
        delete [] edges[i];
        delete [] edges_exists[i];
    }
    delete [] edges;
    delete [] edges_exists;
    
    delete [] original_edges_exists;
}

double Graph::GetEdgeVal(int v, int u) const {
    return edges[v][u];
}

void Graph::SetEdgeVal(int v, int u, double val) {
    edges[v][u] = val;
}
 
vector<int> Graph::GetInstanceVertices() const {
    return vertices;
}

Vertice Graph::GetVertice(int v) const {
    return all_vertices[v];
}

bool Graph::EdgeExists(int v, int u) const {
    return edges_exists[v][u];
}

bool Graph::OriginalEdgeExists(int v, int u) const {
    return original_edges_exists[v][u];
}

int Graph::GetNumberOfVertices() const {
    return vertices.size();
}
