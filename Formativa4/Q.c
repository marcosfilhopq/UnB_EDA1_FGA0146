#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 1000

// Pilha para inteiros
typedef struct {
    int data[MAX];
    int topo;
} PilhaInt;

void initInt(PilhaInt* p) {
    p->topo = -1;
}

int vazioInt(PilhaInt* p) {
    return p->topo == -1;
}

void pushInt(PilhaInt* p, int val) {
    p->data[++(p->topo)] = val;
}

int popInt(PilhaInt* p) {
    return p->data[(p->topo)--];
}

// Pilha para caracteres
typedef struct {
    char data[MAX];
    int topo;
} PilhaChar;

void initChar(PilhaChar* p) {
    p->topo = -1;
}

int vazioChar(PilhaChar* p) {
    return p->topo == -1;
}

void pushChar(PilhaChar* p, char val) {
    p->data[++(p->topo)] = val;
}

char popChar(PilhaChar* p) {
    return p->data[(p->topo)--];
}

char topoChar(PilhaChar* p) {
    return p->data[p->topo];
}

// Prioridade dos operadores
int prioridade(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Verifica se parênteses estão balanceados
int parenteses_validos(const char* expr) {
    int cont = 0;
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(') cont++;
        else if (expr[i] == ')') cont--;
        if (cont < 0) return 0;
    }
    return cont == 0;
}

// Converte para pós-fixa
void infixa_para_posfixa(const char* expr, char posfixa[][MAX], int* tam, int valores[26]) {
    PilhaChar operadores;
    initChar(&operadores);
    int i = 0;

    while (expr[i]) {
        if (isalpha(expr[i])) {
            int idx = expr[i] - 'A';
            sprintf(posfixa[(*tam)++], "%d", valores[idx]);
            i++;
        } else if (isdigit(expr[i]) || (expr[i] == '-' && isdigit(expr[i+1]))) {
            char num[20];
            int k = 0;
            if (expr[i] == '-') num[k++] = expr[i++];
            while (isdigit(expr[i])) num[k++] = expr[i++];
            num[k] = '\0';
            strcpy(posfixa[(*tam)++], num);
        } else if (expr[i] == '(') {
            pushChar(&operadores, expr[i]);
            i++;
        } else if (expr[i] == ')') {
            while (!vazioChar(&operadores) && topoChar(&operadores) != '(') {
                char op[2] = {popChar(&operadores), '\0'};
                strcpy(posfixa[(*tam)++], op);
            }
            if (!vazioChar(&operadores)) popChar(&operadores);
            i++;
        } else { // operador
            while (!vazioChar(&operadores) && ((expr[i] != '^' && prioridade(topoChar(&operadores)) >= prioridade(expr[i])) ||
        (expr[i] == '^' && prioridade(topoChar(&operadores)) > prioridade(expr[i]))))  {
                char op[2] = {popChar(&operadores), '\0'};
                strcpy(posfixa[(*tam)++], op);
            }
            pushChar(&operadores, expr[i]);
            i++;
        }
    }

    while (!vazioChar(&operadores)) {
        char op[2] = {popChar(&operadores), '\0'};
        strcpy(posfixa[(*tam)++], op);
    }
}

// Avalia pós-fixa
int avaliar_posfixa(char posfixa[][MAX], int tam, int* erro) {
    PilhaInt pilha;
    initInt(&pilha);

    for (int i = 0; i < tam; i++) {
        if (isdigit(posfixa[i][0]) || (posfixa[i][0] == '-' && isdigit(posfixa[i][1]))) {
            pushInt(&pilha, atoi(posfixa[i]));
        } else {
            if (pilha.topo < 1) {
                *erro = 1;
                return 0;
            }
            int b = popInt(&pilha);
            int a = popInt(&pilha);
            if (posfixa[i][0] == '+') pushInt(&pilha, a + b);
            else if (posfixa[i][0] == '-') pushInt(&pilha, a - b);
            else if (posfixa[i][0] == '*') pushInt(&pilha, a * b);
            else if (posfixa[i][0] == '/') {
                if (b == 0) {
                    *erro = 1;
                    return 0;
                }
                pushInt(&pilha, a / b);
            } else if (posfixa[i][0] == '^') {
                pushInt(&pilha, (int)pow(a, b));
            } else {
                *erro = 1;
                return 0;
            }
        }
    }

    if (pilha.topo != 0) {
        *erro = 1;
        return 0;
    }

    return popInt(&pilha);
}

int main() {
    char expr[MAX];
    int valores[26] = {0};
    char linha[MAX];

    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    if (!parenteses_validos(expr)) {
        printf("emf\n");
        return 0;
    }

    while (fgets(linha, MAX, stdin)) {
        if (strchr(linha, '=')) {
            char var;
            int val;
            if (sscanf(linha, "%c=%d", &var, &val) == 2) {
                if (var >= 'A' && var <= 'Z') {
                    valores[var - 'A'] = val;
                }
            }
        }
    }

    char posfixa[1000][MAX];
    int tam = 0;
    infixa_para_posfixa(expr, posfixa, &tam, valores);

    int erro = 0;
    int resultado = avaliar_posfixa(posfixa, tam, &erro);

    if (erro) {
        printf("emf\n");
    } else {
        printf("%d\n", resultado);
    }

    return 0;
}
