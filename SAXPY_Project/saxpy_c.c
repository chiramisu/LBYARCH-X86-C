#include <stdio.h>

void saxpy_c(float A, const float* X, const float* Y, float* Z, int n)
{
    for (int i = 0; i < n; i++) {
        Z[i] = A*X[i] + Y[i];
    }
}