#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <valarray>

using namespace std;


class KNN {
public:
    KNN(int k, string similarity_measure) // Constructeur paramétrisé
        : k(k), similarity_measure(similarity_measure) {}

    
    double evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const vector<int>& ground_truth) {
        // On vérifie que les deux ensembles ont la même taille
        const vector<int>& ypred = testData.getLabels();

        if (ground_truth.size() != ypred.size()) {
            throw std::invalid_argument("Les deux ensembles doivent avoir la même taille");
        }

        int correct = 0;
        for (size_t i = 0; i < ground_truth.size(); ++i) {
            if (ground_truth[i] == ypred[i]) {
                ++correct;
            }
        }

        return static_cast<double>(correct) / ground_truth.size();
    }

   

private:
    int k;
    string similarity_measure;
};