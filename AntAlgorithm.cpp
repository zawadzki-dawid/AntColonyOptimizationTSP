//
// Created by dawid on 03.01.2020.
//

#include "AntAlgorithm.h"

using namespace std;

ACO::ACO(Matrix& matrix) : matrix(matrix){

}

void ACO::execute(int swarmSize, int iterations, int alpha, int beta, double evaporation){
    vector<int> nodes;
    for(int i=1; i<matrix.getMatrixSize(); i++)
        nodes.push_back(i);
    for(int i=0; i<iterations; i++) {
        for (int j = 0; j<swarmSize; j++) {
            Ant ant{nodes};
            ant.search(matrix, alpha, beta, evaporation);
        }
    }
}