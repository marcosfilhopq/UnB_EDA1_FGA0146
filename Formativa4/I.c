#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int desempilha (celula *p, int *y){
    if(p->prox==NULL){ //vazia
        return 0;
    }

    celula *topo=p->prox; //n precisa do loop, pq em p->prox ja esta o topo da lista em pilha
    *y=topo->dado;

    p->prox = topo->prox; //remove o topo
    free(topo);
    return 1;

}