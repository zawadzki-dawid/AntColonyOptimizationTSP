#include <iostream>

#include "Matrix.h"
#include "AntAlgorithm.h"

using namespace std;

int main() {

    int swarmSize = 10, iterations = 20, alpha = 1, beta = 2;
    double evaporation = 0.1, initialPheromone = 1.0;

    Matrix matrix{"data10.txt", "../DATA/SYM/", initialPheromone};
    ACO aco{matrix};

    aco.execute(swarmSize, iterations, alpha, beta, evaporation);

    return 0;
}
