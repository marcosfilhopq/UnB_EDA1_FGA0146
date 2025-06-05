#include <stdio.h>
#include <math.h>

void regua_inglesa(int nivel){
    if(nivel == 0){
        return;
    }

    else{
        regua_inglesa(nivel-1); //Esquerda da regua

        printf(".");
        for(int i=0;i<nivel;i++){
            printf("-");
        }
        printf("\n");

        regua_inglesa(nivel-1); //Direita da regua

    }

}
    
int main(){
    int n;
    scanf("%d", &n);

    regua_inglesa(n);
    
    return 0;
}