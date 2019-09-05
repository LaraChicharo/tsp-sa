#ifndef GRAPH_H
    #include "Graph.h"
#endif

#include <iostream>
#include <vector>


class ArgumentsReader {
    private:
        std::vector<int> instance_vertices;

    public:
        ArgumentsReader();
        std::vector<int> GetInstanceVertices() const;
};


class DatabaseReader {
    private:
        std::vector<std::pair<std::pair<int, int>, double>> original_edges;
        std::vector<Vertice> all_vertices;

    public:
        DatabaseReader();
        
        std::vector<std::pair<std::pair<int, int>, double>>
            GetOriginalEdges() const;
        
        std::vector<Vertice> GetAllVertices() const;
};


class Reader {
    private:
        ArgumentsReader arguments_reader;
        DatabaseReader database_reader;

    public:
        Reader();

        // ArgumentsReader attributes        
        std::vector<int> GetInstanceVertices() const;
        
        // DatabaseReader attributes
        std::vector<std::pair<std::pair<int, int>, double>>
            GetOriginalEdges() const;
        
        std::vector<Vertice> GetAllVertices() const;
};
