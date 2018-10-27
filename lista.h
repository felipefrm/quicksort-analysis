//Arquivo ListaDinEncadDupla.h
#ifndef LISTA
#define LISTA

typedef struct elemento* Lista;

Lista* criaLista();
void liberaLista(Lista* li);
int insereLista(Lista* li, int num);
void imprimeLista(Lista* li);

#endif
