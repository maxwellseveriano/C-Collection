#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func_A(double x){
    return pow(x, 5) - 2*pow(x, 4) - 9*pow(x, 3) + 22*pow(x, 2) + 4*x - 24;
}

double func_B(double x){
    return sqrt(x) - cos(x);
}

double func_C(double x){
    return (sqrt(fabs(x)) - 5) * exp(-x);
}

double func_D(double x){
    return pow(x, 3) + 3*x - 1;
}

void sc(double x0, double x1, double erro, double (*funcao)(double x)){
    double x_ant = x0;
    double x_atual = x1;
    double temp;

    //x_prox = (x_ant * funcao(x_atual) - x_atual * funcao(x_ant)) / (funcao(x_atual) - funcao(x_ant));
    while(fabs(x_atual - x_ant) > erro){
        temp = x_atual;
        x_atual = (x_ant * funcao(x_atual) - x_atual * funcao(x_ant)) / (funcao(x_atual) - funcao(x_ant));
        x_ant = temp;
    }

    printf("Resultado: %lf\n", x_atual);
}

int main()
{
    char x[100] = "1E-10";
    double erro = atof(x);
    double a = 1;
    double b = 3;

    sc(a, b, erro, func_A);
    //printf("%lf", (funcao(25.92) - funcao(26)));

    return 0;
}