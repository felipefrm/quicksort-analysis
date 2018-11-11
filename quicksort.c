#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "quicksort.h"

#define ESQMDIR(esq, dir)  (dir != NULL && esq != dir && esq != dir->prox)

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

void quickStruct(elemento *vetor, int inicio, int fim, int *compara, int *troca){

  int pivo;

  if(inicio < fim){
    pivo = particionaStruct(vetor, inicio, fim, compara, troca); // encontra um pivo que "divide" o vetor em dois
    quickStruct(vetor, inicio, pivo-1, compara, troca); // realiza a partição para a parte da esquerda
    quickStruct(vetor, pivo+1, fim, compara, troca); // e realiza a partição para a parte de direita
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

void quickInt(int *vetor, int inicio, int fim, int *compara, int *troca){

  int pivo;

  if(inicio < fim){
    pivo = particionaInt(vetor,inicio,fim, compara, troca); // encontra um pivo que "divide" o vetor em dois
    quickInt(vetor, inicio, pivo-1, compara, troca); // realiza a partição para a parte da esquerda
    quickInt(vetor, pivo+1, fim, compara, troca); // e realiza a partição para a parte de direita
  }
}

//Função para particionar a Lista colocando o pivo no meio, tudo que for menor
//antes e todos os maiores depois
Elem* particionaLista(Elem* inicio, Elem* fim, int *compara, int *troca){
  Elem* pivo = inicio;
  Elem* dir = fim;
  Elem* esq = inicio;

  while(dir != NULL && ESQMDIR(esq, dir)){
    while(esq->num <= pivo->num && ESQMDIR(esq, fim)){
      esq = esq->prox;
      (*compara)++;
    }
    while(pivo->num < dir->num){
      dir = dir->ant;
      (*compara)++;
    }
    if (ESQMDIR(esq,dir))
    {
      swap(&(esq->num), &(dir->num));
      (*troca)++;
    }
  }

  int aux;
  aux = pivo->num;
  inicio->num = dir->num;
  dir->num = aux;
  return dir;
}

void quickLista(Elem* inicio, Elem* fim, int *compara, int *troca){

  Elem* pivo;

  if (fim != NULL && inicio != fim && inicio != fim->prox){
    pivo =  particionaLista(inicio, fim, compara, troca);
    quickLista(inicio, pivo->ant, compara, troca);
    quickLista(pivo->prox, fim, compara, troca);
  }
}
