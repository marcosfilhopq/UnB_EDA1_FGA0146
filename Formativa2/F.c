#include <stdio.h>

long long soma_caracteres(long long a){
    int soma = 0;
    if(a==0){
        return 0;
    }
    else{
        return (a%10) + soma_caracteres(a/10);
    }
}

int main(){
    long long n, resultado;

    scanf("%lld", &n);

    if(n<0){
        n = -n;
    }

    resultado = soma_caracteres(n);
    printf("%lld\n", resultado);

    return 0;
}