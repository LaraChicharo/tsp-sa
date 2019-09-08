#include "SimulatedAnnealing.h"

using namespace std;


SimulatedAnnealing::SimulatedAnnealing(
    Temperature temperature, Solution initial_solution, int L
):
    temperature(temperature), initial_solution(initial_solution), L(L)
{}

Solution SimulatedAnnealing::TresholdAccepting() {
    double p = 0;
    Solution best_solution = initial_solution;
    Solution solution = initial_solution;
    while (this->temperature.BiggerThanZero()) {
        double q = DBL_MAX;
        while (p <= q) {
            q = p;
            pair<double, Solution> mpair = ComputeBatch(solution);
            p = mpair.first; solution = mpair.second;
            if (solution.GetCost() < best_solution.GetCost()) {
                best_solution = solution;        
            }
        }
        temperature.Decrease();
    }
    return best_solution;
}

pair<double, Solution> SimulatedAnnealing::ComputeBatch(Solution solution) {
    int total = 0;
    int c = 0;
    double r = 0;
    double temp = temperature.GetTemperature();
    while (c < L && total++ < L * 10) {
        Solution new_solution = solution.GetNeighbour();
        if (new_solution.GetCost() <= solution.GetCost() + temp) {
            solution = new_solution;
            c++;
            r += solution.GetCost();
        }
    }
    return make_pair(r / c, solution);
}
