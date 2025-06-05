#include <stdio.h>
#include <string.h>

#define MAX 1000
#define TAM 1050 // tamanho para strings grandes

int somar_digitos(const char *s) {
    int soma = 0;
    for (int i = 0; s[i]; i++) {
        soma += s[i] - '0';
    }
    return soma;
}

int grau9(const char *s) {
    int grau = 1;
    int soma = somar_digitos(s);
    if (soma % 9 != 0) return 0;

    while (soma >= 10) {
        int temp = 0;
        while (soma > 0) {
            temp += soma % 10;
            soma /= 10;
        }
        soma = temp;
        grau++;
    }
    return grau;
}

int main() {
    char entradas[MAX][TAM];
    int i = 0;

    // Lê todas as entradas até encontrar "0"
    while (1) {
        scanf("%s", entradas[i]);
        if (strcmp(entradas[i], "0") == 0) break;
        i++;
    }

    // Agora imprime todos os resultados
    for (int j = 0; j < i; j++) {
        int grau = grau9(entradas[j]);
        if (grau == 0)
            printf("%s is not a multiple of 9.\n", entradas[j]);
        else
            printf("%s is a multiple of 9 and has 9-degree %d.\n", entradas[j], grau);
    }

    return 0;
}
