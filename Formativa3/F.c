#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>  // para PRId64

// Retorna o número de círculos cujo raio² >= dist2
int busca_binaria(int* raios, int C, long long dist2) {
    int left = 0, right = C - 1;
    int pos = -1; // posição do primeiro raio que contém o tiro

    while (left <= right) {
        int mid = (left + right) / 2;
        long long r2 = (long long)raios[mid] * raios[mid];

        if (r2 >= dist2) {
            pos = mid;      
            right = mid-1; //procura um raio menor que também contenha
        } else {
            left = mid + 1;
        }
    }

    if (pos == -1) {
        return 0;
    }   // nenhum círculo contém o tiro

    return C - pos; // número de círculos que contém o tiro
}

int main() {
    int C, T;
    scanf("%d %d", &C, &T);

    int* raios = (int*)malloc(C*sizeof(int));

    //escanea o raios
    for (int i = 0; i<C; i++) {
        scanf("%d", &raios[i]);
    }

    int64_t total_pontos = 0;

    for (int i = 0; i < T; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        long long dist2 = (long long)x * x + (long long)y * y;

        int pontos = busca_binaria(raios, C, dist2);
        total_pontos = total_pontos + pontos;
    }

    // int64_t para evitar warning
    printf("%" PRId64 "\n", total_pontos);

    free(raios);
    return 0;
}
