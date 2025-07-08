#include <stdio.h>

#define MAX 100010  // garante espaço para n grande

int fila[MAX];
int frente = 0, tras = 0;

void enfileira(int x) {
    fila[tras] = x;
    tras = (tras + 1) % MAX;
}

int desenfileira() {
    int val = fila[frente];
    frente = (frente + 1) % MAX;
    return val;
}

int tamanho() {
    return (tras - frente + MAX) % MAX;
}

int main() {
    int n;
    scanf("%d", &n);

    // inicializa a fila com as cartas de 1 a n
    for (int i = 1; i <= n; i++) {
        enfileira(i);
    }

    printf("Cartas descartadas:");

    while (tamanho() > 1) {
        // descarta a primeira carta
        int descartada = desenfileira();
        printf(" %d", descartada);
        if (tamanho() > 1) printf(",");

        // move a próxima carta para o fim
        enfileira(desenfileira());
    }

    // imprime a última carta restante
    printf("\nCarta restante: %d\n", desenfileira());

    return 0;
}
