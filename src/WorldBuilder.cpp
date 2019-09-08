#include "WorldBuilder.h"

using namespace std;


WorldBuilder::WorldBuilder(Reader* reader): reader(reader) {
    srand(13);
}

Solution WorldBuilder::BuildFirstSolution() const {
    vector<int> instance_vertices = reader->GetInstanceVertices();
    vector<pair<pair<int, int>, double>>
        original_edges = reader->GetOriginalEdges();

    vector<Vertice> all_vertices = reader->GetAllVertices();
    Graph* graph = new Graph(instance_vertices, all_vertices, original_edges);
    Metrologist* metrologist = new Metrologist(graph);

    GraphFiller graph_builder = GraphFiller();
    graph_builder.FillGraph(graph, metrologist);

    vector<int> sequence (instance_vertices);
    Solution first_solution(sequence, metrologist);
    return first_solution;
}

Temperature WorldBuilder::BuildTemperature(Solution solution) const {
    Temperature temperature(
        solution,
        1000,
        .80,
        1e-4,
        reader->GetInstanceSize(),
        .7
    );
    return temperature;
}

SimulatedAnnealing WorldBuilder::BuildSimulatedAnnealing() const {
    Solution solution = BuildFirstSolution();
    printf("Cost: %f\n", solution.GetCost());
    Temperature temperature = BuildTemperature(solution);
    SimulatedAnnealing simannealing(temperature, solution, 1000);
    return simannealing;
}
