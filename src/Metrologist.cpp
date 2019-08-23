#include "Metrologist.h"
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;


Metrologist::Metrologist(Graph graph): graph(graph) {}

double Metrologist::GetWs(int v, int u) {
    if (graph.EdgeExists(v, u)) return graph.GetEdgeVal(v, u);
    double natural_dist = GetNaturalDist(v, u);
    return natural_dist * maxd;
}

// Not implemented yet
double Metrologist::GetNaturalDist(int v, int u) {
    return 1;
}

double Metrologist::GetMaxd() {
    double maxd = 0;
    for (int v : graph.GetVertices()) {
        for (int u=0; u<MAX_VERTICES; u++) {
            if (v == u || !graph.EdgeExists(v, u)) continue;
            maxd = max(graph.GetEdgeVal(v, u), maxd);
        }
    }
    return maxd;
}

double Metrologist::GetNormalizer() {
    vector<double> edges_vals;
    for (int v : graph.GetVertices()) {
        for (int u=0; u<MAX_VERTICES; u++) {
            if (v == u || !graph.EdgeExists(v, u)) continue;
            edges_vals.push_back(graph.GetEdgeVal(v, u));
        }
    }
    cout << "before sort" << endl;
    sort(edges_vals.begin(), edges_vals.end(), greater<double>());
    double normalizer = 0;
    for (
        int i = 0;
        i < min<int>(graph.GetNumberOfVertices() - 1, edges_vals.size());
        i++
    )
        normalizer += edges_vals[i];
    
    return normalizer;
}
