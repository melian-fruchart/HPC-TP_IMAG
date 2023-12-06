CC = gcc
MPICC = mpicc
MPIRUN = mpirun
SHELL = /bin/bash
THIS_SERVER := $(shell hostname)
PEER_SERVER := $(shell echo $(THIS_SERVER) | sed 's/c1/c2/')

.PHONY: clean copy_binary parallel_run all

all: mpi_prog2 mpi_prog2_v2

mpi_prog2: mpi_prog2.c
	$(MPICC) -fopenmp -o mpi_prog2 mpi_prog2.c

mpi_prog2_v2: mpi_prog2_v2.c
	$(MPICC) -fopenmp -o mpi_prog2_v2 mpi_prog2_v2.c

pull:
	git pull

copy_binary: mpi_prog2
	./ship_binary.sh mpi_prog2

parallel_run: mpi_prog2 
	OMP_NUM_THREADS=4 OMP_PROC_BIND=spread OMP_PLACES=cores $(MPIRUN) -np 2 --map-by ppr:1:socket:pe=4 --host $(THIS_SERVER),$(PEER_SERVER) mpi_prog2

parallel_run_v2: mpi_prog2_v2 
	OMP_NUM_THREADS=4 OMP_PROC_BIND=spread OMP_PLACES=cores $(MPIRUN) -np 2 --map-by ppr:1:socket:pe=4 --host $(THIS_SERVER),$(PEER_SERVER) mpi_prog2_v2

clean:
	rm -f mpi_prog2
