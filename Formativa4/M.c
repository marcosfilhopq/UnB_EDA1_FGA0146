#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

int desenfileira (celula *f, int *y){
    if(f->prox==NULL){ //lista vazia
        return 0;
    }

    celula *ptr = f->prox; // primeiro da fila
    *y= ptr->dado;

    f->prox=ptr->prox; // pula o removido
    free(ptr);

    return 1;
}