#include <stdio.h>
int main(){
    int n;
    do{
        scanf("%d", &n);
    } while(n<=0 || n>100);

    for(int i=0; i<=n-1;i++){
        for(int j=0;j<=i;j++){
            printf("%02d ", i+1);
        }
        printf("\n");
    }

    printf("\n");

    for(int i=0; i<=n-1;i++){
        for(int j=0;j<=i;j++){
            printf("%02d ", j+1);
        }
        printf("\n");
    }

    return 0;
}