#include "DatabaseHandler.h"
#include "GraphFiller.h"
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

    vector<int> base_vertices;
    for (int i = 1; i <= all_vertices.size(); i++)
        base_vertices.push_back(i);
 
    Graph graph(base_vertices, all_vertices, original_edges);
    Metrologist metrologist(&graph);

    GraphFiller graph_builder = GraphFiller();
    graph_builder.FillGraph(&graph, &metrologist);
 
    return 0;
}
