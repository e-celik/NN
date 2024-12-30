#include "neuron.h"
#include "layer.h"
#include "stdlib.h"

#define LEAK 0.01
#define ALPHA 0.01

#include <cmath>

using namespace std;

Neuron::Neuron(Layer* l, int _n) {
    layer = l;

    a = 0;

    // consider randomizing here, or not (maybe want to use seed to replicate nets)
    wSize = _n;
    w = new float[wSize];
    for (int i = 0; i < wSize; i++) {
        w[i] = 1.0 - (2.0 * (float)(rand())/(float)(RAND_MAX));
    }

    b = 2 * (float)(rand())/(float)(RAND_MAX);
}

Neuron::Neuron(Layer* l) {
    layer = l;

    w = nullptr;

    b = 0;

    a = (float)(rand())/(float)(RAND_MAX);
}

Neuron::~Neuron() {
        delete[] w;
}

void Neuron::activateNeuron(float* activations) {
    float x = 0;

    for (int i = 0; i < wSize; i++) {
        x += w[i] * activations[i];
    }

    x += b;

    if (layer->next == nullptr && 0) {                       // if final
        a = 1 / (1 + exp(-x));  // Sigmoid
    } else {                                            // if hidden
        a = x > 0 ? x : LEAK*x;  // LReLU
    }
}

float* Neuron::backPropogateNeuron(float y, float* activations) {

    float* result = new float[layer->prev->getSize()];

    float sigma_prime = (a > 0.0) * (1-LEAK) + LEAK;
    // update bias for neuron
    b = b - ALPHA * ( 1.0 / layer->getSize() ) * sigma_prime * 2.0 * ( a - y );

    for (int i = 0; i < layer->prev->getSize(); i++) {  // for all connections to prev layer
        // update weights for neuron
        w[i] = w[i] - ALPHA * ( 1.0 / layer->getSize() ) * activations[i] * sigma_prime * 2.0 * ( a - y );
        // calculate propogation values
            // consider a check in order to not calculate propogation values (desired activations in previous layer) if first hidden layer. 
            // (Because the input layer has no weights and biases)
        result[i] = activations[i] - ALPHA * ( 1.0 / layer->getSize() ) * w[i] * sigma_prime * 2.0 * ( a - y );
    }

    return result; // delete from callee
    
}
