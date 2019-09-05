#include "WorldBuilder.h"
#ifndef SOLUTION_H
    #include "Solution.h"
#endif
#ifndef READER_H
    #include "Reader.h"
#endif
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main(int argc, char** argv) {

    Reader* reader = new Reader();
    WorldBuilder world_builder(reader);
    Solution solution = world_builder.BuildFirstSolution(); 
    
    printf("original cost: %2.15f\n", solution.GetCost());
 
    return 0;
}
