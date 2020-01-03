//
// Created by dawid on 27.12.2019.
//

#ifndef GENETICALGORITHM_MATRIX_H
#define GENETICALGORITHM_MATRIX_H

#include <vector>
#include <string>
#include "fstream"
#include <iostream>

struct Edge {
    int value;
    double pheromone;
};

class Matrix {
    std::string matrixName;

    int matrixSize;

    Edge **matrix;

public:
    Edge *const &operator[](int i) const;

    Matrix(std::string, std::string, double pheromone);

    ~Matrix();

    std::string getName() const;

    int getMatrixSize() const;

    void printMatrixValue() const;

    void printMatrixPheromone() const;

    int pathValue(std::vector<int> path) const;
};


#endif //GENETICALGORITHM_MATRIX_H
