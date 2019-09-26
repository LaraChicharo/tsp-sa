#pragma once

#include "Graph.h"
#include <vector>
#include <string>
#include <fstream>


/// @brief Class to read and parse arguments from command line.
class ArgumentsReader {
    private:
        /// Size of the first instance read. Instance provided by the user
        int instance_size;
        /// Vertices involved in the problem
        std::vector<int> instance_vertices;
        /// Number of times the heuristic is going to run
        int runs;
        /// Seeds that are going to be used to feed srand.
        /// The number of seeds must match runs
        std::vector<int> seeds;

        /// @brief Reads the file that provides the system with
        /// the first proposed solution for the problem.
        /// @param filename filename containing said solution
        void ReadSequenceFile(std::string filename);

        /// @brief Reads the file containing the seeds for each run.
        /// @param filename filename containing said seeds
        void ReadSeedsFile(std::string filename);

    public:

        /// @brief Constructor.
        /// @param argc   number of arguments in argv[]
        /// @param argv[] arguments from command line
        ArgumentsReader(int argc, char* argv[]);

        /// @brief Returns the size of the problem.
        int GetInstanceSize() const;
        /// @brief Returns the id of the vertices involved in the problem.
        std::vector<int> GetInstanceVertices() const;
        /// @brief Returns the number of seeds the system is going to run.
        int GetRuns() const;
        /// @brief Returs the seeds the system is going to run.
        std::vector<int> GetSeeds() const;
};


/// @brief Parser reading from the database.
class DatabaseReader {
    private:
        /// Edges actually contained in the database
        std::vector<std::pair<std::pair<int, int>, double>> original_edges;
        /// All vertices available in the database
        std::vector<Vertice> all_vertices;

    public:
        DatabaseReader();
        
        /// @brief Returns the edges actually contained in the database.
        std::vector<std::pair<std::pair<int, int>, double>>
            GetOriginalEdges() const;
        
        /// @brief Returns all vertices available in the database.
        std::vector<Vertice> GetAllVertices() const;
};


/// @brief Wrapper for classes ArgumentsReader and DatabaseReader.
class Reader {
    private:
        ArgumentsReader* arguments_reader;
        DatabaseReader* database_reader;

    public:
        /// @brief Constructor.
        /// @param argc   number of arguments in argv[]
        /// @param argv[] arguments from command line
        Reader(int argc, char* argv[]);
        ~Reader();                 

        // ArgumentsReader attributes
        
        /// @brief Returns the id of the vertices involved in the problem.
        std::vector<int> GetInstanceVertices() const;
        /// @brief Returns the size of the problem.
        int GetInstanceSize() const;
        /// @brief Returns the number of seeds the system is going to run.
        int GetRuns() const;
        /// @brief Returs the seeds the system is going to run.
        std::vector<int> GetSeeds() const;
        
        // DatabaseReader attributes
        
        /// @brief Returns the edges actually contained in the database.
        std::vector<std::pair<std::pair<int, int>, double>>
            GetOriginalEdges() const;
        
        /// @brief Returns all vertices available in the database.
        std::vector<Vertice> GetAllVertices() const;
};
