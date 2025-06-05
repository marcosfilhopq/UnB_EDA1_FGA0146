#include <stdio.h>

int main(){
    int cine[20][25];
    int i, j, F, L, numero;
    char letra;

    for (i = 0; i < 20; i++){ //Evita lixo de memoria
        for (j = 0; j < 25; j++){
           cine[i][j] = 0;
        }
    }

    scanf("%d%d", &F, &L);
    while ((scanf("%c%d", &letra, &numero)) != EOF){
        cine[letra-65][numero-1] = 1;
    }
    
    printf(" ");
    for (i = 1; i <= L; i++){
        printf(" %02d", i);
    }
    printf("\n");
    
    for (i = F - 1; i >= 0; i--){
        printf("%c", i+65);
        for (j = 0; j < L; j++){
            if (cine[i][j] == 0){
                printf(" --");
            } else{
                printf(" XX");                                 
            }
        }
        printf("\n"); 
    }
    return 0;
}