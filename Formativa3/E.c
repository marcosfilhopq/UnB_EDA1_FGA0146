#include <stdio.h>
#include <stdlib.h>

#define MAX_CASAS 45000
#define MAX_VALOR 1000000001

int main() {
    int N, M, *casas, *mapa;
    scanf("%d %d", &N, &M);

    casas = (int *)malloc(N * sizeof(int));

    mapa = (int *)malloc(MAX_VALOR * sizeof(int));  // mapa[casa] = posição na rua, nesse caso é um vetor auxiliar

    for (int i=0; i<MAX_VALOR; i++) {
        mapa[i] = -1; //nenhuma casa foi alocada
    }

    for (int i=0; i<N; i++) {
        scanf("%d", &casas[i]);
        mapa[casas[i]] = i;
    }

    int atual = 0;  // começa na posição da primeira casa da rua (índice 0)
    int tempo = 0;
    for (int i = 0; i < M; i++) {
        int numero_casa;
        scanf("%d", &numero_casa);

        int destino = mapa[numero_casa];
        tempo = tempo + abs(destino - atual); //abs é como se fosse o modulo
        atual = destino;
    }

    printf("%d\n", tempo);

    free(casas);
    free(mapa);
    return 0;
}
