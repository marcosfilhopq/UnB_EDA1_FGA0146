#include <stdlib.h>
#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime (celula *le){
    celula *ptr= le->prox;

    while(ptr!=NULL){
        printf("%d -> ", ptr->dado);
        ptr = ptr->prox;
    }

    printf("NULL\n");

}

void imprime_rec (celula *le){
    celula *ptr = le->prox; // pula a cabeça

    if (ptr != NULL) {
        
        printf("%d -> ", ptr->dado);
        imprime_rec(ptr); 

    } else {

        printf("NULL\n");
    }
}

/*
void insere(celula *ptr, int x){
    celula *novo=malloc(sizeof(celula));
    novo->dado=x;
    novo->prox=ptr->prox;
    ptr->prox=novo;
}


int main(){
    int tam;
    scanf("%d", &tam);

    celula cabeca;
    cabeca.prox = NULL; //ainda vazio

    int i=tam;

    while(i!=0){
        insere(&cabeca, i);
        i--;
    }

    printf("Iterativo:\n");
    imprime(&cabeca);

    printf("\nRecursivo:\n");
    imprime_rec(&cabeca);

    return 0;
}
*/
