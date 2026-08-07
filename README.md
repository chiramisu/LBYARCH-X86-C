# LBYARCH-X86-C SAXPY Function
### LBYARCH S25A
### Members:
* Dimaunahan, Chelsea
* Pascual, Jaica

# PROJECT SPECIFICATIONS
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

**_(answer) z -> 13.0, 16.0, 19.0_**

**Output:** 
Store result in vector Z. Display the result of 1st ten elements of vector Z for all versions of kernel (i.e., C and x86-64).

**Note:**
1. Write a C main program to call the kernels of the C version and x86-64 assembly language.
2. Time the kernel portion only.
3. For each kernel version, time the process for vector size n = {2^20, 2^24, and 2^30}. If 2^30 is impossible, you may reduce it to the point your machine can support (i.e., 2^28 or 2^29).
4. You must run at least 30 times for each version to get the average execution time.
5. For the data, you may initialize each vector and scalar variable with the same or different random value.
6. You will need to check the correctness of your output. Thus, if the C version is your "sanity check answer key," then the output of the x86-64 version has to be checked with the C version and output correspondingly (i.e., the x86-64 kernel output is correct, etc.).

# COMPARATIVE EXECUTION TIME AND SHORT ANALYSIS OF PERFORMANCE
The C and x86-64 assembly implementations of the SAXPY kernel were tested using three different vector sizes. Each kernel was executed 30 times for every vector size, and the average execution time was recorded.

| Vector Size | C Average Time (s) | x86-64 ASM Average Time (s) | Speedup (C / ASM) |
|---|---:|---:|---:|
| 2^20 (1,048,576) | 0.00145 | 0.00038 | 3.82x |
| 2^24 (16,777,216) | 0.02398 | 0.00821 | 2.92x |
| 2^28 (268,435,456) | 0.38690 | 0.13501 | 2.87x |

### Performance Analysis

The x86-64 assembly implementation was faster than the C implementation for all three tested vector sizes. For a vector size of 2^20, the assembly kernel was approximately 3.82 times faster than the C kernel. For 2^24, it was approximately 2.92 times faster, while for 2^28, it was approximately 2.87 times faster.

As the vector size increased, the execution time of both implementations also increased because a larger number of elements had to be processed. The x86-64 implementation consistently required less execution time than the C implementation during our tests.

The speedup became slightly smaller as the vector size increased. One possible reason is that larger vectors require more memory access. As the amount of data increases, memory access and cache behavior can have a greater effect on the total execution time, rather than the arithmetic instructions alone.

Despite the difference in execution time, both implementations produced the same output. The correctness check passed for all tested vector sizes, confirming that the x86-64 assembly implementation produced results equivalent to the C implementation.

# PROGRAM OUTPUT
![First output for vector size 2^20](/assets/firstOutput.jpeg)
![Second output for vector size 2^24](/assets/secondOutput.jpeg)
![Third output for vector size 2^28](/assets/thirdOutput.jpeg)

All three outputs show the first 10 elements of vector Z for each kernel, whether it passed the correctness check, and the average time for each implementation.

# DEMO VIDEO
VIEW HERE: https://youtu.be/Ts5uCkCq-qI

## IMPORTANT: HOW TO COMPILE AND RUN
**Notes:**
* Please make sure you're in the SAXPY_Project directory.
* saxpy_asm.asm uses MASM syntax and must be assembled using `ml64`. It cannot be compiled directly with `gcc`.

**ALL FILES ARE ALREADY AVAILABLE IN THE SAXPY_Project FOLDER. Proceed to Step 3 if you want to run the program.**

### Step 1 - ASM Implementation

The **.asm** file was assembled using the x64 Native Tools Command Prompt with the command:

`ml64 /c saxpy_asm.asm`

which created the **_saxpy_asm.obj_** file


### Step 2 - C Implementation

The C files were compiled one by one:

`gcc -c saxpy_c.c`

`gcc -c main.c`

which created the **_main.o_** and **_saxpy_c.o_** files

### Step 3 - Running the Program

Linking everything, to make the program run, input in the Command Prompt the following command:

`gcc main.o saxpy_c.o saxpy_asm.obj -o main.exe`


