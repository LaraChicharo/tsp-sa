#include "DatabaseHandler.h"
#include <iostream>
#include "Reader.h"

using namespace std;


ArgumentsReader::ArgumentsReader() {
    int number_of_cities;
    cin >> number_of_cities;
    for (int i = 0; i < number_of_cities; i++) {
        int ai;
        cin >> ai;
        instance_vertices.push_back(ai);
    }
}

vector<int> ArgumentsReader::GetInstanceVertices() const {
    return instance_vertices;
}

 
DatabaseReader::DatabaseReader() {
    DatabaseHandler* dbh = new DatabaseHandler();
    dbh->OpenDatabase();
    original_edges = dbh->GetEdges();
    all_vertices = dbh->GetVertices();
    dbh->CloseDatabase();
}

vector<pair<pair<int, int>, double>> DatabaseReader::GetOriginalEdges() const {
    return original_edges;
}

vector<Vertice> DatabaseReader::GetAllVertices() const {
    return all_vertices;
}


Reader::Reader() {}

// ArgimentReader atrributes
vector<int> Reader::GetInstanceVertices() const {
    return arguments_reader.GetInstanceVertices();
}

// DatabaseReader attributes
vector<pair<pair<int, int>, double>> Reader::GetOriginalEdges() const {
    return database_reader.GetOriginalEdges();
}

vector<Vertice> Reader::GetAllVertices() const {
    return database_reader.GetAllVertices();
}
