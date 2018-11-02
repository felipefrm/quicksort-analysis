#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include "analisys.h"
#include "convert.h"
#include "lista.h"
#include <sys/resource.h>

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
      for (int k=0; k<sizestr-1; k++){
        v[i].str[j][k] = letras[rand()%alfabeto];
      }
      v[i].str[j][sizestr-1] = '\0';  //terminador de string
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

int* leituraParametros(FILE *input, int *qtdN, int *N){
  int i, j; char c, vetN[3];    //lendo a quantidade de parametro N
  for(i=0; (c=fgetc(input)) != '\n'; i++)
    vetN[i] = c;  //o valor é lido como char
  vetN[i] = '\0';
  *qtdN = CharParaInt(vetN); // transformamos o vetor de char para int
  char **matN = (char**)calloc((*qtdN),sizeof(char*));
  for (i=0; i<*qtdN; i++){
    matN[i] = (char*)calloc(10,sizeof(char));  // lê os valores de N é guarda em uma matriz de char
    for(j=0; (c=fgetc(input)) != '\n'; j++)
      matN[i][j] = c;
    matN[i][j] = '\0';
  }
  N = (int*)calloc((*qtdN),sizeof(int));
  for(i=0; i<*qtdN; i++){
    N[i] = CharParaInt(matN[i]);  //transforma vetor de char para int
    free(matN[i]);
  }
  free(matN);

  return N;
}

void contaTempo(double *utime, double *stime){
  struct rusage resources;
  getrusage(RUSAGE_SELF, &resources);
  *utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
  *stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
}


void computaEstatisticas(double *tmpmed, double *trcmed, double *cmpmed, int tipo, double tempo, int troca, int compara){
  tmpmed[tipo] += tempo;       //somatorio do tempo total
  trcmed[tipo] += troca;       //somatorio das trocas de registros
  cmpmed[tipo] += compara;     //somatorio das comparações de chaves
}
