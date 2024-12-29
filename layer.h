#ifndef LAYER_H
#define LAYER_H

#include "neuron.h"
#include <iostream>
#include <iomanip>

class Layer {
private:
    Neuron** neurons;
    int size;

public:
    Layer* next;
    Layer* prev;

    Layer(int n);
    Layer(int n, int _n);

    ~Layer();

    int getSize() { return size; }
    Neuron** getNeurons() { return neurons; }

    float* getLayerActivations();
    void activateNeurons();


    void printLayerActivations();
};

#endif // LAYER_H
