#include "neuron.h"
#include "layer.h"
#include "network.h"
#include "util.h"

using namespace std;

Layer::Layer(Network* nn, int n, Act func) {
    this->nn = nn;
    next = nullptr;
    prev = nullptr;
    size = n;
    neurons = new Neuron*[n];
    for (int i = 0; i < n; i++) {
        Neuron* newNeuron = new Neuron(this, func);
        neurons[i] = newNeuron;   //consider statement aggregation
    }
}

Layer::Layer(Network* nn, int n, int _n, Act func) {
    this->nn = nn;
    next = nullptr;
    prev = nullptr;
    size = n;
    neurons = new Neuron*[n];
    for (int i = 0; i < n; i++) {
        Neuron* newNeuron = new Neuron(this, _n, func);
        neurons[i] = newNeuron;   //consider statement aggregation
    }
}

Layer::~Layer() {  
    for (int i = 0; i < size; i++) {
        delete neurons[i];
    }
    delete[] neurons;
}

void Layer::setActivations(float* input) {
    for (int i = 0; i < size; i++) {
        neurons[i]->setA(input[i]);
    }
}


float* Layer::getLayerActivations() {
    float* activations = new float[size];
    for (int i = 0; i < size; i++) {
        activations[i] = neurons[i]->getA();
    }
    return activations;                                 // NOTE: callee must delete when done
}

void Layer::activateNeurons() {
    float* activations = prev->getLayerActivations();
    for (int i = 0; i < size; i++) {
        neurons[i]->activateNeuron(activations);
    }
    delete[] activations;
}

void Layer::backPropogateLayer(float* y) {
    float* yBack = new float[prev->size];
    for (int k = 0; k < prev->size; k++) {
        yBack[k] = 0;
    }
    float* activations = prev->getLayerActivations();
    for (int i = 0; i < size; i++) {                            
        float* result = neurons[i]->backPropogateNeuron(y[i], activations);     // get results from each node
        for (int j = 0; j < prev->size; j++) {
            yBack[j] += result[j];                              // add to total for next node  
        }
        delete[] result;  
    }
    delete[] activations;
    if (prev != nn->getInput()) {
        prev->backPropogateLayer(yBack);
    }
    delete[] yBack;
}

void Layer::printLayerActivations() {
    float* activations = this->getLayerActivations();
    for (int i = 0; i < size; i++) {
        cout << fixed << setprecision(0) << setw(2) << "|" << activations[i]*100 << ", " << neurons[i]->getB() << ", " << neurons[i]->getW()[0] << "|";
    }
    cout << "       " << neurons[0]->getActivation() << endl;
    delete[] activations;
}
