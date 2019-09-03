#include "DatabaseHandler.h"
#include "GraphFiller.h"
#include "Solution.h"
#include <iostream>
#include <vector>

using namespace std;


int main() {
    
    int number_of_cities;
    cin >> number_of_cities;
    vector<int> instance_vertices(number_of_cities);
    for (int i=0; i<number_of_cities; i++) {
        int ai;
        cin >> ai;
        instance_vertices[i] = ai;
    }
    
    DatabaseHandler* dbh = new DatabaseHandler();
    dbh->OpenDatabase();
    vector<pair<pair<int, int>, double>> original_edges = dbh->GetEdges();
    vector<Vertice> all_vertices = dbh->GetVertices();
    dbh->CloseDatabase();

    Graph graph(instance_vertices, all_vertices, original_edges);
    Metrologist metrologist(&graph);

    GraphFiller graph_builder = GraphFiller();
    graph_builder.FillGraph(&graph, &metrologist);

    srand(666);
    vector<int> sequence (instance_vertices);
    Solution solution(sequence, &metrologist); 
 

    int z = 0;
    while (z++ < 5) {
        double cost = solution.GetCost();
        solution.Print();
        printf("cost: %2.15f\n", cost);
        solution = solution.GetNeighbour();
    }
    return 0;
}
