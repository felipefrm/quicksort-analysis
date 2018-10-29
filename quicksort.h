#ifndef QUICKSORT
#define QUICKSORT

typedef struct TElemento {
  int ch; //chave
  char** str;
  float *f;
} elemento;

int particionaStruct(elemento* vetor, int inicio, int fim, int *compara);
void quickStruct(elemento *vetor, int inicio, int fim, int *cont, int *compara);
int particionaInt(int *vetor, int inicio, int fim, int *compara);
void quickInt(int *vetor, int inicio, int fim, int *cont, int *compara);
// int particionaLista(Lista* li, int inicio, int fim);
// void quickLista(Lista* li, int inicio, int fim, int *cont);

#endif
