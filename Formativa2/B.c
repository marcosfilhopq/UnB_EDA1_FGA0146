#include <stdio.h>

void inverter(char *str){
    if(*str == '\0'){ //String vazia (caso base)
        return;
    } else {
        inverter(str + 1); //acessa o proximo caractere
        putchar(*str); //imprime apos recursao (inverte)
    }
} //Isso aqui é quase como empilhar algo, voce empilha "amor", sendo o "a" o primeiro livro e depois tem que desempilhar na ordem, so que ai os ultimos serao os primeiros, começa agora pelo "r" e nao mais pelo "a"

int main(){
    char s[500];
    scanf("%s", &s);

    inverter(s);
    putchar('\n');

    return 0;
}