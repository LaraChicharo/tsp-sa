#include "Metrologist.h"
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;


Metrologist::Metrologist(Graph* graph): graph(graph) {}

double Metrologist::GetWs(int v, int u) const {
    if (graph->EdgeExists(v, u)) return graph->GetEdgeVal(v, u);
    double natural_dist = GetNaturalDist(v, u);
    return natural_dist * maxd;
}

// Not implemented yet
double Metrologist::GetNaturalDist(int v, int u) const {
    return 1;
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

// Not implemented yet
double Metrologist::GetNormalizer() const {
    return 1;
}
