#include "neuron.h"
#include "layer.h"
#include "util.cpp"

Layer::Layer(int n) {
    next = nullptr;
    prev = nullptr;
    size = n;
    neurons = new Neuron*[n];
    for (int i = 0; i < n; i++) {
        Neuron* newNeuron = new Neuron(this);
        neurons[i] = newNeuron;   //consider statement aggregation
    }
}

Layer::Layer(int n, int _n) {
    next = nullptr;
    prev = nullptr;
    size = n;
    neurons = new Neuron*[n];
    for (int i = 0; i < n; i++) {
        Neuron* newNeuron = new Neuron(this, _n);
        neurons[i] = newNeuron;   //consider statement aggregation
    }
}

Layer::~Layer() {  
}

float* Layer::getLayerActivations() {
    float* activations = new float[size];
    for (int i = 0; i < size; i++) {
        activations[i] = neurons[i]->getA();
    }
    return activations;                                 // NOTE: callee must delete when done
}

void Layer::activateNeurons() {
    for (int i = 0; i < size; i++) {
        neurons[i]->activateNeuron();
    }
}

void Layer::printLayerActivations() {
    float* activations = getLayerActivations();
    for (int i = 0; i < size; i++) {
        cout << fixed << setprecision(2) << activations[i]*100 << "    ";
    }
    cout << endl;
}
