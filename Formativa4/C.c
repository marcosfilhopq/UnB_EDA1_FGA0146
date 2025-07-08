#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){
    celula *ptr = le;

    celula *novo= malloc(sizeof(celula));
    novo->dado=x;
    novo->prox=ptr->prox;
    ptr->prox= novo;
}

void insere_antes (celula *le, int x, int y){
    celula *anterior = le;
    celula *atual = le->prox;

    while(atual !=NULL){
        if(atual->dado == y){
            celula *novo= malloc(sizeof(celula));
            novo->dado=x;
            novo->prox=atual;
            anterior->prox= novo;
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    // Se y não for encontrado, insere no final
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = NULL;
    anterior->prox = novo;
}

