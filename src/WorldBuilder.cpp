#include "WorldBuilder.h"

using namespace std;


WorldBuilder::WorldBuilder(Reader* reader): reader(reader) {
    srand(13);
}

Solution WorldBuilder::BuildFirstSolution() const {
    vector<int>instance_vertices = reader->GetInstanceVertices();
    vector<pair<pair<int, int>, double>>
        original_edges = reader->GetOriginalEdges();

    vector<Vertice> all_vertices = reader->GetAllVertices();
    Graph graph(instance_vertices, all_vertices, original_edges);
    Metrologist metrologist(&graph);

    GraphFiller graph_builder = GraphFiller();
    graph_builder.FillGraph(&graph, &metrologist);

    vector<int> sequence (instance_vertices);
    Solution first_solution(sequence, &metrologist);
    return first_solution;
}
