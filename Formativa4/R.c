#include <stdio.h>
#include <string.h>

char historico[100000][101];
int topo = 0;

int main() {
    char linha[200];

    while (fgets(linha, sizeof(linha), stdin)) {
        if (strncmp(linha, "inserir ", 8) == 0) {
            strcpy(historico[topo], linha + 8);
            historico[topo][strcspn(historico[topo], "\n")] = '\0';  // tira o \n
            topo++;
        } else if (strncmp(linha, "desfazer", 8) == 0) {
            if (topo == 0)
                printf("NULL\n");
            else
                printf("%s\n", historico[--topo]);
        }
    }

    return 0;
}
