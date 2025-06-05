#include <stdio.h>
#include <math.h>

double potencia(double base, double exp){
    return pow(base,exp);
}

double fatorial(double n){
    return tgamma(n + 1); // Γ(n+1) = n!
}

const char* maior(double a, double b){ //ponteiro para string constante, isso retorna strings
    if(a>b){
        return "Lucas";
    } else {
        return "Pedro";
    }

}

int main(){
    int min = 2, max = 20000000;
    double base, expoente, fat;

    do{
        //printf("Digite a entrada de Lucas: \n");
        scanf("%lf %lf", &base, &expoente);

        /*if(!(base >= min && base<=max && expoente>=min && expoente<=max )){ //! significa not
            printf("Valores devem estar entre o %d e %d\n", min, max);
        } */

    } while(!(base >= min && base<=max && expoente>=min && expoente<=max )); 
    
    do{
        //printf("Digite a entrada de Pedro: \n");
        scanf("%lf", &fat);

        /*if(fat < min || fat > max){
            printf("Valores devem estar entre o %d e %d\n", min, max);
        } */
    } while(fat < min || fat > max);

    double rl = potencia(base,expoente);
    //printf("%0.2lf\n", rl); 

    double rp = fatorial(fat);
    //printf("%0.2lf\n", rp); 
    
    const char* resultado = maior(rl, rp);
    printf("%s", resultado);

    return 0;
}