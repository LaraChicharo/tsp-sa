#include "DatabaseHandler.h"
#include "Metrologist.h"
#include <iostream>
#include <vector>

using namespace std;


int main() {
    
    int number_of_cities;
    cin >> number_of_cities;
    cout << number_of_cities << endl;
    vector<int> vertices(number_of_cities);
    for (int i=0; i<number_of_cities; i++) {
        int ai;
        cin >> ai;
        vertices[i] = ai;
        cout << ai << endl;
    }
    
    DatabaseHandler* dbh = new DatabaseHandler();
    dbh->OpenDatabase();
    vector<pair<pair<int, int>, double>> edges = dbh->GetEdges();
    vector<Vertice> all_vertices = dbh->GetVertices();
    dbh->CloseDatabase();

    cout << "Vertices: " << endl;
    for (Vertice v : all_vertices) {
        cout << v.GetId() << " " << v.GetPopulation() << endl;
    }
    
    Graph graph(vertices, all_vertices, edges);
    Metrologist metrologist(&graph);
    double maxd = metrologist.GetMaxd();
    double normalizer = metrologist.GetNormalizer();
    printf("Maxd: %2.15f\n", maxd);
    printf("Normalizer: %2.15f\n", normalizer);
    
    return 0;
}
