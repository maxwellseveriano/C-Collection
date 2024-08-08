#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 20
#define H 0.1
#define PARADA 1e-4

int jacobi(double);
int seidel(double);
int sor(double);

int main(){
	
	int i, k;
	double x[N], xProx[N];
	double parada = pow(10, -4);
	
	int iteracoesJ = jacobi(parada);
	printf("Gauss-Jacobi: %d iteracoes\n\n", iteracoesJ);
	int iteracoesS = seidel(parada);
	printf("Gauss-Seidel: %d iteracoes\n\n", iteracoesS);
	int iteracoesSOR = sor(parada);
	printf("SOR: %d iteracoes\n\n", iteracoesSOR);
}

int jacobi(double parada){
	int i, j, k, cont = 0;
	double x[N+2] = {0}, x_prox[N+2];
	double fim = PARADA + 1;
	
	while(fim > parada){
		fim = 0;
		for(i = 1; i <= N; i++){
			x_prox[i] = (1 - x[i - 1] - x[i + 1]) / (-2 * (1 + pow(H, 2)));
			fim += fabs(x_prox[i] - x[i]);
		}
		for(i = 1; i <= N; i++){
			x[i] = x_prox[i];
		}
		cont++;
	}

	for(i = 1; i <= N; i++){
		printf("x%d: %f\n", i, x[i]);
	}
	printf("\n");
	
	return cont;
}
int seidel(double parada){
	int i, j, k, cont = 0;
	double x[N+2] = {0}, x_prox;
	double fim = parada + 1;
	
	while(fim > parada){
		fim = 0;
		for(i = 1; i <= N; i++){
			x_prox = (1 - x[i - 1] - x[i + 1]) / (-2 * (1 + pow(H, 2)));
			fim = fabs(x_prox - x[i]);
			
			x[i] = x_prox;
		}
		cont++;
	}
	for(i = 1; i <= N; i++){
		printf("x%d: %f\n", i, x[i]);
	}
	printf("\n");
	
	return cont;
}
int sor(double parada){
	int i, j, k, cont = 0;
	double x[N+2] = {0}, x_prox;
	double fim = parada + 1;
	double W = 1;
	
	
	while(fim > parada){
		fim = 0;
		for(i = 1; i <= N; i++){
			x_prox = ((1 - W) * x[i]) + (W * (1 - x[i - 1] - x[i + 1]) / (-2 * (1 + pow(H, 2))));
			fim = fabs(x_prox - x[i]);
			
			x[i] = x_prox;
		}
		cont++;
	}
	for(i = 1; i <= N; i++){
		printf("x%d: %f\n", i, x[i]);
	}
	printf("\n");
	
	return cont;
}

