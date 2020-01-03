//
// Created by dawid on 03.01.2020.
//

#ifndef ACO_ANT_H
#define ACO_ANT_H

#include "Matrix.h"
#include <vector>
#include <cmath>
#include <random>

class Ant {
    int currentNode;
    std::vector<int> unvisitedNodes;
    std::vector<int> visitedNodes;
    void chooseNode(const Matrix& matrix, int alpha, int beta);
    void addPheromone(Matrix& matrix, double evaporation);

public:
    Ant(std::vector<int> unvisitedNodes);
    void search(Matrix& matrix, int alpha, int beta, double evaporation);
};


#endif //ACO_ANT_H
