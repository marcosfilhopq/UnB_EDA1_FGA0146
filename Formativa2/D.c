#include <stdio.h>

void movex(char *x, char *semx, char *comx, int i, int j){

    if(*x == '\0'){
        semx[i] = '\0';
        comx[j] = '\0'; //Casos base, string vazia
        return;
    }
   
    if(*x!='x'){
        semx[i] = *x;
        movex(x+1, semx, comx, i+1, j); /*Como ele reiniciam se iniciar no inicio da função, o correto é colocar nos parametros, ou seja
        - x+1 //(Vai pro proximo caractere
        - semx e i+1 //Faz com que nao reseta
        */
        
    } else{
        comx[j] = *x;
        movex(x+1, semx, comx, i, j+1); //Aqui ele so anda com j, por isso j+1
    }
} 

int main(){
    char str[101];
    char resultado1[101], resultado2[101];

    if (scanf("%100s", str) != 1) {
        // Em caso de erro na leitura, imprime linha vazia e retorna
        printf("\n");
        return 0;
    }


    movex(str, resultado1, resultado2, 0, 0);

    printf("%s%s\n", resultado1, resultado2);

    return 0;
}