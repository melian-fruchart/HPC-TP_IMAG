CC = gcc
SHELL = /bin/bash
OPT = -fopenmp
all: prog1 prog2

prog1: prog1.c
	$(CC) $(OPT) -o prog1 prog1.c

prog2: prog2.c
	$(CC) $(OPT) -o prog2 prog2.c

pull:
	git pull

run: all
	./prog1 & ./prog2 &

compare: all
	bash compare.sh

clean:
	rm -f prog1 prog2
