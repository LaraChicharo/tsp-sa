#pragma once

#include "Solution.hpp"
#include "Temperature.hpp"
#include "Journal.hpp"
#include <cfloat>


/// @brief Implements the heuristic of Simulated Annealing for the TSP.
class SimulatedAnnealing {
    private:
        /// temperature of the simulation
        Temperature temperature;
        /// first proposed solution
        Solution* initial_solution;
        /// pointer to journal
        Journal* journal;
        /// size of a batch
        int L;
        /// number of accepted solutions over time, globally
        int accepted_global;

    public:
        /// @brief Constructor.
        /// @param temperature proposed initial temperature for the
        /// heuristic, this is not going to be the real initial temperature
        /// @param initial_solution first proposed solution
        /// @param journal pointer to journal
        /// @param L size of a batch 
        SimulatedAnnealing(
            Temperature temperature,
            Solution* initial_solution,
            Journal* journal,
            int L
        );

        /// @brief Destructor.
        ~SimulatedAnnealing();

        /// @brief Executes the full heuristic and gets the best solution
        /// it found
        /// @return The best solution found.
        Solution* TresholdAccepting();
        /// @brief Executes TresholdAccepting but also uses the sweep
        /// neighbourhood technique.
        /// @return The best solution found.
        Solution* TresholdAcceptingSweep();
        /// @brief Computes a batch given a solution.
        /// @param solution the solution from which the batch will work upon.
        /// @return A pair, the first number is the accepted ratio
        /// of the batch and the second is the last solution computed.
        std::pair<double, Solution*> ComputeBatch(Solution* solution);
        /// @brief Writes info on the solutions obtained to a file
        /// in the form of points.
        void WriteToJournalFiles();
};
