#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

celula *enfileira (celula *f, int x){

  celula *novo=malloc(sizeof(celula));
  novo->prox=f->prox; //vira o ultimo

  f->dado=x;
  f->prox=novo;

  return novo;
}