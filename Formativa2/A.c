#include <stdio.h>

int f(int a){
    if(a>=101){
        return a-10;
    }
    else {
        return f(f(a+11));
    }
}

int main(){
    int N, resultado, entradas[250000], i=0;

    //Escanea o N e joga para o vetor
    while(1){
        scanf("%d", &N );

        if (N == 0) {
            break; //Quebra antes para que, se N for 0, nao chegue a ser salvo no vetor entradas
        } 
        else{
            entradas[i++] = N;
        }
    }
        
    // Agora processa e imprime os resultados
    for(int j=0; j<i;j++){
        resultado = f(entradas[j]);
        printf("f91(%d) = %d\n", entradas[j], resultado);
    }

    return 0;
}