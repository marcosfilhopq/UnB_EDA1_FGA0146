#include <stdio.h>
#include <stdlib.h>

void insercao(int *v, int n){
    /*Comeca pelo segundo elemento
        Compara com os anteriores.
        Vai movendo os maiores até encontrar a posição certa.
        {5, 3, 4}
        → {3, 5, 4}
        → {3, 4, 5}
        */      
    for(int i=1; i<n;i++){ 
        int chave = v[i];
        int j=i-1;
    
    while(j>=0 && v[j]>chave){ //j>=0 quer dizer para o indice ainda esta no vetor
        v[j+1] = v[j];
        j--; //descresce no vetor
    }

    v[j+1]=chave; //como descreceu o j a -1, para sair do while, o v[j+1] cai no v[0]
    }
}

// Selection Sort
void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i; //Assume que o menor valor é o atual
        for (int j = i + 1; j < n; j++) { //Procura, apos o indice atual, o menor valor ate o fim do vetor
            if (v[j] < v[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
}

// Bubble Sort
void BubbleSort(int *v, int n){
    int i, continua, aux, fim=n;
    do{
        continua=0;
        for(int i=0; i<fim-1 /*penultima posicao*/; i++){
            if(v[i]>v[i+1]){ //aqui se faz um troca com o proximo caso seja maior
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                continua=1;
            }
            fim=fim-1; //como o maior numero foi para o final, ta feito, agora trazer o maior para o final desse "subvetor" 1 casa menor que o original
        }
    }while(continua!=0); 
}

int main(){
    int m;
    scanf("%d", &m);

    int *v;
    v=(int*) calloc (m, sizeof(int)); 
    /*
    (int*) = converte para int;
    calloc = zera todos espaços de memoria
    sizeof(int) = do tipo inteiro
    */

    if(v==NULL){
        return 1;
    }

    //Escanea
    for(int i=0;i<m;i++){
        scanf("%d", &v[i]);
    }

    insercao(v, m);  // ORDENAR o vetor

    for(int i=0;i<m;i++){
        printf("%d", v[i]);
    }

    free(v); //tira o lixo(libera o vetor)
    
    return 0;
}

void insercao(int *v, int tamanho){
    for(int i=1; i<tamanho; i++){
        int chave=v[i];
        for(int j=i; (j>=0) && v[j-1]>chave; j--){
            v[j]=v[j-1];
        }
        v[j+1]=chave; 
    }
}

void bubble(int *v, int tamanho){
    int continua=0;
    do{

        for(int i=0; i<tamanho; i++){
            if(v[i]>v[i+1]){
                int aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;

                tamanho--;
                continua=1;
            }
        }
    } while(continua!=0);
    
}

void insercao(int *v, int n){
    for(int i=1; i<n; i++){
        int chave=v[i];
        for(int j=i; j>=0 && v[j-1]>chave;j-- ){
            v[j] = v[j-1];
        }
        v[j+1] = chave;
    }
}

void bublle(int *v, int n){
    int continua=0;
    do{
        for(int i=0; i<n; i++){
            if(v[i]>v[i+1]){
                int aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
            }
            continua=1;
        }
    }while(continua!=0);
}

void selecao(int *v, int n){
    for(int i=0; i<n-1; i++){
        int menor=i; //assume momentaneamente que ele é o menor
        for(int j=i+1;j<n;j++){
            if(v[j]<v[menor]){
                menor=j;
            }
        }

        if(i!=menor){
            int aux=v[i];
            v[i]=v[menor];
            v[menor]=aux;
        }
    }
}

// Função que junta dois pedaços ordenados em um só
void merge(int array[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Cria arrays temporários
    int esquerda[n1], direita[n2];

    // Copia os elementos
    for (int i = 0; i < n1; i++)
        esquerda[i] = array[inicio + i];
    for (int j = 0; j < n2; j++)
        direita[j] = array[meio + 1 + j];

    // Junta os dois arrays na ordem
    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            array[k] = esquerda[i];
            i++;
        } else {
            array[k] = direita[j];
            j++;
        }
        k++;
    }

    // Copia o que sobrou
    while (i < n1) {
        array[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = direita[j];
        j++;
        k++;
    }
}

// Função principal recursiva de ordenação
void mergeSort(int array[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        mergeSort(array, inicio, meio);
        mergeSort(array, meio + 1, fim);
        merge(array, inicio, meio, fim);
    }
}

// Função para imprimir o array
void imprimirArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Função principal (main)
int main() {
    int array[] = {38, 27, 43, 3, 9, 82, 10};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Antes do Merge Sort:\n");
    imprimirArray(array, tamanho);

    mergeSort(array, 0, tamanho - 1);

    printf("Depois do Merge Sort:\n");
    imprimirArray(array, tamanho);

    return 0;
}


int particiona(int *v, int inicio, int fim){
    int esq=inicio;
    int dir=fim;
    int pivo=v[inicio];
    while(esq<dir){
        while(v[esq]<=pivo){
            esq++;
        }
        while(v[dir]>pivo){
            dir--;
        }
        if(esq<dir){
            int aux=v[esq];
            v[esq]=v[dir];
            v[dir]=aux;
        }
    }

    // Troca o pivô com o valor final da partição
    int aux = v[inicio];
    v[inicio] = v[dir];
    v[dir] = aux;

    return dir;
}

void quickSort(int *v, int inicio, int fim){
    int pivo;
    if(fim>inicio){
        pivo=particiona(v,inicio,fim);
        quickSort(v, inicio, pivo-1);
        quickSort(v, pivo+1, fim);
    }
}

