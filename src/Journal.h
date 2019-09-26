#include <vector>
#include <string>
#include <fstream>
#include <iomanip>


#define JOURNAL_H

/// @brief A point in a 2D space representing solutions.
struct PointSolution {
    /// number of accepted solutions so far in which the solution was found.
    /// Represents the x axis
    int accepted;
    /// cost of said solution. Represents y axis
    double cost;
};


/// @brief writes data of the solutions explored by the heuristic
// to a textfile to eventally plot that data.
class Journal {
    private:
        /// file extension of the output files (includes dot)
        std::string EXT;
        /// name of the output file
        std::string base_filename;
        /// contains the costs of the best solutions the heuristic
        /// has found over time
        std::vector<PointSolution> best_solutions;
        /// all of the costs of the accepted solutions explored by the
        /// heuristic over time
        std::vector<PointSolution> accepted_solutions;
        
        /// @brief Writes the points of the accepted solutions during 
        /// the execution of the heuristic.
        void WriteToAcceptedSolutionsFile() const;
        /// @brief Writes the points of the best solutions.
        void WriteToBestSolutionsFile() const;
        
    
    public:
        /// Constructor.
        /// @param seed seed of the execution to plot.
        Journal(int seed);

        /// @brief adds a new solution to the list of accepted solutions.
        /// @param accepted number of accepted solutions so far
        /// @param cost the cost of the solution.
        void AppendAcceptedSolution(int accepted, double solution_cost);
        /// @brief adds a new solution to the list of best solutions.
        /// @param accepted number of accepted solutions so far
        /// @param cost the cost of the solution.
        void AppendBestSolution(int accepted, double solution_cost);
        
        /// @brief writes the points to an output file.
        void WriteToJournalFiles() const;
};
