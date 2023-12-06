CC = gcc
MPICC = mpicc
MPIRUN = mpirun
SHELL = /bin/bash
THIS_SERVER := $(shell hostname)
PEER_SERVER := $(shell echo $(THIS_SERVER) | sed 's/c1/c2/')

.PHONY: clean copy_binary parallel_run all

all: prog2_optimized_mpi_omp

prog2_optimized_mpi_omp: prog2_optimized_mpi_omp.c
	$(MPICC) -fopenmp -o prog2_optimized_mpi_omp prog2_optimized_mpi_omp.c

pull:
	git pull

copy_binary: prog2_optimized_mpi_omp 
	./ship_binary.sh prog2_optimized_mpi_omp

parallel_run: prog2_optimized_mpi_omp # TODO : copy_binary
	OMP_NUM_THREADS=4 OMP_PROC_BIND=spread OMP_PLACES=cores $(MPIRUN) -np 2 --map-by ppr:1:socket:pe=4 --host $(THIS_SERVER),$(PEER_SERVER) prog2_optimized_mpi_omp 1500

clean:
	rm -f prog2_optimized_mpi_omp
