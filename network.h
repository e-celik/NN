#ifndef NETWORK_H
#define NETWORK_H

#include "layer.h"

class Network {
private:
    Layer* layers;
    Layer* input;
    Layer* output;
    int numLayers;

public:
    Network(int l, int* ns);
    ~Network();

    void feedForward();

    void backPropogate(float*);

    void printNetworkActivations();

    Layer* getInput() { return input; }
    Layer* getoutput() { return output; }
    int getNumLayers() { return numLayers; }

};

#endif // NETWORK_H
