#include <iostream>
#include <vector>
#ifndef METROLOGIST_H
    #include "Metrologist.h"
#endif

#define SOLUTION_H


class AncestryData {
    private:
        double parent_cost;
        double parent_sum;
        std::pair<int, int> swaped_indexes;

    public:
        AncestryData(
            double parent_cost,
            double parent_sum,
            std::pair<int, int> swaped_indexes);

        double GetParentCost();
        double GetParentSum();
        std::pair<int, int> GetSwapedIndexes();
};


class Solution {
    private:
        Metrologist* metrologist;
        AncestryData* ancestry;
        std::vector<int> sequence;
        double cost;
        double ssum;
        
        double CalculateCost(double ssum);
        
        double CalculateSum(std::vector<int> sequence);
        double CalculateSum(std::vector<int> sequence, AncestryData* ancestry);

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
        double GetSum();
        void Print();
};
