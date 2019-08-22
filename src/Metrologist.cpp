#include "Metrologist.h"
using namespace std;


Metrologist::Metrologist(Graph graph): 
    graph(graph)
    {
        double maxd = 0;
        for (int v : graph.GetVertices()) {
            for (int u=0; u<MAX_VERTICES; u++) {
                if (v == u) continue;
                maxd = max(graph.GetEdgeVal(v, u), maxd);
            }
        }
    }

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
    return maxd;
}
