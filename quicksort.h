#ifndef QUICKSORT
#define QUICKSORT

#define qntstr 10
#define sizestr 200
#define qntfloat 4

typedef struct TElemento {
  int ch; //chave
  char str[qntstr][sizestr];
  int boleano;
  float f[qntfloat];
} elemento;

int particionaStruct(elemento* vetor, int inicio, int fim, int *compara, int *troca);
void quickStruct(elemento *vetor, int inicio, int fim, int *cont, int *compara, int *troca);
int particionaInt(int *vetor, int inicio, int fim, int *compara, int *troca);
void quickInt(int *vetor, int inicio, int fim, int *cont, int *compara, int *troca);
// int particionaLista(Lista* li, int inicio, int fim);
// void quickLista(Lista* li, int inicio, int fim, int *cont);

#endif
