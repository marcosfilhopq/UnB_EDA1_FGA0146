#include <stdio.h>
#include <stdlib.h>

void contagem( int *v, int n){
    int baldes[100];
    for(int i=0; i<100; i++){
        baldes[i]=0;
    }

    for(int i=0; i<n; i++){
        baldes[v[i]]=baldes[v[i]]+1;
    }

    for(int i=0, j=0; j<100; j++){
        for(int k=baldes[j]; k>0; k--){
            v[i++]=j;
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

    contagem(v,n);

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