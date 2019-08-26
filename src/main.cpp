#include "DatabaseHandler.h"
#include "Metrologist.h"
#include <iostream>
#include <vector>

using namespace std;


int main() {
    DatabaseHandler* dbh = new DatabaseHandler();
    dbh->OpenDatabase();
    vector<pair<pair<int, int>, double>> edges = dbh->GetEdges();
    dbh->CloseDatabase();
    
    int number_of_cities;
    cin >> number_of_cities;
    vector<int> vertices(number_of_cities);
    for (int i=0; i<number_of_cities; i++) {
        int vi;
        cin >> vi;
        vertices[i] = vi;
    }

    Graph graph(vertices, edges);
    Metrologist metrologist(&graph);
    double maxd = metrologist.GetMaxd();
    printf("Maxd: %2.15f\n", maxd);
    return 0;
}
