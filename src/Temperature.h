#ifndef SOLUTION_H
    #include "Solution.h"
#endif
#include <cmath>


#define TEMPERATURE_H


class Temperature {
    private:
        double temperature;
        double virtual_zero;
        int instance_size;
        double decrease_rate;
        
        double BinarySearch(Solution* solution, double T1, double T2, double P);
        double AcceptedPercentage(Solution* solution, double temp);
        double InitialTemperature(
            Solution* solution,
            double initial_temp,
            double P
        );

    public:
        Temperature(
            Solution* solution,
            double initial_temp,
            double P,
            double virtual_zero,
            int instance_size,
            double decrease_rate
        );
        double GetTemperature();
        bool BiggerThanZero();
        void Decrease();
};
