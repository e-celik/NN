#ifndef NEURON_H
#define NEURON_H

class Layer;

class Neuron {
private:
    Layer* layer;
    float a;
    float* w;
    int wSize;
    float b;

public:
    Neuron(Layer* l, int _n);
    Neuron(Layer* l);

    ~Neuron();

    void activateNeuron(float*);

    float* backPropogateNeuron(float, float*);

    float getA() { return a; }
    float* getW() { return w; }
    int getWSize() { return wSize; }
    float getB() { return b; }
};

#endif // NEURON_H
