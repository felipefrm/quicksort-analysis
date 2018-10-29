#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "convert.h"

int transformaChar(char num){

  if (num >= 48 && num <= 57)
    num = num - 48;
  return num;
}

int CharParaInt(char *charN){
  int soma = 0, expoente = strlen(charN)-1;
  for (int i = 0; i < 3; i++){
    soma += transformaChar(charN[i]) * pow(10, expoente);
    expoente--;
  }
  return soma;
}
