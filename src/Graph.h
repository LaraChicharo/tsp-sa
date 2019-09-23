#include "Constants.h"
#include <vector>
#include <string>


#define GRAPH_H


/// @brief Represents a vertice (a city) in the graph of the system.
class Vertice {
    private:
        /// id of the vertice in the database
        int id;
        /// latitude of the vertice
        double lat;
        /// longitude of the vertice
        double lon;
        /// population of the city represented
        long long population;

    public:
        /// @brief Constructor.
        /// @param id         id of the vertice in the database
        /// @param lat        latitude of the vertice
        /// @param lon        longitude of the vertice
        /// @param population population of the city represented
        Vertice(
            int id,
            double lat,
            double lon,
            long long population
        );

        /// @brief returns the id of the vertice.
        int GetId() const;
        /// @brief returns the latitued of the vertice.
        double GetLat() const;
        /// @brief returns the longitude of the vertice.
        double GetLon() const;
        /// @brief returns the population of the city represented.
        long long GetPopulation() const;
};


/// @brief Represents an undirected graph where each vertex
/// is a city and each edge is a route from city A to city B.
class Graph {
    private:
        /// vertices of the graph
        std::vector<int> vertices;
        /// all vertices that exists (not all of them are part of the graph)
        std::vector<Vertice> all_vertices;
        
        /// matrix that represents if a certain edge is real/original
        /// or fake/added later
        bool** original_edges_exists;
        
        /// weight of the edges
        double** edges;

        /// holds wether a vertex exists or not
        bool** edges_exists;
    public:
        
        /// @brief Constructor.
        /// @param vertices       vertices of the graph 
        /// @param all_vertices   all vertices that exists in the database
        /// @param original_edges edges that are not made up
        Graph(
            std::vector<int> vertices,
            std::vector<Vertice> all_vertices, 
            std::vector<std::pair<std::pair<int, int>, double>> original_edges
        );
        
        ~Graph();        

        /// @brief Returns the value/weight of the edge
        /// going from vertice v to vertice u
        /// @param v vertice id
        /// @param u vertice id
        double GetEdgeVal(int v, int u) const;
        /// @brief Sets the value of the edge (u, v) to val
        /// @param v vertice id
        /// @param u vertice id
        /// @param val new value of the edge
        void SetEdgeVal(int v, int u, double val);

        /// @brief Returns a copy of the vertices of this graph
        std::vector<int>GetInstanceVertices() const;
        /// @brief Returns the vertice with id v
        /// @param v id of vertice to return
        Vertice GetVertice(int v) const;
        
        /// @brief Returns wether the edge (v, u) is original or 
        /// is one of the extremely long edges.
        /// @param v vertice id
        /// @param u vertice id
        bool OriginalEdgeExists(int v, int u) const;

        /// @brief Returns wether the edge (v, u) exists in the graph or not
        /// @param v vertice id
        /// @param u vertice id
        bool EdgeExists(int v, int u) const;

        /// @brief Returns the number of vertices in this graph
        int GetNumberOfVertices() const;
};
