#include "neuron.h"
#include "layer.h"
#include "stdlib.h"

#define LEAK 0.01
#define ALPHA 0.1

#include <cmath>

using namespace std;

Neuron::Neuron(Layer* l, int _n, Act func) {
    layer = l;

    activation = func;

    a = 0;

    // consider randomizing here, or not (maybe want to use seed to replicate nets)
    wSize = _n;
    w = new float[wSize];
    for (int i = 0; i < wSize; i++) {
        w[i] = (1.0 - (2.0 * (float)(rand())/(float)(RAND_MAX)))/1.0;
    }

    b = 0;
}

Neuron::Neuron(Layer* l, Act func) {
    layer = l;

    activation = func;

    float defaultw[] = {0.0};
    w = defaultw;

    b = 0;

    a = (float)(rand())/(float)(RAND_MAX);
}

Neuron::~Neuron() {
        delete[] w;
}

void Neuron::activateNeuron(float* activations) {
    float x = 0.0;

    for (int i = 0; i < wSize; i++) {
        x += w[i] * activations[i];
        //cout << setprecision(2) << activations[i]*100 << ", " << w[i] << ", " << b << endl;
    }

    x += b;

    switch (activation) {
    case LReLU:
        a = x > 0.0 ? x : LEAK*x;
        break;
    case Sigmoid:
        a = 1.0 / (1.0 + exp(-x));
        break;
    case NoFunc:
        a = 0.0;
        break;
    }
}

float* Neuron::backPropogateNeuron(float y, float* activations) {

    float* result = new float[layer->prev->getSize()];

    float sigma_prime;

    switch (activation) {
        case LReLU:
            sigma_prime = (a > 0.0) * (1.0-LEAK) + LEAK;
            break;
        case Sigmoid:
            sigma_prime = a*(1.0-a);
            break;
        case NoFunc:
            sigma_prime = 0;
            break;
    }

    b = b - ALPHA * ( 1.0 / layer->getSize() ) * sigma_prime * 2.0 * ( a - y );
    for (int i = 0; i < layer->prev->getSize(); i++) { 
        w[i] = w[i] - ALPHA * ( 1.0 / layer->getSize() ) * activations[i] * sigma_prime * 2.0 * ( a - y );
        result[i] = activations[i] - ALPHA * ( 1.0 / layer->getSize() ) * w[i] * sigma_prime * 2.0 * ( a - y );
    }

    return result; // delete from callee
    
}
