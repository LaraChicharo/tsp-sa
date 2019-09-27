#pragma once

#include "Graph.hpp"
#include "earth.hpp"


/// @brief Calculates measurements. Distance between cities, etc.
class Metrologist {
    private:
        /// graph in which some measurements are going to be based on
        Graph* graph;
        /// max distance between two cities in the graph
        double maxd;
        /// normalizer as described in the specification of the problem
        double normalizer;
        
        /// @brief Calculates the maximum distance between two cities
        /// in the graph and returns it.
        double CalculateMaxd();
        /// @brief Calculates the normalizer and returns it.
        double CalculateNormalizer();
        /// @brief Returns the conversion of degrees to radians
        /// @param degrees the quantity to convert.
        double DegreesToRadians(double degrees) const;

    public:
        /// @brief Constructor.
        /// @param the graph in which some measurements
        /// are going to be based on
        Metrologist(Graph* graph);

        /// @brief Calculates weight of the edge (v, u) 
        /// (not necessarily the real, natural distance).
        /// @param v vertex id
        /// @param u vertex id
        /// @return  weight of the edge (v, u)
        double GetWs(int v, int u) const;
        /// @brief Calculates the natural distance between the to vertices
        /// v and u.
        /// @param v vertice id
        /// @param u vertice id
        /// @return  the natural distance between the vertices
        double GetNaturalDist(int v, int u) const;
        /// @brief Returns the maximum distance between any two cities
        /// in the graph.
        double GetMaxd() const;
        /// @brief Returns the normalizer.
        double GetNormalizer() const;
};
