#include "GraphFiller.h"
#include "Solution.h"
#ifndef METROLOGIST_H
    #include "Metrologist.h"
#endif
#include "Reader.h"
#include "Temperature.h"
#include "SimulatedAnnealing.h"


/// @brief Class to wrap all the necesary steps to set up the heuristic
class WorldBuilder {
    private:
        /// first sequence of vertices
        std::vector<int> first_sequence;
        /// pointer to Reader instance
        Reader* reader;
        /// pointer to the graph of the heuristic
        Graph* graph;
        /// pointer to Metrologist instance
        Metrologist* metrologist;
        /// pointer to GraphFiller instance
        GraphFiller* graph_builder;

        /// @brief Builds an instance of the class Temperature.
        /// @param solution solution used to calculate the initial
        /// temperature.
        /// @return the instance just created.
        Temperature BuildTemperature(Solution* solution) const;

    public:
        /// @brief Constructor.
        /// @param reader an instance of the class Reader.
        WorldBuilder(Reader* reader);

        /// @brief builds an object of the class SimulatedAnnealing.
        /// @return the object.
        SimulatedAnnealing BuildSimulatedAnnealing() const;
        /// @brief generates a first solution based on first_sequence.
        /// @return said first solution.
        Solution* BuildFirstSolution() const;
};
