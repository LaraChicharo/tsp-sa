#ifndef GRAPH_H
    #include "Graph.h"
#endif
#include <vector>


class Metrologist {
    private:
        Graph* graph;
        double maxd;
        double normalizer;
        
        double CalculateMaxd();
        double CalculateNormalizer();
        double DegreesToRadians(double degrees) const;

    public:
        Metrologist(Graph* graph);

        double GetWs(int v, int u) const;
        double GetNaturalDist(int v, int u) const;
        double GetMaxd() const;
        double GetNormalizer() const;
        double GetCost() const;
};
