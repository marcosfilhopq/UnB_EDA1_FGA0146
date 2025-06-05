#include<stdio.h>
#include<string.h>

int encaixa(int a, int b){
    char str1[20], str2[20];

    sprintf(str1, "%d", a);
    sprintf(str2, "%d", b);

    int tam1 = strlen(str1);
    int tam2 = strlen(str2);

    //Se o numero 2 for maior que o numero 1, nao tem como "caber" o numero 2 no numero 1;
    if(tam2 > tam1){ 
        return 0;
    }

    //Aqui embaixo exemplifica o seguinte, strcmp compara se a str2 "pertence" a str1, tudo ai tranquilo. Agora essa de tam1 - tam2 siginfica que, se str1 for "12345", logo seu tam1 == 5, o mesmo ocorre pro tam2. Dessa forma str1 + (5 - 2, de exemplo), logo vai para a terceira posicao da str1, nesse caso '4', ent vai compara esse resto '45' com a str2

    if(strcmp(str1 + tam1 - tam2, str2) == 0){
        return 1;
    } else{
        return 0;
    }
}
