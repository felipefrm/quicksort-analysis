#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "quicksort.h"
#include "analysis.h"

#define TYPE 3
#define REPEAT 5
#define INCREASE 10

int main(int argc, char** argv){

  if (argc > 3) {

    FILE *input;
    input = fopen(argv[2], "r");
    int qtdN, *N = leituraParametros(input, &qtdN);
    fclose(input);    //le parametros N do arquivo de entrada

    FILE *output;
    output = fopen(argv[3], "w");

    for (int i=0; i<qtdN; i++){
      fprintf(output, "-------------------------------\nPara N = %d\n\n", N[i]);
      int *vetor = (int*) malloc(N[i]*sizeof(int));
      elemento *vStruct = (elemento*)malloc(N[i]*sizeof(elemento));
      Lista* li = criaLista();
      // Alocação na memoria para os 3 tipos

      double cmpmed[TYPE]={0,0,0}, trcmed[TYPE]={0,0,0}, tmpmed[TYPE] = {0,0,0};
      int seed = atoi(argv[1]);   // declara a seed recebendo o argumento 1

      for (int j=0; j<REPEAT; j++){
        srand(seed+j*INCREASE); //seta a seed e incrementa 10 a cada repetição
        fprintf(output, ">>> %dª repetição\n", j+1);
        randomVetor(vetor, N[i]);
        randomStruct(vStruct, N[i]);    // gerador de valores aleatorios
        randomLista(li, vetor, N[i]);

        // vetor de inteiros
        double utime_ant, utime_pos, stime_ant, stime_pos, diftempo;
        int compara = 0, troca = 0;
        contaTempo(&utime_ant, &stime_ant); //marca tempo inicial
        quickInt(vetor, 0, N[i]-1, &compara, &troca);
        contaTempo(&utime_pos, &stime_pos); //marca tempo final
        diftempo = (utime_pos-utime_ant) + (stime_pos-stime_ant);
        computaEstatisticas(tmpmed, trcmed, cmpmed, VET, diftempo, troca, compara);
        fprintf(output, "- Vetor de inteiros\n   Comparações de chaves: %d\n   Trocas de registros: %d\n   Tempo gasto: %fs\n\n", compara, troca, diftempo);

        // vetor de struct
        compara = troca = 0;
        contaTempo(&utime_ant, &stime_ant);  //marca o tempo inicial
        quickStruct(vStruct, 0, N[i]-1, &compara, &troca);
        contaTempo(&utime_pos, &stime_pos); //marca o tempo final
        diftempo = (utime_pos-utime_ant) + (stime_pos-stime_ant);
        computaEstatisticas(tmpmed, trcmed, cmpmed, STRCT, diftempo, troca, compara);
        fprintf(output, "- Vetor de Struct:\n   Comparações de chaves: %d\n   Trocas de registros: %d\n   Tempo gasto: %fs\n\n", compara, troca, diftempo);

        // lista duplamente encadeada de inteiros
        compara = troca = 0;
        contaTempo(&utime_ant, &stime_ant); //marca o tempo inicial
        quickLista(*li, ultimono(li), &compara, &troca);
        contaTempo(&utime_pos, &stime_pos); //marca o tempo final
        diftempo = (utime_pos-utime_ant) + (stime_pos-stime_ant);
        computaEstatisticas(tmpmed, trcmed, cmpmed, LIST, diftempo, troca, compara);
        fprintf(output, "- Lista duplamente encadeada de inteiros\n   Comparações de chaves: %d\n   Trocas de registros: %d\n   Tempo gasto: %fs\n\n", compara, troca, diftempo);
        esvaziaLista(li);  //esvazia lista para inserir novos elementos
      }

      free(vetor);
      free(vStruct);    // libera os ponteiros
      liberaLista(li);

      imprimeMediaArq(output, cmpmed, trcmed, tmpmed, REPEAT);  // imprime media
    }

    fclose(output);
    free(N);
  }
  
  else
    printf("Digite todos argumentos na linha de argumento\n");
  return 0;
}
