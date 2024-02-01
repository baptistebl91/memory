CC = gcc

.PHONY: build run clean

build: main.o interface.o grille.o
	$(CC) -o ./src/main ./src/main.o ./src/interface.o  ./src/grille.o -lgraph -ansi -Wall -Wextra

main.o:
	$(CC) -c ./src/main.c -o ./src/main.o

interface.o:
	$(CC) -c ./src/interface.c -o ./src/interface.o

grille.o:
	$(CC) -c ./src/grille.c -o ./src/grille.o

.PHONY:
clean:
	rm -rf src/*.o src/main

run: clean build
	./src/main


all: run
