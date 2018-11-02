########## Makefile ############

all: main.o quicksort.o lista.o convert.o analysis.o
	gcc analysis.o convert.o lista.o quicksort.o main.o -o quicksort -lm

main.o: main.c quicksort.h lista.h convert.h analysis.h
	gcc -g -c main.c
quicksort.o: quicksort.h quicksort.c
	gcc -g -c quicksort.c
lista.o: lista.h lista.c
	gcc -g -c lista.c
convert.o: convert.h convert.c
	gcc -g -c convert.c
analysis.o: analysis.h analysis.c
	gcc -g -c analysis.c
