#include <stdio.h>
#include <stdlib.h>

void selecao(int *v, int n){
    for(int i=0; i<n; i++){
        int menor=i;
        for(int j=i+1; j<n; j++){
            if(v[j]<v[menor]){
                menor=j;
            }
        }

        if(i!=menor){
            int aux=v[i];
            v[i]=v[menor];
            v[menor]=aux;
        }
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