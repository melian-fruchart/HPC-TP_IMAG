CC = gcc
SHELL = /bin/bash
all: prog2_optimized

prog2_optimized: prog2_optimized.c
	$(CC) -O0 -fopenmp -o prog2_optimized prog2_optimized.c

pull:
	git pull

run: all
	./prog2_optimized &

clean:
	rm -f prog2_optimized openmp_hello
