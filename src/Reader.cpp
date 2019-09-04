#include "Reader.h"

using namespace std;


Reader::Reader(int argc, char** argv) {
    int number_of_cities;
    cin >> number_of_cities;
    for (int i = 0; i < number_of_cities; i++) {
        int ai;
        cin >> ai;
        instance_vertices.push_back(ai);
    } 
}

vector<int> Reader::GetInstanceVertices() const {
    return instance_vertices;
}
