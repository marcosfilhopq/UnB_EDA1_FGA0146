//SelectionSort é melhor pra usar sem loop

int loopInt(int v[], int j, int n, int menor){
    if (j == n) {
        return menor;
    } //acaba
    
    if(v[j]<v[menor]) menor=j;
    return loopInt(v, j + 1, n, menor);
}

void loopExt(int v[], int i, int n){
    if(i==n-1) return;

    int menor = loopInt(v,i+1, n,i); // acha o menor do resto

    // troca se necessário
    if (menor != i) {
        int tmp = v[i];
        v[i] = v[menor];
        v[menor] = tmp;
    }

    loopExt(v,i+1,n); // faz o mesmo para a próxima posição
}

void ordena(int *v, int n){
    loopExt(v, 0, n);
}
