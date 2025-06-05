#include <stdio.h>

double calculaVelocidadeMedia(int tA, int tB, double distancia){
    double vt;
    double vm;
    vt = (tB-tA)/3600.0; //segundos para hora

    vm=distancia/vt;

    return vm;
}

int levouMulta(int tA, int tB, double distancia, double velocidadeMaxima){
    double vm2 = calculaVelocidadeMedia(tA, tB, distancia);
    if(vm2>velocidadeMaxima){
        return 1;
    } 
    if(vm2<=velocidadeMaxima){
        return 0;
    }
}
