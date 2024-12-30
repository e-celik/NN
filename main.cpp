#include "network.h"

#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
    int layerSizes[] = {1,2,1};

    Network* nn = new Network(3, layerSizes);

    nn->printNetworkActivations();

    float ys[] = {0.75};

    for (int i = 0; i < 10000; i++) {
        float input[] = {(float)(rand())/(float)(RAND_MAX)};
        nn->doInput(input);
        float output[] = {pow(input[0],0.5)};
        nn->feedForward();
        nn->backPropogate(output);
        if (i%100==0) {
            cout << "expected: " << fixed << setprecision(0) << output[0]*100 << endl;
            nn->printNetworkActivations();
        }
    }
    cout << "done\n";


    delete nn;

    return 0;
}