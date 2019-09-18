#include "Solution.h"

using namespace std;


AncestryData::AncestryData(
    double parent_cost,
    double parent_sum,
    pair<int, int> swaped_indexes
):
    parent_cost(parent_cost),
    parent_sum(parent_sum),
    swaped_indexes(swaped_indexes)
{}

double AncestryData::GetParentCost() {
    return parent_cost;
}

double AncestryData::GetParentSum() {
    return parent_sum;
}

pair<int, int> AncestryData::GetSwapedIndexes() {
    return swaped_indexes;
}


Solution::Solution(vector<int> sequence, Metrologist* metrologist):
    sequence(sequence), metrologist(metrologist)
{
    this->ancestry = nullptr;
    this->ssum = CalculateSum(this->sequence);
    this->cost = CalculateCost(this->ssum);
}

Solution::Solution(Solution* solution) {
    metrologist = solution->GetMetrologist();
    sequence = solution->GetSequence();
    ancestry = solution->GetAncestry();
    ssum = CalculateSum(sequence);
    cost = CalculateCost(ssum);
}

AncestryData* Solution::GetAncestry() {
    return ancestry;
}

Metrologist* Solution::GetMetrologist() {
    return metrologist;
}

double Solution::CalculateCost(double ssum) {
    return (ssum / metrologist->GetNormalizer());
}

double Solution::CalculateSum(vector<int>& sequence) {
    double ssum = 0;
    for (int i = 0; i < sequence.size() - 1; i++) {
        int v = sequence[i];
        int u = sequence[i + 1];
        ssum += metrologist->GetWs(v, u);
    }
    return ssum;
}

double Solution::CalculateSum(
    vector<int>& sequence, AncestryData* ancestry)
{
    double ssum = ancestry->GetParentSum();
    vector<int> parent_sequence (sequence);
    pair<int, int> swaped_indexes = ancestry->GetSwapedIndexes();
    int i = swaped_indexes.first;
    int j = swaped_indexes.second;
    
    swap(parent_sequence[i], parent_sequence[j]);
    
    int veri = parent_sequence[i];
    int verj = parent_sequence[j];
    int size = sequence.size();

     
    if (i - 1 >= 0)
        ssum -= metrologist->GetWs(veri, parent_sequence[i - 1]);
    if (i + 1 < size)
        ssum -= metrologist->GetWs(veri, parent_sequence[i + 1]);
    if (j - 1 >= 0)
        ssum -= metrologist->GetWs(verj, parent_sequence[j - 1]);
    if (j + 1 < size)
        ssum -= metrologist->GetWs(verj, parent_sequence[j + 1]);

    if (abs(i - j) == 1)
        ssum += metrologist->GetWs(veri, verj);
    
    
    veri = sequence[i];
    verj = sequence[j];
    if (i - 1 >= 0)
        ssum += metrologist->GetWs(veri, sequence[i - 1]);
    if (i + 1 < size)
        ssum += metrologist->GetWs(veri, sequence[i + 1]);
    if (j - 1 >= 0)
        ssum += metrologist->GetWs(verj, sequence[j - 1]);
    if (j + 1 < size)
        ssum += metrologist->GetWs(verj, sequence[j + 1]);

    if (abs(i - j) == 1)
        ssum -= metrologist->GetWs(veri, verj);
    return ssum;
}

vector<int> Solution::GetSequence() {
    return sequence;
}

void Solution::SetCost(vector<int>& sequence, AncestryData* ancestry) {
    ssum = CalculateSum(sequence, ancestry);
    cost = CalculateCost(ssum);
}

void Solution::MorphIntoNeighbour() {
    sequence = GetSequence();
    int size = sequence.size();
    int i, j;
    i = j = 0;
    while (i == j) {
        i = rand() % size;
        j = rand() % size;
    }
    swap(sequence[i], sequence[j]);
    pair<int, int> swaped_indexes = {i, j};
    delete ancestry;
    ancestry = new AncestryData(
        GetCost(),
        GetSum(),
        swaped_indexes);
    SetCost(sequence, ancestry);
}

void Solution::MorphBack() {
    if (ancestry == nullptr) {
        printf("Imposible to morph solution back\n");
    }
    pair<int, int> swaped_indexes = ancestry->GetSwapedIndexes();
    swap(sequence[swaped_indexes.first], sequence[swaped_indexes.second]);
    delete ancestry;
    ancestry = new AncestryData(
        GetCost(),
        GetSum(),
        swaped_indexes
    );
    SetCost(sequence, ancestry);
}



double Solution::GetCost() {
    return cost;
}

double Solution::GetSum() {
    return ssum;
}

void Solution::Print() {
    for (int z=0; z<sequence.size(); z++)
            printf("%d ", sequence[z]);
    printf("\n");
}
