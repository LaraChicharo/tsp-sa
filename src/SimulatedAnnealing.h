#ifndef SOLUTION_H
    #include "Solution.h"
#endif
#ifndef TEMPERATURE_H
    #include "Temperature.h"
#endif
#include <cfloat>


class SimulatedAnnealing {
    private:
        Temperature temperature;
        Solution* initial_solution;
        int L;

    public:
        SimulatedAnnealing(
            Temperature temperature, Solution* initial_solution, int L
        );

        Solution* TresholdAccepting();
        std::pair<double, Solution*> ComputeBatch(Solution* solution);
};
