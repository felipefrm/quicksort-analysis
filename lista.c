#include <stdio.h>
#include <stdlib.h>
#include "lista.h" //inclui os Protótipos

Lista* criaLista(){
  Lista* li = (Lista*) malloc(sizeof(Lista));
  if(li != NULL)
    *li = NULL;
  return li;
}

void liberaLista(Lista* li){
  if(li != NULL){
    Elem* no;
    while((*li) != NULL){
      no = *li;
      *li = (*li)->prox;
      free(no);
    }
    free(li);
  }
}

void insereLista(Lista* li, int n){
  Elem* no = (Elem*)malloc(sizeof(Elem));
  no->num = n;
  no->prox = (*li);
  no->ant = NULL;
  if(*li != NULL)
    (*li)->ant = no;
  *li = no;
}

void imprimeLista(Lista* li){
  if(li == NULL)
    return;
  Elem* no = *li;
  while(no != NULL){
    printf("%d\n",no->num);
    no = no->prox;
  }
  printf("\n");
}

//Função para trocar elementos facilmente
void swap(int* a, int* b){
  int aux = *a;
  *a = *b;
  *b = aux;
}
//Função para achar o último nó
Elem* ultimono(Lista* li){
  Elem* no = *li;
  while(no->prox != NULL)
    no = no->prox;
  return no;
}

//Função para limpar todos os nós da Lista
void esvaziaLista(Lista* li){
  Elem* no = (*li), *aux;
  while (no != NULL) {
    aux = no;
    no = no->prox;
    free (aux);
  }
    *li = NULL;
}
