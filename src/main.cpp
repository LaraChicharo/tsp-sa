#include "DatabaseHandler.h"
#include "GraphFiller.h"
#include "Solution.h"
#include "Reader.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main(int argc, char** argv) {

    Reader reader(argc, argv);
    vector<int> instance_vertices = reader.GetInstanceVertices();
     
    DatabaseHandler* dbh = new DatabaseHandler();
    dbh->OpenDatabase();
    vector<pair<pair<int, int>, double>> original_edges = dbh->GetEdges();
    vector<Vertice> all_vertices = dbh->GetVertices();
    dbh->CloseDatabase();

    Graph graph(instance_vertices, all_vertices, original_edges);
    Metrologist metrologist(&graph);

    GraphFiller graph_builder = GraphFiller();
    graph_builder.FillGraph(&graph, &metrologist);

    srand(13);
    vector<int> sequence (instance_vertices);
    Solution solution(sequence, &metrologist); 
    
    printf("original cost: %2.15f\n", solution.GetCost());
 
    solution = solution.GetNeighbour();
    Solution solution_twin = Solution(
        solution.GetSequence(), &metrologist
    );
    double cost = solution.GetCost();
    double cost_twin = solution_twin.GetCost();
    printf("cost: %2.15f\n", cost);
    printf("cost twin: %2.15f\n", cost_twin);

    double treshold = 1e-7;
    if (abs(cost - cost_twin) <= treshold) {
       cout <<
        "Cost functions are close enough" << endl;
    } else {
       cout << "Cost functions are NOT close enough" << endl;
       printf("Diff: %2.15f\n", cost - cost_twin);
    }
    
    return 0;
}
