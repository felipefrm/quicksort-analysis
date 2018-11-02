########## Makefile ############

all: main.o quicksort.o lista.o convert.o analisys.o
	gcc analisys.o convert.o lista.o quicksort.o main.o -o quicksort -lm

main.o: main.c quicksort.h lista.h convert.h analisys.h
	gcc -g -c main.c
quicksort.o: quicksort.h quicksort.c
	gcc -g -c quicksort.c
lista.o: lista.h lista.c
	gcc -g -c lista.c
convert.o: convert.h convert.c
	gcc -g -c convert.c
analisys.o: analisys.h analisys.c
	gcc -g -c analisys.c
