#include "Metrologist.h"
#include "earth.h"
#include <functional>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;


Metrologist::Metrologist(Graph* graph): graph(graph) {
    maxd = CalculateMaxd();
    normalizer = CalculateNormalizer();
}

double Metrologist::GetWs(int v, int u) const {
    if (graph->OriginalEdgeExists(v, u)) return graph->GetEdgeVal(v, u);
    double natural_dist = GetNaturalDist(v, u);
    return natural_dist * maxd;
}

double Metrologist::GetNaturalDist(int v, int u) const {
    double latv = graph->GetVertice(v).GetLat();
    double latu = graph->GetVertice(u).GetLat();
    double lonv = graph->GetVertice(v).GetLon();
    double lonu = graph->GetVertice(u).GetLon();
    double A = pow(sin((latv - latu) / 2), 2) +
        cos(latu) * pow(cos(latv) * sin((lonv - lonu) / 2), 2);
    double C = 2 * atan2(sqrt(A), sqrt(1 - A));
    double nat_dist = C * RADIUS;
    return nat_dist;
}

double Metrologist::CalculateMaxd() {
    double maxd = 0;
    for (int v : graph->GetInstanceVertices()) {
        for (int u : graph->GetInstanceVertices()) {
            if (v == u || !graph->OriginalEdgeExists(v, u)) continue;
            maxd = max(graph->GetEdgeVal(v, u), maxd);
        }
    }
    return maxd;
}

double Metrologist::GetMaxd() const {
    return maxd;
}

double Metrologist::CalculateNormalizer() {
    double normalizer = 0;
    vector<double> edges;
    for (int v : graph->GetInstanceVertices()) {
        for (int u : graph->GetInstanceVertices()) {
            if (v <= u || !graph->OriginalEdgeExists(v, u)) continue;
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

double Metrologist::GetNormalizer() const {
    return normalizer;
}
