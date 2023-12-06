CC = gcc
MPICC = mpicc
MPIRUN = mpirun
SHELL = /bin/bash
THIS_SERVER := $(shell hostname)
PEER_SERVER := $(shell echo $(THIS_SERVER) | sed 's/c1/c2/')

.PHONY: clean copy_binary parallel_run all

all: prog2_optimized_mpi

prog2_optimized_mpi: prog2_optimized_mpi.c
	$(MPICC) -o prog2_optimized_mpi prog2_optimized_mpi.c

pull:
	git pull

copy_binary: prog2_optimized_mpi
	./ship_binary.sh prog2_optimized_mpi

parallel_run: prog2_optimized_mpi # TODO : copy_binary
	$(MPIRUN) -np 2 --host $(THIS_SERVER),$(PEER_SERVER) prog2_optimized_mpi

clean:
	rm -f prog2_optimized_mpi
