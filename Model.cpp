//
// Created by Mark Hsu on 2019/11/11.
//

#include "Model.h"
#include <cmath>

void Model::setFunction(Functions function) {
    this->function = function;
}

void Model::setDimension(int dim) {
    this->dimension = dim;
}

int Model::getDimension() {
    return dimension;
}

void Model::setDomain(float lower, float upper) {
    this->domain.lower = lower;
    this->domain.upper = upper;
}

Domain Model::getDomain() {
    return this->domain;
}

double Model::calcFitness(float *pos) {
    double fitness = 0;
    //TODO function should write in one line
    switch (this->function) {
        case Absolute:
            for (int i = 0; i < this->dimension; i++) {
                fitness += absolute(pos[i]);
            }
            return fitness;
        case Sphere:
            for (int i = 0; i < this->dimension; i++) {
                fitness += sphere(pos[i]);
            }
            return fitness;
        case Rastrigin:
            for (int i = 0; i < this->dimension; i++) {
                fitness += rastrigin(pos[i]);
            }
            fitness += 10.0 * this->dimension;
            return fitness;
    }
}

bool Model::isOutOfRange(float position) {
    return (position > this->domain.upper || position < this->domain.lower);
}

double Model::absolute(float pos) {
    return fabs(pos);
}

double Model::sphere(float pos) {
    return powf(pos, 2);
}

double Model::rastrigin(float pos) {
    return pow(pos, 2.0) - 10.0 * cos(2.0 * acos(-1) * pos);
}
