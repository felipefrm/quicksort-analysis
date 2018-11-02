########## Makefile ############

all: main.o quicksort.o lista.o convert.o funcoes.o
	gcc funcoes.o convert.o lista.o quicksort.o main.o -o quicksort -lm

main.o: main.c quicksort.h lista.h convert.h funcoes.h
	gcc -g -c main.c
quicksort.o: quicksort.h quicksort.c
	gcc -g -c quicksort.c
lista.o: lista.h lista.c
	gcc -g -c lista.c
convert.o: convert.h convert.c
	gcc -g -c convert.c
funcoes.o: funcoes.h funcoes.c
	gcc -g -c funcoes.c
