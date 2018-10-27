#ifndef QUICKSORT
#define QUICKSORT

typedef struct TElemento {
    int ch; //chave
    char** str;
    float *f;
} elemento;

int particionaStruct(elemento* vetor, int inicio, int fim);
void quickStruct(elemento *vetor, int inicio, int fim, int *cont);
int particionaInt(int *vetor, int inicio, int fim);
void quickInt(int *vetor, int inicio, int fim, int *cont);
// int particionaLista(Lista* li, int inicio, int fim);
// void quickLista(Lista* li, int inicio, int fim, int *cont);

#endif
