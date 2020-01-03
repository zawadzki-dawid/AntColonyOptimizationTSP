//
// Created by dawid on 27.12.2019.
//

#include "Matrix.h"

using namespace std;

Matrix::~Matrix() {
    delete [] matrix;
}

Matrix::Matrix(string fileName, string filePath, double pheromone) {

    ifstream file;
    file.open(filePath+fileName, ios::out);
    file >> matrixName;
    file >> matrixSize;
    if(file.is_open()){
        matrix = new Edge*[matrixSize];
        for(int i=0; i<matrixSize; i++) {
            matrix[i] = new Edge[matrixSize];
            for (int j = 0; j < matrixSize; j++) {
                file >> matrix[i][j].value;
                matrix[i][j].pheromone = pheromone;
            }
        }
        file.close();
    }
    else{
        cout<<"File cannot be opened!"<<endl;
    }
}

void Matrix::printMatrixValue() const {
    for(int i=0; i<matrixSize;i++){
        for(int j=0; j<matrixSize; j++)
            cout<<matrix[i][j].value<<" ";
        cout<<endl;
    }
}

void Matrix::printMatrixPheromone() const {
    for(int i=0; i<matrixSize;i++){
        for(int j=0; j<matrixSize; j++)
            cout<<matrix[i][j].pheromone<<" ";
        cout<<endl;
    }
}

int Matrix::getMatrixSize() const {
    return matrixSize;
}

std::string Matrix::getName() const {
    return matrixName;
}

Edge* const &Matrix::operator[](int i) const{
    return matrix[i];
}

int Matrix::pathValue(std::vector<int> path) const {
    int sum = 0;
    for(int i=0; i<path.size()-1; i++)
        sum += matrix[path[i]][path[i+1]].value;
    sum += matrix[path[path.size() - 1]][0].value;
    return sum;
}