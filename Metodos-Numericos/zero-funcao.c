#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void bs(double a, double b, double erro, double (*funcao)(double x));
void sc(double a, double b, double erro, double (*funcao)(double x));

double func_A(double x);
double func_B(double x);
double func_C(double x);

//Entrada da forma: ./nome_arquivo metodo(bs/sc) erro a b
int main(int argc, char *argv[]) {

    double a = atof(argv[3]);
    double b = atof(argv[4]);
    double erro = atof(argv[2]);

    if(strcmp(argv[1], "bs") == 0){
        printf("\n\t***METEDO BISSECAO***\n\n");
        printf("----f(x) = x^5 - 2x^4 - 9x^3 + 22x^2 + 4x - 24\n");
        bs(a, b, erro, func_A);

        printf("----f(x) = cos(x) - sqrt(x)\n");
        bs(a, b, erro, func_B);

        printf("----f(x) = (sqrt(x) - 5)e^-x\n");
        bs(a, b, erro, func_C);
    }

    else if(strcmp(argv[1], "sc") == 0){
        printf("\n\t***METEDO SECANTE***\n\n");
        printf("----f(x) = x^5 - 2x^4 - 9x^3 + 22x^2 + 4x - 24----\n");
        sc(a, b, erro, func_A);

        printf("----f(x) = cos(x) - sqrt(x)----\n");
        sc(a, b, erro, func_B);

        printf("----f(x) = (sqrt(x) - 5)e^-x----\n");
        sc(a, b, erro, func_C);
    }

    else
        printf("Erro ao chamar a funcao\n");
   
    return 0;
}

void bs(double a, double b, double erro, double (*funcao)(double x)){
    double x0 = a;
    double x1 = b;
    int passos = 0;
    
    if((funcao(a) * funcao(b)) <= 0){
        x1 = (a + b) / 2.0;
        
        while(fabs(x1 - x0) > erro){
            x0 = x1;

            if((funcao(a) * funcao(x1)) < 0){
                b = x1;
                x1 = (a + b) / 2.0;
            }
            else if((funcao(b) * funcao(x1)) < 0){
                a = x1;
                x1 = (a + b) / 2.0;
            }
            passos ++;
        } 
        printf("Valor de x: %.8lf\nPassos: %d\n\n", x0, passos);
    }
    else{
        printf("Nao existe 0 da funcao para esse intervalo\n\n");
    }
}
void sc(double x0, double x1, double erro, double (*funcao)(double x)){
    double x_ant = x0;
    double x_atual = x1;
    double temp;
    int passos = 0;

    while(fabs(x_atual - x_ant) > erro){
        temp = x_atual;
        x_atual = (x_ant * funcao(x_atual) - x_atual * funcao(x_ant)) / (funcao(x_atual) - funcao(x_ant));
        x_ant = temp;
        passos++;
    }

    printf("Valor de x: %lf\nPassos: %d\n\n", x_atual, passos);
}
/*O metodo secante nem sempre apresenta o resultado esperado para funcoes que necessitam da raiz quadrada de 
um valor, nos casos onde esse valor eh negativo. Esse numero negativo eh obitido durante o calculo de x+1.*/

double func_A(double x){
    return pow(x, 5) - 2*pow(x, 4) - 9*pow(x, 3) + 22*pow(x, 2) + 4*x - 24;
}

double func_B(double x){
    return cos(x) - sqrt(x);
}

double func_C(double x){
    return (sqrt(x) - 5) * exp(-x);
}