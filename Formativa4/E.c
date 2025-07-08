#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){
    celula *ptr1 = l1->prox;
    celula *ptr2 = l2->prox;
    celula *lista= l3;

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->dado <= ptr2->dado){
            lista->prox=ptr1; //recebe o ponteir
            ptr1=ptr1->prox; //avança
        }
        else{
            lista->prox=ptr2;
            ptr2=ptr2->prox; //avança
        }

        lista=lista->prox; //avança na lista
    }

    // Liga o restante da lista que ainda sobrou
    if (ptr1 != NULL) {
        lista->prox = ptr1;
    }
    else {
        lista->prox = ptr2;
    }
}