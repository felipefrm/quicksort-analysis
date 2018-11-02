#include <stdio.h>
#include <stdlib.h>
// #include "lista.h"
#include "quicksort.h"
#include "convert.h"
#include "analisys.h"

#define VET 0
#define STRCT 1
#define LIST 2
#define TYPE 3
#define REPEAT 5
#define INCREASE 10

int main(int argc, char** argv){

  if (argc > 3) {

    FILE *input;
    input = fopen(argv[2], "r");
    int qtdN, *N;
    N = leituraParametros(input, &qtdN, N);
    fclose(input);

    FILE *output;
    output = fopen(argv[3], "w");

    for (int i=0; i<qtdN; i++){
      fprintf(output, "-------------------------------\nPara N = %d\n\n", N[i]);
      int *vetor = (int*) malloc(N[i]*sizeof(int));
      elemento* vStruct = (elemento*)malloc(N[i]*sizeof(elemento));
      // Lista* li = criaLista();

      double cmpmed[TYPE]={0,0,0}, trcmed[TYPE]={0,0,0}, tmpmed[TYPE] = {0,0,0};

      int seed = atoi(argv[1]);   // declara a seed recebendo o argumento 1

      for (int j=0; j<REPEAT; j++){
        fprintf(output, ">>> %dª repetição\n", j+1);
        randomVetor(vetor, N[i]);
        randomStruct(vStruct, N[i]);
        // randomLista(li, vetor, N)
        srand(seed+j*INCREASE); //seta a seed e incrementa 10 a cada repetição

        double utime_ant, utime_pos, stime_ant, stime_pos, diftempo;
        int compara = 0, troca = 0;
        contaTempo(&utime_ant, &stime_ant); //marca tempo inicial
        quickInt(vetor, 0, N[i]-1, &compara, &troca);
        contaTempo(&utime_pos, &stime_pos); //marca tempo final
        diftempo = (utime_pos-utime_ant) + (stime_pos-stime_ant);
        computaEstatisticas(tmpmed, trcmed, cmpmed, VET, diftempo, troca, compara);
        fprintf(output, "- Vetor\n   Comparações de chaves: %d\n   Trocas de registros: %d\n   Tempo gasto: %f\n\n", compara, troca, diftempo);

        compara = troca = 0;
        contaTempo(&utime_ant, &stime_ant);  //marca o tempo inicial
        quickStruct(vStruct, 0, N[i]-1, &compara, &troca);
        contaTempo(&utime_pos, &stime_pos); //marca o tempo final
        diftempo = (utime_pos-utime_ant) + (stime_pos-stime_ant);
        computaEstatisticas(tmpmed, trcmed, cmpmed, STRCT, diftempo, troca, compara);
        fprintf(output, "- Vetor de Struct:\n   Comparações de chaves: %d\n   Trocas de registros: %d\n   Tempo gasto: %f\n\n", compara, troca, diftempo);

      }
      //liberaLista(li):
      free(vetor);
      free(vStruct);

      fprintf(output, "\n>>>   MÉDIA   <<<\n\n");
      fprintf(output, ">>> VETOR\n   Comparações de chaves: %.2f\n   Trocas de registros: %.2f\n   Tempo gasto médio na ordenação: %fs\n\n", cmpmed[VET]/(float)REPEAT, trcmed[VET]/(float)REPEAT, tmpmed[VET]/(float)REPEAT);
      fprintf(output, ">>> VETOR DE STRUCT\n   Comparações de chaves: %.2f\n   Trocas de registros: %.2f\n   Tempo gasto médio na ordenação: %fs\n\n", cmpmed[STRCT]/(float)REPEAT, trcmed[STRCT]/(float)REPEAT, tmpmed[STRCT]/(float)REPEAT);
      }

      fclose(output);
      free(N);
  }
  else
    printf("Digite o tamanho do vetor na linha de argumento\n");
  return 0;
}

/* FALTA:
quick pra lista
*/
