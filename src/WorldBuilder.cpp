#include "WorldBuilder.h"

using namespace std;


WorldBuilder::WorldBuilder(Reader* reader): reader(reader) {
    first_sequence = reader->GetInstanceVertices();
    vector<pair<pair<int, int>, double>>
        original_edges = reader->GetOriginalEdges();

    vector<Vertice> all_vertices = reader->GetAllVertices();
    graph = new Graph(first_sequence, all_vertices, original_edges);
    metrologist = new Metrologist(graph);

    graph_builder = new GraphFiller();
    graph_builder->FillGraph(graph, metrologist);
}

Solution* WorldBuilder::BuildFirstSolution() const {
    Solution* first_solution = new Solution(first_sequence, metrologist);
    return first_solution;
}

Temperature WorldBuilder::BuildTemperature(Solution* solution) const {
    Temperature temperature(
        solution,
        1000,
        .80,
        1e-4,
        reader->GetInstanceSize(),
        .95
    );
    return temperature;
}

SimulatedAnnealing WorldBuilder::BuildSimulatedAnnealing() const {
    Solution* solution = BuildFirstSolution();
    Temperature temperature = BuildTemperature(solution);
    SimulatedAnnealing simannealing(temperature, solution, 1000);
    return simannealing;
}
