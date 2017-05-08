.PHONY: all grtest

all: 15_puzzle

15_puzzle: src/main.c
	gcc -Wall src/main.c -o 15_puzzle -lncurses

grtest: 15_puzzle_test

15_puzzle_test:
	gcc -Wall src/main.c src/graphics.c src/graphics.h -o 15_puzzle_test -lncurses

#all: bin/15_puzzle

#bin/15_puzzle: src/main.c
#	mkdir bin -p
#	gcc -Wall src/main.c -o bin/15_puzzle -lncurses
