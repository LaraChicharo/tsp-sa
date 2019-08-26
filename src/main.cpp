#include "DatabaseHandler.h"
#include "Metrologist.h"
#include <iostream>
#include <vector>

using namespace std;


int main() {
    
    int number_of_cities;
    cin >> number_of_cities;
    vector<int> vertices(number_of_cities);
    for (int i=0; i<number_of_cities; i++) {
        int vi;
        cin >> vi;
        vertices[i] = vi;
    }
    
    DatabaseHandler* dbh = new DatabaseHandler();
    dbh->OpenDatabase();
    vector<pair<pair<int, int>, double>> edges = dbh->GetEdges();
    pair<double, double> v = dbh->GetCoordinates(vertices[0]);
    cout << "coordinates of " << vertices[0] << ": " << v.first <<
        ", " << v.second << endl;
    dbh->CloseDatabase();

    Graph graph(vertices, edges);
    Metrologist metrologist(&graph);
    double maxd = metrologist.GetMaxd();
    double normalizer = metrologist.GetNormalizer();
    printf("Maxd: %2.15f\n", maxd);
    printf("Normalizer: %2.15f\n", normalizer);
    return 0;
}
