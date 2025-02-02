#include "GraphFiller.hpp"
using namespace std;


GraphFiller::GraphFiller() {}

void GraphFiller::FillGraph(Graph* graph, Metrologist* metrologist) {
    for (int v : graph->GetInstanceVertices()) {
        for (int u : graph->GetInstanceVertices()) {
            if (v == u) continue;
            double val = metrologist->GetWs(v, u);
            graph->SetEdgeVal(u, v, val);
            graph->SetEdgeVal(v, u, val);
        }
    }
}

