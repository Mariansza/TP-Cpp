#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <cmath>
#include <random>

using std::vector;
using std::default_random_engine;
using std::uniform_real_distribution;
using std::sqrt;
using std::log;
using std::cos;

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;
    double standardDeviation;

public:
    // Constructeur par défaut
    GaussianGenerator() : TimeSeriesGenerator(), mean(0), standardDeviation(1) {}

    // Constructeur paramétrisé
    GaussianGenerator(int seed, double mean, double standardDeviation) : TimeSeriesGenerator(seed), mean(mean), standardDeviation(standardDeviation) {}

    // Implémentation de la fonction virtuelle pure, j'utilise default_random_engine et uniform_real_distribution pour générer des nombres aléatoires avec une distribution normale suivant la méthode de Box-Muller
    vector<double> generateTimeSeries(int size) override {
        vector<double> series(size);
        default_random_engine generator(seed);
        uniform_real_distribution<double> distribution(0.0, 1.0);

        for (int i = 0; i < size; ++i) {
            double u1 = distribution(generator);
            double u2 = distribution(generator);
            series[i] = mean + standardDeviation * sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
        }

        return series;
    }
};

#endif