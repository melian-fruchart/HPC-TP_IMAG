# Multiserver execution
In this third step, we'll look at how to parallelize the program on two machines. To do this, we'll use OpenMPI.

OpenMPI is an open-source implementation of MPI (Message Passing Interface), a standard for parallel programming on distributed or distributed-memory systems.
OpenMPI facilitates the development of parallel applications by providing features for communication and coordination between processes running simultaneously on a cluster of machines.

### **Read and run the MPI implementation [prog2_optimized_mpi.c](./prog2_optimized_mpi.c)**

- Once you've understood what the program does, run it with :
```
make parallel_run
```
This command compiles the program, sends a copy of the binary to the second machine (via the `ship_binary.sh` script), then starts execution. 
Each machine then performs one part of the matrix multiplication, and the final result is obtained by merging the two parts. 

- Given that the execution of `prog2_optimized` took 60 seconds on a single thread and a single machine, estimate how long it will take to execute `prog2_optimized_mpi` with a matrix size of 1500x1500.

To pass the matrix size as a parameter to the executed program, you need to modify the `parallel_run` target command line in the makefile, as shown below:
```makefile
parallel_run: prog2_optimized_mpi copy_binary
	$(MPIRUN) -np 2 --host $(THIS_SERVER),$(PEER_SERVER) ./prog2_optimized_mpi [matrix size] .
```

- Modify the Makefile and check the program execution time for a 1500x1500 matrix.
