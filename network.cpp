#include "network.h"
#include "layer.h"
#include "util.h"

#include <iostream>

using namespace std;

Network::Network(int l, int* ns) {
    layers = new Layer(this, ns[0]);
    Layer* curLayer = layers;
    input = layers;
    for (int i = 1; i < l; i++) {
        Layer* newLayer = new Layer(this, ns[i], ns[i-1]);
        curLayer->next = newLayer;
        newLayer->prev = curLayer;
        curLayer = newLayer;
    }

    output = curLayer;

    numLayers = l;

    printf("Neural Network Created, with %d input neurons, and %d output neurons. \n", input->getSize(), output->getSize());
}

Network::~Network() {
    Layer* curLayer = input;
    Layer* temp;
    while (curLayer != nullptr) {
        temp = curLayer->next;
        delete curLayer;
        curLayer = temp;
    }
}

void Network::feedForward() {
    Layer* curLayer = input->next;
    while (curLayer != nullptr) {
        curLayer->activateNeurons();
        curLayer = curLayer->next;
    }
}

void Network::backPropogate(float* y) {
    output->backPropogateLayer(y);
}

void Network::printNetworkActivations() {
    Layer* curLayer = input;
    for (int i = 0; i < numLayers; i++) {
        curLayer->printLayerActivations();
        curLayer = curLayer->next;
    }
    cout << "-------------------------------------------------------------------------------" << endl;
}
