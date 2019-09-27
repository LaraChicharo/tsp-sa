#include "WorldBuilder.hpp"

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

WorldBuilder::~WorldBuilder() {
    delete reader;
    delete graph;
    delete metrologist;
    delete graph_builder;
}

Solution* WorldBuilder::BuildFirstSolution() const {
    Solution* first_solution = new Solution(first_sequence, metrologist);
    return first_solution;
}

Temperature WorldBuilder::BuildTemperature(Solution* solution) const {
    Temperature temperature(
        solution,
        INITIAL_TEMPERATURE,
        P,
        EPSILON,
        reader->GetInstanceSize(),
        TEMPERATURE_DECAY
    );
    return temperature;
}

Journal* WorldBuilder::BuildJournal(int seed) const {
    Journal* journal = new Journal(seed);
    return journal;
}

SimulatedAnnealing* WorldBuilder::BuildSimulatedAnnealing(int seed) const {
    srand(seed);
    Solution* solution = BuildFirstSolution();
    Temperature temperature = BuildTemperature(solution);
    Journal* journal = BuildJournal(seed);
    SimulatedAnnealing* simannealing =
        new SimulatedAnnealing(temperature, solution, journal, L);
    return simannealing;
}
