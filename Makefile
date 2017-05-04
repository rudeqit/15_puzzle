.PHONY: all

all: 15_puzzle

15_puzzle: src/main.c
	gcc -Wall src/main.c -o 15_puzzle -lncurses

#all: bin/15_puzzle

#bin/15_puzzle: src/main.c
#	mkdir bin -p
#	gcc -Wall src/main.c -o bin/15_puzzle -lncurses
