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
    cout << "seeds: ";
    for (int seed : seeds)
        cout << seed << " ";
    cout << endl;
    
    SimulatedAnnealing simannealing =
        world_builder.BuildSimulatedAnnealing();
    Solution best_solution = simannealing.TresholdAccepting();
    printf("Best solution cost: %2.15f\n", best_solution.GetCost());
    best_solution.Print();
 
    return 0;
}
