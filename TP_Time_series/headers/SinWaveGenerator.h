#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>
#include <cmath>

using std::vector;
using std::sin;

class SinWaveGenerator : public TimeSeriesGenerator {
public:

    // Constructeur par défaut
    SinWaveGenerator() 
        : TimeSeriesGenerator(0), amplitude(1.0), frequency(1.0), initialPhase(0.0) {}



    // Constructeur paramétrisé
    SinWaveGenerator(int seed, double amplitude, double frequency, double initialPhase) 
        : TimeSeriesGenerator(seed), amplitude(amplitude), frequency(frequency), initialPhase(initialPhase) {}

    // Implémentation de la fonction virtuelle pure
    vector<double> generateTimeSeries(int size) override {
        vector<double> series(size);

        for (int i = 0; i < size; ++i) {
            series[i] = amplitude * sin(frequency * i + initialPhase);
        }

        return series;
    }

private:
    double amplitude;
    double frequency;
    double initialPhase;
};

#endif