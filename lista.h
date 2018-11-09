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
int insereLista(Lista* li, int num);
void imprimeLista(Lista* li);
void swap(int* a,int* b);
Elem* ultimono(Lista* li);

#endif
