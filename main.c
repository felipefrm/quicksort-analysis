#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
// #include "lista.h"
#include "quicksort.h"
#include "convert.h"

#define K 10
#define alfabeto 26
#define sizestr 200
#define qntfloat 4
#define repeat 5


int main(int argc, char** argv) {
  struct rusage resources;
  int rc;
  double vet_utime[5], vet_stime[5], vet_total_time[5],
  strct_utime[5], strct_stime[5], strct_total_time[5],
  vet_soma_time=0, strct_soma_time=0;
  if (argc > 3) {

    FILE *input;
    input = fopen(argv[2], "r");

    FILE *output;
    output = fopen(argv[3], "w");

    char c, vetN[5];  //lendo a quantidade de N
    for(int i=0; (c=fgetc(input)) != '\n'; i++)  // o valor é lido como char
      vetN[i] = c;

    int qtdN = CharParaInt(vetN);  //transformamos o vetor de char para int
    char **matN = (char**)malloc(qtdN*sizeof(char*));
    for (int i=0; i<qtdN; i++){
      matN[i] = (char*)malloc(K*sizeof(char));
      for (int j=0; (c=fgetc(input)) != '\n'; j++)
        matN[i][j] = c;
    }

    int *N = (int*)malloc(qtdN*sizeof(int));
    for (int i=0; i<qtdN; i++)
      N[i] = CharParaInt(matN[i]);

    fclose(input);

    for (int x=0; x<qtdN; x++){

      int *vetor = (int*) malloc(N[x]*sizeof(int));
      elemento* vStruct = (elemento*)malloc(N[x]*sizeof(elemento));
      // Lista* li = criaLista();

      int seed = atoi(argv[1]);
      for (int y=0; y<repeat; y++){

        srand(seed); //seta a seed
        char letras[26] = {"abcdefghijklmnopqrstuvwxyz"};
        for (int i=0; i < N[x]; i++) {
          vetor[i] = abs(rand()%(100*N[x]));
          // insereLista(li, vetor[i]);
          vStruct[i].ch = abs(rand()%(100*N[x]));
          vStruct[i].boleano = abs(rand()%2);
          //Lógica para preencher str e f
          vStruct[i].str = (char**)malloc(K*sizeof(char*));
          for (int j=0; j < K; j++) {
            vStruct[i].str[j] = (char*)malloc(sizestr*sizeof(char));
            for (int p=0; p<sizestr; p++) {
              vStruct[i].str[j][p] = letras[rand()%alfabeto];
            }
          }
          for (int j=0; j < qntfloat; j++)
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

        vet_utime[y] = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        vet_stime[y] = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
        vet_total_time[y] = vet_utime[y]+vet_stime[y];
        printf("User time %.3f, System time %.3f, Total Time %.3f\n",vet_utime[y], vet_stime[y], vet_total_time[y]);
        vet_soma_time += vet_total_time[y];

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

        strct_utime[y] = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        strct_stime[y] = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
        strct_total_time[y] = strct_utime[y]+strct_stime[y];
        printf("User time %.3f, System time %.3f, Total Time %.3f\n",strct_utime[y], strct_stime[y], strct_total_time[y]);
        strct_soma_time += strct_total_time[y];
        seed++;
      }
      free(vetor);
      free(vStruct);


      fprintf(output, "Para N = %d, a media do tempo de execução em vetor foi de: %fs,\n"
      "para struct foi de: %fs.\n", N[x], vet_soma_time/(float)repeat, strct_soma_time/(float)repeat);
    }
  fclose(output);
  }
  else
    printf("Digite o tamanho do vetor na linha de argumento\n");
  return 0;
}

/* FALTA:
ajeitar o time
compara e troca
quick pra lista
arq saida
media estatisticas
modularizar
constantes
