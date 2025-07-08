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

char peek(Pilha *p) {
    if (p->topo == 0) return 0;
    return p->dados[p->topo - 1];
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char c) {
    switch(c) {
        case '^': return 4;
        case '*': case '/': return 3;
        case '+': case '-': return 2;
        case '(': return 1;
        default: return 0;
    }
}

int main() {
    char expr[MAX];
    if (!fgets(expr, MAX, stdin)) return 1;

    int len = strlen(expr);
    if (expr[len-1] == '\n') expr[len-1] = '\0';

    Pilha pilha;
    pilha.topo = 0;
    char output[MAX];
    int out_pos = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (c >= 'A' && c <= 'Z') {
            //operando direto para saída
            output[out_pos++] = c;
        } else if (c == '(') {
            push(&pilha, c);
        } else if (c == ')') {
            //sesempilha até '(' ou erro
            char t;
            int achou_abertura = 0;
            while (pilha.topo > 0) {
                t = pop(&pilha);
                if (t == '(') {
                    achou_abertura = 1;
                    break;
                }
                output[out_pos++] = t;
            }
            if (!achou_abertura) {
                printf("incorretamente parentizada\n");
                return 0;
            }
        } else if (isOperator(c)) {
            //desempilha operadores com precedência 
            while (pilha.topo > 0) {
                char t = peek(&pilha);
                if (t == '(') break;

                int precT = precedence(t);
                int precC = precedence(c);

                //associatividade: ^ é direita (so desempilha se precT > precC), outros são esquerda (desempilha se precT >= precC)
                if ((c == '^' && precT > precC) || (c != '^' && precT >= precC)) {
                    output[out_pos++] = pop(&pilha);
                } else {
                    break;
                }
            }
            push(&pilha, c);
        } else {
            //inválido, pode ignorar ou tratar como erro
            //ignora
        }
    }

    //desempilha resto
    while (pilha.topo > 0) {
        char t = pop(&pilha);
        if (t == '(') {
            printf("incorretamente parentizada\n");
            return 0;
        }
        output[out_pos++] = t;
    }

    output[out_pos] = '\0';

    printf("%s\n", output);
    return 0;
}
