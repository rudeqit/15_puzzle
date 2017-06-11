.PHONY: all clean test

all: bin/15_puzzle

bin/15_puzzle: build/src/main.o build/src/graphics.o build/src/logic.o src/graphics.h src/logic.h
	mkdir bin -p
	gcc -Wall build/src/main.o build/src/graphics.o build/src/logic.o -o bin/15_puzzle -lncurses

build/src/main.o: src/main.c src/graphics.h src/logic.h
	mkdir build/src -p
	gcc -std=c99 -I scr -Wall -c src/main.c -o build/src/main.o

build/src/graphics.o: src/graphics.c src/graphics.h
	mkdir build/src -p
	gcc -std=c99 -Wall -c src/graphics.c -o build/src/graphics.o

build/src/logic.o: src/logic.c src/logic.h
	mkdir build/src -p
	gcc -std=c99 -Wall -c src/logic.c -o build/src/logic.o

test: bin/15_puzzle_test

bin/15_puzzle_test: build/test/main.o build/test/logic_test.o build/src/logic.o
	mkdir bin -p
	gcc -std=c99 -I thirdparty -I src -Wall build/test/main.o build/src/logic.o build/test/logic_test.o -o bin/15_puzzle_test
	./bin/15_puzzle_test

build/test/main.o: test/main.c
	mkdir build/test -p
	gcc -std=c99 -I thirdparty -I src -Wall -c test/main.c -o build/test/main.o

build/test/logic_test.o: test/logic_test.c
	mkdir build/test -p
	gcc -std=c99 -I thirdparty -I src -Wall -c test/logic_test.c -o build/test/logic_test.o

clean:
	rm -rf build/* bin/*
