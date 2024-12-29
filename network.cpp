#include "layer.cpp"
#include "util.cpp"

class Network
{
private:
    Layer** layers;

    Layer* input;
    Layer* output;
    Layer* firstHidden;

    int numLayers; // including i/o
public:


    Network(int, int*);
    ~Network();
};

Network::Network(int l, int* ns) {
    layers = new Layer*[l];
    layers[0] = new Layer(ns[0]);
    for (int i = 1; i < l; i++) {
        Layer* newLayer = new Layer(ns[i], ns[i-1]);
        this->layers[i] = newLayer;
    }

    this->numLayers = l;

    this->input = layers[0];
    this->output = layers[l-1];
    this->firstHidden = layers[1];

    printf("Neural Network Created, with %d input neurons, and %d output neurons. \n", this->input->getSize(), this->output->getSize());
}

Network::~Network() {
}
