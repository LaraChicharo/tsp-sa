#include "WorldBuilder.h"
#ifndef SOLUTION_H
    #include "Solution.h"
#endif
#ifndef READER_H
    #include "Reader.h"
#endif
#include <vector>

using namespace std;


int main(int argc, char* argv[]) {

    Reader* reader = new Reader(argc, argv);
    WorldBuilder* world_builder = new WorldBuilder(reader);
 
    vector<int> seeds = reader->GetSeeds();
    
    // taking first seed only to simulate how the Journal is goint to work
    int seed = seeds[0];
    SimulatedAnnealing* simannealing =
        world_builder->BuildSimulatedAnnealing(seed);
    Solution* best_solution = simannealing->TresholdAccepting();
    printf("Best solution for seed: %d cost: %2.15f\n",
        seed, best_solution->GetCost());
    best_solution->Print();
    simannealing->WriteToJournalFiles();
    
    delete best_solution;
    delete simannealing;
    delete world_builder;

    return 0;
}
