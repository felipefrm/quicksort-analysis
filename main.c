#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
// #include "lista.h"
#include "quicksort.h"
#include <string.h>
#include <math.h>

#define K 10
#define QNT 200
#define FLT 4

int transformaChar(char num){

  if (num >= 48 && num <= 57)
    num = num - 48;
  return num;
}

int CharParaInt(char *charN){
  int soma = 0, expoente = strlen(charN)-1;
  for (int i = 0; i < 3; i++){
    soma += transformaChar(charN[i]) * pow(10, expoente);
    expoente--;
  }
  return soma;
}

int main(int argc, char** argv) {
  struct rusage resources;
  int rc;
  double utime, stime, total_time;
  if (argc > 1) {
    srand(time(NULL));
    int SIZE = atoi(argv[1]);

    FILE *input;
    input = fopen(argv[2], "r");

    char c, vetN[5];  //lendo a quantidade de N
    for(int i=0; (c=fgetc(input)) != '\n'; i++)  // o valor é lido como char
      vetN[i] = c;

    char q;
    int qtdN = CharParaInt(vetN);  //transformamos o vetor de char para int
    printf("%d\n", qtdN);
    char **matN = (char**)malloc(qtdN*sizeof(char*));
    for (int i=0; i<qtdN; i++){
      matN[i] = (char*)malloc(10*sizeof(char));
      for (int j=0; j<10; j++){
        matN[i][j] = fgetc(input);
        printf("%c", matN[i][j]);
      }
    }

    fclose(input);

    FILE *output;
    output = fopen(argv[3], "w");
    fclose(output);

    int *vetor = (int*) malloc(SIZE*sizeof(int));
    elemento* vStruct = (elemento*)malloc(SIZE*sizeof(elemento));
    // Lista* li = criaLista();

    char letras[10] = {'a','b','c','d','e','f','g','h','i','j'};
    for (int i=0; i < SIZE; i++) {
      vetor[i] = abs(rand()%(100*SIZE));
      // insereLista(li, vetor[i]);
      vStruct[i].ch = abs(rand()%(100*SIZE));
      //Lógica para preencher str e f
      vStruct[i].f = (float*)malloc(FLT*sizeof(float));
      vStruct[i].str = (char**)malloc(K*sizeof(char*));
      for (int j=0; j < K; j++) {
        vStruct[i].str[j] = (char*)malloc(QNT*sizeof(char));
        for (int p=0; p<QNT; p++) {
          vStruct[i].str[j][p] = letras[rand()%K];
        }
      }
      for (int j=0; j < FLT; j++)
          vStruct[i].f[j] = (float)rand()/RAND_MAX;
    }

    int numAtivacoes = 0;
    printf("Vetor inicial:\n");
    for (int i=0; i < SIZE; i++)
      printf("%d\n", vetor[i]);
    printf("\n");

    quickInt(vetor,0,SIZE-1,&numAtivacoes);

    printf("Vetor ordenado:\n");
    for (int i=0; i < SIZE; i++)
      printf("%d\n", vetor[i]);
    printf("\n");
    printf("Número de ativações: %d\n\n", numAtivacoes);

    free(vetor);

    numAtivacoes = 0;
    printf("Vetor de struct inicial:\n");
    for (int i=0; i < SIZE; i++){
      printf("%d %f %f %f %f\n", vStruct[i].ch, vStruct[i].f[0], vStruct[i].f[1], vStruct[i].f[2], vStruct[i].f[3]);
      //for (int j=0; j < K; j++)
      //  printf("str%d: %s\n", j, vStruct[i].str[j]);

    }
    printf("\n");

    quickStruct(vStruct,0,SIZE-1,&numAtivacoes);

    printf("Vetor de struct ordenado:\n");
    for (int i=0; i < SIZE; i++){
      printf("%d %f %f %f %f\n", vStruct[i].ch, vStruct[i].f[0], vStruct[i].f[1], vStruct[i].f[2], vStruct[i].f[3]);
      //for (int j=0; j < K; j++)
      //  printf("str%d: %s\n", j, vStruct[i].str[j]);
      //printf("\n");
    }
    printf("Número de ativações: %d\n\n", numAtivacoes);

    free(vStruct);

    //imprimeLista(li);

    //liberaLista(li):

    if((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
      perror("getrusage failed");

    utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
    stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
    total_time = utime+stime;
    printf("User time %.3f, System time %.3f, Total Time %.3f\n",utime, stime, total_time);

  }
  else
    printf("Digite o tamanho do vetor na linha de argumento\n");
  return 0;
}
