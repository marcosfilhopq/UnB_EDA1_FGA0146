#include <stdio.h>
#include <stdlib.h>

void decParaRom(int num) {
    int valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char *simbolos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for(int i = 0; i < 13; i++) {
        while(num >= valores[i]) {
            printf("%s", simbolos[i]);
            num -= valores[i];
        }
    }
    printf("\n");
}

int main() {
    int n, num[3999]; // O problema garante que n ≤ 3999
    
    scanf("%d", &n); // Lê o valor de n
    
    // Lê os n números
    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    
    // Converte e imprime cada número
    for(int i = 0; i < n; i++) {
        decParaRom(num[i]);
    }
    
    return 0;
}