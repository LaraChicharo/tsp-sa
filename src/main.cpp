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
    Solution* solution = world_builder.BuildFirstSolution();

 
    return 0;
}
