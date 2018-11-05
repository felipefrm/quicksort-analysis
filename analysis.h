#ifndef ANALYSIS
#define ANALYSIS

#define VET 0
#define STRCT 1
#define LIST 2

void randomVetor(int *v, int N);
void randomStruct(elemento *v, int N);
// void randomLista(Lista *li, int *v, int N)
int* leituraParametros(FILE *input, int *qtdN, int *N);
void contaTempo(double *utime, double *stime);
void computaEstatisticas(double *tmpmed, double *trcmed, double *cmpmed, int tipo, double tempo, int troca, int compara);
void imprimeMediaArq(FILE *output, double *cmpmed, double *trcmed, double *tmpmed, int repeat);


#endif
