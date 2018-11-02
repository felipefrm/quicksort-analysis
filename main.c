#include <stdio.h>
#include <stdlib.h>
// #include "lista.h"
#include "quicksort.h"
#include "convert.h"
#include "funcoes.h"

#define VET 0
#define STRCT 1
#define LIST 2
#define ENTRADA 3
#define REPEAT 5
#define INCREASE 10

int main(int argc, char** argv){
  double utime_ant, utime_pos, stime_ant, stime_pos;
  if (argc > 3) {

    FILE *input;
    input = fopen(argv[2], "r");

    FILE *output;
    output = fopen(argv[3], "w");

    int qtdN, *N;
    leituraParametros(input, &qtdN, N);
    // le quantidade de parametros e o valor de cada um
    //
    printf("%d\n", qtdN);
    for(int i=0; i<qtdN; i++)
      printf("%c\n", N[i]);
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
    //
    // int *N = (int*)malloc(qtdN*sizeof(int));
    // for (int i=0; i<qtdN; i++)
    //   N[i] = CharParaInt(matN[i]);
    // //
    fclose(input);

    for (int i=0; i<qtdN; i++){

      fprintf(output, "-------------------------------\nPara N = %d\n\n", N[i]);
      int *vetor = (int*) malloc(N[i]*sizeof(int));
      elemento* vStruct = (elemento*)malloc(N[i]*sizeof(elemento));
      // Lista* li = criaLista();

      double cmpmed[ENTRADA]={0,0,0}, trcmed[ENTRADA]={0,0,0};
      double total_time[ENTRADA] = {0,0,0};

      int seed = atoi(argv[1]);   // declara a seed recebendo o argumento 1

      for (int j=0; j<REPEAT; j++){
        randomVetor(vetor, N[i]);
        randomStruct(vStruct, N[i]);
        // randomLista(li, vetor, N)
        srand(seed+j*INCREASE); //seta a seed e incrementa 10 a cada repetição

        // printf("Vetor inicial:\n");
        // for (int i=0; i < N[i]; i++)
        //   printf("%d\n", vetor[i]);
        // printf("\n");

        int compara = 0, troca = 0;
        contaTempo(&utime_ant, &stime_ant); //marca tempo inicial
        quickInt(vetor, 0, N[i]-1, &compara, &troca);
        contaTempo(&utime_pos, &stime_pos); //marca tempo final

        total_time[VET] += ((utime_pos-utime_ant) + (stime_pos-stime_ant)); //somatorio do tempo total para vetor
        trcmed[VET] += troca;   //somatorio das trocas para vetor
        cmpmed[VET] += compara; //somatorio das comparações para vetor
        // fprintf(output, "")

        // printf("Vetor ordenado:\n");
        // for (int i=0; i < N[i]; i++)
        //   printf("%d\n", vetor[i]);
        // printf("\n");


        // printf("Vetor de struct inicial:\n");
        // for (int m=0; m < N[i]; m++){
        //   printf("%d %d\n", vStruct[m].ch, vStruct[m].boleano);
        //   // for (int t=0; t < 10; t++){
        //   //
        //    // printf("str%d: %s\n\n", t, vStruct[r].str[t]);
        // // }
        //   for (int n=0; n < 4; n++)
        //    printf("%f ", vStruct[n].f[m]);
        //   printf("\n");
        //  }
        // printf("\n");

        compara = troca = 0;
        contaTempo(&utime_ant, &stime_ant);  //marca o tempo inicial
        quickStruct(vStruct, 0, N[i]-1, &compara, &troca);
        contaTempo(&utime_pos, &stime_pos); //marca o tempo final

        total_time[STRCT] += ((utime_pos-utime_ant) + (stime_pos-stime_ant)); //somatorio do tempo total para struct
        trcmed[STRCT] += troca;   //somatorio das trocas para struct
        cmpmed[STRCT] += compara; //somatorio das comparações para struct

        // printf("Vetor de struct ordenado:\n");
        // for (int i=0; i < N[i]; i++){
          // printf("%d %d\n", vStruct[i].ch, vStruct[i].boleano);
          //for (int j=0; j < K; j++)
          //  printf("str%d: %s\n", j, vStruct[i].str[j]);
          //printf("\n");
        // }
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

      // fprintf(output, "Para N = %d\n\nVetor:\nComparações de chaves: %d\nTrocas de registros: %d", N[i], )
      //
      // fprintf(output, "Para N = %d, a media do tempo de eiecução em vetor foi de: %fs,\n"
      // "para struct foi de: %fs.\n", N[i], vet_soma_time/(float)repeat, strct_soma_time/(float)repeat);
      fprintf(output, "Vetor:\nComparações de chaves: %f\nTrocas de registros: %f\nTempo total gasto na ordenação: %fs\n\n", cmpmed[VET]/(float)REPEAT, trcmed[VET]/(float)REPEAT, total_time[VET]/(float)REPEAT);
      fprintf(output, "Vetor de struct:\nComparações de chaves: %f\nTrocas de registros: %f\nTempo total gasto na ordenação: %fs\n\n", cmpmed[STRCT]/(float)REPEAT, trcmed[STRCT]/(float)REPEAT, total_time[STRCT]/(float)REPEAT);
      }

  fclose(output);
  }
  else
    printf("Digite o tamanho do vetor na linha de argumento\n");
  return 0;
}

/* FALTA:
quick pra lista
constantes
*/
