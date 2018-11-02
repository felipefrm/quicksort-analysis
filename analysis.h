#ifndef ANALYSIS
#define ANALYSIS

void randomVetor(int *v, int N);
void randomStruct(elemento *v, int N);
// void randomLista(Lista *li, int *v, int N)
int* leituraParametros(FILE *input, int *qtdN, int *N);
void contaTempo(double *utime, double *stime);
void computaEstatisticas(double *tmpmed, double *trcmed, double *cmpmed, int tipo, double tempo, int troca, int compara);

#endif
