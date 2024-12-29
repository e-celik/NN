class Neuron
{
private:
    float a;

    float* w;
    int wSize;

    float b;

public:
    Neuron(int);
    Neuron();
    ~Neuron();

    float getA() { return a; }
    float* getW() { return w; }
    int getWSize() { return wSize; }
    float getB() { return b; }
};

Neuron::Neuron(int _n) {
    a = 0;

    // consider randomizing here, or not (maybe want to use seed to replicate nets)
    wSize = _n;
    w = new float[wSize];

    b = 0;
}

Neuron::Neuron() {
}

Neuron::~Neuron() {
}