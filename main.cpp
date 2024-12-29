#include "network.cpp"
#include "util.cpp"

#include <stdio.h>

using namespace std;

int main() {
    int layerSizes[] = {16, 8, 8, 2};

    Network* nn = new Network(4, layerSizes);



    return 0;
}