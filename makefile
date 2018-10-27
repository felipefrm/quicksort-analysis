########## Makefile ############

all: main.o quicksort.o lista.o
	gcc lista.o quicksort.o main.o -o quicksort

main.o: main.c quicksort.h lista.h
	gcc -g -c main.c
quicksort.o: quicksort.h quicksort.c
	gcc -g -c quicksort.c
lista.o: lista.h lista.c
	gcc -g -c lista.c
