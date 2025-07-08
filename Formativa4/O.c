#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 501

typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void push(Pilha *p, char c) {
    p->dados[p->topo++] = c;
}

char pop(Pilha *p) {
    if (p->topo == 0) return 0;
    return p->dados[--p->topo];
}

int vazio(Pilha *p) {
    return p->topo == 0;
}

int corresponde(char aberto, char fechado) {
    return (aberto == '(' && fechado == ')') ||
           (aberto == '[' && fechado == ']') ||
           (aberto == '{' && fechado == '}');
}

int main() {
    char expr[MAX];
    Pilha pilha;
    pilha.topo = 0;

    if (!fgets(expr, MAX, stdin)) return 1;

    int len = strlen(expr);
    if (expr[len-1] == '\n') expr[len-1] = '\0'; // remove newline

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&pilha, c);
        } else if (c == ')' || c == ']' || c == '}') {
            char topo = pop(&pilha);
            if (!corresponde(topo, c)) {
                printf("nao\n");
                return 0;
            }
        }
    }

    if (vazio(&pilha)) printf("sim\n");
    else printf("nao\n");

    return 0;
}
