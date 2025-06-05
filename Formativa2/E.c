#include <stdio.h>

int pa_recursiva (int *v, int primeiro, int ultimo){
    // Caso base: quando os índices se cruzarem ou se encontrarem, meio da P.A
    if (primeiro >= ultimo) {
        return 1;
    }

    if(v[primeiro] + v[ultimo] != v[primeiro+1] + v[ultimo-1]){
        return 0;

    }

    return pa_recursiva(v, primeiro+1, ultimo-1);
    //primeiro e ultimo agem como indices, como i e j por exemplo
}

/* Exemplo

int main(){
    int vetor[] = {1,2,3,4};
    int resultado = pa_recursiva(vetor, 0, 3); //Indices, nao o numero em si
    printf("%d", resultado);
    return 0;
} 
    
*/