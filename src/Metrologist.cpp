#include "Metrologist.h"
#include <functional>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;


Metrologist::Metrologist(Graph* graph): graph(graph) {}

double Metrologist::GetWs(int v, int u) const {
    if (graph->EdgeExists(v, u)) return graph->GetEdgeVal(v, u);
    double natural_dist = GetNaturalDist(v, u);
    return natural_dist * maxd;
}

// Not fully implemented yet
double Metrologist::GetNaturalDist(int v, int u) const {
    const int RADIUS = 1; // Not the final value
    
    double latv = 1;
    double latu = 1;
    double lonv = 1;
    double lonu = 1;
    double A = pow(sin((latv - latu) / 2), 2) +
        cos(latu) * pow(cos(latv) * sin((lonv - lonu) / 2), 2);
    double C = 2 * atan2(sqrt(A), sqrt(1 - A));
    double nat_dist = C * RADIUS;
    return nat_dist;
}

double Metrologist::GetMaxd() const {
    double maxd = 0;
    for (int v : graph->GetVertices()) {
        for (int u : graph->GetVertices()) {
            if (v == u || !graph->EdgeExists(v, u)) continue;
            maxd = max(graph->GetEdgeVal(v, u), maxd);
        }
    }
    return maxd;
}

double Metrologist::GetNormalizer() const {
    double normalizer = 0;
    vector<double> edges;
    for (int v : graph->GetVertices()) {
        for (int u : graph->GetVertices()) {
            if (v <= u || !graph->EdgeExists(v, u)) continue;
            edges.push_back(graph->GetEdgeVal(v, u));
        }
    }
    sort(edges.begin(), edges.end(), greater<double>());
    int end = min<int>(edges.size(), graph->GetNumberOfVertices() - 1);
    for (int i = 0; i < end; i++) {
        normalizer += edges[i];
    }
    return normalizer;
}
