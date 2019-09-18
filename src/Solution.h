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
        
        double CalculateSum(std::vector<int>& sequence);
        double CalculateSum(std::vector<int>& sequence, AncestryData* ancestry);
        void SetCost(std::vector<int>& sequence, AncestryData* ancestry);
        AncestryData* GetAncestry();
        Metrologist* GetMetrologist();

    public:
        Solution(std::vector<int> sequence, Metrologist* metrologist);
        Solution(Solution* solution);

        std::vector<int> GetSequence();
        void MorphIntoNeighbour();
        void MorphBack();
        double GetCost();
        double GetSum();
        void Print();
};
