#include "WorldBuilder.h"
#ifndef SOLUTION_H
    #include "Solution.h"
#endif
#ifndef READER_H
    #include "Reader.h"
#endif
#include <vector>

using namespace std;


int main(int argc, char** argv) {

    Reader* reader = new Reader();
    WorldBuilder world_builder(reader);
    
    vector<int> seeds = reader->GetSeeds();
    for (int seed : seeds) {
        srand(seed);
        SimulatedAnnealing simannealing =
            world_builder.BuildSimulatedAnnealing();
        Solution best_solution = simannealing.TresholdAccepting();
        printf("Best solution for seed: %d cost: %2.15f\n",
            seed, best_solution.GetCost());
        best_solution.Print();

        cout << " ---- " << endl;
    }
 
    return 0;
}
