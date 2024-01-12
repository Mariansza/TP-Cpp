#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>
#include <numeric>
#include <valarray>
#include <cmath>
#include <stdexcept>

using namespace std;
using std::vector;
using std::accumulate;
using std::inner_product;

class TimeSeriesDataset {
public:

    // Constructeur par défaut
    TimeSeriesDataset() 
        : znormalize(false), isTrain(false), maxLength(0), numberOfSamples(0) {}

    // Constructeur paramétrisé
    TimeSeriesDataset(bool znormalize, bool isTrain) 
        : znormalize(znormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}

    const vector<int>& getLabels() const {
        return labels;
    }

    // addTimeSeries() ajoute une série temporelle à l'ensemble de données
    void addTimeSeries(const vector<double>& timeSeries) {
        data.insert(data.end(), timeSeries.begin(), timeSeries.end());
    }

    // normalize() calcule la moyenne et l'écart-type de la série temporelle et normalise les valeurs de la série temporelle
    void normalize() {
        if (znormalize) {
            double mean = accumulate(data.begin(), data.end(), 0.0) / data.size();
            double sq_sum = inner_product(data.begin(), data.end(), data.begin(), 0.0);
            double stdDev = sqrt(sq_sum / data.size() - mean * mean);

            for (auto& val : data) {
                val = (val - mean) / stdDev;
            }
        }
    }


     size_t size() const {
        return data.size();
    }
    
    // euclidean_distance() calcule la distance euclidienne entre deux séries temporelles
    double euclidean_distance(const vector<double>& x, const vector<double>& y) {
        if (x.size() != y.size()) {
            throw std::invalid_argument("Les deux séries temporelles doivent avoir la même taille");
        }

        double sum = 0.0;
        for (size_t i = 0; i < x.size(); ++i) {
            double diff = x[i] - y[i];
            sum += diff * diff;
        }

        return sqrt(sum);
    }

    void addTimeSeries(const vector<double>& timeSeries, int label) {
        data.insert(data.end(), timeSeries.begin(), timeSeries.end());
        labels.push_back(label);
    }

    

private:
    bool znormalize;
    bool isTrain;
    vector<double> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;
};

#endif