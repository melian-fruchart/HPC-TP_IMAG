# Sequential execution
In this first step, we study a naive implementation of a matrix multiplication program. We then study how a small modification of the original program can improve performance.

### **1. Compile prog1_naive and prog2_optimized** programs
In the directory `step1-sequential/` :

``make```

The `prog2_optimized` program is not to be run immediately, but will be useful later.

### **2. Read and execute the original implementation in [prog1_naive.c](./prog1_naive.c)**.


This C code implements a program that multiplies two square matrices. If an argument is supplied at runtime, it defines the size of the matrices (default 500x500 elements).

The program dynamically allocates memory (`malloc`) for two input matrices and one result matrix, all of specified size. The input matrices mat1 and mat2 are initialized by the `initialize_matrices` function, and the result matrix is initialized to zero (`calloc`).

The program then multiplies these matrices and measures the time taken for this operation. The `TIC` and `TOC` methods measure the execution time between their two calls (in seconds).
Finally, it displays the duration of this operation (`TICTOC_SECONDS`) before terminating. 

Note: The code for checking the result is commented out and will be used in the rest of the tutorial.

To run the program :
```
./prog1_naive [optionnal SIZE]
```

# Scaling analysis

Using the script [scaling_naive.sh](./scaling_naive.sh), study the evolution of the program's performance for larger and larger matrix sizes:
```
./scaling_naive.sh
```

- Describe the evolution of execution time depending on the matrix size.

- Study the algorithmic complexity (number of operations) of the algorithm used, as well as its spatial complexity (memory footprint). Is it consistent with the evolution of execution time?

You can check a program's memory footprint with the command `top` or `htop` (column RES expressed in KiB) (it's best to check the memory footprint when running `prog1_naive`, as matrix sizes change during execution of `scaling_naive.sh`).

- Predict the execution time of 1500x1500 element matrices and the memory footprint (knowing that the size of a double is 8 bytes).

You can check the execution time using the following command:
`./prog1_naive 1500`

- What must be the maximum matrix size for the multiplication to take less than 60 seconds?


# Optimized version
Read and execute the optimized implementation in [prog2_optimized.c](./prog2_optimized.c)

- Compare execution speed with the first version
```
./prog1_naive 
./prog2_optimized
```
- Identify the difference between these two programs
- How do you explain this difference in performance? **Try to formulate hypotheses, represent the multiplications, and don't hesitate to ask us questions or submit theories ** (If you can't come up with any ideas, you can consult the hint: [Locality and Caching](https://www.cs.utexas.edu/users/fussell/courses/cs429h/lectures/Lecture_18-429h.pdf)).
- Using the script [scaling_both.sh](./scaling_both.sh), study the time evolution of the two programs.
- Run the following command and compare this time with that of `prog1_naive.c` :
```
./prog2_optimized 1500
```
