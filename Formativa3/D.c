#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int pos;
} Item;

//comparação para qsort (ordenar por val)
int cmp(const void *a, const void *b) {
    Item *ia = (Item*)a;
    Item *ib = (Item*)b;
    if (ia->val < ib->val) return -1;
    if (ia->val > ib->val) return 1;
    return 0;
}

// Busca binária retorna índice do item encontrado ou -1
int busca_binaria(Item *arr, int n, int x) {
    int left = 0, right = n -1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid].val == x) {
            // Se houver duplicatas, queremos a primeira ocorrência, ela percorre pra trás pra achar a primeira
            while(mid > 0 && arr[mid-1].val == x) mid--;
            return mid;
        }
        else if(arr[mid].val < x) {
            left = mid +1;
        } else {
            right = mid -1;
        }
    }
    return -1;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Item *arr = malloc(N * sizeof(Item));
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i].val);
        arr[i].pos = i;
    }

    qsort(arr, N, sizeof(Item), cmp);

    for(int i=0; i<M; i++) {
        int x;
        scanf("%d", &x);
        int idx = busca_binaria(arr, N, x);
        if(idx == -1) {
            printf("-1\n");
        } else {
            printf("%d\n", arr[idx].pos);
        }
    }

    free(arr);
    return 0;
}
