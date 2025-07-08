#include <stdio.h>
#include <stdlib.h>

void insercao(int *v, int tamanho){
    for(int i=1; i<tamanho; i++){
        int chave=v[i];
        int j=i;
        for(j=i; j>0 && v[j-1]>chave;j--){
            v[j]=v[j-1];
        }
        v[j]=chave;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int *v= (int*) calloc (n,sizeof(int));

    for(int i=0; i<n;i++){
        scanf("%d", &v[i]);
    }

    insercao(v, n);

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