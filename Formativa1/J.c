#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1005

int P, M = 0, N = 0;
char mapa[MAX][MAX];
int visitado[MAX][MAX];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int fila_x[MAX * MAX], fila_y[MAX * MAX];
int frente, tras;

int bfs(int sx, int sy) {
    int mortos = 0;
    memset(visitado, 0, sizeof(visitado));
    frente = tras = 0;
    fila_x[tras] = sx;
    fila_y[tras] = sy;
    tras++;
    visitado[sx][sy] = 1;

    while (frente < tras) {
        int x = fila_x[frente];
        int y = fila_y[frente];
        frente++;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if (visitado[nx][ny]) continue;

            if (mapa[nx][ny] == '_' || mapa[nx][ny] == 'E') {
                visitado[nx][ny] = 1;
                fila_x[tras] = nx;
                fila_y[tras] = ny;
                tras++;
            } else if (mapa[nx][ny] == 'o') {
                // Um pato morre, buraco é preenchido e se torna ponte
                mortos++;
                mapa[nx][ny] = '_';
                visitado[nx][ny] = 1;
                fila_x[tras] = nx;
                fila_y[tras] = ny;
                tras++;
            }
        }
    }

    // Verifica se há pelo menos um 'E' alcançado
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (mapa[i][j] == 'E' && visitado[i][j]) {
                return mortos;
            }
        }
    }

    return -1; // nenhum chegou
}

int main() {
    char linha[MAX];
    scanf("%d", &P);
    getchar(); // consumir newline

    while (fgets(linha, MAX, stdin)) {
        if (linha[strlen(linha) - 1] == '\n') linha[strlen(linha) - 1] = '\0';
        strcpy(mapa[M], linha);
        M++;
    }
    N = strlen(mapa[0]);

    int sx = -1, sy = -1;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (mapa[i][j] == 'S') {
                sx = i;
                sy = j;
                break;
            }
        }
        if (sx != -1) break;
    }

    int mortos = bfs(sx, sy);

    if (mortos == -1 || mortos >= P) {
        printf("Todos morreram :)\n");
    } else if (mortos == 0) {
        printf("Nenhum morreu :(\n");
    } else {
        printf("%d encontraram o vovo\n", P - mortos);
    }

    return 0;
}
