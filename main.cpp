#include "network.h"

#include <stdio.h>

using namespace std;

int main() {
    int layerSizes[] = {32, 16, 16, 16, 10};

    Network* nn = new Network(5, layerSizes);

    nn->printNetworkActivations();

    nn->feedForward();

    nn->printNetworkActivations();

    float ys[] = {0.0, 0.5, 0.0, 0.5, 0.0, 0.5, 0.0, 0.5, 0.0, 0.5};

    nn->backPropogate(ys);

    nn->feedForward();

    nn->printNetworkActivations();

    delete nn;

    return 0;
}