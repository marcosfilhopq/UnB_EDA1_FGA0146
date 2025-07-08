#include <stdio.h>
#include <stdlib.h>

int particiona(int *v, int inicio, int fim){
    int esq=inicio;
    int dir=fim;
    int pivo=v[inicio];
    while(esq<dir){
        while(v[esq]<=pivo){
            esq++;
        }
        while(v[dir]>pivo){
            dir--;
        }
        if(esq<dir){
            int aux=v[esq];
            v[esq]=v[dir];
            v[dir]=aux;
        }
    }

    // Troca o pivô com o valor final da partição
    int aux = v[inicio];
    v[inicio] = v[dir];
    v[dir] = aux;

    return dir;
}

void quickSort(int *v, int inicio, int fim){
    int pivo;
    if(fim>inicio){
        pivo=particiona(v,inicio,fim);
        quickSort(v, inicio, pivo-1);
        quickSort(v, pivo+1, fim);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int *v= (int*) calloc (n,sizeof(int));

    for(int i=0; i<n;i++){
        scanf("%d", &v[i]);
    }

    quickSort(v, 0, n-1);

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