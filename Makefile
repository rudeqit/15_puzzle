.PHONY: all clean

all: 15_puzzle_test

15_puzzle_test: build/main.o build/graphics.o src/graphics.h
	gcc -Wall build/main.o build/graphics.o -o 15_puzzle_test -lncurses

build/main.o: src/main.c src/graphics.h
	mkdir build -p
	gcc -Wall -c src/main.c -o build/main.o

build/graphics.o: src/graphics.c src/graphics.h
	mkdir build -p
	gcc -Wall -c src/graphics.c -o build/graphics.o

clean:
	rm -f 15_puzzle*
