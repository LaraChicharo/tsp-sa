#include "GraphFiller.h"
#include "Solution.h"
#ifndef METROLOGIST_H
    #include "Metrologist.h"
#endif
#include "Reader.h"
#include "Temperature.h"
#include "SimulatedAnnealing.h"


class WorldBuilder {
    private:
        std::vector<int> first_sequence;
        Reader* reader;
        Graph* graph;
        Metrologist* metrologist;
        GraphFiller* graph_builder;

        Temperature BuildTemperature(Solution* solution) const;

    public:
        WorldBuilder(Reader* reader);
        SimulatedAnnealing BuildSimulatedAnnealing() const;
        Solution* BuildFirstSolution() const;
};
