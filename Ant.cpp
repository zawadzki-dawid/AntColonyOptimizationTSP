//
// Created by dawid on 03.01.2020.
//

#include "Ant.h"

using namespace std;

std::random_device rd;


std::mt19937 e2(rd());

std::uniform_real_distribution<> dist(0, 1);

Ant::Ant(vector<int> unvisitedNodes) : unvisitedNodes(unvisitedNodes) {
    currentNode = 0;
    visitedNodes.push_back(0);
}

void Ant::chooseNode(const Matrix& matrix, int alpha, int beta) {
    double sum = 0.0;
    vector<double> roulette;
    vector<double> results;
    for(int i=0; i<unvisitedNodes.size(); i++) {
        results.push_back(pow(matrix[currentNode][unvisitedNodes[i]].pheromone, alpha) *
               pow(1.0 / matrix[currentNode][unvisitedNodes[i]].value, beta));
        sum += results[i];
    }
    for(int i=0; i<unvisitedNodes.size(); i++){
        if(i == 0)
            roulette.push_back(results[i]);
        else
            roulette.push_back(roulette[i - 1] + results[i]);
    }
    double random = dist(e2);
    for(int i=0; i<roulette.size(); i++)
        if(random < roulette[i]){
            currentNode = unvisitedNodes[i];
            visitedNodes.push_back(unvisitedNodes[i]);
            unvisitedNodes.erase(unvisitedNodes.begin() + i);
            break;
        }
}

void Ant::addPheromone(Matrix& matrix, double evaporation) {
    int sum;
    sum = matrix.pathValue(visitedNodes);
    for(int i=0; i<visitedNodes.size()-1; i++)
       matrix[visitedNodes[i]][visitedNodes[i+1]].pheromone += (1.0/(double)sum);
    matrix[visitedNodes[visitedNodes.size() - 1]][0].pheromone += (1.0/(double)sum);
}

void Ant::search(Matrix& matrix, int alpha, int beta, double evaporation) {
     while(unvisitedNodes.size() > 0)
        chooseNode(matrix, alpha, beta);
    addPheromone(matrix, evaporation);
}