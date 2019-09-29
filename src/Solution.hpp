#pragma once

#include <iostream>
#include <vector>
#include "Metrologist.hpp"


/// @brief Stores data of the ancestor of a solution to be able to recover
/// said ancestor fast.
class AncestryData {
    private:
        /// cost of the parent solution
        double parent_cost;
        /// sum of the weights of the solution
        double parent_sum;
        /// indexes that by swapping them created the solution
        /// associated with this instance
        std::pair<int, int> swaped_indexes;

    public:
        /// @brief Constructor.
        /// @param parent_cost    cost of the parent solution
        /// @param parent_sum     sum of the weights of the solution
        /// @param swaped_indexes indexes that by swapping them created
        /// this solution
        AncestryData(
            double parent_cost,
            double parent_sum,
            std::pair<int, int> swaped_indexes);

        /// @brief Returns the cost of the parent solution.
        double GetParentCost();
        /// @brief Returns the sum of the weights of the solution.
        double GetParentSum();
        /// @brief Returns the indexes that created this solution.
        std::pair<int, int> GetSwapedIndexes();
};


/// @brief Class to represent a solution to the TSP.
class Solution {
    private:
        /// entity to make measurements
        Metrologist* metrologist;
        /// data of the parent of this solution
        AncestryData* ancestry;
        /// sequence of cities
        std::vector<int> sequence;
        /// cost of this solution
        double cost;
        /// sum of the weights of the solution
        double ssum;
        
        /// @brief Divides the cost of the solution by a normalizer
        /// thus giving the real cost.
        /// @param ssum cost without dividing it.
        /// @return cost of the solution normalized.
        double CalculateCost(double ssum);
        
        /// @brief Calculates a sum of the edges involved in the sequence.
        /// @param sequence whose edges are to be evaluated. Linear time.
        /// @return the sum
        double CalculateSum(std::vector<int>& sequence);
        /// @brief Calculates the sum of the edges involved in the
        /// sequence given the information of the parent solution. 
        /// Constant time.
        /// @param sequence sequence to evaluate
        /// @param ancestry information on the parent solution.
        /// @return the sum,
        double CalculateSum(std::vector<int>& sequence, AncestryData* ancestry);
        /// @brief Calculates both the sum and the cost of the given sequence.
        /// and sets the cost and ssum variables to the values calculated.
        /// @param sequence             sequence of vertices to evaluate.
        /// @param ancestry             data on the parent solution.
        /// @param calculate_everything if set true, the evaluation will
        /// use the linear time function, else it will use the constant time
        /// function.
        void SetCost(
            std::vector<int>& sequence,
            AncestryData* ancestry,
            bool calculate_everything = false
        );
        /// @brief Returns the ancestry data of this solution.
        AncestryData* GetAncestry();
        /// @brief Returns the metrologist object associated.
        Metrologist* GetMetrologist();

    public:
        /// @brief Constructor.
        /// @param sequence    sequence of cities
        /// @param metrologist instance of metrologist.
        Solution(std::vector<int> sequence, Metrologist* metrologist);
        /// @brief Copy constructor.
        /// @param solution instance to copy.
        Solution(Solution* solution);

        /// @brief Returns the sequence associated with this solution.
        std::vector<int> GetSequence();
        /// @brief Transforms this solution into a random neighbour solution.
        /// @param calculate_everything if true the linear function to
        /// calculate the cost of the solution will be executed, the 
        /// constant time function otherwise.
        void MorphIntoNeighbour(bool calculate_everything = false);
        
        /// @brief Transforms the current solution into a neigbour solution
        /// by swapping the ith and the jth items in the sequence.
        /// @param i                    first index to swap
        /// @param j                    second index to swap
        /// @param calculate_everything if true the linear function to
        /// calculate the cost of the solution will be executed, the 
        /// constant time function otherwise.
        void MorphIntoNeighbour(
            int i,
            int j,
            bool calculate_everything = false
        );
        /// @brief Transforms the current solution to its parent soluiton.
        void MorphBack();
        /// @brief Checks all of its neihbours lookig for a better solution,
        /// if it finds it, the current solution morphs into it.
        bool Sweep();
        /// @brief Keeps morphing the soluition into the best in its
        /// neighbourhood until the current solution its the best.
        /// @return true if it found a better solution, false otherwise.
        void HardSweep();
        /// @brief Returns the cost of the solution.
        double GetCost();
        /// @brief Returns the sum of the edges associated with the soluition.
        double GetSum();
        /// @brief Prints the ids of the vertices of the solution in sequence.
        void Print();
};
