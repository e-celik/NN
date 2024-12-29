#include "neuron.cpp"
#include "util.cpp"

class Layer

{
private:
    Neuron** neurons;
    int size;

public:
    Layer(int, int);
    Layer(int);

    ~Layer();

    int getSize() { return this->size; }
    Neuron** getNeurons() { return neurons; }
    void printLayerActivations();
};

Layer::Layer(int n) {
    this->size = n;
    this->neurons = new Neuron*[n];
    for (int i = 0; i < n; i++) {
        Neuron* newNeuron = new Neuron();
        this->neurons[i] = newNeuron;   //consider statement aggregation
    }
}

Layer::Layer(int n, int _n) {
    this->size = n;
    this->neurons = new Neuron*[n];
    for (int i = 0; i < n; i++) {
        Neuron* newNeuron = new Neuron(_n);
        this->neurons[i] = newNeuron;   //consider statement aggregation
    }
}

Layer::~Layer() {  
}

void Layer::printLayerActivations() {
    for (int i = 0; i < size; i++) {
        cout << fixed << setprecision(2) << neurons[i]->getA() << endl;
    }
}
