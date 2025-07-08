#include <stdlib.h>
#include <stdio.h>

typedef struct pilha {
  int *dados;
  int N, topo;
} pilha;

int desempilha (pilha *p, int *y){
    if(p->topo == 0){
        return 0;
    }

    //como em pilha so retira o ultimo da pilha, o top ddescrece, já que o topo esta vazio de certa, e seu antecessor possui algu valor
    p->topo--; //topo-1
    *y= p->dados[p->topo]; //y vai recever o ultimo da pilha, desconsiderando o topo, no indice do atual topo, que diminuiu
    return 1;
}
