#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *proximo;
} No; //o nome da variavel mesmo

//inserir no inicio
void inserir_incio(No **lista, int num){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->dado = num;
        novo->proximo = *lista; //vai receber o conteudo da lista
        *lista = novo; //o inicio da lista passa a ser o novo
    }
    else{
        printf("Deu ruim mano, nn alocou");
    }
}

//inserir no final
void inserir_final(No **lista, int num){
    No *aux, *novo=malloc(sizeof(No));
    if(novo){
        novo->dado = num;
        novo->proximo = NULL //null pq é o ultimo

        //é o primeiro?
        if(*lista == NULL){ //caso nn tenha lista, o conteudo dela vai ser a nova variavel no
            *lista = novo; 
        }
        else{ //lista nn vazia
            aux = *lista; //nao pode percorres a lista assim, pq se nn perde os seus valores
            while(aux->proximo){ //enquanto existir um proximo
                aux = aux->proximo;
            } //acaba quando for NULL
            aux->proximo = novo; //ao chegar em NULL(ultimo), o proximo recebe o novo no
        }
    }
    else{
        printf("Deu ruim viado");
    }

}

void inserir_no_meio(No **lista, int num ,int ant){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->dado=num;
        
        //[e o primeiro?]
        if(*lista==NULL){
            novo->proximo=NULL;
            *lista = novo;
        }
        else{
            
        }
    }
    else{
        return 1;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int *v= (int*) calloc (n,sizeof(int));

    for(int i=0; i<n;i++){
        scanf("%d", &v[i]);
    }

    selecao(v, n);

    for(int i=0; i<n;i++){
        if(i<n-1){
            printf("%d ", v[i]);
        }
        else{
            printf("%d", v[i]);
        }
        
    }

    return 0;
}