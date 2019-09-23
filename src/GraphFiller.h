#include "Metrologist.h"

/// @brief Fills the graph of cities with fake edges.
class GraphFiller {
    public:
        GraphFiller();

        /// @brief Fills the graph passed with fake edges.
        /// @param graph       the graph to fill
        /// @param metrologist metrologist to make measuremets with
        void FillGraph(Graph* graph, Metrologist* metrologist);
};
