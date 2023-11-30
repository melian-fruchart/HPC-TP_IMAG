CC = gcc
MPICC = mpicc
MPIRUN = mpirun
SHELL = /bin/bash
THIS_SERVER := $(shell hostname)
PEER_SERVER := $(shell echo $(THIS_SERVER) | sed 's/c1/c2/')

.PHONY: clean copy_binary parallel_run all

all: mpi_prog2

mpi_prog2: mpi_prog2.c
	$(MPICC) -o mpi_prog2 mpi_prog2.c

pull:
	git pull

copy_binary: mpi_prog2
	./ship_binary.sh mpi_prog2

parallel_run: mpi_prog2 copy_binary
	$(MPIRUN) -np 2 --host $(THIS_SERVER),$(PEER_SERVER) mpi_prog2

clean:
	rm -f mpi_prog2
