.PHONY: all clean

all: bin/15_puzzle

bin/15_puzzle: build/main.o build/graphics.o build/logic.o src/graphics.h src/logic.h
	gcc -Wall build/main.o build/graphics.o build/logic.o -o bin/15_puzzle -lncurses

build/main.o: src/main.c src/graphics.h src/logic.h
	mkdir build -p
	gcc -I scr -Wall -c src/main.c -o build/main.o

build/graphics.o: src/graphics.c src/graphics.h
	mkdir build -p
	gcc -Wall -c src/graphics.c -o build/graphics.o

build/logic.o: src/logic.c src/logic.h
	mkdir build -p
	gcc -Wall -c src/logic.c -o build/logic.o

clean:
	rm -f build/* bin/*
