#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include "funcoes.h"
#include "convert.h"
#include "lista.h"

#define alfabeto 26

void randomVetor(int *v, int N){
  for(int i=0; i < N; i++)
    v[i] = abs(rand()%(100*N));
}

void randomStruct(elemento *v, int N){
  char letras[alfabeto] = {"abcdefghijklmnopqrstuvwxyz"};
  for(int i=0; i<N; i++){
  v[i].ch = abs(rand()%(100*N));
  v[i].boleano = abs(rand()%2);
    for(int j=0; j<qntstr; j++){
      for (int k=0; k<sizestr; k++){
        v[i].str[j][k] = letras[rand()%alfabeto];
      }
    }
    for(int j=0; j<qntfloat; j++){
      v[i].f[j] = (float)rand()/RAND_MAX;
    }
  }
}

// void randomLista(*li, *v, N){
//   Elem* no;
//   no = (Elem*)malloc(sizeof(Elem));
//   for(int i=0; i < N; i++){
//     v[i] = abs(rand()%(100*N));
//     no->num = v[i];
//     no->prox = (*li);
//     no->ant = NULL;
//     if(*li != NULL)//lista não vazia: apontar para o anterior!
//         (*li)->ant = no;
//     *li = no;
//   }
// }

void leituraParametros(FILE *input, int *qtdN, int *N){
  char c, vetN[2];    //lendo a quantidade de parametro N
  for(int i=0; (c=fgetc(input)) != '\n'; i++)
    vetN[i] = c;  //o valor é lido como char
  *qtdN = CharParaInt(vetN); // transformamos o vetor de char para int
  char **matN = (char**)malloc(*qtdN*sizeof(char*));
  for (int i=0; i<*qtdN; i++){
    matN[i] = (char*)malloc(10*sizeof(char));  // lê os valores de N é guarda em uma matriz de char
    for(int j=0; (c=fgetc(input)) != '\n'; j++)
      matN[i][j] = c;
  }
  *N = (int*)malloc(*qtdN*sizeof(int));
  for(int i=0; i<*qtdN; i++)
    N[i] = CharParaInt(matN[i]);  //transforma vetor de char para int
}
