#include "DatabaseHandler.h"
#include "Reader.h"

using namespace std;


ArgumentsReader::ArgumentsReader(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(
            stderr,
            "Wrong input. Arguments must be: <sequence file> <seeds file>\n"
        );
        exit(1);
    }

    string sequencefile_name = argv[1];
    string seedsfile_name = argv[2];
    ReadSequenceFile(sequencefile_name);
    ReadSeedsFile(seedsfile_name);
}

void ArgumentsReader::ReadSequenceFile(string filename) {
    ifstream first_sequence_file;
    first_sequence_file.open(filename);
    if (first_sequence_file.fail()) {
        fprintf(
            stderr,
            "Error opening file: %s\n", filename.c_str()
        );
        exit(1);
    }
    first_sequence_file >> instance_size;
    for (int i = 0; i < instance_size; i++) {
        int ai;
        first_sequence_file >> ai;
        instance_vertices.push_back(ai);
    }
    first_sequence_file.close();
}

void ArgumentsReader::ReadSeedsFile(string filename) {
    ifstream seeds_file;
    seeds_file.open(filename);
    if (seeds_file.fail()) {
        fprintf(
            stderr,
            "Error opening file: %s\n", filename.c_str()
        );
        exit(1);
    }
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


Reader::Reader(int argc, char* argv[]) {
    arguments_reader = new ArgumentsReader(argc, argv);
    database_reader = new DatabaseReader();
}

Reader::~Reader() {
    delete arguments_reader;
    delete database_reader;
}

// ArgimentReader atrributes
vector<int> Reader::GetInstanceVertices() const {
    return arguments_reader->GetInstanceVertices();
}

int Reader::GetInstanceSize() const {
    return arguments_reader->GetInstanceSize();
}

int Reader::GetRuns() const {
    return arguments_reader->GetRuns();
}

vector<int> Reader::GetSeeds() const {
    return arguments_reader->GetSeeds();
}

// DatabaseReader attributes
vector<pair<pair<int, int>, double>> Reader::GetOriginalEdges() const {
    return database_reader->GetOriginalEdges();
}

vector<Vertice> Reader::GetAllVertices() const {
    return database_reader->GetAllVertices();
}
