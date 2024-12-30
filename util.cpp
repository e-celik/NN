//using namespace std;
#include "util.h"

float calculateMSE(float* e, int n) {
    float result = 0;
    for (int i = 0; i < n; i++) {
        result += e[i];
    }
    return result / n;
}

float* getErrorVector(float* y_hat, float* y,int n) {
    float* result = new float[n];
    for (int i = 0; i < n; i++) {
        result[i] = pow((y_hat[i]-y[i]),2);
    }
    return result;                                  // must be deleted by callee
}