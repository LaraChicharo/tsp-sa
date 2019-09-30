#include "WorldBuilder.hpp"
#include "Solution.hpp"
#include "Reader.hpp"
#include <vector>

using namespace std;


int main(int argc, char* argv[]) {

    Reader* reader = new Reader(argc, argv);
    WorldBuilder* world_builder = new WorldBuilder(reader);
 
    if (reader->GoingToPlot()) {
        int seed = reader->GetSeed();
        SimulatedAnnealing* simannealing =
            world_builder->BuildSimulatedAnnealing(seed);
        Solution* best_solution = simannealing->TresholdAcceptingSweep();
        simannealing->WriteToJournalFiles();
        delete best_solution;
        delete simannealing;
    } else {
        vector<int> seeds = reader->GetSeeds();
        for (int seed : seeds) {
            SimulatedAnnealing* simannealing =
                world_builder->BuildSimulatedAnnealing(seed);
            Solution* best_solution = simannealing->TresholdAcceptingSweep();
            printf("Best solution for seed: %d cost: %2.15f\n",
                seed, best_solution->GetCost());
            best_solution->Print();
            delete best_solution;
            delete simannealing;
        }
    }
    
    delete world_builder;
    return 0;
}
