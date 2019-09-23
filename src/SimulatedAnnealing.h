#ifndef SOLUTION_H
    #include "Solution.h"
#endif
#ifndef TEMPERATURE_H
    #include "Temperature.h"
#endif
#include <cfloat>

/// @brief Implements the heuristic of Simulated Annealing for the TSP.
class SimulatedAnnealing {
    private:
        /// temperature of the simulation
        Temperature temperature;
        /// first proposed solution
        Solution* initial_solution;
        /// size of a batch
        int L;

    public:
        /// @brief Constructor.
        /// @param temperature proposed initial temperature for the
        /// heuristic, this is not going to be the real initial temperature
        /// @param initial_solution first proposed solution
        /// @param L size of a batch 
        SimulatedAnnealing(
            Temperature temperature, Solution* initial_solution, int L
        );

        /// @brief Executes the full heuristic and gets the best solution
        /// it found
        /// @return The best solution found.
        Solution* TresholdAccepting();
        /// @brief Computes a batch given a solution.
        /// @param solution the solution from which the batch will work upon.
        /// @return A pair, the first number is the accepted ratio
        /// of the batch and the second is the last solution computed.
        std::pair<double, Solution*> ComputeBatch(Solution* solution);
};
