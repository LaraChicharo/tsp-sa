#include "Graph.h"
using namespace std;


Graph::Graph(
    vector<int> vertices, vector<pair<pair<int, int>, double>> edges
):
    vertices(vertices)
    {
        for (pair<pair<int, int>, double> e : edges) {
            this->edges[e.first.first][e.first.second] = e.second;
            this->edges[e.first.second][e.first.first] = e.second;
        } 
        for (pair<pair<int, int>, double> e : edges) {
            this->edges_exists[e.first.first][e.first.second] = true;
            this->edges_exists[e.first.second][e.first.first] = true;
        }
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

