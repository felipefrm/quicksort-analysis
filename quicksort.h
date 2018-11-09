#include "lista.h"

#ifndef QUICKSORT
#define QUICKSORT

#define qntstr 10
#define sizestr 201   // 200+1 considerando o terminador de string
#define qntfloat 4

typedef struct TElemento {
  int ch; //chave
  char str[qntstr][sizestr];
  int boleano;
  float f[qntfloat];
} elemento;

int particionaStruct(elemento* vetor, int inicio, int fim, int *compara, int *troca);
void quickStruct(elemento *vetor, int inicio, int fim, int *compara, int *troca);
int particionaInt(int *vetor, int inicio, int fim, int *compara, int *troca);
void quickInt(int *vetor, int inicio, int fim, int *compara, int *troca);
Elem* particionaLista(Elem* inicio, Elem* fim, int *compara, int *troca);
void quickLista(Elem* inicio, Elem* fim, int *compara, int *troca);
#endif
