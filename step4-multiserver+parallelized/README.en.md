# Multiserver and parallelized execution
In this final step, we'll be looking at parallelizing the program on two machines, with 4 threads per machine. We will therefore combine OpenMP and OpenMPI.

### **Read and run the OpenMP + MPI implementation [prog2_optimized_mpi_omp.c](./prog2_optimized_mpi_omp.c)**
- Once you've understood what the program does, run it with :
```
make parallel_run
```

The code of this command has been modified to pass OpenMP information.

It is still possible to pass the matrix size as a parameter to the executed program:
```makefile
parallel_run: prog2_optimized_mpi copy_binary
	OMP_NUM_THREADS=4 OMP_PROC_BIND=spread OMP_PLACES=cores $(MPIRUN) -np 2 --map-by ppr:1:socket:pe=4 --host $(THIS_SERVER),$(PEER_SERVER) ./prog2_optimized_mpi [matrix size]
```
It is also possible to modify the number of threads in the Makefile, by changing the value associated with `OMP_NUM_THREADS` (see command above).

- Given the execution time of `prog2_optimized_mpi`, estimate the time it will take to run `prog2_optimized_mpi_omp` with a 1500x1500 matrix.
- Edit the Makefile and check the program execution time for a 1500x1500 matrix.