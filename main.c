#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
// #include "lista.h"
#include "quicksort.h"
#include "convert.h"

#define K 10
#define QNT 200
#define FLT 4


int main(int argc, char** argv) {
  struct rusage resources;
  int rc;
  double utime, stime, total_time;
  if (argc > 3) {
    srand(atoi(argv[1])); //seta a seed

    FILE *input;
    input = fopen(argv[2], "r");

    char c, vetN[5];  //lendo a quantidade de N
    for(int i=0; (c=fgetc(input)) != '\n'; i++)  // o valor é lido como char
      vetN[i] = c;

    int qtdN = CharParaInt(vetN);  //transformamos o vetor de char para int
    printf("%d\n", qtdN);
    char **matN = (char**)malloc(qtdN*sizeof(char*));
    for (int i=0; i<qtdN; i++){
      matN[i] = (char*)malloc(K*sizeof(char));
      for (int j=0; (c=fgetc(input)) != '\n'; j++){
        matN[i][j] = c;
      }
      // printf("%s\n", matN[i]);
    }
    int *N = (int*)malloc(qtdN*sizeof(int));
    for (int i=0; i<qtdN; i++){
      N[i] = CharParaInt(matN[i]);
      printf("%d\n", N[i]);
    }

    fclose(input);

    FILE *output;
    output = fopen(argv[3], "w");
    fclose(output);

    for (int x=0; x<qtdN; x++){
      printf("\n\nN = %d\n\n", N[x]);
      int *vetor = (int*) malloc(N[x]*sizeof(int));
      elemento* vStruct = (elemento*)malloc(N[x]*sizeof(elemento));
      // Lista* li = criaLista();
      for (int y=0; y<5; y++){
        // printf("\n\ny = %d\n\n", y);

        char letras[10] = {'a','b','c','d','e','f','g','h','i','j'};
        for (int i=0; i < N[x]; i++) {
          vetor[i] = abs(rand()%(100*N[x]));
          // insereLista(li, vetor[i]);
          vStruct[i].ch = abs(rand()%(100*N[x]));
          vStruct[i].boleano = abs(rand()%2);
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


    int numAtivacoes = 0, compara = 0;
    printf("Vetor inicial:\n");
    for (int i=0; i < N[x]; i++)
      printf("%d\n", vetor[i]);
    printf("\n");

    quickInt(vetor,0,N[x]-1,&numAtivacoes, &compara);

    printf("Vetor ordenado:\n");
    for (int i=0; i < N[x]; i++)
      printf("%d\n", vetor[i]);
    printf("\n");
    printf("Número de ativações: %d\nNúmero de comparação de chaves: %d\n\n", numAtivacoes, compara);


    if((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
      perror("getrusage failed");

    utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
    stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
    total_time = utime+stime;
    printf("User time %.3f, System time %.3f, Total Time %.3f\n",utime, stime, total_time);

    numAtivacoes = compara = 0;
    printf("Vetor de struct inicial:\n");
    for (int i=0; i < N[x]; i++){
      printf("%d %d\n", vStruct[i].ch, vStruct[i].boleano);
      //for (int j=0; j < K; j++)
      //  printf("str%d: %s\n", j, vStruct[i].str[j]);

    }
    printf("\n");

    quickStruct(vStruct,0,N[x]-1,&numAtivacoes, &compara);

    printf("Vetor de struct ordenado:\n");
    for (int i=0; i < N[x]; i++){
      printf("%d %d\n", vStruct[i].ch, vStruct[i].boleano);
      //for (int j=0; j < K; j++)
      //  printf("str%d: %s\n", j, vStruct[i].str[j]);
      //printf("\n");
    }
    printf("Número de ativações: %d\nNúmero de comparação de chaves: %d\n\n", numAtivacoes, compara);


    //imprimeLista(li);

    //liberaLista(li):

    if((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
      perror("getrusage failed");

    utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
    stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
    total_time = utime+stime;
    printf("User time %.3f, System time %.3f, Total Time %.3f\n",utime, stime, total_time);
  }
  free(vetor);
  free(vStruct);
  }

  }
  else
    printf("Digite o tamanho do vetor na linha de argumento\n");
  return 0;
}
