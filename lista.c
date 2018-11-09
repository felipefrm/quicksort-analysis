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
void swap(int* a,int* b){
  int t = *a;
  *a = *b;
  *b = t;
}
//Função para achar o último nó
Elem* ultimono(Lista* li){
  Elem* no = *li;
  while(no->prox != NULL){
    no = no->prox;
  }
  return no;
}
