#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>
#include <random>

using std::vector;
using std::default_random_engine;
using std::uniform_real_distribution;

class StepGenerator : public TimeSeriesGenerator {
public:

    // Constructeur par défaut
    StepGenerator() : TimeSeriesGenerator(0) {}

    // Constructeur paramétrisé
    StepGenerator(int seed) : TimeSeriesGenerator(seed) {}

    // Implémentation de la fonction virtuelle pure
    vector<double> generateTimeSeries(int size) override {
        vector<double> series(size);
        default_random_engine generator(seed);
        uniform_real_distribution<double> distribution(0.0, 100.0);
        uniform_real_distribution<double> decision(0.0, 1.0);

        series[0] = 0; // Le premier instant contient la valeur 0

        for (int i = 1; i < size; ++i) {
            if (decision(generator) < 0.5) {
                series[i] = series[i - 1]; // Garde la valeur de l'instant précédent
            } else {
                series[i] = distribution(generator); // Choisis une nouvelle valeur entre 0 et 100
            }
        }

        return series;
    }
};

#endif