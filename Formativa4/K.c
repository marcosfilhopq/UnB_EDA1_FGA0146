#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
  int *dados;
  int N, p, u;
} fila;

int desenfileira (fila *f, int *y){
    if(f->p == f->u){ //fila vazia
        return 0;
    }

 
    *y=f->dados[f->p]; //pega valor da frente da fila
    f->p = (f->p + 1) % f->N; //avança circularmente
    return 1;
  
}