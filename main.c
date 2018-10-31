#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
// #include "lista.h"
#include "quicksort.h"
#include "convert.h"

#define qntfloat 4
#define repeat 5
#define K 10
#define alfabeto 26
#define sizestr 200


int main(int argc, char** argv) {
  struct rusage resources;
  double utime_ant, utime_pos, stime_ant, stime_pos;
  if (argc > 3) {

    FILE *input;
    input = fopen(argv[2], "r");

    FILE *output;
    output = fopen(argv[3], "w");

    char c, vetN[2];  //lendo a quantidade de N
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

      fprintf(output, "-------------------------------\nPara N = %d\n\n", N[x]);
      int *vetor = (int*) malloc(N[x]*sizeof(int));
      elemento* vStruct = (elemento*)malloc(N[x]*sizeof(elemento));
      // Lista* li = criaLista();

      double cmpmed[3]={0,0,0}, trcmed[3]={0,0,0};
      double total_time[3] = {0,0,0};

      int seed = atoi(argv[1]);

      for (int y=0; y<repeat; y++){

        srand(seed+y*10); //seta a seed e incrementa a cada repetição
        char letras[alfabeto] = {"abcdefghijklmnopqrstuvwxyz"};
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

        // printf("Vetor inicial:\n");
        // for (int i=0; i < N[x]; i++)
          // printf("%d\n", vetor[i]);
        // printf("\n");

        int numAtivacoes = 0, compara = 0, troca = 0;
        getrusage(RUSAGE_SELF, &resources);
        utime_ant = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        stime_ant = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
        quickInt(vetor,0,N[x]-1,&numAtivacoes, &compara, &troca);

        getrusage(RUSAGE_SELF, &resources);
        utime_pos = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        stime_pos = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;

        total_time[0] += ((utime_pos-utime_ant) + (stime_pos-stime_ant));

        // printf("Vetor ordenado:\n");
        // for (int i=0; i < N[x]; i++)
          // printf("%d\n", vetor[i]);
        // printf("\n");
        cmpmed[0] += compara;
        trcmed[0] += troca;
        // printf("Número de ativações: %d\nNúmero de comparação de chaves: %d\nNúmero de troca de registros: %d\n\n", numAtivacoes, compara, troca);



        // vet_utime[y] = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        // vet_stime[y] = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
        // vet_total_time[y] = vet_utime[y]+vet_stime[y];
        // // printf("User time %.3f, System time %.3f, Total Time %.3f\n",vet_utime[y], vet_stime[y], vet_total_time[y]);
        // vet_soma_time += vet_total_time[y];

        // printf("Vetor de struct inicial:\n");
        for (int i=0; i < N[x]; i++){
          // printf("%d %d\n", vStruct[i].ch, vStruct[i].boleano);
          //for (int j=0; j < K; j++)
          //  printf("str%d: %s\n", j, vStruct[i].str[j]);

        }
        // printf("\n");

        numAtivacoes = compara = troca = 0;
        getrusage(RUSAGE_SELF, &resources);
        utime_ant = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        stime_ant = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
        quickStruct(vStruct,0,N[x]-1,&numAtivacoes, &compara, &troca);

        getrusage(RUSAGE_SELF, &resources);
        utime_pos = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        stime_pos = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;

        total_time[1] += ((utime_pos-utime_ant) + (stime_pos-stime_ant));

        // printf("Vetor de struct ordenado:\n");
        for (int i=0; i < N[x]; i++){
          // printf("%d %d\n", vStruct[i].ch, vStruct[i].boleano);
          //for (int j=0; j < K; j++)
          //  printf("str%d: %s\n", j, vStruct[i].str[j]);
          //printf("\n");
        }
        trcmed[1] += troca;
        cmpmed[1] += compara;
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
      fprintf(output, "Vetor:\nComparações de chaves: %f\nTrocas de registros: %f\nTempo total: %fs\n\n", cmpmed[0]/5.0, trcmed[0]/5.0, total_time[0]/5.0);
      fprintf(output, "Vetor de struct:\nComparações de chaves: %f\nTrocas de registros: %f\nTempo total: %fs\n\n", cmpmed[1]/5.0, trcmed[1]/5.0, total_time[1]/5.0);
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
