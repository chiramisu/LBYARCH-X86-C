# LBYARCH-X86-C
### LBYARCH S25A
### Members:
* Dimaunahan, Chelsea
* Pascual, Jaica

## PROJECT SPECIFICATIONS
Write the kernel in (1) C program and (2) an x86-64 assembly language. The kernel is to perform the SAXPY (A*X + Y) function.
* Required to use functional scalar SIMD registers
* Required to use functional scalar SIMD floating-point instructions

**Input:** 
Scalar variable n (integer) contains the length of the vector; Scalar variable A is a single-precision float. Vectors X, Y and Z are single-precision float.

**Process:** 
Z[i] = A•X[i] + Y[i]

**Example:**
A -> 2.0
x -> 1.0, 2.0, 3.0
y - 11.0, 12.0, 13.0
(answer) z-> 13.0, 16.0, 19.0
Output: store result in vector Z. Display the result of 1st ten elements of vector Z for all versions of kernel (i.e., C and x86-64).
