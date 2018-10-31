#ifndef QUICKSORT
#define QUICKSORT

typedef struct TElemento {
  int ch; //chave
  char** str;
  int boleano;
  float f[4];
} elemento;

int particionaStruct(elemento* vetor, int inicio, int fim, int *compara, int *troca);
void quickStruct(elemento *vetor, int inicio, int fim, int *cont, int *compara, int *troca);
int particionaInt(int *vetor, int inicio, int fim, int *compara, int *troca);
void quickInt(int *vetor, int inicio, int fim, int *cont, int *compara, int *troca);
// int particionaLista(Lista* li, int inicio, int fim);
// void quickLista(Lista* li, int inicio, int fim, int *cont);

#endif
