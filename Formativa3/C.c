#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int *v, int n, int x){
    int esquerda=0;
    int direita=n;

    while(esquerda<direita){
        int metade = (esquerda+direita)/2;

        if(x<=v[metade]){
            direita=metade; //x cabe antes ou no meio do vetor
        }
        else{
            esquerda=metade+1; //x cabe depois do meio do vetor
        }
    }

    // ao final, a esquerda eh o j que v[j-1] < x <= v[j], mas pd ser "return direita" tbm, já que os dois se igualam no final, mas por convencao é "return esquerda"
    return esquerda;
}

void ordenacao(int *v, int n){  
    for(int i=1; i<n;i++){
        int chave=v[i];
        int j=i-1;
        
        while(j>=0 && v[j]>chave){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=chave;
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n, &m);

    int *v=(int*) calloc (n, sizeof(int));
    int *buscas = (int*) calloc(m, sizeof(int)); // vetor com os valores a serem buscados
    if(v==NULL){
        return 1;
    }

    for(int i=0; i<n; i++){ //escanear n numeros
        scanf("%d", &v[i]);
    }

    ordenacao(v, n);

    //escanea m numeros
    for (int i = 0; i < m; i++) {
        scanf("%d", &buscas[i]);
    }

    //realiza a busca binaria para cada valor em m
    for (int i = 0; i < m; i++) {
        int lugar_vetor = busca_binaria(v, n, buscas[i]);
        printf("%d\n", lugar_vetor);
    }

    /*Printa(Teste)
    for(int j=0; j<n;j++){
        printf("%d", v[j]);
    }*/

    free(v);
    free(buscas);

    return 0;
}