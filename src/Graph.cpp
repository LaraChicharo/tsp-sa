#include "Graph.h"
#include <iostream>

using namespace std;


Graph::Graph(
    vector<int> vertices, vector<pair<pair<int, int>, double>> edges
):
    vertices(vertices)
    {
        this->edges = new double*[MAX_VERTICES];
        this->edges_exists = new bool*[MAX_VERTICES];
        for (int i = 0; i < MAX_VERTICES; i++) {
            this->edges[i] = new double[MAX_VERTICES];
            this->edges_exists[i] = new bool[MAX_VERTICES];
        
            for (int j=0; j<MAX_VERTICES; j++) {
                this->edges[i][j] = 0;
                this->edges_exists[i][j] = false;
            }
        
        }

        for (pair<pair<int, int>, double> e : edges) {
            this->edges[e.first.first][e.first.second] = e.second;
            this->edges[e.first.second][e.first.first] = e.second;
        }
        for (pair<pair<int, int>, double> e : edges) {
            edges_exists[e.first.first][e.first.second] = true;
            edges_exists[e.first.second][e.first.first] = true;
        }
    }

Graph::~Graph() {
    for (int i=0; i<MAX_VERTICES; i++) {
        delete [] edges[i];
        delete [] edges_exists[i];
    }
    delete [] edges;
    delete [] edges_exists;
    cout << "destroying graph" << endl;
}

double Graph::GetEdgeVal(int v, int u) {
    return edges[v][u];
}

void Graph::SetEdgeVal(int v, int u, double val) {
    edges[v][u] = val;
}

void Graph::SetVertices(vector<int> vertices) {
    this->vertices = vertices;
}

vector<int> Graph::GetVertices() {
    return vertices;
}

bool Graph::EdgeExists(int v, int u) {
    return edges_exists[v][u];
}

int Graph::GetNumberOfVertices() {
    return vertices.size();
}

