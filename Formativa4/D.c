#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void remove_depois (celula *p){
    if(p==NULL || p->prox == NULL){
        return; //nada adianta se p for vazio ou seu proximo tiver vazio
    }

    celula *temp=p->prox;
    p->prox = temp->prox; //se nao quebra a lista
    free(temp);
}

void remove_elemento (celula *le, int x){
    celula *anterior= le;
    celula *ptr = le->prox;

    while(ptr != NULL){
        if(ptr->dado == x){
            anterior->prox = ptr->prox;
            free(ptr); //libera o nó removido da memória
            return; //return para nn dar merda se tiver outro igual
        }

        //avança normalmente
        anterior=ptr;
        ptr=ptr->prox;
    }

}

void remove_todos_elementos (celula *le, int x){
    celula *anterior= le;
    celula *ptr = le->prox;

    while(ptr != NULL){
        if(ptr->dado == x){
            anterior->prox = ptr->prox;
            free(ptr); //libera o nó removido da memória
            ptr=anterior->prox; //pd avançar agora
        }
        else{
            //avança normalmente
            anterior=ptr;
            ptr=ptr->prox;
        }
    }
}