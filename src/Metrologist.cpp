#include "Metrologist.h"
#include <functional>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;


Metrologist::Metrologist(Graph* graph): graph(graph) {
    maxd = CalculateMaxd();
    normalizer = CalculateNormalizer();
}

double Metrologist::DegreesToRadians(double degrees) const {
    return M_PI * (degrees / 180);
}

double Metrologist::GetWs(int v, int u) const {
    if (v == u) return 0;
    if (graph->OriginalEdgeExists(v, u)) {
        return graph->GetEdgeVal(v, u);
    }
    double natural_dist = GetNaturalDist(v, u);
    double ws = natural_dist * maxd;
    return ws;
}

double Metrologist::GetNaturalDist(int v, int u) const {
    graph->GetVertice(v);
    double latv = this->DegreesToRadians(graph->GetVertice(v).GetLat());
    double latu = this->DegreesToRadians(graph->GetVertice(u).GetLat());
    double lonv = this->DegreesToRadians(graph->GetVertice(v).GetLon());
    double lonu = this->DegreesToRadians(graph->GetVertice(u).GetLon());
    double A = pow(sin((latv - latu) / 2), 2) +
        cos(latu) * cos(latv) * pow(sin((lonv - lonu) / 2), 2);
    double C = 2 * atan2(sqrt(A), sqrt(1 - A));
    double nat_dist = C * (double)EARTH_RADIUS;
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

/*double Metrologist::GetCost(Solution solution) const {
    double cost = 0;
    vector<int> sequence = solution.GetSequence();
    for (int i = 0; i < graph->GetNumberOfVertices() - 1; i++) {
        int v = sequence[i];
        int u = sequence[i + 1];
        cost += GetWs(v, u);
    }
    cost /= GetNormalizer();
    return cost;
}*/
