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
        Reader* reader;

        Temperature BuildTemperature(Solution sol) const;

    public:
        WorldBuilder(Reader* reader);
        SimulatedAnnealing BuildSimulatedAnnealing() const;
        Solution BuildFirstSolution() const;
};
