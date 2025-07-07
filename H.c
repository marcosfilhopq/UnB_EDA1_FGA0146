#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    int ia = *(int *)a;
    int ib = *(int *)b;
    if (ia < ib) return -1;
    if (ia > ib) return 1;
    return 0;
}

static inline int fast_read_int() {
    int x = 0, c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

char outbuf[1000000];
int outpos = 0;

static inline void fast_write_int(int x) {
    char temp[12];
    int i = 0;
    if (x == 0) {
        outbuf[outpos++] = '0';
    } else {
        while (x > 0) {
            temp[i++] = (x % 10) + '0';
            x /= 10;
        }
        while (i--) outbuf[outpos++] = temp[i];
    }
    outbuf[outpos++] = '\n';
}

int main() {
    int N = fast_read_int();
    int P = fast_read_int();
    int X = fast_read_int();

    int *ids = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        ids[i] = fast_read_int();
    }

    qsort(ids, N, sizeof(int), compara);

    long long inicio = (long long) P * X;
    long long final = inicio + X;

    if (inicio >= N) {
        free(ids);
        return 0;
    }
    if (final > N) final = N;

    for (long long i = inicio; i < final; i++) {
        fast_write_int(ids[i]);
    }

    fwrite(outbuf, 1, outpos, stdout);

    free(ids);
    return 0;
}
