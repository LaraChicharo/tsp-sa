#include "Constants.h"
#include <vector>


class Graph {
    private:
        std::vector<int> vertices;
        double** edges;
        bool** edges_exists;
    public:
        Graph(
            std::vector<int> vertices, 
            std::vector<std::pair<std::pair<int, int>, double>> edges
        );
        
        ~Graph();        

        double GetEdgeVal(int v, int u);
        void SetEdgeVal(int v, int u, double val);
        void SetVertices(std::vector<int> vertices);
        std::vector<int>GetVertices();
        
        bool EdgeExists(int v, int u);
        int GetNumberOfVertices();
};
