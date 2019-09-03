#include <iostream>
#include <vector>
#ifndef METROLOGIST_H
    #include "Metrologist.h"
#endif

#define SOLUTION_H


class AncestryData {
    private:
        double parent_cost;
        std::pair<int, int> swaped_indexes;

    public:
        AncestryData(double parent_cost, std::pair<int, int> swaped_indexes);

        double GetParentCost();
        std::pair<int, int> GetSwapedIndexes();
};


class Solution {
    private:
        Metrologist* metrologist;
        AncestryData* ancestry;
        std::vector<int> sequence;
        double cost;
        
        double CalculateCost(std::vector<int> sequence);
        double CalculateCost(std::vector<int> sequence, AncestryData* ancestry);

    public:
        Solution(std::vector<int> sequence, Metrologist* metrologist);
        Solution(
            std::vector<int> sequence,
            AncestryData* ancestry,
            Metrologist* metrologist
        );

        std::vector<int> GetSequence();
        Solution GetNeighbour();
        double GetCost();
        void Print();
};
