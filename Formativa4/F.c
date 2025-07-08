#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void divide_lista (celula *l, celula *l1, celula *l2){
    celula *ptr=l->prox;
    celula *lista1 = l1; // aponta para o fim atual da lista l1 (ímpares)
    celula *lista2 = l2; // aponta para o fim atual da lista l2 (pares)

    while(ptr != NULL){
        celula *prox = ptr->prox; //salva o próximo antes de reencadear

        if((ptr->dado)%2 != 0){
            lista1->prox = ptr;
            lista1 = lista1->prox; //avança
        } 
        else{
            lista2->prox = ptr;
            lista2 = lista2->prox; //avança
        }

        ptr=ptr->prox;
    }

    // Finaliza as listas corretamente, ao acabar o loop
    lista1->prox = NULL;
    lista2->prox = NULL;
}