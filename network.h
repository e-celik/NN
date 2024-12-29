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

    void printNetworkActivations();
};

#endif // NETWORK_H
