#include <stdlib.h>
#include <stdio.h>

typedef struct pilha {
  int *dados;
  int N, topo;
} pilha;

int empilha (pilha *p, int x){
    if(p->topo == p->N){ //pilha nn pd ta cheia para add
        int novo_tam = p->N + 1;
        int *novo= realloc(p->dados, novo_tam*sizeof(int));
        if(novo == NULL){
            return 0;
        }

        p->dados=novo;
        p->N=novo_tam;
        
    }

    p->dados[p->topo] = x; //armzena momentaneamente no top

    p->topo++; //avança
    
    return 1; //sucesso
}