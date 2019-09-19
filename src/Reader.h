#ifndef GRAPH_H
    #include "Graph.h"
#endif
#include <vector>
#include <string>
#include <fstream>

#define READER_H

class ArgumentsReader {
    private:
        int instance_size;
        std::vector<int> instance_vertices;
        int runs;
        std::vector<int> seeds;

        void ReadSequenceFile(std::string filename);
        void ReadSeedsFile(std::string filename);

    public:
        ArgumentsReader(int argc, char* argv[]);
        int GetInstanceSize() const;
        std::vector<int> GetInstanceVertices() const;
        int GetRuns() const;
        std::vector<int> GetSeeds() const;
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
        ArgumentsReader* arguments_reader;
        DatabaseReader* database_reader;

    public:
        Reader(int argc, char* argv[]);
        ~Reader();                 

        // ArgumentsReader attributes        
        std::vector<int> GetInstanceVertices() const;
        int GetInstanceSize() const;
        int GetRuns() const;
        std::vector<int> GetSeeds() const;
        
        // DatabaseReader attributes
        std::vector<std::pair<std::pair<int, int>, double>>
            GetOriginalEdges() const;
        
        std::vector<Vertice> GetAllVertices() const;
};
