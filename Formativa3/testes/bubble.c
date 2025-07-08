#include <stdio.h>
#include <stdlib.h>

void bubble( int *v, int n){
    int continua;
    do{
        continua=0;
        for(int i=0; i<n; i++){
            if(v[i]>v[i+1]){
                int aux=v[i];
                v[i]=v[i+1];
                v[i+1]= aux;
                continua=1;
            }
        }
    }while(continua!=0);
}

int main(){
    int n;
    scanf("%d", &n);

    int *v= (int*) calloc (n,sizeof(int));

    for(int i=0; i<n;i++){
        scanf("%d", &v[i]);
    }

    bubble(v, n);

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