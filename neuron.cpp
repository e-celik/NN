#include "neuron.h"
#include "layer.h"

#include <cmath>

Neuron::Neuron(Layer* l, int _n) {
    layer = l;

    a = 0.141593;

    // consider randomizing here, or not (maybe want to use seed to replicate nets)
    wSize = _n;
    w = new float[wSize];

    b = 0;
}

Neuron::Neuron(Layer* l) {
    layer = l;

    a = 0.718;
}

Neuron::~Neuron() {
}

void Neuron::activateNeuron() {
    float* activations = layer->getLayerActivations();

    float x = 0;

    for (int i = 0; i < wSize; i++) {
        x += w[i] * activations[i];
    }

    x += b;

    if (layer->next == nullptr) {                       // if final
        a = 1 / (1 + exp(-x));
    } else {                                            // if hidden
        a = x > 0 ? x : 0;
    }
}