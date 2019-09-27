#include "Journal.hpp"

using namespace std;

Journal::Journal(int int_seed): EXT(".dat") {
    string seed = to_string(int_seed);
    base_filename = seed + "-journal-";
}

void Journal::AppendAcceptedSolution(int accepted, double solution_cost) {
    PointSolution point_solution = {accepted, solution_cost};
    accepted_solutions.push_back(point_solution);
}

void Journal::AppendBestSolution(int accepted, double solution_cost) {
    PointSolution point_solution = {accepted, solution_cost};
    best_solutions.push_back(point_solution);
}

void Journal::WriteToBestSolutionsFile() const {
    string filename = base_filename + "best" + EXT;
    ofstream output_file;
    output_file.open(filename);
    for (PointSolution ps : best_solutions) {
        output_file << ps.accepted << " " <<
        fixed << setprecision(5) << ps.cost << endl;
    }
    output_file.close();
}

void Journal::WriteToAcceptedSolutionsFile() const {
    string filename = base_filename + "accepted" + EXT;
    ofstream output_file;
    output_file.open(filename);
    for (PointSolution ps : accepted_solutions) {
        output_file << ps.accepted << " " <<
        fixed << setprecision(5) << ps.cost << endl;
    }
    output_file.close();
}

void Journal::WriteToJournalFiles() const {
    WriteToBestSolutionsFile();
    WriteToAcceptedSolutionsFile();
}
