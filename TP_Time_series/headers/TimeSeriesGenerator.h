#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include <vector>
#include <iostream>

class TimeSeriesGenerator {
protected:
    int seed;

public:
    // Constructeur par défaut
    TimeSeriesGenerator() : seed(0) {}

    // Constructeur paramétrisé
    TimeSeriesGenerator(int seed) : seed(seed) {}

    // Fonction virtuelle pure
    virtual std::vector<double> generateTimeSeries(int size) = 0;

    // Fonction statique
    static void printTimeSeries(const std::vector<double>& series) {
        for (const auto& value : series) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

#endif