#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"

int particionaStruct(elemento* vetor, int inicio, int fim, int *compara, int *troca) {

  int esq, dir;
  elemento pivo, aux;
  esq = inicio;
  dir = fim;
  pivo = vetor[inicio];

  while(esq < dir){
    while(vetor[esq].ch <= pivo.ch && esq < fim) { // vetor[esq] <= pivo
      (*compara)++;
      esq++;
    }

    while(pivo.ch < vetor[dir].ch){ //  vetor[dir] > pivo
      dir--;
      (*compara)++;
    }

    if(dir < inicio || esq > fim) printf("\nERRO\n\n");

    if(esq < dir){
      aux = vetor[esq]; // troca vetor[esq] com vetor[dir]
      vetor[esq] = vetor[dir];
      vetor[dir] = aux;
      (*troca)++;
    }
  }

  vetor[inicio] = vetor[dir];
  vetor[dir] = pivo;
  // printf("Vetor ordenado entre %d e %d\n", inicio, fim);
  // for (int i=inicio; i < fim; i++)
  //     printf("%d ", vetor[i].ch);
  // printf("\n");
  return dir;               //retorna dir, que é o índice que vai dividir o vetor
}

void quickStruct(elemento *vetor, int inicio, int fim, int *cont, int *compara, int *troca){

  (*cont)++;
  int pivo;

  if(inicio < fim){
    pivo = particionaStruct(vetor, inicio, fim, compara, troca); // encontra um pivo que "divide" o vetor em dois
    quickStruct(vetor, inicio, pivo-1, cont, compara, troca); // realiza a partição para a parte da esquerda
    quickStruct(vetor, pivo+1, fim, cont, compara, troca); // e realiza a partição para a parte de direita
  }
}


int particionaInt(int *vetor, int inicio, int fim, int *compara, int *troca){

  int esq, dir;
  int pivo, aux;
  esq = inicio;
  dir = fim;
  pivo = vetor[inicio];

  while(esq<dir){
    while(vetor[esq] <= pivo && esq<fim) { // vetor[esq] <= pivo
      esq++;
      (*compara)++;
    }

    while(pivo < vetor[dir]) { //  vetor[dir] > pivo
      (*compara)++;
      dir--;
    }

    if(dir < inicio || esq > fim) printf("\nERRO\n\n");

    if(esq < dir){
      aux = vetor[esq]; // troca vetor[esq] com vetor[dir]
      vetor[esq] = vetor[dir];
      vetor[dir] = aux;
      (*troca)++;
    }
  }

  vetor[inicio] = vetor[dir];
  vetor[dir] = pivo;
  return dir;               //retorna dir, que é o índice que vai dividir o vetor
}

void quickInt(int *vetor, int inicio, int fim, int *cont, int *compara, int *troca){

  (*cont)++;
  int pivo;

  if(inicio < fim){
    pivo = particionaInt(vetor,inicio,fim, compara, troca); // encontra um pivo que "divide" o vetor em dois
    quickInt(vetor, inicio, pivo-1, cont, compara, troca); // realiza a partição para a parte da esquerda
    quickInt(vetor, pivo+1, fim, cont, compara, troca); // e realiza a partição para a parte de direita
  }
}
//
// void particionaLista(Lista* li, Elem* dir){
//   if (!validos(esq, dir)) return;
//
// }
//
// void quickLista(Lista* li, int inicio, int fim){
//   Elem* pivo;
//   if (fim > inicio){
//     pivo = particionaLista(li, inicio, fim);
//     quickLista(li, inicio, pivo)
//   }
// }
