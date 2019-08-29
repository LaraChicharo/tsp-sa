#include "Constants.h"
#include <vector>
#include <string>


#define GRAPH_H


class Vertice {
    private:
        int id;
        double lat;
        double lon;
        long long population;

    public:
        Vertice(
            int id,
            double lat,
            double lon,
            long long population
        );

        int GetId() const;
        double GetLat() const;
        double GetLon() const;
        long long GetPopulation() const;
};


class Graph {
    private:
        std::vector<int> vertices;
        std::vector<Vertice> all_vertices;
        double** edges;
        bool** edges_exists;
    public:
        Graph(
            std::vector<int> vertices,
            std::vector<Vertice> all_vertices, 
            std::vector<std::pair<std::pair<int, int>, double>> edges
        );
        
        ~Graph();        

        double GetEdgeVal(int v, int u) const;
        void SetEdgeVal(int v, int u, double val);
        std::vector<int>GetVertices() const;
        Vertice GetVertice(int v) const;
        
        bool EdgeExists(int v, int u) const;
        int GetNumberOfVertices() const;
};
