#include "DatabaseHandler.h"
#include "Reader.h"
#include <iostream>
#include <fstream>

using namespace std;


ArgumentsReader::ArgumentsReader() {
    ifstream first_sequence_file;
    first_sequence_file.open("samples/40.txt");
    first_sequence_file >> instance_size;
    for (int i = 0; i < instance_size; i++) {
        int ai;
        first_sequence_file >> ai;
        instance_vertices.push_back(ai);
    }
    first_sequence_file.close();
    
    ifstream seeds_file;
    seeds_file.open("samples/seeds.txt");
    int runs;
    seeds_file >> runs;
    for (int i=0; i<runs; i++) {
        int seedi;
        seeds_file >> seedi;
        seeds.push_back(seedi);
    }
    seeds_file.close();
}

vector<int> ArgumentsReader::GetInstanceVertices() const {
    return instance_vertices;
}

int ArgumentsReader::GetInstanceSize() const {
    return instance_size;
}

int ArgumentsReader::GetRuns() const {
    return runs;
}

vector<int> ArgumentsReader::GetSeeds() const {
    return seeds;
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

int Reader::GetInstanceSize() const {
    return arguments_reader.GetInstanceSize();
}

int Reader::GetRuns() const {
    return arguments_reader.GetRuns();
}

vector<int> Reader::GetSeeds() const {
    return arguments_reader.GetSeeds();
}

// DatabaseReader attributes
vector<pair<pair<int, int>, double>> Reader::GetOriginalEdges() const {
    return database_reader.GetOriginalEdges();
}

vector<Vertice> Reader::GetAllVertices() const {
    return database_reader.GetAllVertices();
}
