#include <stdio.h>
#include <stdlib.h>

#define MAX 10000001

int BIT[MAX];

// Atualiza o BIT no índice idx com valor val
void update(int idx, int val) {
    while (idx < MAX) {
        BIT[idx] += val;
        idx += idx & (-idx);
    }
}

// Consulta soma prefixada no BIT até idx
int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

// Busca o k-ésimo número inserido (k entre 1 e total elementos)
int busca_k_esimo(int k) {
    int idx = 0;
    int bitMask = 1 << 24; // maior potência de 2 menor que MAX (ajustar se precisar)
    
    while (bitMask != 0) {
        int tIdx = idx + bitMask;
        if (tIdx < MAX && BIT[tIdx] < k) {
            k -= BIT[tIdx];
            idx = tIdx;
        }
        bitMask >>= 1;
    }
    return idx + 1;
}

int main() {
    int O, x;
    int total = 0;

    while (scanf("%d", &O) != EOF) {
        if (O == 1) {
            scanf("%d", &x);
            x++;  // BIT usa índices 1-based
            update(x, 1);
            total++;
        }
        else if (O == 2) {
            scanf("%d", &x);
            if (x > total) x = total;

            for (int i = 1; i <= x; i++) {
                if (i > 1) printf(" ");
                int val = busca_k_esimo(i) - 1; // volta ao zero-based
                printf("%d", val);
            }
            printf("\n");
        }
    }
    return 0;
}
