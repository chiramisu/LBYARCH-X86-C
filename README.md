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
text
# PROGRAM OUTPUT - ASM IMPLEMENTATION
hyperlink image and text desc

# PROGRAM OUTPUT - C IMPLEMENTATION
hyperlink image and text desc

# DEMO VIDEO
hyperlink video

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


