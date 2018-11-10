#ifndef LISTA
#define LISTA

//Definição do tipo lista
struct elemento{
  struct elemento *ant;
  struct elemento *prox;
  int num;
};

typedef struct elemento Elem;
typedef struct elemento* Lista;


Lista* criaLista();
void liberaLista(Lista* li);
void insereLista(Lista* li, int n);
void imprimeLista(Lista* li);
void swap(int* a,int* b);
Elem* ultimono(Lista* li);
void esvaziaLista(Lista* li);

#endif
