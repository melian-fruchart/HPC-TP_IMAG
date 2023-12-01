CC = gcc
SHELL = /bin/bash
all: prog1_naive prog2_optimized

prog1_naive: prog1_naive.c
	$(CC) -o prog1_naive prog1_naive.c

prog2_optimized_optimized: prog2_optimized.c
	$(CC) -o prog2_optimized prog2_optimized.c

pull:
	git pull

run: all
	./prog1_naive & ./prog2_optimized &

scaling: all
	bash scaling.sh

clean:
	rm -f prog1_naive prog2_optimized
