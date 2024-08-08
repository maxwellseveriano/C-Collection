#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double mult(double *, double *);
double* eleva(double vet[], int exp);

int main(){

    double vetorX[8] = {-8, -5.71428571, -3.42857143, -1.14285714, 1.14285714, 3.42857143, 5.71428571, 8};
    double vetorY[8] = {1.06635918, 0.80014487, 0.64216079, 0.54170856, 0.44962931, 0.39317197, 0.33772819, 0.31377657};

    double res = mult(eleva(vetorX, 0), eleva(vetorY, -1));

    printf("Resultado: %.8f\n", res);
}

double mult(double vet1[], double vet2[]){
    double soma = 0.0;
    for(int i = 0; i < 8; i++){
        soma += vet1[i] * vet2[i];
    }
    return soma;
}

double* eleva(double vet[], int exp){
    
    double *res = (double*) malloc(8 * sizeof(double));
    for(int i = 0; i < 8; i++){
        res[i] = pow(vet[i], exp);
    }
    return res;
}