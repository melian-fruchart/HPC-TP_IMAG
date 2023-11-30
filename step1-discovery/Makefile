CC = gcc
SHELL = /bin/bash
all: prog1 prog2

prog1: prog1.c
	$(CC) -o prog1 prog1.c

prog2: prog2.c
	$(CC) -o prog2 prog2.c

pull:
	git pull

run: prog1 prog2
	./prog1 & ./prog2 &

clean:
	rm -f prog1 prog2
