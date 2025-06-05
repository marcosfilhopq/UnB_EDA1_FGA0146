#include <stdio.h>

int media(int vet[], int n){
    long long soma = 0;

    // Calcula a soma de todos os elementos do vetor
    for (int i = 0; i < n; i++) {
        soma += vet[i];
    }

    // Retorna a média (parte inteira)
    return soma / n;
}

int main() {
    int tam_vetor = 0;
    int vetor[10000]; // Limite máximo do vetor (10000 elementos)

    // Tamanho do vetor
    scanf("%d", &tam_vetor); 

    // Elementos do vetor
    for (int i = 0; i < tam_vetor; i++) {
        scanf("%d", &vetor[i]); 
    }

    // Calcula a média
    int media_final = media(vetor, tam_vetor);

    // Variável para verificar se há elementos maiores que a média
    int encontrou = 0;

    // Primeiro, coletamos todos os números maiores que a média
    for (int j = 0; j < tam_vetor; j++) {
        if (vetor[j] > media_final) {
            if (encontrou) {
                printf(" "); // Adiciona espaço entre os números
            }
            printf("%d", vetor[j]);
            encontrou = 1;
        }
    }

    // Se não encontrou nenhum número maior que a média
    if (!encontrou) {
        printf("0");
    }

    printf("\n"); // Adiciona a quebra de linha ao final

    return 0;
}

/*
#include <stdio.h>

int media(int vet[], int n){
    long long soma = 0;

    // Calcula a soma de todos os elementos do vetor
    for (int i = 0; i < n; i++) {
        soma += vet[i];
    }

    // Retorna a média (parte inteira)
    return soma / n;
}

int main() {
    int tam_vetor = 0;
    int vetor[10000]; // Limite máximo do vetor (10000 elementos)

    // Tamanho do vetor
    scanf("%d", &tam_vetor); // Leitura direta sem do-while já que as restrições garantem que o valor é válido

    // Elementos do vetor
    for (int i = 0; i < tam_vetor; i++) {
        scanf("%d", &vetor[i]); // Leitura direta
    }

    // Calcula a média
    int media_final = media(vetor, tam_vetor);

    // Variável para verificar se há elementos maiores que a média
    int encontrou = 0;

    // Primeiro, coletamos todos os números maiores que a média
    for (int j = 0; j < tam_vetor; j++) {
        if (vetor[j] > media_final) {
            if (encontrou) {
                printf(" "); // Adiciona espaço entre os números
            }
            printf("%d", vetor[j]);
            encontrou = 1;
        }
    }

    // Se não encontrou nenhum número maior que a média
    if (!encontrou) {
        printf("0");
    }

    printf("\n"); // Adiciona a quebra de linha ao final

    return 0;
}
*/