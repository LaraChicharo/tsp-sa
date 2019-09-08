#include "Temperature.h"

using namespace std;


Temperature::Temperature(
    Solution solution,
    double initial_temp,
    double P,
    double virtual_zero,
    int instance_size,
    double decrease_rate
):
        virtual_zero(virtual_zero),
        instance_size(instance_size),
        decrease_rate(decrease_rate)
{
    temperature = InitialTemperature(solution, initial_temp, P);
}

double Temperature::InitialTemperature(
    Solution solution,
    double initial_temp,
    double P
) {
    double p = AcceptedPercentage(solution, initial_temp);
    double T1;
    double T2;
    if (abs(P - p) <= virtual_zero) {
        return initial_temp;
    } else if (p < P) {
        while (p < P) {
            initial_temp *= 2;
            p = AcceptedPercentage(solution, initial_temp);
        }
        T1 = initial_temp / 2;
        T2 = initial_temp;
    } else {
        while (p > P) {
            initial_temp /= 2;
            p = AcceptedPercentage(solution, initial_temp);
        }
        T1 = initial_temp;
        T2 = 2 * initial_temp;
    }
    return BinarySearch(solution, T1, T2, P);
}

double Temperature::BinarySearch(
    Solution solution, double T1, double T2, double P
) {
    double Tm = (T1 + T2)/2;
    if (T2 - T1 < virtual_zero)
        return Tm;
    double p = AcceptedPercentage(solution, Tm);
    if (abs(P - p) < virtual_zero) {
        return Tm;
    }
    if (p > P)
        return BinarySearch(solution, T1, Tm, P);
    else
        return BinarySearch(solution, Tm, T2, P);
}

double Temperature::AcceptedPercentage(Solution solution, double temp) {
    int c = 0;
    for (int i = 1; i <= instance_size; i++) {
        Solution new_solution = solution.GetNeighbour();
        double new_cost = new_solution.GetCost();
        double cost = solution.GetCost();
        if (new_cost <= cost + temp) {
            c++;
            solution = new_solution;
        }
    }
    double ans = ((double)c / instance_size);
    return ans;
}

double Temperature::GetTemperature() {
    return temperature;
}

bool Temperature::BiggerThanZero() {
    return temperature > virtual_zero;
}

void Temperature::Decrease() {
    this->temperature *= decrease_rate;
}
