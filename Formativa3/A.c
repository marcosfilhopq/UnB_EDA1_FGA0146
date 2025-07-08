#include <stdio.h>
#include <stdlib.h>

void insercao(int v[], int n){
    for(int i=1; i<n; i++){
        int c = v[i];
        int j= i-1;

        while(j>=0 && v[j]>c){
            v[j+1]=v[j];
            j=j-1; 
        }

        v[j+1]=c; //quando for j=-1. pois descreceu a -1 no while, a posicao v[0] assume o valor da chave c
    }
 
}

int main(){
    int v[1000], i=0;

    while(scanf("%d", &v[i]) != EOF && i<1000){
        i=i+1;
    }

    insercao(v,i);

    for(int aux=0; aux<i; aux++ ){
        if(aux==i-1) {
            printf("%d", v[aux]); //ultimo sem espaco
        }
        else {
            printf("%d ", v[aux]); //demais com espaco
        }
    }

    return 0;
}