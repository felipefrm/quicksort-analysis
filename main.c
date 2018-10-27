#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
// #include "lista.h"
#include "quicksort.h"
#include <string.h>

#define K 10
#define QNT 30
#define FLT 4

int transformaChar(char num){

  if (num >= 48 && num <= 57)
    num = num - 48;
  return num;
}

int main(int argc, char** argv)
{
    struct rusage resources;
    int rc;
    double utime, stime, total_time;
        if (argc > 1)
        {
                srand(time(NULL));
                int SIZE = atoi(argv[1]);

                FILE *input;
                input = fopen(argv[2], "r");

                char linha1[3];
                char* tamanhoN = fgets(linha1, 3, input);  //lendo a quantidade de N
                tamanhoN[strcspn(tamanhoN,"\0")] = '\n';
                for(int i=0; i<3; i++){
                  printf("T:%d\n", tamanhoN[i]);
                  printf("L:%d\n", linha1[i]);
              }
                // int N = transformaChar(tamanhoN);
                // printf("%d\n", n);

                fclose(input);

                FILE *output;
                output = fopen(argv[3], "w");

                fclose(output);

                // int *meuVetor = (int*) malloc(SIZE*sizeof(int));
                elemento* vetor = (elemento*)malloc(SIZE*sizeof(elemento));
                // Lista* li = criaLista();

                char letras[10] = {'a','b','c','d','e','f','g','h','i','j'};
                for (int i=0; i < SIZE; i++)
                {
                    // meuVetor[i] = abs(rand()%(100*SIZE));
                    // insereLista(li, meuVetor[i]);
                    vetor[i].ch = abs(rand()%(100*SIZE));
                    //Lógica para preencher str e f
                    // vetor[i].f = (float)rand()/RAND_MAX;
                    vetor[i].f = (float*)malloc(FLT*sizeof(float));
                    vetor[i].str = (char**)malloc(K*sizeof(char*));
                    for (int j=0; j < K; j++)
                    {
                        vetor[i].str[j] = (char*)malloc(QNT*sizeof(char));
                        for (int p=0; p<QNT; p++){
                          vetor[i].str[j][p] = letras[rand()%K];
                        }
                    }
                    for (int j=0; j < FLT; j++)
                    {
                        vetor[i].f[j] = (float)rand()/RAND_MAX;
                    }
                }


                int numAtivacoes = 0;
                printf("Vetor inicial:\n");
                // imprimeLista(li);
                for (int i=0; i < SIZE; i++){
                        // printf("%d\n", meuVetor[i]);
                        printf("%d %f %f %f %f\n", vetor[i].ch, vetor[i].f[0], vetor[i].f[1], vetor[i].f[2], vetor[i].f[3]);
                        for (int j=0; j < K; j++){
                            printf("str%d: %s\n", j, vetor[i].str[j]);

                        }
                }
                printf("\n");

                quickStruct(vetor,0,SIZE-1,&numAtivacoes);
                //quick_int(meuVetor,0,SIZE-1,&numAtivacoes);

                printf("Vetor ordenado:\n");
                for (int i=0; i < SIZE; i++){
                    printf("%d %f %f %f %f\n", vetor[i].ch, vetor[i].f[0], vetor[i].f[1], vetor[i].f[2], vetor[i].f[3]);
                    for (int j=0; j < K; j++){
                        printf("str%d: %s\n", j, vetor[i].str[j]);

                    }
                    // printf("%d ", meuVetor[i]);
                    printf("\n");
                }
                printf("Número de ativações: %d\n", numAtivacoes);

                // liberaLista(li):
                // free(meuVetor);
                free(vetor);
                if((rc = getrusage(RUSAGE_SELF, &resources)) != 0) {
                    perror("getrusage failed");
                }
                utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
                stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
                total_time = utime+stime;
                printf("User time %.3f, System time %.3f, Total Time %.3f\n",utime, stime, total_time);
        }
        else
                printf("Digite o tamanho do vetor na linha de argumento\n");
        return 0;
}
