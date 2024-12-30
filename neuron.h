#ifndef NEURON_H
#define NEURON_H

#include <string>

using namespace std;

class Layer;

enum Act {
    LReLU,
    Sigmoid,
    NoFunc
};

class Neuron {
private:
    Layer* layer;
    float a;
    //float z; //not needed (yet) may be needed for more complex activation functions in order to compute derivative
    float* w;
    int wSize;
    float b;
    Act activation;

public:
    Neuron(Layer* l, int _n, Act func);
    Neuron(Layer* l, Act func);

    ~Neuron();

    void activateNeuron(float*);

    float* backPropogateNeuron(float, float*);

    float getA() { return a; }
    float* getW() { return w; }
    int getWSize() { return wSize; }
    float getB() { return b; }
    void setA(float input) {a = input;}
    string getActivation() {
        switch(activation) {
            case LReLU:
            return "LReLU";
            case Sigmoid:
            return "Sigmoid";
            case NoFunc:
            return "NoFunc";
            default:
            return "Oops";
        }
    }
};

#endif // NEURON_H
