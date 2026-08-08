#include <stdio.h>

extern void saxpy_asm(float A, const float*X, const float*Y, float*Z, int n);
void saxpy_c(float A, const float* X, const float* Y, float* Z, int n);

int main(void) {

    // initialize variables
    int n = 15;                                          // length of the vector
    float A = 6.7;                                       // scalar multiplier

    float X[15] = {1.1, 2.2, 3.3, 4.4, 5.5,              // input vector X
                   6.6, 7.7, 8.8, 9.9, 10.10,
                   11.11, 12.12, 13.13, 14.14, 15.15};  

    float Y[15] = {1.0, 2.0, 3.0, 4.0, 5.0,              // input vector Y
                   6.0, 7.0, 8.0, 9.0, 10.0,   
                   11.0, 12.0, 13.0, 14.0, 15.0};      

    // Two Z vectors to compare the results of C and Assembly implementations
    float Z_c[15];                                       // output vector Z for C implementation
    float Z_asm[15];                                     // output vector Z for Assembly implementation

    // C implementation of SAXPY
    printf("C Implementation:\n");
    saxpy_c(A, X, Y, Z_c, n);
    // printing first 10 elements of the output vector Z
    printf("First 10 elements of Z (C implementation):\n");
    for (int i = 0; i < n && i < 10; i++) {
        printf("%.2f ", Z_c[i]);
    }

    // Assembly implementation of SAXPY
    printf("\n\nAssembly Implementation:\n");
    saxpy_asm(A, X, Y, Z_asm, n);
    // printing first 10 elements of the output vector Z
    printf("First 10 elements of Z (Assembly implementation):\n");
    for (int i = 0; i < n && i < 10; i++) {
        printf("%.2f ", Z_asm[i]);
    }

    return 0;
}