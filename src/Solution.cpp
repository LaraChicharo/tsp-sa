#include "Solution.h"

using namespace std;


AncestryData::AncestryData(
    double parent_cost, pair<int, int> swaped_indexes
): parent_cost(parent_cost), swaped_indexes(swaped_indexes) {}


double AncestryData::GetParentCost() {
    return parent_cost;
}

pair<int, int> AncestryData::GetSwapedIndexes() {
    return swaped_indexes;
}


Solution::Solution(vector<int> sequence, Metrologist* metrologist):
    sequence(sequence), metrologist(metrologist)
{
    this->ancestry = nullptr;
    this->cost = CalculateCost(sequence);
}

Solution::Solution(
    vector<int> sequence, AncestryData* ancestry, Metrologist* metrologist
):
    sequence(sequence), ancestry(ancestry), metrologist(metrologist)
{
    this->cost = CalculateCost(sequence);
}

double Solution::CalculateCost(vector<int> sequence) {
    double cost = 0;
    for (int i = 0; i < sequence.size() - 1; i++) {
        int v = sequence[i];
        int u = sequence[i + 1];
        cost += metrologist->GetWs(v, u);
    }
    cost /= metrologist->GetNormalizer();
    return cost;
}

// Not implemented as its supposed to be
double Solution::CalculateCost(
    vector<int> sequence, AncestryData* ancestry)
{
    return CalculateCost(sequence);
}

vector<int> Solution::GetSequence() {
    return sequence;
}

Solution Solution::GetNeighbour() {
    vector<int> sequence = GetSequence();
    int size = sequence.size();
    int i, j;
    i = j = 0;
    while (i == j) {
        i = rand() % size;
        j = rand() % size;
    }
    swap(sequence[i], sequence[j]);
    pair<int, int> swaped_indexes = {i, j};
    AncestryData* ancestry = new AncestryData(GetCost(), swaped_indexes);
    Solution neighbour_solution(sequence, ancestry, metrologist);
    return neighbour_solution;
}

double Solution::GetCost() {
    return cost;
}

void Solution::Print() {
    int i;
    int j;
    if (ancestry != nullptr) {
        pair<int, int> swaped_indexes = ancestry->GetSwapedIndexes();
        i = swaped_indexes.first;
        j = swaped_indexes.second;
    } else {
        i = -1;
        j = -1;
    }
    for (int z=0; z<sequence.size(); z++) {
        if (z == i || z == j )
            cout << " swaped: " << sequence[z] << " ";
        else
            cout << sequence[z] << " ";
    }
    cout << endl;
}
