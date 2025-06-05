#include <stdio.h>
void trocaxy(char *str){
    if (*str == '\0')
    {
        return;
    }
    if(*str == 'x'){
        *str = 'y';
    }

    trocaxy(str + 1); //Ao final, ele vai para o proximo caractere, conferindo se tem x ou y em alguma parte da string.
}

int main(){
    char str[80];

    scanf("%s", str);

    trocaxy(str);

    printf("%s\n", str);

    return 0;
}