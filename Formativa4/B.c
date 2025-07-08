#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;


celula *busca (celula *le, int x){
    celula *ptr = le->prox;

    while(ptr!=NULL){
        if(ptr->dado==x){
            return ptr;
        }
        else{
            ptr=ptr->prox;
        }
        
    }
    return NULL;
}

celula *busca_rec (celula *le, int x){
    le=le->prox;

     if (le == NULL) {
        return NULL;
    }

    if (le->dado == x)
        return le;

    return busca_rec(le, x);
}


/*
void insere(celula *ptr, int x){
    celula *novo=malloc(sizeof(celula));
    novo->dado=x;
    novo->prox=ptr->prox;
    ptr->prox=novo;
}


int main(){
    int tam, x;
    scanf("%d", &tam);

    celula cabeca;
    cabeca.prox = NULL; //ainda vazio

    for (int i = tam; i > 0; i--) {
        int valor;
        scanf("%d", &valor);
        insere(&cabeca, valor);  // insere 1 até tam
    }

    scanf("%d", &x);

    printf("Iterativo:\n");

    celula *resultado = busca(&cabeca, x);

    if (resultado != NULL){
        printf("Achou: %d\n", resultado->dado);
    }
    else{
        printf("Nao achou.\n");
    }
        

    printf("\nRecursivo:\n");

    celula *resultado_rec = busca_rec(&cabeca, x);
    if(resultado_rec != NULL){
        printf("Achou %d", resultado_rec->dado);
    }
    else{
        printf("Nao achou.\n");
    }


    return 0;
}
*/
