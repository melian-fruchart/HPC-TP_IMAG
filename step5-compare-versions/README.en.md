# STEP 5 - compare

The script [./compare.sh](./compare.sh) executes each version of the matrix multiplication code seen in the previous steps.

### Configuration
```
MATRICE_SIZE: Size of matrices to be multiplied.
OMP_NUM_THREADS: Number of threads used for OpenMP.
```

### Execution
*Check that all binary versions exist. (if you've used `make clean` in a folder, you'll have to go back there to compile it)*.



To run the test script and display the performance of each program version, use the following command in the terminal:
```
./compare.sh
```

The `compare.sh` script runs each program version with the specified matrix size and displays the results in tabular form, including program type, number of threads, number of servers and execution time.

# Summary
- For a matrix multiplication of 1500x1500, what were the speed-up factors between the different program "improvements" (naive, optimized, OpenMP, MPI, OpenMP + MPI)?

You can do this using the `compare.sh` script, by setting the matrix size to 1500 instead of 500.

- What was the total acceleration factor?