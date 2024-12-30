#ifndef LAYER_H
#define LAYER_H

#include "neuron.h"
#include <iostream>
#include <iomanip>

class Network;

class Layer {
private:
    Neuron** neurons;
    int size;
    Network* nn;

public:
    Layer* next;
    Layer* prev;

    Layer(Network*, int n);
    Layer(Network*, int n, int _n);

    ~Layer();

    int getSize() { return size; }
    Neuron** getNeurons() { return neurons; }

    float* getLayerActivations();
    void activateNeurons();

    void backPropogateLayer(float*);


    void printLayerActivations();
};

#endif // LAYER_H
