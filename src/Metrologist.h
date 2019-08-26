#include "Graph.h"
#include <vector>


class Metrologist {
    private:
        Graph* graph;
        double maxd;

    public:
        Metrologist(Graph* graph);

        double GetWs(int v, int u) const;
        double GetNaturalDist(int v, int u) const;
        double GetMaxd() const;
        double GetNormalizer() const;
};
