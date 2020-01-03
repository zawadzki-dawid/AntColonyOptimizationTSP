//
// Created by dawid on 03.01.2020.
//

#ifndef ACO_ANTALGORITHM_H
#define ACO_ANTALGORITHM_H

#include "Matrix.h"
#include "Ant.h"
#include <vector>

class ACO {
    Matrix& matrix;

public:
    ACO(Matrix& matrix);
    void execute(int swarmSize, int iterations, int alpha, int beta, double evaporation);
};

#endif //ACO_ANTALGORITHM_H
