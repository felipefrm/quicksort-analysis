#include <stdio.h>
#include <stdlib.h>
#include "lista.h" //inclui os Prot�tipos

//Defini��o do tipo lista
struct elemento{
  struct elemento *ant;
  struct elemento *prox;
  int num;
};
typedef struct elemento Elem;

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

int insereLista(Lista* li, int num){
  if(li == NULL)
    return 0;
  Elem* no;
  no = (Elem*) malloc(sizeof(Elem));
  if(no == NULL)
    return 0;
  no->num = num;
  no->prox = (*li);
  no->ant = NULL;
  if(*li != NULL)//lista n�o vazia: apontar para o anterior!
    (*li)->ant = no;
  *li = no;
  return 1;
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
