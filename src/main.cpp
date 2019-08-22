#include "DatabaseHandler.h"
#include <iostream>
#include <vector>

using namespace std;


int main() {
    DatabaseHandler* dbh = new DatabaseHandler();
    dbh->OpenDatabase();
    vector<pair<pair<int, int>, double>> edges = dbh->GetEdges();
    for (pair<pair<int, int>, double> e : edges) {
        cout << e.first.first << ", " << e.first.second << ", " <<
            e.second << endl;
    }
    dbh->CloseDatabase();
}
