#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
// #include "lista.h"
#include "quicksort.h"
#include "convert.h"
#include "funcoes.h"

#define vet 0
#define strct 1
#define list
#define repeat 5

int main(int argc, char** argv){
  struct rusage resources;
  double utime_ant, utime_pos, stime_ant, stime_pos;
  if (argc > 3) {

    FILE *input;
    input = fopen(argv[2], "r");

    FILE *output;
    output = fopen(argv[3], "w");

    int qtdN, *N;
    leituraParametros(input, &qtdN, N);
    // le quantidade de parametros e o valor de cada um

    // printf("%d\n", qtdN);
    // for(int i=0; i<qtdN; i++)
    //   printf("%d\n", N[i]);
    // char c, vetN[2];  //lendo a quantidade de N
    // for(int i=0; (c=fgetc(input)) != '\n'; i++)  // o valor é lido como char
    //   vetN[i] = c;
    //
    // int qtdN = CharParaInt(vetN);  //transformamos o vetor de char para int
    // char **matN = (char**)malloc(qtdN*sizeof(char*));
    // for (int i=0; i<qtdN; i++){
    //   matN[i] = (char*)malloc(10*sizeof(char));    // lê os parametros N e guarda em uma matriz
    //   for (int j=0; (c=fgetc(input)) != '\n'; j++)
    //     matN[i][j] = c;
    // }

    // int *N = (int*)malloc(qtdN*sizeof(int));
    // for (int i=0; i<qtdN; i++)
    //   N[i] = CharParaInt(matN[i]);

    fclose(input);

    for (int x=0; x<qtdN; x++){

      fprintf(output, "-------------------------------\nPara N = %d\n\n", N[x]);
      int *vetor = (int*) malloc(N[x]*sizeof(int));
      elemento* vStruct = (elemento*)malloc(N[x]*sizeof(elemento));
      // Lista* li = criaLista();

      double cmpmed[3]={0,0,0}, trcmed[3]={0,0,0};
      double total_time[3] = {0,0,0};

      int seed = atoi(argv[1]);   // declara a seed recebendo o argumento 1

      for (int y=0; y<repeat; y++){
        randomVetor(vetor, N[x]);
        randomStruct(vStruct, N[x]);
        // randomLista(li, vetor, N)
        srand(seed+y*10); //seta a seed e incrementa 10 a cada repetição

        // printf("Vetor inicial:\n");
        // for (int i=0; i < N[x]; i++)
        //   printf("%d\n", vetor[i]);
        // printf("\n");

        int numAtivacoes = 0, compara = 0, troca = 0;
        getrusage(RUSAGE_SELF, &resources);
        utime_ant = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        stime_ant = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
        quickInt(vetor,0,N[x]-1,&numAtivacoes, &compara, &troca);

        getrusage(RUSAGE_SELF, &resources);
        utime_pos = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        stime_pos = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;

        total_time[vet] += ((utime_pos-utime_ant) + (stime_pos-stime_ant));

        // printf("Vetor ordenado:\n");
        // for (int i=0; i < N[x]; i++)
        //   printf("%d\n", vetor[i]);
        // printf("\n");

        cmpmed[vet] += compara;
        trcmed[vet] += troca;

        // printf("Vetor de struct inicial:\n");
        // for (int i=0; i < N[x]; i++){
        //   // printf("%d %d\n", vStruct[i].ch, vStruct[i].boleano);
        //   for (int j=0; j < 10; j++){
        //
        //    printf("str%d: %s\n\n", j, vStruct[i].str[j]);
        //    printf("\n%ld\n", strlen(vStruct[i].str[j]));
        //  }
          // for (int j=0; j < 4; j++)
          //  printf("%f ", vStruct[i].f[j]);
          // printf("\n");
        // }
        // printf("\n");

        numAtivacoes = compara = troca = 0;
        getrusage(RUSAGE_SELF, &resources);
        utime_ant = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        stime_ant = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
        quickStruct(vStruct,0,N[x]-1,&numAtivacoes, &compara, &troca);

        getrusage(RUSAGE_SELF, &resources);
        utime_pos = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        stime_pos = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;

        total_time[strct] += ((utime_pos-utime_ant) + (stime_pos-stime_ant));

        // printf("Vetor de struct ordenado:\n");
        for (int i=0; i < N[x]; i++){
          // printf("%d %d\n", vStruct[i].ch, vStruct[i].boleano);
          //for (int j=0; j < K; j++)
          //  printf("str%d: %s\n", j, vStruct[i].str[j]);
          //printf("\n");
        }
        trcmed[strct] += troca;
        cmpmed[strct] += compara;
        // printf("Número de ativações: %d\nNúmero de comparação de chaves: %d\nNúmero de troca de registros: %d\n\n", numAtivacoes, compara, troca);


        //imprimeLista(li);

        //liberaLista(li):
        //
        // if((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
        //   perror("getrusage failed");

        // strct_utime[y] = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        // strct_stime[y] = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
        // strct_total_time[y] = strct_utime[y]+strct_stime[y];
        // // printf("User time %.3f, System time %.3f, Total Time %.3f\n",strct_utime[y], strct_stime[y], strct_total_time[y]);
        // strct_soma_time += strct_total_time[y];

      }
      free(vetor);
      free(vStruct);

      // fprintf(output, "Para N = %d\n\nVetor:\nComparações de chaves: %d\nTrocas de registros: %d", N[x], )
      //
      // fprintf(output, "Para N = %d, a media do tempo de execução em vetor foi de: %fs,\n"
      // "para struct foi de: %fs.\n", N[x], vet_soma_time/(float)repeat, strct_soma_time/(float)repeat);
      fprintf(output, "Vetor:\nComparações de chaves: %f\nTrocas de registros: %f\nTempo total gasto na ordenação: %fs\n\n", cmpmed[vet]/5.0, trcmed[vet]/5.0, total_time[vet]/5.0);
      fprintf(output, "Vetor de struct:\nComparações de chaves: %f\nTrocas de registros: %f\nTempo total gasto na ordenação: %fs\n\n", cmpmed[strct]/5.0, trcmed[strct]/5.0, total_time[strct]/5.0);
      }

  fclose(output);
  }
  else
    printf("Digite o tamanho do vetor na linha de argumento\n");
  return 0;
}

/* FALTA:
ajeitar o time
quick pra lista
modularizar
constantes
*/
