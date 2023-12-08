# Parallelized execution
In this second step, we study the parallelization of the matrix multiplication program seen before.
To do this, we'll use the OpenMP programming model. 

OpenMP (Open Multi-Processing) is an API (Application Programming Interface) for parallel programming in shared memory. It is mainly used to improve program performance by exploiting the power of multi-core processor architectures. 

### **Before you start**

OpenMP is renowned for its ease of use, enabling developers to efficiently integrate parallelism into their applications with simple pre-compiler directives and minimal source code modifications.
To grasp the concept, use the file [openmp_hello.c](./openmp_hello.c) and compile it with the following command:
```
gcc -fopenmp openmp_hello.c -o openmp_hello
./openmp_hello
```

- Search the Internet for the `OMP_NUM_THREADS` environment variable and what is it used for ([Environment variables](https://gcc.gnu.org/onlinedocs/libgomp/Environment-Variables.html)).
- Comment the line `omp_set_num_threads(4);` then run the program a few times, after defining different numbers of threads (`export OMP_NUM_THREADS=3`).

### **1. Compile prog1_naive and prog2_optimized** programs

In the `step2-parallelized/` directory:

```make```

### **2. Read and experiment with the parallelized implementation [prog2_optimized.c](./prog2_optimized.c)**.

- Understand the syntax used to parallelize for loops.
- Study different executions with different numbers of threads

```bash
export OMP_NUM_THREADS=n
./prog2_optimized
```

# OpenMP scaling


- What do you think is the best number of threads to use? (hint: use the `lscpu` command)


- Using the script [scaling_omp.sh](./scaling_omp.sh), study the evolution of program performance for an increasing number of threads, and a fixed matrix size:
```
./scaling_omp.sh
```

- Describe the evolution of execution time depending on the number of threads, and explain the performance behavior.
- What is the program's acceleration factor?