#include "network.h"
#include "util.cpp"

#include <stdio.h>

using namespace std;

int main() {
    int layerSizes[] = {32, 16, 16, 16, 10};

    Network* nn = new Network(5, layerSizes);

    nn->printNetworkActivations();

    nn->feedForward();

    nn->printNetworkActivations();

    return 0;
}