#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

extern void saxpy_asm(float A, const float*X, const float*Y, float*Z, int n);
void saxpy_c(float A, const float* X, const float* Y, float* Z, int n);

// Functions for checking
double averageTime(void(*implementation)(float, const float*, const float*, float*, int), 
                float A, const float* X, const float* Y, float* Z, int n)
{
    double total = 0;
    LARGE_INTEGER start, end, freq;
    QueryPerformanceFrequency(&freq);

    for(int i=0;i<30;i++)
    {
        QueryPerformanceCounter(&start);

        implementation(A, X, Y, Z, n);

        QueryPerformanceCounter(&end);

        total +=
            (double)(end.QuadPart-start.QuadPart)/
            freq.QuadPart;
    }

    return total/30.0;      // average after 30 times
}

int main(void) {

    int sizes[] = {1 << 20, 1 << 24, 1 << 28};

    // looping through the sizes to check the performance 
    for (int s = 0; s < 3; s++) {

    // initialize variables
    int n = sizes[s];                                   // length of the vector
    float A = 6.7;                                      // scalar multiplier; keeping it the same throughout every different vector size
    
    printf("\n\n=====================================\n");
    printf("Vector Size (n) = %d\n", n);
    printf("=====================================\n");

    float *X = malloc(n*sizeof(float));                 // input vector X
    float *Y = malloc(n*sizeof(float));                 // input vector Y
    float *Z_c = malloc(n*sizeof(float));               // output vector Z for C Implementation
    float *Z_asm = malloc(n*sizeof(float));             // output vector Z for Assembly implementation

    // malloc check if it failed or not
    if (X == NULL || Y == NULL || Z_c == NULL || Z_asm == NULL) {
        printf("Memory allocation failed for n = %d\n", n);
        return 1;
    }

    // fill input vectors with values
    // not using rand() so the values are deterministic accdg to n
    for(int i=0;i<n;i++)
    {
        X[i] = (float)i;
        Y[i] = (float)(i + 1);
    }

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

    // Correctness check
    int correct = 1;
    for (int i = 0; i < n; i++) {
        if (fabsf(Z_c[i] - Z_asm[i]) > 0.0001f) {
            printf("Mismatch at index %d\n", i);
            printf("C   = %.6f\n", Z_c[i]);
            printf("ASM = %.6f\n", Z_asm[i]);
            correct = 0;
            break;
        }
    }
    if (correct)
        printf("\nCorrectness Check: PASSED\n");
    else
        printf("\nCorrectness Check: FAILED\n");

    // Average time -- C
    double cAverage = averageTime(saxpy_c, A, X, Y, Z_c, n);
    printf("C average time = %.5f seconds\n", cAverage);

    // Average time -- ASM
    double asmAverage = averageTime(saxpy_asm, A, X, Y, Z_asm, n);
    printf("ASM average time = %.5f seconds\n", asmAverage);

    // freeing memory after
    free(X);
    free(Y);
    free(Z_c);
    free(Z_asm);

    }

    return 0;

}