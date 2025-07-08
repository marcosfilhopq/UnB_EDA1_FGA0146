#include <stdio.h>
#include<stdlib.h>

void intercala( int *v, int e, int meio, int d){
    int i=e, j=meio+1, k=0;
    int *aux = malloc((d-e+1)*sizeof(int));
    while(i<=meio && j<=d){
        if(v[i]<=v[j]){
            aux[k]=v[i];
        }
        else{
            aux[k]=v[j]; k++; j++;
        }
    }

    while(i<meio){
        aux[k++]=v[i++];
    }   

    while(j<=d){
        aux[k++]=v[j++];
    }

    for(k=0, i=e ;i<=d; k++, i++){
        v[i]=aux[k];
    }

    free(aux);
}

void mergesort(int *v, int e, int d){
    if(e<d){
        int meio= (e+d)/2;
        mergesort(v, e, meio);
        mergesort(v, meio+1, d);
        intercala(v, e, meio, d);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int *v= (int*) calloc (n,sizeof(int));

    for(int i=0; i<n;i++){
        scanf("%d", &v[i]);
    }

    mergesort(v, 0, n-1);

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