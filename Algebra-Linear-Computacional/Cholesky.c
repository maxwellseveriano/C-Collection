#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** geraMatriz(int, int);
void imprime(double **, int );

int main(){
    int n = 21; 
	int definida = 1;
	double total, valor;
	
    double **A = geraMatriz(n+1, 1);
    double **L = geraMatriz(n+1, 0); 

	for(int i = 0; i < n; i++){
        for(int j = 0; j < (i + 1); j++){
            total = 0.0;
            if(j == i){
                for(int k = 0; k < j; k++){
                    total += pow(L[j][k], 2);
                }
                valor = A[j][j] - total;
                if(valor <= 0){
                    definida = 0;
                    break;
                }
                L[j][j] = sqrt(valor);
            }
			else{
                for(int k = 0; k < j; k++){
                    total += L[i][k] * L[j][k];
                }
                L[i][j] = (A[i][j] - total) / L[j][j];
            }
        }
    }
    
    if(definida){
        printf("[A] EH SIMETRICA DEFINIDA POSITIVA.\n");;
        imprime(L, n);
    } 
	else{
        printf("[A] NAO EH SIMETRICA DEFINIDA POSITIVA\n");
        imprime(L, n);
    }

    return 0;
}
double** geraMatriz(int n, int x){
	int i, j, aux = 0;
	double** matriz1;
	
	matriz1 = (double **) malloc(n * sizeof(double *));
    for (i = 0; i < n; i++) {
        matriz1[i] = (double *) malloc(n * sizeof(double));
    }
    if(x == 0){
    	for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				matriz1[i][j] = 0;
			}
		}
		return matriz1;
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			matriz1[i][j] = abs(j - i);
		}
	}
	return matriz1;
}
void imprime(double ** matriz,int n){
	int i, j;
	printf("\nFatoracao:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%4.1f ", matriz[i][j]);
		}
		printf("\n");
	}
}
