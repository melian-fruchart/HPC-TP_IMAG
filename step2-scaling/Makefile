CC = gcc
SHELL = /bin/bash
all: prog1 prog2

prog1: prog1.c
	$(CC) -o prog1 prog1.c

prog2: prog2.c
	$(CC) -o prog2 prog2.c

pull:
	git pull

run: all
	./prog1 & ./prog2 &

scaling: all
	bash scaling.sh

clean:
	rm -f prog1 prog2
