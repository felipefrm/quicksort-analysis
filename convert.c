#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "convert.h"

#define a 48
#define z 57
#define base 10

int transformaChar(char num){

  if (num >= a && num <= z)
    num = num - a;
  return num;
}

int CharParaInt(char *charN){
  int soma = 0, expoente = strlen(charN)-1;
  for (int i = 0; i < strlen(charN); i++){
    soma += transformaChar(charN[i]) * pow(base, expoente);
    expoente--;
  }
  return soma;
}
